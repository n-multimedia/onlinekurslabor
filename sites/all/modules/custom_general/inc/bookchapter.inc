<?php

/**
 * @file
 *   Helper functions for automated numbering for book sections.
 */

/**
 * Helper functions for Domain-Settings
 */
function _custom_general_toc_enabled($nid) {
  //Caching of the result necessery?
  $node = current(entity_load('node', array($nid)));

  if (isset($node->book)) {
    //parent book ID
    //$bid = $node->book['bid'];
    $domain_id = _custom_general_get_group($node);
    //check if toc is enabled
    if (!$domain_id) {
      return FALSE;
    }

    $domain_node = node_load($domain_id);
    $f_val = field_get_items('node', $domain_node, 'field_tableofcontents', $node->language);

    //check if toc value of domain is set
    if (!empty($f_val)) {
      $toc_value = current(current(field_get_items('node', $domain_node, 'field_tableofcontents', $node->language)));
    }
    else {
      $toc_value = 'none';
    }


    if ($toc_value === 'numeric') {
      return TRUE;
    }
  }

  return FALSE;
}

function nm_bookchapters_rewrite_menu_link_title(&$item) {
  $chapter_numbering = nm_bookchapters_get_chapter_numbering_recursive($item['link']['menu_name'], $item['link']['plid'], $item['link']['mlid']);
  //wrap chapter number into label
  $chapter_numbering = '<table><tr valign="top"><td><span class="badge badge-info">' . $chapter_numbering .  '</span></td>';
  $title = $item['link']['link_title'];
  //wrap title
  $title = '<td style="padding-left:5px;">' . $title . '</td></tr></table>';
  
  $item['link']['localized_options']['html'] = TRUE;
  $item['link']['link_title'] = $chapter_numbering . ' ' . $title;
  $item['link']['title'] = $chapter_numbering . ' ' . $title;

  if (!empty($item['below'])) {
    foreach ($item['below'] as $key => $value) {
      nm_bookchapters_rewrite_menu_link_title($item['below'][$key]);
    }
  }
}

function nm_bookchapters_get_chapter_numbering($nid) {
  static $bookchapter_values; //@todo change to $bookchapters =  &static_drupal(__FUNCTION__,array())

  if (empty($bookchapter_values)) {
    $bookchapter_values = array();
  }

  if (isset($bookchapter_values[$nid])) {
    return $bookchapter_values[$nid];
  }

  $book_info = db_query('SELECT * FROM {book} b INNER JOIN {menu_links} ml ON b.mlid = ml.mlid WHERE b.nid = :nid', array(':nid' => $nid))->fetchAssoc();

  if (!empty($book_info)) {
    $bookchapter_values[$nid] = nm_bookchapters_get_chapter_numbering_recursive($book_info['menu_name'], $book_info['plid'], $book_info['mlid']);
    return $bookchapter_values[$nid];
  }
}

function nm_bookchapters_get_chapter_numbering_mlid($mlid) {
  $book_info = db_query('SELECT nid FROM {book} b WHERE mlid = :mlid', array(':mlid' => $mlid))->fetchAssoc();
  if (!empty($book_info)) {
    return nm_bookchapters_get_chapter_numbering($book_info['nid']);
  }
}

function nm_bookchapters_get_chapter_numbering_recursive($menu_name, $plid, $mlid) {
  if (empty($menu_name) || empty($plid) || empty($mlid)) {
    return;
  }
  //to gain performance benefits filter using primary key field
  $result = db_query('SELECT * FROM {menu_links} WHERE menu_name =:menu_name AND plid = :plid ORDER BY weight ASC, link_title ASC', array(':menu_name' => $menu_name, ':plid' => $plid));
  $order_number = 1;
  while ($row = $result->fetchAssoc()) {
    if ($row['mlid'] == $mlid) {
      if ($row['plid'] > 0) {
        $parent = db_query('SELECT * FROM {menu_links} WHERE menu_name = :menu_name AND mlid = :mlid', array(":menu_name" => $menu_name, ":mlid" => $row['plid']))->fetchAssoc();
        if ($parent['plid'] > 0) {
          $parent_order_number = nm_bookchapters_get_chapter_numbering_recursive($menu_name, $parent['plid'], $parent['mlid']);
        }
        if (isset($parent_order_number) && !empty($parent_order_number)) {
          $order_number = "$parent_order_number" . NM_CHAPTER_SEPARATOR . "$order_number";
        }
      }
      return $order_number;
    }
    $order_number++;
  }
}
