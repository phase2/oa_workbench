<?php
/**
 * @file
 * oa_workbench_section_profile.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function oa_workbench_section_profile_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_oa_workbench_profile'
  $field_bases['field_oa_workbench_profile'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_oa_workbench_profile',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '- Inherit from Space -',
      ),
      'allowed_values_function' => 'oa_workbench_section_profile_allowed_values_callback',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  return $field_bases;
}
