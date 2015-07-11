<?php

/**
 * @file
 * Administrative page for configuring workflow extensions.
 */

/**
 * Menu callback for admin settings.
 */
function workflow_extensions_admin_configure($form, &$form_state) {
  // Form styles
  $form['workflow_extensions_forms'] = array(
    '#type' => 'fieldset',
    '#title' => t('Workflow form styles'),
    '#description' => t(''),
  );
  $radio_options = array(
    WORKFLOW_EXTENSIONS_UI_RADIOS => t('Radio buttons (classic style)'),
    WORKFLOW_EXTENSIONS_UI_BUTTONS => t('Single-action buttons'),
    WORKFLOW_EXTENSIONS_UI_DROPDOWN => t('Dropdown selector'),
  );
  $form['workflow_extensions_forms']['workflow_extensions_ui_style'] = array(
    '#type' => 'radios',
    '#title' => t("Select the form style you'd like to use for changing workflow states"),
    '#options' => $radio_options,
    '#default_value' => variable_get('workflow_extensions_ui_style', WORKFLOW_EXTENSIONS_UI_BUTTONS),
    '#description' => t(''),
  );
  // Buttons
  $form['workflow_extensions_buttons'] = array(
    '#type' => 'fieldset',
    '#title' => t('Workflow labels'),
    '#description' => t('Define fixed-text or tokenized labels to appear on the workflow state change form.'),
  );
  $form['workflow_extensions_buttons']['workflow_extensions_change_state_form_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title to appear above the state change form'),
    '#default_value' => variable_get('workflow_extensions_change_state_form_title', ''),
    '#description' => t('Use <em>&lt;none&gt;</em> to force no title.'),
  );
  $form['workflow_extensions_buttons']['workflow_extensions_default_save_button_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Label for the button on the edit form that saves content without changing the workflow state'),
    '#default_value' => variable_get('workflow_extensions_default_save_button_label', ''),
    '#description' => t('Applies only when <strong>Single-action buttons</strong> is selected above. Example: <em>Save, don\'t change state</em>. If left blank, the label will be the <strong>Workflow</strong> module default, i.e. <em>Save</em>. Your text may contain replacement tokens, e.g. <em>Save this draft of "[node:title]"</em>. Tokens require the <strong>Token</strong> module to be enabled.'),
  );
  $form['workflow_extensions_buttons']['workflow_extensions_change_state_button_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Label pattern for buttons for transitioning workflow state'),
    '#default_value' => variable_get('workflow_extensions_change_state_button_label', ''),
    '#description' => t('If <strong>Single-action buttons</strong> is selected above, use replacement tokens or leave blank. When left blank in single-action mode, the pattern applied is <em>Move to "[workflow:workflow-new-state-name]"</em>. For the others styles the default is <em>Submit</em>. Other useful tokens you may want to use are <em>[workflow:workflow-name]</em>, <em>[workflow:workflow-current-state-name]</em> and <em>[node:author]</em>.'),
  );
  // Comments
  $form['workflow_extensions_comments'] = array(
    '#type' => 'fieldset',
    '#title' => t('Workflow comments'),
    '#description' => t(''),
  );
  $form['workflow_extensions_comments']['workflow_extensions_allow_blank_comments'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow blank workflow log comments (ticked is the default)'),
    '#default_value' => variable_get('workflow_extensions_allow_blank_comments', TRUE),
    '#description' => t('If ticked and no comment is entered when transitioning state, a blank comment will be attached by default.'),
  );
  // Schedule
  $form['workflow_extensions_schedule'] = array(
    '#type' => 'fieldset',
    '#title' => t('Workflow schedule'),
    '#description' => t(''),
  );
  $form['workflow_extensions_schedule']['workflow_extensions_display_schedule_toggle'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show the form for scheduling workflow transitions only upon selection by the user'),
    '#default_value' => variable_get('workflow_extensions_display_schedule_toggle', TRUE),
    '#description' => t('This prevents users from entering scheduled dates and times and then forgetting to activate the form. Only applies when the user has the "schedule workflow transition" permission.'),
  );
  return system_settings_form($form);
}
