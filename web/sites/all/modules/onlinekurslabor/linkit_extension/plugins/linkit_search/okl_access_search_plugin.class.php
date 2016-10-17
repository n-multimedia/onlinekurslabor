<?php

/**
 * @file
 * Wir machen das hier, weil Linkit keine Permission-Checks hat. Wir müssen die Ergebnisse filtern,
 * um Items auszusortieren, die im aktuellen Lehrtext nicht genutzt werden koennen.
 * Moechte man bei einem Linkit-Profil Filterung verwenden, muss man "node with access-check" 
 * als Provider in der linkit-konfiguration wählen und ggf. die Methode hier anpassen
 * Define Linkit entity search plugin class.
 */

/**
 * Represents a Linkit entity search plugin.
 */
class OKLAccessSearchPlugin extends LinkitSearchPluginNode {

    /**
     * Overrides LinkitSearchPlugin::ui_title().
     */
    function ui_title() {
        return t('node with access-check');
    }

    /**
     * Overrides LinkitSearchPlugin::ui_description().
     */
    function ui_description() {
        return t('Includes an access-check for onlinekurslabor.');
    }

    /**
     * Implements LinkitSearchPluginInterface::fetchResults().
     */
    public function fetchResults($search_string) {
        global $user;

        /* calculate active domain */
        $refer = @$_SERVER['HTTP_REFERER'];
        preg_match("/og_group_ref=(\d*)/", $refer, $res);
        $active_domain_nid = $res[1];

        $unfiltered_results = parent::fetchResults($search_string);
        //konnte aktuelle domain nicht entdecken - ungefiltert alle autocomplete-results zurueck
        if (!$active_domain_nid) {
            return $unfiltered_results;
        }

        /* die ungefilterten results werden jetzt geprueft, ob sie im aktuellen lehrtext anwindung finden koennen */
        foreach ($unfiltered_results as $counter => $unf_res) {
            //hole ausm path die node-id
            $results_node_id = preg_replace('/\D/', '', $unf_res["path"]);

            $result_node = node_load($results_node_id);
            switch ($result_node->type) {
                case NM_INTERACTIVE_CONTENT:
                    //h5p is nicht member der domain und dozent darf den content auch nicht bearbeiten
                    if (!og_is_member('node', $active_domain_nid, 'node', $result_node) && !node_access('update', $result_node)) {
                        unset($unfiltered_results[$counter]);
                    }
                    break;
                /* aufgaben im lehrtext */
                case NM_CONTENT_MULTIPLE_CHOICE:
                case NM_CONTENT_QUESTION_AND_ANSWER:
                    if (!og_is_member('node', $active_domain_nid, 'node', $result_node)) {
                        unset($unfiltered_results[$counter]);
                    }
                    break;
            }
        }

        //result list ist nun gefiltert
        return $unfiltered_results;
    }

}
