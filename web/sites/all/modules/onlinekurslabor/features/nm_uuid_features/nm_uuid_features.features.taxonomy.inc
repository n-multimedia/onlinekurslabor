<?php

/**
 * @file
 * nm_uuid_features.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nm_uuid_features_taxonomy_default_vocabularies() {
  return array(
    'forums' => array(
      'name' => 'Foren',
      'machine_name' => 'forums',
      'description' => 'Forum Navigations-Vokabular',
      'hierarchy' => 0,
      'module' => 'forum',
      'weight' => -10,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'hochschulen' => array(
      'name' => 'Hochschulen',
      'machine_name' => 'hochschulen',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -9,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
