<?php
/**
 * @file
 * videosafe_features.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function videosafe_features_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-videosafe_folder-body'.
  $field_instances['node-videosafe_folder-body'] = array(
    'bundle' => 'videosafe_folder',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'nm_stream' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-videosafe_folder-field_parent_folder'.
  $field_instances['node-videosafe_folder-field_parent_folder'] = array(
    'bundle' => 'videosafe_folder',
    'default_value' => array(
      0 => array(
        'target_id' => 2438,
      ),
    ),
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => 'Oberordner',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'nm_stream' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_parent_folder',
    'label' => 'Übergeordneter Ordner',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'action' => 'hide',
          'action_on_edit' => 0,
          'fallback' => 'none',
          'providers' => array(
            'og_context' => 0,
            'url' => 1,
          ),
          'skip_perm' => 0,
          'status' => 1,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-videosafe_video-body'.
  $field_instances['node-videosafe_video-body'] = array(
    'bundle' => 'videosafe_video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Interne Bemerkung',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 0,
          'filtered_html' => 0,
          'full_html' => 0,
          'php_code' => 0,
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ds_code' => array(
              'weight' => 12,
            ),
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'multiple_value_widget' => 'table',
        'rows' => 2,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-videosafe_video-field_exclusive_access'.
  $field_instances['node-videosafe_video-field_exclusive_access'] = array(
    'bundle' => 'videosafe_video',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'Hat das Video einen <strong>Sperrvermerk</strong>, so können hier einzelne Autoren ausgewählt werden, die exklusiv die Berechtigung erhalten, das Video einzusehen und in Lehrtexten zu verwenden.  
<br><strong>Mehrere Werte kommagetrennt.</strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exclusive_access',
    'label' => 'Optional: Zugriff nur für',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-videosafe_video-field_parent_folder'.
  $field_instances['node-videosafe_video-field_parent_folder'] = array(
    'bundle' => 'videosafe_video',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_parent_folder',
    'label' => 'Ordner',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'action' => 'hide',
          'action_on_edit' => 0,
          'fallback' => 'none',
          'providers' => array(
            'og_context' => 0,
            'url' => 1,
          ),
          'skip_perm' => 0,
          'status' => 1,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-videosafe_video-field_video'.
  $field_instances['node-videosafe_video-field_video'] = array(
    'bundle' => 'videosafe_video',
    'deleted' => 0,
    'description' => 'Wählen Sie mindest ein Video zum Upload aus. Für die bestmögliche Browserunterstützung sollten Sie das Video im  <b>.webm</b>-Format und im  <b>.mp4</b>-Format hochladen.<br>
Achten Sie idealerweise auf eine sinnvolle Benennung der Datei!',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_video',
    'label' => 'Video-Dateien',
    'required' => 1,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'videosafe',
      'file_extensions' => 'mp4 m4v avi ogg ogm ogv webm weba',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'multiple_value_widget' => 'table',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Hat das Video einen <strong>Sperrvermerk</strong>, so können hier einzelne Autoren ausgewählt werden, die exklusiv die Berechtigung erhalten, das Video einzusehen und in Lehrtexten zu verwenden.  
<br><strong>Mehrere Werte kommagetrennt.</strong>');
  t('Interne Bemerkung');
  t('Oberordner');
  t('Optional: Zugriff nur für');
  t('Ordner');
  t('Video-Dateien');
  t('Wählen Sie mindest ein Video zum Upload aus. Für die bestmögliche Browserunterstützung sollten Sie das Video im  <b>.webm</b>-Format und im  <b>.mp4</b>-Format hochladen.<br>
Achten Sie idealerweise auf eine sinnvolle Benennung der Datei!');
  t('Übergeordneter Ordner');

  return $field_instances;
}
