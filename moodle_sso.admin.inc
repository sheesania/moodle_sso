<?php

function moodle_sso_settings(){
  global $cookie_domain;
  if(!module_exists('moodle_connector')) {
    $form['moodle_sso_uri'] = array(
      '#type' => 'textfield',
      '#title' => t("The url needed to reach moodle."),
      '#description' => t("Please provide the absolute url to reach moodle. Include the http or https, and do not include a trailing slash."),
      '#default_value' => variable_get('moodle_sso_uri', false),
    );
  }
  else{
    $form['moodle_sso_uri'] = array(
      '#type' => 'item',
      '#title' => t("The url needed to reach moodle."),
      '#description' => t("This value is provided by the moodle connector module."),
    );

  }
  $form['moodle_sso_logout_moodle'] = array(
    '#type' => 'checkbox',
    '#title' => t("Log out of moodle"),
    '#description' => t("Log out of moodle when users log out of Drupal. Note: This just deletes the session cookie using the configuration below, and doesn't call any of moodle's logout processes."),
    '#default_value' => variable_get('moodle_sso_logout_moodle', false),
  );
  $form['moodle_sso_cookie_name'] = array(
    '#type' => 'textfield',
    '#title' => t("Moodle Session Cookie Name."),
    '#description' => t("The name of the session cookie moodle uses. this will usually be \"MoodleSession\" but may be different in some cases. "),
    '#default_value' => variable_get('moodle_sso_cookie_name', 'MoodleSession'),
  );
  $form['moodle_sso_cookie_domain'] = array(
    '#type' => 'textfield',
    '#title' => t("Cookie Domain."),
    '#description' => t("The cookie domain moodle has set. Make sure that the url/domain Drupal is running on has access to this cookie!"),
    '#default_value' => variable_get('moodle_sso_cookie_domain', $cookie_domain),
  );
  $form['moodle_sso_cookie_path'] = array(
    '#type' => 'textfield',
    '#title' => t("Cookie Path"),
    '#description' => t("This is the path portion of the cookie. In most cases this will be \"/\" but in some cases it might be different. "),
    '#default_value' => variable_get('moodle_sso_cookie_path', '/'),
  );



  return system_settings_form($form);
}