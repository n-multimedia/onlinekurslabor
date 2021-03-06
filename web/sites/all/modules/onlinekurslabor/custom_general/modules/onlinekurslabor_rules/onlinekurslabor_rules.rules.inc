<?php

/**
 * Implementation of hook_rules_action_info().
 */
function onlinekurslabor_rules_rules_action_info() {
  return array(
    'mail_to_user_roles_in_group' => array(
      'label' => t('Send mail to all users of a group'),
      'group' => 'Onlinekurslabor',
      'parameter' => array(
        'group' => array(
          'type' => array_keys(og_get_all_group_entity()),
          'label' => t('Group'),
          'description' => t('The group where the members shoud be extracted from.'),
          'wrapped' => TRUE,
        ),
        'og_roles' => array(
          'type' => 'list<text>',
          'label' => t("Select recipients' roles"),
          'restriction' => 'input',
          'options list' => '_custom_general_get_og_group_roles',
          'optional' => TRUE,
          'description' => t('Select which role(s) the recipients must have in this group. If no role is selected, all <em>active</em> members of the group will get the e-mail.'),
        ),
        'exlude_user' => array(
          'type' => 'integer',
          'label' => t('Exclude User'),
          'description' => t('Check if you want to exclude a user (e.g the author.)'),
          'optional' => TRUE,
        ),
        'subject' => array(
          'type' => 'text',
          'label' => t('Subject'),
          'description' => t("The mail's subject."),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'description' => t("The mail's message body."),
        ),
        'from' => array(
          'type' => 'text',
          'label' => t('From'),
          'description' => t("The mail's from address. Leave it empty to use the site-wide configured address."),
          'optional' => TRUE,
        ),
      ),
      'base' => 'onlinekurslabor_rules_action_mail_to_user_roles_in_group',
      'access callback' => 'rules_system_integration_access',
    ),
  );
}

/**
 * Action: Send mail to all users of a specific role group(s).
 */
function onlinekurslabor_rules_action_mail_to_user_roles_in_group(EntityDrupalWrapper $group, $og_roles, $exlude_user, $subject, $message, $from = NULL, $settings, RulesState $state, RulesPlugin $element) {
  //get group members
  $res = custom_general_get_users_in_group($group->getIdentifier(), true);
  $recipient_counter = 0;

  $from = !empty($from) ? str_replace(array("\r", "\n"), '', $from) : NULL;

  // Set a unique key for this mail.
  $name = isset($element->root()->name) ? $element->root()->name : 'unnamed';
  $key = 'rules_action_mail_to_users_of_role_' . $name . '_' . $element->elementId();


  foreach ($res as $member) {
    //exlude
    if (isset($exlude_user) && $exlude_user == $member->uid) {
      continue;
    }

    $account = user_load($member->uid);

    $role_names = array_intersect_key(_custom_general_get_og_group_roles(), $og_roles);

    //falls keine Rollenbeschränkung erwünscht
    if (!empty($role_names)) {
      //check og_role 
      //does the member have one of the selected roles?

      /**
       * ---------- CAUTION - no common check. Only works for courses! No general solution needed atm.
       */
      if (!_section_courses_user_has_role_in_course($account, node_load($group->getIdentifier()), $role_names)) {
        continue;
      }
    }
    if ($account->status) {

      $recipient_counter++;
      //not really nice but works
      //need to relpace [user:name] tokens - $account object is available here only
      //instead of putting 'Hallo [user:name]' into the body text of the email
      //i'm prepending this part of the email here
      //(passing a token, which is not available ([og_user:name] in this example)
      //was replaced by an empty string)
      $args = array('user' => $account);

      $message_user = token_replace('Hallo [user:name], ', $args) . $message;

      // Now, actually send the mails.
      $params = array(
        'subject' => $subject,
        'message' => $message_user,
      );

      $message_result = array('result' => TRUE);

      $message_result = drupal_mail('rules', $key, $account->mail, language_default(), $params, $from);
      //dpm('sending mail to');
      //dpm($account->mail);
    }
    //Wenn ein Problem mitm Mailsystem besteht, breche ab.
    if (!$message_result['result']) {
      drupal_set_message(t("Error in mailsystem, operation cancelled.").t("Please contact the site administrator."), 'error');
      break;
    }
  }
  watchdog('rules', '(Tried to) send email(s) to %count group members with role(s) %roles.', array("%count" => $recipient_counter, '%roles' => implode(', ', $role_names)));
}
