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
          'label' => t('Select recipients\' roles'),
          'restriction' => 'input',
          'options list' => '_section_courses_get_default_course_roles',
          'optional' => FALSE,
          'description' => t('Select which role(s) the recipients must have in this group.'),
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
function onlinekurslabor_rules_action_mail_to_user_roles_in_group(EntityDrupalWrapper $group, $og_roles,  $exlude_user, $subject, $message, $from = NULL, $settings, RulesState $state, RulesPlugin $element) {
  //get group members
  $res = custom_general_get_users_in_group($group->getIdentifier());

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

     $role_names = array_intersect_key(_section_courses_get_default_course_roles(),$og_roles);
    
    //check og_role 
    //does the member have one of the selected roles?
    if (!_section_courses_user_has_role_in_course($account, node_load($group->getIdentifier()), $role_names)) {
        continue;
    }
    if ($account->status) {

      
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
    if (!$message_result['result']) {
      break;
    }
  }
  if ($message['result']) {
    watchdog('rules', 'Sent email to the group members with role(s) %roles.', array('%roles' => implode(', ', $role_names)));
  }
}
