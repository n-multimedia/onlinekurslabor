<?php

/**
 * @file
 * Theme implementation to display information about a given user.
 *
 * Since the user is the author of a post or of a profile page, the user is
 * referred to as "author" below.
 *
 * Available variables (core modules):
 * - $account: The entire user object for the author.
 * - $picture: Themed user picture for the author. 
 *   See author-pane-user-picture.tpl.php.
 * - $account_name: Themed user name for the author.
 * - $account_id: User ID number for the author.
 *
 * - $joined: Date the post author joined the site. (Uses shortdate format)
 * - $joined_ago: Time since the author registered in the format "TIME ago"
 *
 * - $online_status_class: "author-offline" or "author-online".
 * - $online_status: Translated text "Online" or "Offline"
 * - $last_active: Time since author was last active. eg: "5 days 3 hours"
 *
 * - $contact: Linked translated text "Contact user".
 *
 * Available variables (contributed modules):
 * - $facebook_status: Status, including username, from the Facebook-style 
 *   Statuses module.
 * - $facebook_status_status: Status from the Facebook-style Statuses module.
 *
 * - $privatemsg: Linked translated text "Send private message" provided by
 *   the Privatemsg module.
 *
 * - $user_badges: Badges from User Badges module.
 *
 * - $userpoints_points: Author's total number of points from all categories.
 * - $userpoints_categories: Array holding each category and the points for 
 *   that category. Both provided by the User Points module.
 *
 * - $user_stats_posts: Number of posts from the User Stats module.
 * - $user_stats_ip: IP address from the User Stats module.
 *
 * - $user_title: Title from the User Titles module.
 * - $user_title_image: Image version of title from User Titles module. This is
 *   not shown by default. If you want to show images instead of titles, change
 *   all instances of the variable in the code below.
 *
 * - $og_groups: Linked list of Organic Groups that the author is a member of.
 *
 * - $fasttoggle_block_author: Link to toggle the author blocked/unblocked.
 *
 * Not working as of this writing but kept for future compatability:
 * - $user_relationships: Linked text "Add to <relationship>" or 
 *   "Remove from <relationship>".
 * - $flag_friend: Linked text. Actual text depends on module settings.
 *
 */
?>

<?php
  // This bit of debugging info will show the full path to and name of this
  // template file to make it easier to figure out which template is
  // controlling which author pane.
  if (!empty($show_template_location)) {
    print __FILE__;
  }
?>

<div class="author-pane">
 <div class="author-pane-inner">
    <?php /* General section */ ?>
    <div class="author-pane-section author-pane-general">
      <?php /* Account name */ ?>
      <div class="author-pane-line author-name">
        <?php print $account_name; ?>
      </div>

      <?php /* User picture / avatar (has div in variable) */ ?>
      <?php if (!empty($picture)): ?>
        <?php print $picture; ?>
      <?php endif; ?>

      <?php /* Online status */ ?>
      <?php if (!empty($online_status)): ?>
        <div class="author-pane-line <?php print $online_status_class ?>">
           <?php print $online_status; ?>
        </div>
      <?php endif; ?>

      <?php /* Last active */ ?>
      <?php if (!empty($last_active)): ?>
        <div class="author-pane-line">
           <span class="author-pane-label"><?php print t('Last seen'); ?>:</span> <?php print t('!time ago', array('!time' => $last_active)); ?>
        </div>
      <?php endif; ?>

      <?php /* User title */ ?>
      <?php if (!empty($user_title)): ?>
        <div class="author-pane-line author-title">
          <span class="author-pane-label"><?php print t('Title'); ?>:</span> <?php print $user_title; ?>
        </div>
      <?php endif; ?>

      <?php /* User badges */ ?>
      <?php if (!empty($user_badges)): ?>
        <div class="author-pane-line author-badges">
          <?php print $user_badges; ?>
        </div>
      <?php endif; ?>

      <?php /* Joined */ ?>
      <?php if (!empty($joined)): ?>
        <div class="author-pane-line author-joined">
          <span class="author-pane-label"><?php print t('Joined'); ?>:</span> <?php print $joined; ?>
        </div>
      <?php endif; ?>

      <?php /* Posts */ ?>
      <?php if (isset($user_stats_posts)): ?>
        <div class="author-pane-line author-posts">
          <span class="author-pane-label"><?php print t('Posts'); ?>:</span> <?php print $user_stats_posts; ?>
        </div>
      <?php endif; ?>

      <?php /* Points */ ?>
      <?php if (isset($userpoints_points)): ?>
        <div class="author-pane-line author-points">
          <span class="author-pane-label"><?php print t('!Points', userpoints_translation()); ?></span>: <?php print $userpoints_points; ?>
        </div>
      <?php endif; ?>
    </div>

    <?php /* Contact section */ ?>
    <div class="author-pane-section author-pane-contact">
      <?php /* Contact / Email */ ?>
      <?php if (!empty($contact)): ?>
        <div class="author-pane-line author-pane-link-line author-contact">
          <?php print $contact; ?>
        </div>
      <?php endif; ?>

      <?php /* Private message */ ?>
      <?php if (!empty($privatemsg)): ?>
        <div class="author-pane-line author-pane-link-line author-privatemsg">
          <?php print $privatemsg; ?>
        </div>
      <?php endif; ?>

      <?php /* User relationships */ ?>
      <?php if (!empty($user_relationships)): ?>
        <div class="author-pane-line author-pane-link-line author-user-relationship">
          <?php print $user_relationships; ?>
        </div>
      <?php endif; ?>

      <?php /* Flag friend */ ?>
      <?php if (!empty($flag_friend)): ?>
        <div class="author-pane-line author-pane-link-line author-flag-friend">
          <?php print $flag_friend; ?>
        </div>
      <?php endif; ?>
    </div>

    <?php /* Admin section */ ?>
    <div class="author-pane-section author-pane-admin">
      <?php /* IP */ ?>
      <?php if (!empty($user_stats_ip)): ?>
        <div class="author-pane-line author-ip">
          <span class="author-pane-label"><?php print t('IP'); ?>:</span> <?php print $user_stats_ip; ?>
        </div>
      <?php endif; ?>

     <?php /* Fasttoggle block */ ?>
     <?php if (!empty($fasttoggle_block_author)): ?>
        <div class="author-fasttoggle-block"><?php print $fasttoggle_block_author; ?></div>
      <?php endif; ?>
    </div>
  </div>
</div>
