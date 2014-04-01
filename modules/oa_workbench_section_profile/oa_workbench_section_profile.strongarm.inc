<?php
/**
 * @file
 * oa_workbench_section_profile.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function oa_workbench_section_profile_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_profile_weights';
  $strongarm->value = array(
    'workbench_moderation_profile_og' => array(
      'weight' => '-9',
    ),
    'oa_workbench_section_profile' => array(
      'weight' => '-10',
    ),
  );
  $export['workbench_moderation_profile_weights'] = $strongarm;

  return $export;
}
