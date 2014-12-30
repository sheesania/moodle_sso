<?php

function moodle_sso_settings(){
  if(!module_exists('moodle_connector')) {
    $form['moodle_sso_uri'] = array(
      '#type' => 'textfield',
      '#title' => t("The url needed to reach moodle."),
      '#description' => t("Please provide the absolute url to reach moodle. Include the http or https, and do not include a trailing slash."),
      '#default_value' => variable_get('moodle_sso_uri', false),
    );
    system_settings_form($form);
  }
  else{
    $form['moodle_sso_uri'] = array(
      '#type' => 'item',
      '#title' => t("The url needed to reach moodle."),
      '#description' => t("This value is provided by the moodle connector module."),
    );

  }

  return $form;
}