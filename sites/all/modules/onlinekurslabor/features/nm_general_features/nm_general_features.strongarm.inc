<?php
/**
 * @file
 * nm_general_features.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nm_general_features_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'anonymous';
  $strongarm->value = 'Gast';
  $export['anonymous'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_annotations';
  $strongarm->value = 'none';
  $export['biblio_annotations'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_author_links';
  $strongarm->value = 1;
  $export['biblio_author_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_author_link_profile';
  $strongarm->value = 0;
  $export['biblio_author_link_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_author_link_profile_path';
  $strongarm->value = 'user/[user:uid]';
  $export['biblio_author_link_profile_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_auto_citekey';
  $strongarm->value = 1;
  $export['biblio_auto_citekey'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_auto_orphaned_author_delete';
  $strongarm->value = 0;
  $export['biblio_auto_orphaned_author_delete'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_base';
  $strongarm->value = 'biblio';
  $export['biblio_base'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_baseopenurl';
  $strongarm->value = '';
  $export['biblio_baseopenurl'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_base_title';
  $strongarm->value = 'Biblio';
  $export['biblio_base_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_citekey_field1';
  $strongarm->value = 'nid';
  $export['biblio_citekey_field1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_citekey_field2';
  $strongarm->value = 'nid';
  $export['biblio_citekey_field2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_citekey_phpcode';
  $strongarm->value = '';
  $export['biblio_citekey_phpcode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_citekey_prefix';
  $strongarm->value = '';
  $export['biblio_citekey_prefix'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_contrib_fields_delta';
  $strongarm->value = '2';
  $export['biblio_contrib_fields_delta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_copy_taxo_terms_to_keywords';
  $strongarm->value = 0;
  $export['biblio_copy_taxo_terms_to_keywords'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_crossref_pid';
  $strongarm->value = '';
  $export['biblio_crossref_pid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_display_citation_key';
  $strongarm->value = 0;
  $export['biblio_display_citation_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_download_links_to_node';
  $strongarm->value = 0;
  $export['biblio_download_links_to_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_export_links';
  $strongarm->value = array(
    'bibtex' => 'bibtex',
    'xml' => 'xml',
  );
  $export['biblio_export_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_file_link_type';
  $strongarm->value = 'text';
  $export['biblio_file_link_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_fix_isi_links';
  $strongarm->value = 0;
  $export['biblio_fix_isi_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_footnotes_integration';
  $strongarm->value = 0;
  $export['biblio_footnotes_integration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_hide_bibtex_braces';
  $strongarm->value = 0;
  $export['biblio_hide_bibtex_braces'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_index';
  $strongarm->value = 0;
  $export['biblio_index'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_init_auth_count';
  $strongarm->value = '4';
  $export['biblio_init_auth_count'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_inpress_year_text';
  $strongarm->value = 'In Press';
  $export['biblio_inpress_year_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_isi_url';
  $strongarm->value = 'http://apps.isiknowledge.com/InboundService.do?Func=Frame&product=WOS&action=retrieve&SrcApp=EndNote&Init=Yes&SrcAuth=ResearchSoft&mode=FullRecord&UT=';
  $export['biblio_isi_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_keyword_freetagging';
  $strongarm->value = 0;
  $export['biblio_keyword_freetagging'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_keyword_orphan_autoclean';
  $strongarm->value = 1;
  $export['biblio_keyword_orphan_autoclean'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_keyword_sep';
  $strongarm->value = ',';
  $export['biblio_keyword_sep'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_keyword_vocabulary';
  $strongarm->value = '0';
  $export['biblio_keyword_vocabulary'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_last_ftdid';
  $strongarm->value = 217;
  $export['biblio_last_ftdid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_links_target_new_window';
  $strongarm->value = 0;
  $export['biblio_links_target_new_window'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_link_title_url';
  $strongarm->value = 0;
  $export['biblio_link_title_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_lookup_links';
  $strongarm->value = array(
    'google' => 'google',
  );
  $export['biblio_lookup_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_my_pubs_menu';
  $strongarm->value = 0;
  $export['biblio_my_pubs_menu'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_node_layout';
  $strongarm->value = 'tabular';
  $export['biblio_node_layout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_no_year_text';
  $strongarm->value = 'Submitted';
  $export['biblio_no_year_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_openurlimage';
  $strongarm->value = '';
  $export['biblio_openurlimage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_openurl_sid';
  $strongarm->value = 'Biblio:e-stage';
  $export['biblio_openurl_sid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_order';
  $strongarm->value = 'DESC';
  $export['biblio_order'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_orphan_clean_interval';
  $strongarm->value = '86400';
  $export['biblio_orphan_clean_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_orphan_clean_next_execution';
  $strongarm->value = 1374667208;
  $export['biblio_orphan_clean_next_execution'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_rowsperpage';
  $strongarm->value = '25';
  $export['biblio_rowsperpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_rss';
  $strongarm->value = 0;
  $export['biblio_rss'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_rss_number_of_entries';
  $strongarm->value = '10';
  $export['biblio_rss_number_of_entries'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_search';
  $strongarm->value = 0;
  $export['biblio_search'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_search_button_text';
  $strongarm->value = 'Biblio search';
  $export['biblio_search_button_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_settings__active_tab';
  $strongarm->value = 'edit-biblio-profile';
  $export['biblio_settings__active_tab'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_show_crossref_profile_form';
  $strongarm->value = 1;
  $export['biblio_show_crossref_profile_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_show_openurl_profile_form';
  $strongarm->value = 1;
  $export['biblio_show_openurl_profile_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_show_profile';
  $strongarm->value = 0;
  $export['biblio_show_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_show_user_profile_form';
  $strongarm->value = 0;
  $export['biblio_show_user_profile_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_sort';
  $strongarm->value = 'year';
  $export['biblio_sort'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_sort_tabs';
  $strongarm->value = array(
    'author' => 'author',
    'title' => 'title',
    'type' => 'type',
    'year' => 'year',
    'keyword' => 0,
  );
  $export['biblio_sort_tabs'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_sort_tabs_style';
  $strongarm->value = 0;
  $export['biblio_sort_tabs_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_stop_words';
  $strongarm->value = 'a,an,is,on,the';
  $export['biblio_stop_words'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_style';
  $strongarm->value = 'cse';
  $export['biblio_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_user_style';
  $strongarm->value = 'system';
  $export['biblio_user_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_view_only_own';
  $strongarm->value = 0;
  $export['biblio_view_only_own'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'book_allowed_types';
  $strongarm->value = array(
    0 => 'book',
    3 => 'course_medial_content',
    'content_chapter' => 'content_chapter',
    'content_domain' => 'content_domain',
  );
  $export['book_allowed_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'book_block_mode';
  $strongarm->value = 'all pages';
  $export['book_block_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'book_child_type';
  $strongarm->value = 'book';
  $export['book_child_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clean_url';
  $strongarm->value = TRUE;
  $export['clean_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_api_version';
  $strongarm->value = '7.2';
  $export['date_api_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_default_timezone';
  $strongarm->value = 'Europe/Berlin';
  $export['date_default_timezone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_first_day';
  $strongarm->value = '1';
  $export['date_first_day'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_long';
  $strongarm->value = 'l, F j, Y - H:i';
  $export['date_format_long'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_medium';
  $strongarm->value = 'j. F Y - G:i';
  $export['date_format_medium'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_short';
  $strongarm->value = 'd.m.Y';
  $export['date_format_short'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_count';
  $strongarm->value = 2;
  $export['language_count'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_default';
  $strongarm->value = (object) array(
    'language' => 'de',
    'name' => 'German',
    'native' => 'Deutsch',
    'direction' => '0',
    'enabled' => '1',
    'plurals' => '2',
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'de',
    'weight' => '0',
    'javascript' => 'nzTJUlSIPF9TcI4WyZ9ZGm28B3-d5sp5utnBDPHUzN0',
  );
  $export['language_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language_url';
  $strongarm->value = array(
    'locale-url' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_url',
        'switcher' => 'locale_language_switcher_url',
        'url_rewrite' => 'locale_language_url_rewrite_url',
      ),
      'file' => 'includes/locale.inc',
    ),
    'locale-url-fallback' => array(
      'callbacks' => array(
        'language' => 'locale_language_url_fallback',
      ),
      'file' => 'includes/locale.inc',
    ),
  );
  $export['language_negotiation_language_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_types';
  $strongarm->value = array(
    'language' => TRUE,
    'language_content' => FALSE,
    'language_url' => FALSE,
  );
  $export['language_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_context_negotiation_group_context';
  $strongarm->value = array(
    'url' => array(),
    'node' => array(),
  );
  $export['og_context_negotiation_group_context'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_context_providers_weight_group_context';
  $strongarm->value = array(
    'url' => '-5',
    'node' => '-4',
    'user-edit' => '0',
    'user-view' => '0',
    'og_forum' => '0',
    'comment' => '0',
  );
  $export['og_context_providers_weight_group_context'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_features_ignore_og_fields';
  $strongarm->value = 0;
  $export['og_features_ignore_og_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_manager_full_access';
  $strongarm->value = 1;
  $export['og_group_manager_full_access'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_node_access_strict';
  $strongarm->value = 1;
  $export['og_node_access_strict'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_orphans_delete';
  $strongarm->value = 0;
  $export['og_orphans_delete'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_ui_admin_people_view';
  $strongarm->value = 'og_members_admin:default';
  $export['og_ui_admin_people_view'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_use_queue';
  $strongarm->value = 0;
  $export['og_use_queue'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_403';
  $strongarm->value = '';
  $export['site_403'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_404';
  $strongarm->value = '';
  $export['site_404'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_default_country';
  $strongarm->value = 'DE';
  $export['site_default_country'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'node';
  $export['site_frontpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_mail';
  $strongarm->value = 'sergej.naumenko@phil.uni-augsburg.de';
  $export['site_mail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_name';
  $strongarm->value = 'e-stage';
  $export['site_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_slogan';
  $strongarm->value = '';
  $export['site_slogan'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_bartik_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 0,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 1,
    'default_logo' => 0,
    'logo_path' => 'public://online-akademie_0.png',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'scheme' => '',
    'palette' => array(
      'top' => '#d1d1d1',
      'bottom' => '#ebebeb',
      'bg' => '#ffffff',
      'sidebar' => '#f6f6f2',
      'sidebarborders' => '#f9f9f9',
      'footer' => '#292929',
      'titleslogan' => '#fffeff',
      'text' => '#3b3b3b',
      'link' => '#0071B3',
    ),
    'theme' => 'bartik',
    'info' => array(
      'fields' => array(
        'top' => 'Kopfbereich oben',
        'bottom' => 'Kopfbereich unten',
        'bg' => 'Haupthintergrund',
        'sidebar' => 'Hintergrund der Seitenleiste',
        'sidebarborders' => 'Rahmen der Seitenleiste',
        'footer' => 'Hintergrund des Fußbereich',
        'titleslogan' => 'Titel und Slogan',
        'text' => 'Schriftfarbe',
        'link' => 'Linkfarbe',
      ),
      'schemes' => array(
        'default' => array(
          'title' => 'Blaue Lagune (Standard)',
          'colors' => array(
            'top' => '#0779bf',
            'bottom' => '#48a9e4',
            'bg' => '#ffffff',
            'sidebar' => '#f6f6f2',
            'sidebarborders' => '#f9f9f9',
            'footer' => '#292929',
            'titleslogan' => '#fffeff',
            'text' => '#3b3b3b',
            'link' => '#0071B3',
          ),
        ),
        'firehouse' => array(
          'title' => 'Feuerwehrhaus',
          'colors' => array(
            'top' => '#cd2d2d',
            'bottom' => '#cf3535',
            'bg' => '#ffffff',
            'sidebar' => '#f1f4f0',
            'sidebarborders' => '#ededed',
            'footer' => '#1f1d1c',
            'titleslogan' => '#fffeff',
            'text' => '#3b3b3b',
            'link' => '#d6121f',
          ),
        ),
        'ice' => array(
          'title' => 'Eis',
          'colors' => array(
            'top' => '#d0d0d0',
            'bottom' => '#c2c4c5',
            'bg' => '#ffffff',
            'sidebar' => '#ffffff',
            'sidebarborders' => '#cccccc',
            'footer' => '#24272c',
            'titleslogan' => '#000000',
            'text' => '#4a4a4a',
            'link' => '#019dbf',
          ),
        ),
        'plum' => array(
          'title' => 'Pflaume',
          'colors' => array(
            'top' => '#4c1c58',
            'bottom' => '#593662',
            'bg' => '#fffdf7',
            'sidebar' => '#edede7',
            'sidebarborders' => '#e7e7e7',
            'footer' => '#2c2c28',
            'titleslogan' => '#ffffff',
            'text' => '#301313',
            'link' => '#9d408d',
          ),
        ),
        'slate' => array(
          'title' => 'Slate',
          'colors' => array(
            'top' => '#4a4a4a',
            'bottom' => '#4e4e4e',
            'bg' => '#ffffff',
            'sidebar' => '#ffffff',
            'sidebarborders' => '#d0d0d0',
            'footer' => '#161617',
            'titleslogan' => '#ffffff',
            'text' => '#3b3b3b',
            'link' => '#0073b6',
          ),
        ),
        '' => array(
          'title' => 'Benutzerdefiniert',
          'colors' => array(),
        ),
      ),
      'css' => array(
        0 => 'css/colors.css',
      ),
      'copy' => array(
        0 => 'logo.png',
      ),
      'gradients' => array(
        0 => array(
          'dimension' => array(
            0 => 0,
            1 => 0,
            2 => 0,
            3 => 0,
          ),
          'direction' => 'vertical',
          'colors' => array(
            0 => 'top',
            1 => 'bottom',
          ),
        ),
      ),
      'fill' => array(),
      'slices' => array(),
      'blend_target' => '#ffffff',
      'preview_css' => 'color/preview.css',
      'preview_js' => 'color/preview.js',
      'preview_html' => 'color/preview.html',
      'base_image' => 'color/base.png',
    ),
  );
  $export['theme_bartik_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_bootstrap_onlinekurslabor_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 0,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 0,
    'toggle_secondary_menu' => 0,
    'default_logo' => 0,
    'logo_path' => 'sites/all/themes/bootstrap_onlinekurslabor/images/onlinekurslabor-logo-header.jpg',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'bootstrap_rebuild_registry' => 0,
    'cdn_bootstrap' => 1,
    'cdn_bootstrap_version' => '2.3.2',
  );
  $export['theme_bootstrap_onlinekurslabor_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'bootstrap_onlinekurslabor';
  $export['theme_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_settings';
  $strongarm->value = array(
    'toggle_node_info_quiz' => 0,
  );
  $export['theme_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'transliteration_file_lowercase';
  $strongarm->value = 1;
  $export['transliteration_file_lowercase'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'transliteration_file_uploads';
  $strongarm->value = 1;
  $export['transliteration_file_uploads'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_admin_role';
  $strongarm->value = '3';
  $export['user_admin_role'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_cancel_method';
  $strongarm->value = 'user_cancel_block';
  $export['user_cancel_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_default_timezone';
  $strongarm->value = '0';
  $export['user_default_timezone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_email_verification';
  $strongarm->value = 1;
  $export['user_email_verification'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_cancel_confirm_body';
  $strongarm->value = '[user:name],

Eine Anfrage zur Löschung Ihres Benutzerkontos auf [site:name] wurde gestellt.

Sie können Ihr Konto auf [site:url-brief] jetzt durch Klick auf den folgenden Link löschen oder diesen alternativ in Ihren Browser kopieren:

[user:cancel-url]

HINWEIS: Die Löschung Ihres Benutzerkontos kann nicht rückgängig gemacht werden und ist endgültig.

Der Link ist einen Tag lang gültig und läuft automatisch aus, falls Sie ihn nicht verwenden.

Viele Grüße
Das Team von [site:name]';
  $export['user_mail_cancel_confirm_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_cancel_confirm_subject';
  $strongarm->value = 'Antrag auf Löschung von Benutzerkonto [user:name] auf [site:name]';
  $export['user_mail_cancel_confirm_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_password_reset_body';
  $strongarm->value = '[user:name],

eine Anfrage zum Zurücksetzen des Passworts für Ihr Benutzerkonto auf [site:name] wurde gestellt.

Sie können sich jetzt mit einem Klick auf folgenden Link anmelden oder diesen alternativ in Ihren Browser kopieren:

[user:one-time-login-url]

Dieser Link kann nur einmal verwendet werden und leitet Sie zu einer Seite, auf der Sie ein neues Passwort festlegen können. Er ist einen Tag lang gültig und läuft automatisch aus, falls Sie ihn nicht verwenden.

Viele Grüße
Das Team von [site:name]';
  $export['user_mail_password_reset_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_password_reset_subject';
  $strongarm->value = 'Neue Login-Daten für Benutzerkonto [user:name] auf [site:name]';
  $export['user_mail_password_reset_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_admin_created_body';
  $strongarm->value = '[user:name],

Ein Administrator der Website [site:name] hat für Sie ein Benutzerkonto angelegt. Sie können sich jetzt mit einem Klick auf den folgenden Link anmelden oder diesen alternativ in Ihren Browser kopieren:

[user:one-time-login-url]

Dieser Link kann nur einmal verwendet werden und leitet Sie zu einer Seite, auf der Sie ein neues Passwort vergeben können.

Nachdem Sie Ihr Passwort festgelegt haben, können Sie sich zukünftig auf [site:login-url] mit den folgenden Zugangsdaten anmelden:

Benutzername: [user:name]
Passwort: Ihr Passwort

Viele Grüße
Das Team von [site:name]';
  $export['user_mail_register_admin_created_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_admin_created_subject';
  $strongarm->value = 'Ein Administrator hat für Sie auf [site:name] ein Benutzerkonto angelegt';
  $export['user_mail_register_admin_created_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_no_approval_required_body';
  $strongarm->value = '[user:name],

vielen Dank für die Registrierung auf [site:name]. Sie können sich jetzt mit einem Klick auf den folgenden Link anmelden oder diesen alternativ in Ihren Browser kopieren:

[user:one-time-login-url]

Dieser Link kann nur einmal verwendet werden und leitet Sie auf eine Seite, auf der Sie Ihr Passwort festlegen können.

Nachdem Sie Ihr Passwort festgelegt haben, können Sie sich zukünftig mit folgenden Zugangsdaten bei [site:login-url] anmelden:

Benutzername: [user:name]
Passwort: Ihr Passwort

Viele Grüße
Das Team von [site:name]';
  $export['user_mail_register_no_approval_required_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_no_approval_required_subject';
  $strongarm->value = 'Benutzerkontendetails für [user:name] auf [site:name]';
  $export['user_mail_register_no_approval_required_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_pending_approval_body';
  $strongarm->value = '[user:name],

vielen Dank für die Registrierung auf [site:name]. Ihr Antrag für ein Benutzerkonto wird aktuell geprüft. Sobald eine Freigabe erfolgt ist, erhalten Sie eine weitere E-Mail mit Informationen zum Login, Setzen Ihres Passwortes sowie weitere Details.

Viele Grüße
Das Team von [site:name]';
  $export['user_mail_register_pending_approval_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_pending_approval_subject';
  $strongarm->value = 'Benutzerkontendetails für [user:name] auf [site:name] (Genehmigung durch einen Administrator steht aus)';
  $export['user_mail_register_pending_approval_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_body';
  $strongarm->value = '[user:name],

Ihr Benutzerkonto auf [site:name] wurde aktiviert.

Sie können sich jetzt mit einem Klick auf folgenden Link anmelden oder diesen alternativ in Ihren Browser kopieren:

[user:one-time-login-url]

Dieser Link kann nur einmal verwendet werden und leitet Sie zu einer Seite, auf der Sie ein neues Passwort festlegen können.

Nachdem Sie Ihr Passwort festgelegt haben, können Sie sich zukünftig auf [site:login-url] mit den folgenden Zugangsdaten anmelden:

Benutzername: [user:name]
Passwort: Ihr Passwort

Viele Grüße
Das Team von [site:name]';
  $export['user_mail_status_activated_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_notify';
  $strongarm->value = 1;
  $export['user_mail_status_activated_notify'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_subject';
  $strongarm->value = 'Benutzerkontendetails für [user:name] auf [site:name] (genehmigt)';
  $export['user_mail_status_activated_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_blocked_body';
  $strongarm->value = '[user:name],

Ihr Benutzerkonto auf [site:name] wurde gesperrt.

--  [site:name]-Team';
  $export['user_mail_status_blocked_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_blocked_notify';
  $strongarm->value = 0;
  $export['user_mail_status_blocked_notify'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_blocked_subject';
  $strongarm->value = 'Details für Benutzerkonto [user:name] auf [site:name] (gesperrt)';
  $export['user_mail_status_blocked_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_canceled_body';
  $strongarm->value = '[user:name],

Ihr Benutzerkonto auf [site:name] wurde gelöscht.

--  [site:name]-Team';
  $export['user_mail_status_canceled_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_canceled_notify';
  $strongarm->value = 0;
  $export['user_mail_status_canceled_notify'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_canceled_subject';
  $strongarm->value = 'Details für Benutzerkonto [user:name] auf [site:name] (gelöscht)';
  $export['user_mail_status_canceled_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_pictures';
  $strongarm->value = 0;
  $export['user_pictures'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_default';
  $strongarm->value = '/sites/all/themes/bootstrap_onlinekurslabor/images/noprofile.jpg';
  $export['user_picture_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_dimensions';
  $strongarm->value = '1024x1024';
  $export['user_picture_dimensions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_file_size';
  $strongarm->value = '800';
  $export['user_picture_file_size'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_guidelines';
  $strongarm->value = '';
  $export['user_picture_guidelines'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_path';
  $strongarm->value = 'profile_pictures';
  $export['user_picture_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_style';
  $strongarm->value = 'thumbnail';
  $export['user_picture_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_register';
  $strongarm->value = '2';
  $export['user_register'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_signatures';
  $strongarm->value = 0;
  $export['user_signatures'] = $strongarm;

  return $export;
}
