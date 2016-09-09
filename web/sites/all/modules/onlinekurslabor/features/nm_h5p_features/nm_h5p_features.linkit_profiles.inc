<?php
/**
 * @file
 * nm_h5p_features.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function nm_h5p_features_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'h5p_interactive_content';
  $linkit_profile->admin_title = 'H5P Interactive Content ';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '1';
  $linkit_profile->data = array(
    'text_formats' => array(
      'filtered_html' => 0,
      'full_html' => 0,
      'plain_text' => 0,
      'php_code' => 0,
      'ds_code' => 0,
    ),
    'search_plugins' => array(
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:profile2' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:relation' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_book' => 0,
        'comment_node_biblio' => 0,
        'comment_node_content_question_and_answer' => 0,
        'comment_node_content_chapter' => 0,
        'comment_node_content_multiple_choice' => 0,
        'comment_node_content_domain' => 0,
        'comment_node_courses_news' => 0,
        'comment_node_courses_generic_task' => 0,
        'comment_node_courses_generic_task_solution' => 0,
        'comment_node_courses_course' => 0,
        'comment_node_courses_docs' => 0,
        'comment_node_courses_group' => 0,
        'comment_node_page' => 0,
        'comment_node_forum' => 0,
        'comment_node_h5p_content' => 0,
        'comment_node_nm_stream' => 0,
        'comment_node_panel' => 0,
        'comment_node_plattform_log' => 0,
        'comment_node_projects_documentation' => 0,
        'comment_node_projects_cooperation_agreement' => 0,
        'comment_node_projects_objective' => 0,
        'comment_node_projects_organization' => 0,
        'comment_node_projects_proposal' => 0,
        'comment_node_projects_blog' => 0,
        'comment_node_videosafe_folder' => 0,
        'comment_node_videosafe_video' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:node' => array(
      'result_description' => '',
      'bundles' => array(
        'h5p_content' => 'h5p_content',
        'book' => 0,
        'biblio' => 0,
        'content_question_and_answer' => 0,
        'content_chapter' => 0,
        'content_multiple_choice' => 0,
        'content_domain' => 0,
        'courses_news' => 0,
        'courses_generic_task' => 0,
        'courses_generic_task_solution' => 0,
        'courses_course' => 0,
        'courses_docs' => 0,
        'courses_group' => 0,
        'page' => 0,
        'forum' => 0,
        'nm_stream' => 0,
        'panel' => 0,
        'plattform_log' => 0,
        'projects_documentation' => 0,
        'projects_cooperation_agreement' => 0,
        'projects_objective' => 0,
        'projects_organization' => 0,
        'projects_proposal' => 0,
        'projects_blog' => 0,
        'videosafe_folder' => 0,
        'videosafe_video' => 0,
      ),
      'group_by_bundle' => 0,
      'include_unpublished' => 0,
    ),
    'entity:profile2' => array(
      'result_description' => '',
      'bundles' => array(
        'master' => 0,
        'student' => 0,
        'data' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:relation' => array(
      'result_description' => '',
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
        'application' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'url_type' => 'entity',
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'forums' => 0,
        'hochschulen' => 0,
        'hashtags' => 0,
        'sponsors' => 0,
        'semester' => 0,
        'operational_area' => 0,
        'task_area' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'insert_plugin' => array(
      'url_method' => '2',
    ),
    'attribute_plugins' => array(
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '1',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['h5p_interactive_content'] = $linkit_profile;

  return $export;
}
