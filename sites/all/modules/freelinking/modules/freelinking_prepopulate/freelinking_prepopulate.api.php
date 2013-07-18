<?php
/**
 * Freelinking Prepopulate API
 *
 * @file
 *  Extends the Freelinking API with Prepopulate functions
 *
 *  These functions are for Freelinking Plugin developers.
 *
 *  To implement a new form field for processing,
 *  see freelinking_prepopulate_list_fields()
 */

/**
 * Extract the specified array fields from the current or specified page.
 * Build a l() 'query' array suitable for use by Prepopulate.
 *
 * @param $fields
 *   Array of fields to process.
 * @param path
 *   If NULL, the current page. Otherwise, lookup the path and use that page.
 *   (Path lookup not yet implemented)
 *
 * @see freelinking_prepopulate_list_fields(), l()
 */
function freelinking_prepopulate_fields_from_page($fields, $plugin = 'nodecreate', $path = NULL) {
  static $prepopulate;
  $query = array();
  $index = $plugin . serialize($fields);
  if (!$prepopulate[$index]) {
    $prepopulate[$index] = array_intersect_key(freelinking_prepopulate_list_fields($plugin), $fields);
  }

  if ($plugin == 'nodecreate' && arg(0) == 'node' && is_numeric(arg(1)) && !arg(2)) {
    $object = node_load(arg(1));
  }

  foreach ($prepopulate[$index] as $field => $definition) {
    switch ($field) {
      case 'og':
        $group = og_get_group_context();
        $query[$definition['prepopulate']] = $group->nid;
        break;
      case 'taxonomy':
        if (!$object->taxonomy) {
          break;
        }
        foreach ($object->taxonomy as $term) {
          $query[$definition['prepopulate'] . '[' . $term->vid . ']'] .= $term->name . ',';
        }
        break;
      case 'book':
        if ($node->book) {
          $query['parent'] = $object->book['mlid'];
        }
        break;
      default:
        if ($object->$field) {
          $query[$definition['prepopulate']] = $object->field;
        }
        break;
    }
  }
  return $query;
}

/**
 * Extract arguments for Prepopulate from the array.
 * Build a 'query' array suitable for use by Prepopulate.
 *
 * @param $target : array
 *   Array build from syntax defining arguments for use by the plugin.
 *  Any elements recognized by freelinking_prepopulate will be used.
 *
 * @see freelinking_prepopulate_list_fields(), l()
 */
function freelinking_prepopulate_fields_from_array($plugin, $target) {
  $query = array();
  $prepopulate = array_intersect_key(freelinking_prepopulate_list_fields($plugin), $target);
  foreach ($prepopulate as $field => $values) {
    // If it's an organic group, break the groups out to separate values.
    if ($field == 'og') {
      $query[$values['prepopulate']] = $target[$field];
    }
    // If it's a taxonomy, special handling of vocabulary is necessary.
    elseif ($field == 'taxonomy') {
      if (!strpos($target[$field], ':')) {
        $query[$values['prepopulate'] . '[1]'] = $target[$field];
        continue;
      }
      list($vocab, $terms) = explode(':', $target[$field]);

      if (is_int($vocab)) {
        $query[$values['prepopulate'] . '[' . $vocab . ']'] = $terms;
      }
      else {
        $query[$values['prepopulate'] . '[1]'] = $terms;
      }
    }
    else {
      $query[$values['prepopuplate']] = $target[$field];
    }
  }
  return $query;
}



/**
 * Build & retrieve the list of form fields for URL construction.
 * This is made with Prepopulate in mind, but is not restricted to Prepopulate.
 * You may add a $field to this list by calling this with the $field parameter
 * set.
 *
 * Predefines fields for taxonomy (tagging only), og audience, book parent, and
 * locale.  Taxonomy's 'prepopulate' must have [$vid] appended to it.
 *
 * While you can do a lot with Prepopulate, this is not intended as a method of
 * cloning an object. See modules such as http://drupal.org/project/node_clone
 * for that kind of functionality. Maybe create a plugin to leverage it.
 *
 * @param $plugin
 *   Specify the plugin name for which to collect relevant prepopulate fields.
 *
 * @param $field : array
 *  - 'field': The shorthand name for the form element within prepopulate.
 *  - 'title': Form title to active the field for processing.
 *  - 'prepopulate': The prepopulate URL 'edit' index for the field.
 *
 * @return array
 *   Returns an array of all form field values for the given plugin.
 *   array('field' => array('prepopulate' => String, 'title' => String));
 */
function freelinking_prepopulate_list_fields($plugin = 'nodecreate', $field = NULL) {
  static $fields;
  static $plugins;

  // We have fields, and no new one to add.
  // Return all fields associated with the plugin.
  if ($fields && !$field) {
    return array_intersect_key($fields, $plugins[$plugin]);
  }

  if ($field) {
    // Define a field with prepopulate, or override.
    if ($field['prepopulate']) {
      $fields[$field['field']]['prepopulate'] = $field['prepopulate'];
    }
    //Define the title of a new field, or override.
    if ($field['title']) {
      $fields[$field['field']]['title'] = $field['title'];
    }
    // Add an entry for an existing field to the plugins array.
    // Uniqueness does not matter.
    if ($fields[$field['field']]['prepopulate']) {
      $plugins[$plugin][$field['field']] = TRUE;
    }
  }

  if (!$fields) {
    if (module_exists('taxonomy')) {
      $fields['taxonomy'] = array(
        'title' => t('Same taxonomy terms (for shared vocabularies)'),
        'prepopulate' => 'edit[taxonomy][tags]',
      );
      $plugins['nodecreate']['taxonomy'] = TRUE;
    }
    if (module_exists('book')) {
      $fields['book'] = array(
        'title' => t('Parent book page'),
        'prepopulate' => 'parent',
      );
      $plugins['nodecreate']['book'] = TRUE;
    }
    if (module_exists('og')) {
      $fields['og'] = array(
        'title' => t('Organic Group audience'),
        'prepopulate' => 'gids[]',
      );
      $plugins['nodecreate']['og'] = TRUE;
    }
    if (module_exists('locale')) {
      // To Be Implemented
    }
  }

  return array_intersect_key($fields, $plugins[$plugin]);
}
