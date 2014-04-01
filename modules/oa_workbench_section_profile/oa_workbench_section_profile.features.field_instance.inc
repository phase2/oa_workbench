<?php
/**
 * @file
 * oa_workbench_section_profile.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function oa_workbench_section_profile_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-oa_section-field_oa_workbench_profile'
  $field_instances['node-oa_section-field_oa_workbench_profile'] = array(
    'bundle' => 'oa_section',
    'comment_alter' => 0,
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 10,
      ),
      'featured' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_oa_workbench_profile',
    'label' => 'Workbench Moderation Profile',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Workbench Moderation Profile');

  return $field_instances;
}
