<?php

/**
 * Node-Permissions für Stream-Nodes an Annvid-Objekten
 */

/**
 * hook_node_access($node, $op, $account) {
 */
function annvid_node_access($node, $op, $account) {
//ergänzt nm_stream module um annvid-spezifische perms
    if ($node->type == 'nm_stream') {


        switch ($op) {
            //setze create-permission fuer annvid
            case 'create':
                $env_new_node = nm_stream_get_environment();

                //context: course/lehrtext, container: annvid
                $context = $env_new_node['context'];
                //ist der aktuelle nutzer mitglied im context (=KURS / DOMAIN) ?
                $context_membership = og_get_membership('node', $context->nid, 'user', $account->uid);
                //ist annvid && bin tn des Kontexts
                if ($env_new_node['container']->type == ANNVID_CONTENTTYPE && !empty($context_membership)) {
                    return NODE_ACCESS_ALLOW;
                }

                break;
            case 'update':
            case 'delete':
                //nun fuer einzelne nodes setzen, ob man editen /deleten darf
                $deny_edit = true;
                //eigene darf man immer bearbeiten, deswegen ignore (diese permission wurde früher schon festgelegt)
                if ($node->uid === $account->uid)
                    return NODE_ACCESS_IGNORE;

                //environment of existing node
                $env_node = _nm_stream_get_node_environment($node);
                if ($env_node['container']->type === ANNVID_CONTENTTYPE) {
                    $stream_privacy = $node->field_nm_privacy[LANGUAGE_NONE][0]['value'];
                    //in course
                    if ($stream_privacy == NM_STREAM_COURSE) {
                        //kann user den kurs bearbeitne?
                        $deny_edit = !node_access('update', node_load($env_node['context']->nid), $account);
                    } elseif ($stream_privacy == NM_STREAM_DOMAIN) {
                        //kann user den LEHRTEXT bearbeitne?
                        $deny_edit = !node_access('update', node_load($env_node['context']->nid), $account)
                                //spezialfall: context ist COURSE aber  visibility LT: dann über container (=annvid) den parent (=LT) holen und EDIT prüfen
                                && !node_access('update', node_load($env_node['container']->parent->nid), $account);
                        ;
                    }
                   //andere privacies sind privat & kursgruppe - hier passen die perms schon
                  
                    //jetzt deny setzen, falls keine bearbeitungsrechte fuer den streameintrag
                    if ($deny_edit)
                        return NODE_ACCESS_DENY;
                    break;
                }
        }
    }
    //default: 
    return NODE_ACCESS_IGNORE;
}

/**
 * override nm stream create, update and delete permissions
 * @param $perm
 * @param $context
 */
//ergänzt funktion nm_stream_og_user_access_alter um annvid-spezifische permissions
function annvid_og_user_access_alter(&$perm, $context) {

    global $user;
    $account = clone $user;

    /**
     * Problem: ANNVID_CONTENTTYPE ist als og_group ersellt. In og_groups dürfen nur members schreiben.
     * Jetzt wärs aber ein overkill, sämtliche Personen immer vererbend in die Annvids mit einzuschreiben.
     * Deswegen permission ergänzen unabhängig von der group-logik
     */
    if ($context['group']->type == ANNVID_CONTENTTYPE) {
        $stream_env = nm_stream_get_environment();

        $obj_context = node_load($stream_env['context']->nid);
        $og_membership = og_get_membership('node', $obj_context->nid, 'user', $account->uid);
        //create wird in nm_stream_node_access gesetzt   $perm['create ' . "nm_stream" . ' content'] = TRUE;
        //do not process if user is not member of this course
        if (!empty($og_membership)) {
            //erlaube uneingeschränkt zugriff auf das field; permission auf den stream selbst wird ja separat geregelt
            $perm['view field_nm_attachments field'] = true;
            $roles = og_get_user_roles('node', $og_membership->gid, $account->uid, TRUE, ($og_membership->state < OG_STATE_BLOCKED));
            //hab ich rollen? dann sicher im kurs.
            if (count($roles)) {
                $perm['update own ' . "nm_stream" . ' content'] = TRUE;
                $perm['delete own ' . "nm_stream" . ' content'] = TRUE;
            }


            //fall1 : ist ein kurs und bin tutor / dozent
            //fall2: ist LT und kann LT bearbeiten
            if ($obj_context->type == NM_COURSE && array_intersect($roles, array(
                        NM_COURSES_ROLE_ADMINISTRATOR,
                        NM_COURSES_ROLE_TUTOR
                    )) ||
                    $obj_context->type == NM_CONTENT_DOMAIN && count($roles)) {
                //wir machen hier "any" permissions. diese müssen in nm_stream_node_access weiter eingeschraenkt werden (bspw: tutor bearbeitet keine lehrtext-streameinträge)
                $perm['update any ' . "nm_stream" . ' content'] = TRUE;
                $perm['delete any ' . "nm_stream" . ' content'] = TRUE;
            }
        }
    }
}
