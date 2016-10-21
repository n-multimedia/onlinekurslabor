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

        $unfiltered_results = parent::fetchResults($search_string);

        /* calculate active domain */
        $refer = @$_SERVER['HTTP_REFERER'];
        preg_match("/og_group_ref=(\d*)/", $refer, $res);
        $found_og_ref = $res[1];

        //konnte keinen context entdecken - ungefiltert alle autocomplete-results zurueck
        if (!$found_og_ref) {
            return $unfiltered_results;
        }
        $o_og_ref = node_load($found_og_ref);


        /* die ungefilterten results werden jetzt geprueft, ob sie im aktuellen lehrtext anwendung finden koennen */
        foreach ($unfiltered_results as $counter => $unf_res) {
            //hole ausm path die node-id
            $results_node_id = preg_replace('/\D/', '', $unf_res["path"]);
            $result_node = node_load($results_node_id);
            
            if (!_onlinekurslabor_access_domain_content_is_available_in($result_node, $o_og_ref)) {
                unset($unfiltered_results[$counter]);
            }
        }

        //result list ist nun gefiltert
        return $unfiltered_results;
    }

}
