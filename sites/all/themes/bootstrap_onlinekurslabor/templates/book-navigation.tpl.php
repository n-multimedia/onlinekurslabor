<?php

/**
 * @file
 * Default theme implementation to navigate books.
 *
 * Presented under nodes that are a part of book outlines.
 *
 * Available variables:
 * - $tree: The immediate children of the current node rendered as an unordered
 *   list.
 * - $current_depth: Depth of the current node within the book outline. Provided
 *   for context.
 * - $prev_url: URL to the previous node.
 * - $prev_title: Title of the previous node.
 * - $parent_url: URL to the parent node.
 * - $parent_title: Title of the parent node. Not printed by default. Provided
 *   as an option.
 * - $next_url: URL to the next node.
 * - $next_title: Title of the next node.
 * - $has_links: Flags TRUE whenever the previous, parent or next data has a
 *   value.
 * - $book_id: The book ID of the current outline being viewed. Same as the node
 *   ID containing the entire outline. Provided for context.
 * - $book_url: The book/node URL of the current outline being viewed. Provided
 *   as an option. Not used by default.
 * - $book_title: The book/node title of the current outline being viewed.
 *   Provided as an option. Not used by default.
 *
 * @see template_preprocess_book_navigation()
 *
 * @ingroup themeable
 */
$nm_booknav_span1 = 'span5';
$nm_booknav_span2 = 'span2';
$nm_booknav_span3 = 'span5';
$nm_booknav_extra = '';

if($prev_url && empty($parent_url) && empty($next_url)) {

}
if(empty($prev_url) && empty($parent_url) && $next_url) {

  $nm_booknav_extra = 'nm_float_right';
}
?>
<?php if ($tree || $has_links): ?>
  <div id="book-navigation-<?php print $book_id; ?>" class="book-navigation">
    <?php print $tree; ?>

    <?php if ($has_links): ?>
    <div class="page-links clearfix row-fluid">
      <?php if ($prev_url): ?>
        <a href="<?php print $prev_url; ?>" class="page-previous <?php print $nm_booknav_span1. ' ' . $nm_booknav_extra; ?>" title="<?php print t('Go to previous page'); ?>"><?php print $prev_title; ?></a>
      <?php endif; ?>
      <?php if ($parent_url): ?>
        <a href="<?php print $parent_url; ?>" class="page-up <?php print $nm_booknav_span2. ' ' . $nm_booknav_extra; ?>" title="<?php print t('Go to parent page'); ?>"><?php print t('up'); ?></a>
      <?php endif; ?>
      <?php if ($next_url): ?>
        <a href="<?php print $next_url; ?>" class="page-next <?php print $nm_booknav_span3 . ' ' . $nm_booknav_extra; ?>" title="<?php print t('Go to next page'); ?>"><?php print $next_title; ?></a>
      <?php endif; ?>
    </div>
    <?php endif; ?>

  </div>
<?php endif; ?>
