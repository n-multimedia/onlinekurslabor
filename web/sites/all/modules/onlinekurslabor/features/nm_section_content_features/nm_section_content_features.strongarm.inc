<?php
/**
 * @file
 * nm_section_content_features.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nm_section_content_features_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_content_chapter';
  $strongarm->value = 'edit-print';
  $export['additional_settings__active_tab_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_content_domain';
  $strongarm->value = 'edit-print';
  $export['additional_settings__active_tab_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_content_multiple_choice';
  $strongarm->value = 'edit-print';
  $export['additional_settings__active_tab_content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_content_question_and_answer';
  $strongarm->value = 'edit-print';
  $export['additional_settings__active_tab_content_question_and_answer'] = $strongarm;

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
    'marc' => 'marc',
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
  $strongarm->value = 1;
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
  $strongarm->value = 1449303546;
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
  $strongarm->value = 'edit-footnotes';
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
  $strongarm->name = 'comment_anonymous_biblio';
  $strongarm->value = 0;
  $export['comment_anonymous_biblio'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_book';
  $strongarm->value = 0;
  $export['comment_anonymous_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_content_chapter';
  $strongarm->value = 0;
  $export['comment_anonymous_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_content_domain';
  $strongarm->value = 0;
  $export['comment_anonymous_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_content_multiple_choice';
  $strongarm->value = 0;
  $export['comment_anonymous_content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_content_question_and_answer';
  $strongarm->value = 0;
  $export['comment_anonymous_content_question_and_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_panel';
  $strongarm->value = 0;
  $export['comment_anonymous_panel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_content_chapter';
  $strongarm->value = '1';
  $export['comment_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_content_domain';
  $strongarm->value = '1';
  $export['comment_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_content_multiple_choice';
  $strongarm->value = '1';
  $export['comment_content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_content_question_and_answer';
  $strongarm->value = '1';
  $export['comment_content_question_and_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_content_chapter';
  $strongarm->value = 1;
  $export['comment_default_mode_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_content_domain';
  $strongarm->value = 1;
  $export['comment_default_mode_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_content_multiple_choice';
  $strongarm->value = 1;
  $export['comment_default_mode_content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_content_question_and_answer';
  $strongarm->value = 1;
  $export['comment_default_mode_content_question_and_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_content_chapter';
  $strongarm->value = '50';
  $export['comment_default_per_page_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_content_domain';
  $strongarm->value = '50';
  $export['comment_default_per_page_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_content_multiple_choice';
  $strongarm->value = '50';
  $export['comment_default_per_page_content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_content_question_and_answer';
  $strongarm->value = '50';
  $export['comment_default_per_page_content_question_and_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_content_chapter';
  $strongarm->value = 1;
  $export['comment_form_location_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_content_domain';
  $strongarm->value = 1;
  $export['comment_form_location_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_content_multiple_choice';
  $strongarm->value = 1;
  $export['comment_form_location_content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_content_question_and_answer';
  $strongarm->value = 1;
  $export['comment_form_location_content_question_and_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_content_chapter';
  $strongarm->value = '1';
  $export['comment_preview_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_content_domain';
  $strongarm->value = '1';
  $export['comment_preview_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_content_multiple_choice';
  $strongarm->value = '1';
  $export['comment_preview_content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_content_question_and_answer';
  $strongarm->value = '1';
  $export['comment_preview_content_question_and_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_content_chapter';
  $strongarm->value = 1;
  $export['comment_subject_field_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_content_domain';
  $strongarm->value = 1;
  $export['comment_subject_field_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_content_multiple_choice';
  $strongarm->value = 1;
  $export['comment_subject_field_content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_content_question_and_answer';
  $strongarm->value = 1;
  $export['comment_subject_field_content_question_and_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'emaillog_0';
  $strongarm->value = 'sergej.naumenko@phil.uni-augsburg.de';
  $export['emaillog_0'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'emaillog_1';
  $strongarm->value = 'sergej.naumenko@phil.uni-augsburg.de';
  $export['emaillog_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'emaillog_2';
  $strongarm->value = 'sergej.naumenko@phil.uni-augsburg.de';
  $export['emaillog_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'emaillog_3';
  $strongarm->value = '';
  $export['emaillog_3'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'emaillog_4';
  $strongarm->value = '';
  $export['emaillog_4'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'emaillog_5';
  $strongarm->value = '';
  $export['emaillog_5'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'emaillog_6';
  $strongarm->value = '';
  $export['emaillog_6'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'emaillog_7';
  $strongarm->value = '';
  $export['emaillog_7'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'emaillog_debug_info';
  $strongarm->value = array();
  $export['emaillog_debug_info'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'emaillog_legacy_subject';
  $strongarm->value = 0;
  $export['emaillog_legacy_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'emaillog_max_consecutive_timespan';
  $strongarm->value = '';
  $export['emaillog_max_consecutive_timespan'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'emaillog_max_similarity_level';
  $strongarm->value = '';
  $export['emaillog_max_similarity_level'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'emaillog_max_similar_emails';
  $strongarm->value = '';
  $export['emaillog_max_similar_emails'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_comment__comment_node_content_chapter';
  $strongarm->value = array();
  $export['field_bundle_settings_comment__comment_node_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_comment__comment_node_content_domain';
  $strongarm->value = array();
  $export['field_bundle_settings_comment__comment_node_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_file__audio';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'preview' => array(
        'custom_settings' => TRUE,
      ),
      'filename' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'file_icon' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'media_12' => array(
        'custom_settings' => FALSE,
      ),
      'media_3' => array(
        'custom_settings' => FALSE,
      ),
      'media_4' => array(
        'custom_settings' => FALSE,
      ),
      'media_6' => array(
        'custom_settings' => FALSE,
      ),
      'media_9' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'file' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'filename' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'file_icon' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_file__audio'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_file__document';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'preview' => array(
        'custom_settings' => TRUE,
      ),
      'filename' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'file_icon' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'media_12' => array(
        'custom_settings' => FALSE,
      ),
      'media_3' => array(
        'custom_settings' => FALSE,
      ),
      'media_4' => array(
        'custom_settings' => FALSE,
      ),
      'media_6' => array(
        'custom_settings' => FALSE,
      ),
      'media_9' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'file' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'filename' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'file_icon' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_file__document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_file__image';
  $strongarm->value = array(
    'view_modes' => array(
      'preview' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'filename' => array(
        'custom_settings' => TRUE,
      ),
      'file_icon' => array(
        'custom_settings' => TRUE,
      ),
      'media_12' => array(
        'custom_settings' => TRUE,
      ),
      'media_3' => array(
        'custom_settings' => TRUE,
      ),
      'media_6' => array(
        'custom_settings' => TRUE,
      ),
      'media_9' => array(
        'custom_settings' => TRUE,
      ),
      'media_4' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'media_600px' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'filename' => array(
          'weight' => '-10',
        ),
        'preview' => array(
          'weight' => '-5',
        ),
      ),
      'display' => array(
        'file' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'filename' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'file_icon' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'media_12' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'media_3' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'media_6' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'media_9' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'media_4' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'media_600px' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_file__image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_file__video';
  $strongarm->value = array(
    'view_modes' => array(
      'preview' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'filename' => array(
        'custom_settings' => TRUE,
      ),
      'file_icon' => array(
        'custom_settings' => TRUE,
      ),
      'media_12' => array(
        'custom_settings' => TRUE,
      ),
      'media_3' => array(
        'custom_settings' => FALSE,
      ),
      'media_4' => array(
        'custom_settings' => FALSE,
      ),
      'media_6' => array(
        'custom_settings' => TRUE,
      ),
      'media_9' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'filename' => array(
          'weight' => '0',
        ),
        'preview' => array(
          'weight' => '1',
        ),
      ),
      'display' => array(
        'file' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'filename' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'file_icon' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'media_12' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'media_3' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'media_4' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'media_6' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'media_9' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_file__video'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__biblio';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'task' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'biblio_type' => array(
          'weight' => '-4',
        ),
        'biblio_year' => array(
          'weight' => '-4.5',
        ),
        'biblio_authors_field' => array(
          'weight' => '0.1',
        ),
        'biblio_secondary_authors_field' => array(
          'weight' => '0.2',
        ),
        'biblio_tertiary_authors_field' => array(
          'weight' => '0.3',
        ),
        'biblio_subsidiary_authors_field' => array(
          'weight' => '0.4',
        ),
        'biblio_corp_authors_field' => array(
          'weight' => '0.5',
        ),
        'biblio_secondary_title' => array(
          'weight' => '1.2',
        ),
        'biblio_tertiary_title' => array(
          'weight' => '1.3',
        ),
        'biblio_volume' => array(
          'weight' => '1.4',
        ),
        'biblio_number_of_volumes' => array(
          'weight' => '1.5',
        ),
        'biblio_edition' => array(
          'weight' => '1.5',
        ),
        'biblio_issue' => array(
          'weight' => '1.5',
        ),
        'biblio_section' => array(
          'weight' => '1.5',
        ),
        'biblio_number' => array(
          'weight' => '1.6',
        ),
        'biblio_pages' => array(
          'weight' => '1.7',
        ),
        'biblio_date' => array(
          'weight' => '1.8',
        ),
        'biblio_publisher' => array(
          'weight' => '1.9',
        ),
        'biblio_place_published' => array(
          'weight' => '2',
        ),
        'biblio_type_of_work' => array(
          'weight' => '2.2',
        ),
        'biblio_lang' => array(
          'weight' => '2.3',
        ),
        'biblio_other_author_affiliations' => array(
          'weight' => '2.4',
        ),
        'biblio_issn' => array(
          'weight' => '15',
        ),
        'biblio_isbn' => array(
          'weight' => '15',
        ),
        'biblio_accession_number' => array(
          'weight' => '15.1',
        ),
        'biblio_call_number' => array(
          'weight' => '15.2',
        ),
        'biblio_other_number' => array(
          'weight' => '15.3',
        ),
        'biblio_keywords' => array(
          'weight' => '15.4',
        ),
        'biblio_abst_e' => array(
          'weight' => '15.5',
        ),
        'biblio_abst_f' => array(
          'weight' => '15.6',
        ),
        'biblio_notes' => array(
          'weight' => '15.7',
        ),
        'biblio_url' => array(
          'weight' => '15.8',
        ),
        'biblio_doi' => array(
          'weight' => '15.9',
        ),
        'biblio_research_notes' => array(
          'weight' => '16',
        ),
        'biblio_custom1' => array(
          'weight' => '16.1',
        ),
        'biblio_custom2' => array(
          'weight' => '16.2',
        ),
        'biblio_custom3' => array(
          'weight' => '16.3',
        ),
        'biblio_custom4' => array(
          'weight' => '16.4',
        ),
        'biblio_custom5' => array(
          'weight' => '16.5',
        ),
        'biblio_custom6' => array(
          'weight' => '16.7',
        ),
        'biblio_custom7' => array(
          'weight' => '16.8',
        ),
        'biblio_short_title' => array(
          'weight' => '16.9',
        ),
        'biblio_translated_title' => array(
          'weight' => '17',
        ),
        'biblio_alternate_title' => array(
          'weight' => '17',
        ),
        'biblio_original_publication' => array(
          'weight' => '17.1',
        ),
        'biblio_reprint_edition' => array(
          'weight' => '17.2',
        ),
        'biblio_citekey' => array(
          'weight' => '17.5',
        ),
        'biblio_remote_db_name' => array(
          'weight' => '17.6',
        ),
        'biblio_coins' => array(
          'weight' => '17.6',
        ),
        'biblio_remote_db_provider' => array(
          'weight' => '17.7',
        ),
        'biblio_auth_address' => array(
          'weight' => '17.8',
        ),
        'biblio_label' => array(
          'weight' => '17.8',
        ),
        'biblio_access_date' => array(
          'weight' => '17.9',
        ),
        'biblio_refereed' => array(
          'weight' => '18',
        ),
        'other_fields' => array(
          'weight' => '0',
        ),
        'workflow' => array(
          'weight' => '10',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__biblio'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__content_chapter';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'task' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '5',
        ),
        'workflow' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__content_domain';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'task' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '6',
        ),
        'workflow' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__content_multiple_choice';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'node_embed' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'task' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__content_question_and_answer';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'task' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__content_question_and_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'filter_fallback_format';
  $strongarm->value = 'plain_text';
  $export['filter_fallback_format'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'htmlpurifier_version_current';
  $strongarm->value = '4.6.0';
  $export['htmlpurifier_version_current'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'htmlpurifier_version_ours';
  $strongarm->value = '4.5.0';
  $export['htmlpurifier_version_ours'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_compression_type';
  $strongarm->value = 'none';
  $export['jquery_update_compression_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_cdn';
  $strongarm->value = 'none';
  $export['jquery_update_jquery_cdn'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'jquery_update_jquery_version';
  $strongarm->value = '1.7';
  $export['jquery_update_jquery_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_biblio';
  $strongarm->value = '0';
  $export['language_content_type_biblio'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_book';
  $strongarm->value = '0';
  $export['language_content_type_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_content_chapter';
  $strongarm->value = '0';
  $export['language_content_type_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_content_domain';
  $strongarm->value = '0';
  $export['language_content_type_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_content_multiple_choice';
  $strongarm->value = '0';
  $export['language_content_type_content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_content_question_and_answer';
  $strongarm->value = '0';
  $export['language_content_type_content_question_and_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language';
  $strongarm->value = array();
  $export['language_negotiation_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_negotiation_language_content';
  $strongarm->value = array(
    'locale-interface' => array(
      'callbacks' => array(
        'language' => 'locale_language_from_interface',
      ),
      'file' => 'includes/locale.inc',
    ),
  );
  $export['language_negotiation_language_content'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media__wysiwyg_allowed_types';
  $strongarm->value = array(
    0 => 'image',
    1 => 'video',
    2 => 'audio',
    3 => 'document',
  );
  $export['media__wysiwyg_allowed_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'media__wysiwyg_upload_directory';
  $strongarm->value = 'media_browser';
  $export['media__wysiwyg_upload_directory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_content_chapter';
  $strongarm->value = array();
  $export['menu_options_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_content_domain';
  $strongarm->value = array();
  $export['menu_options_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_content_multiple_choice';
  $strongarm->value = array();
  $export['menu_options_content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_content_question_and_answer';
  $strongarm->value = array();
  $export['menu_options_content_question_and_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_content_chapter';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_content_domain';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_content_multiple_choice';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_content_question_and_answer';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_content_question_and_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_content_chapter';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_content_domain';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_content_multiple_choice';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_content_question_and_answer';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_content_question_and_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_content_chapter';
  $strongarm->value = '0';
  $export['node_preview_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_content_domain';
  $strongarm->value = '0';
  $export['node_preview_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_content_multiple_choice';
  $strongarm->value = '1';
  $export['node_preview_content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_content_question_and_answer';
  $strongarm->value = '1';
  $export['node_preview_content_question_and_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_content_chapter';
  $strongarm->value = 0;
  $export['node_submitted_content_chapter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_content_domain';
  $strongarm->value = 0;
  $export['node_submitted_content_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_content_multiple_choice';
  $strongarm->value = 0;
  $export['node_submitted_content_multiple_choice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_content_question_and_answer';
  $strongarm->value = 0;
  $export['node_submitted_content_question_and_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembedembedly_api_key';
  $strongarm->value = '779ed6b0501448debaf74fd6e1ccc77c';
  $export['oembedembedly_api_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembedembedly_default';
  $strongarm->value = '1';
  $export['oembedembedly_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembedembedly_providers';
  $strongarm->value = array(
    'youtube' => 1,
    'justintv' => 1,
    'twitchtv' => 1,
    'ustream' => 1,
    'qik' => 1,
    'revision3' => 1,
    'dailymotion' => 1,
    'collegehumor' => 1,
    'telly' => 1,
    'break' => 1,
    'myspacevideos' => 1,
    'metacafe' => 1,
    'bliptv' => 1,
    'googlevideo' => 1,
    'yahoovideo' => 1,
    'viddler' => 1,
    'liveleak' => 1,
    'animoto' => 1,
    'dotsub' => 1,
    'overstream' => 1,
    'livestream' => 1,
    'worldstarhiphop' => 1,
    'bambuser' => 1,
    'schooltube' => 1,
    'bigthink' => 1,
    'jibjab' => 1,
    'xtranormal' => 1,
    'socialcam' => 1,
    'youku' => 1,
    'snotr' => 1,
    'clipfish' => 1,
    'myvideo' => 1,
    'vzaar' => 1,
    'coub' => 1,
    'streamio' => 1,
    'vine' => 1,
    'viddy' => 1,
    'tudou' => 1,
    'mixbit' => 1,
    'sproutvideo' => 1,
    'minotovideo' => 1,
    'brainshark' => 1,
    '23video' => 1,
    'goanimate' => 1,
    'brainsonic' => 1,
    'lustich' => 1,
    'whitehouse' => 1,
    'hulu' => 1,
    'crackle' => 1,
    'funnyordie' => 1,
    'vimeo' => 1,
    'ted' => 1,
    'nfb' => 1,
    'thedailyshow' => 1,
    'yahoomovies' => 1,
    'colbertnation' => 1,
    'comedycentral' => 1,
    'theonion' => 1,
    'wordpresstv' => 1,
    'traileraddict' => 1,
    'escapistmagazine' => 1,
    'trailerspy' => 1,
    'foratv' => 1,
    'spike' => 1,
    'gametrailers' => 1,
    'koldcasttv' => 1,
    'mixergy' => 1,
    'pbsvideo' => 1,
    'zapiks' => 1,
    'trutv' => 1,
    'nzonscreen' => 1,
    'wistia' => 1,
    'confreaks' => 1,
    'allthingsd' => 1,
    'nymag' => 1,
    'aniboom' => 1,
    'grindtv' => 1,
    'ifoodtv' => 1,
    'logotv' => 1,
    'lonelyplanet' => 1,
    'streetfire' => 1,
    'sciencestage' => 1,
    'brightcove' => 1,
    'wirewax' => 1,
    'canalplus' => 1,
    'vevo' => 1,
    'pixorial' => 1,
    'spreecast' => 1,
    'showme' => 1,
    'looplogic' => 1,
    'onaol' => 1,
    'videodetective' => 1,
    'khanacademy' => 1,
    'vidyard' => 1,
    'veoh' => 1,
    'univision' => 1,
    'vidcaster' => 1,
    'godtube' => 1,
    'mediamatters' => 1,
    'clikthrough' => 1,
    'clipsyndicate' => 1,
    'srf' => 1,
    'mpora' => 1,
    'espn' => 1,
    'abcnews' => 1,
    'washingtonpost' => 1,
    'boston' => 1,
    'facebook' => 1,
    'cnbc' => 1,
    'cbsnews' => 1,
    'googleplus' => 1,
    'cnn' => 1,
    'cnnedition' => 1,
    'cnnmoney' => 1,
    'msnbc' => 1,
    'nbcnews' => 1,
    'foxsports' => 1,
    'globalpost' => 1,
    'guardian' => 1,
    'bravotv' => 1,
    'nationalgeographic' => 1,
    'discovery' => 1,
    'forbes' => 1,
    'distrify' => 1,
    'foxnews' => 1,
    'foxbusiness' => 1,
    'reuters' => 1,
    'huffpost' => 1,
    'nytimes' => 1,
    'vorarlberg' => 1,
    'spiegel' => 1,
    'github' => 1,
    'crunchbase' => 1,
    'slideshare' => 1,
    'scribd' => 1,
    'screenr' => 1,
    'polldaddy' => 1,
    'howcast' => 1,
    'screencast' => 1,
    'issuu' => 1,
    'kickstarter' => 1,
    'scrapblog' => 1,
    'foursquare' => 1,
    'sliderocket' => 1,
    'chartly' => 1,
    'googlemaps' => 1,
    'craigslist' => 1,
    'myopera' => 1,
    'tumblr' => 1,
    'polleverywhere' => 1,
    'quantcast' => 1,
    'compete' => 1,
    'statusnet' => 1,
    'identica' => 1,
    'vznetworks' => 1,
    'mylocme' => 1,
    'pastebin' => 1,
    'pastie' => 1,
    'redux' => 1,
    'cloudapp' => 1,
    'speakerdeck' => 1,
    'kiva' => 1,
    'timetoast' => 1,
    'storify' => 1,
    'meetup' => 1,
    'dailymile' => 1,
    'kinomap' => 1,
    'metacdn' => 1,
    'prezi' => 1,
    'uservoice' => 1,
    'formspring' => 1,
    'twitlonger' => 1,
    'qwiki' => 1,
    'crocodoc' => 1,
    'wikipedia' => 1,
    'wikimedia' => 1,
    'urtak' => 1,
    'graphicly' => 1,
    'ganxy' => 1,
    'panorama' => 1,
    'behance' => 1,
    'jdsupra' => 1,
    'minilogs' => 1,
    'sketchfab' => 1,
    'jsfiddle' => 1,
    'ponga' => 1,
    'listly' => 1,
    'crowdmap' => 1,
    'ifttt' => 1,
    'weavly' => 1,
    'tagmotion' => 1,
    'cloudup' => 1,
    'hackpad' => 1,
    'talely' => 1,
    'polar' => 1,
    'bubbli' => 1,
    'imajize' => 1,
    'giflike' => 1,
    'rapidengage' => 1,
    'yfrog' => 1,
    'flickr' => 1,
    'twitpic' => 1,
    'imgur' => 1,
    'twitgoo' => 1,
    'photobucket' => 1,
    'mobypicture' => 1,
    'xkcd' => 1,
    'asofterworld' => 1,
    'dinosaurcomics' => 1,
    '23hq' => 1,
    'dribbble' => 1,
    'smugmug' => 1,
    'picasa' => 1,
    'imgly' => 1,
    'tinypic' => 1,
    'meadd' => 1,
    'deviantart' => 1,
    'fotopedia' => 1,
    'photozou' => 1,
    'instagram' => 1,
    'skitch' => 1,
    'questionablecontent' => 1,
    'twitrpix' => 1,
    'someecards' => 1,
    'pikchur' => 1,
    'achewood' => 1,
    'whosay' => 1,
    'owly' => 1,
    'mlkshk' => 1,
    'lockerz' => 1,
    'droplr' => 1,
    'eyeem' => 1,
    'giphy' => 1,
    'frontback' => 1,
    'amazon' => 1,
    'shopstyle' => 1,
    'apple' => 1,
    'shoplocket' => 1,
    'etsy' => 1,
    'fiverr' => 1,
    'soundcloud' => 1,
    'spotify' => 1,
    'lastfm' => 1,
    'mixcloud' => 1,
    'radionomy' => 1,
    'hark' => 1,
    'rdio' => 1,
    'zeroinch' => 1,
    'bandcamp' => 1,
    'freemusicarchive' => 1,
    'npr' => 1,
    'huffduffer' => 1,
    'audioboo' => 1,
    'xiami' => 1,
    'saynow' => 1,
    'grooveshark' => 1,
    'radioreddit' => 1,
    'gogoyoko' => 1,
    'hypem' => 1,
  );
  $export['oembedembedly_providers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'oembedembedly_schemes';
  $strongarm->value = '';
  $export['oembedembedly_schemes'] = $strongarm;

  return $export;
}
