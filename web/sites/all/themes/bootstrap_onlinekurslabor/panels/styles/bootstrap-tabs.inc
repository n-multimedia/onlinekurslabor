<?php
/**
 * SINN 
 * Bei der Konfiguration einer Region innerhalb einer Region kann man als Output "Bootstrap-Tabs" auswählen
 * die einzelnen Panes werden dann in Tabs organisiert
 * 
 */
/**
 * @file
 * Definition of a tabbed region
 */
// Plugin definition
$plugin = array(
    'title' => t('Bootstrap-Tabs'),
    'description' => t('Renders the individual panes as tabs.'),
    'render region' => 'bootstrap_onlinekurslabor_bootstraptabs_style_render_region',
    'settings form' => '_bootstrap_onlinekurslabor_bootstraptabs_settings_form',
);

/**
 * Render callback based on callback name bootstrap_onlinekurslabor_bootstraptabs_style_render_region.
 *  Please note that it's a theme function
 * and has to start with 'theme_' prefix.
 * @ingroup themeable
 */
function theme_bootstrap_onlinekurslabor_bootstraptabs_style_render_region($vars) {

    $configuration = array();
    //build element-info-array with pane-titles
    foreach ($vars['panes'] as $pane_id => $pane_output) {
        /*
         * @TODO    funktioniert nur mit per "override" gesetztem Title (der muss aber nicht mal angehakt sein!). KA wie ich in an den originalen komme!!
         */        
        $pane_title = $vars['display']->content[$pane_id]->configuration['title']? : $vars['display']->content[$pane_id]->configuration['override_title_text'];
        $configuration[$pane_id]['title'] = $pane_title;
        $configuration[$pane_id]['content'] = $pane_output;
    }
     //Rendere die Konfiguration nun als "tabs" -> Default-Output für "Bootstrap-Tabs"
    $tabs = theme('tabs', array("elements" => $configuration));
            $tabs_content = theme('tabs-content', array("elements" => $configuration));;
    if($vars['settings']['region_bootstraptabs']['alignment'] === 'left')
    {
         //Rendere die Konfiguration nun als "tabs" -> Default-Output für "Bootstrap-Tabs"
    return '<div class="col-md-2 bootstrap_tabs-stacked-left">'.$tabs.'</div><div class="col-md-10">'.$tabs_content.'</div>';
    }
       if($vars['settings']['region_bootstraptabs']['alignment'] === 'top')
    {
        
    return $tabs.$tabs_content;
    }
   
}

/**
 * Settings form callback FOR REGION.
 */
function _bootstrap_onlinekurslabor_bootstraptabs_settings_form($style_settings) {
    $form['region_bootstraptabs'] = array();
       $form['region_bootstraptabs']['alignment'] = array(
      '#type' => 'radios',
      '#title' => t('Alignment'),
      '#default_value' => @$style_settings['region_bootstraptabs']['alignment'],
           '#options' => array(
            'above' => t('Above'),
            'left' => t('Stacked left'),
            )

      );
    
    $form['region_bootstraptabs']['desc'] = array(
        '#type' => 'markup',
        '#markup' => ('No settings available atm<br>You may format the individual panes as you want. Pane\'s title is MANDATORY<br> For best results use "No markup at all" for the individual panes<br>'),
    );
    return $form;
}
