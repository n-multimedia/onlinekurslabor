<?php
/**
 * @file
 * Default theme implementation to present an picture configured for the
 * user's account.
 *
 * Available variables:
 * - $picture: Image set by the user or the site's default.
 * - $account: Array of account information. Potentially unsafe. Be sure to
 *   check_plain() before use.
 * - $imagecache_used: TRUE if imagecache was used to size the picture.
 * - $picture_link_profile: $picture with link to the user profile page if
 *   the viewer has permission to view the user's profile page, otherwise FALSE.
 * 
 * Use $picture_link_profile instead of $picture if you want the picture to
 * link to the account profile page.
 */
?>

<?php if (!empty($picture)): ?>
  <div class="picture">
    <?php print $picture; ?>
  </div>
<?php endif; ?>
