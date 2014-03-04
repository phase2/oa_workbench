<?php
/**
 * @file
 * oa_workbench.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function oa_workbench_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:oa_space:moderate content from draft to needs_review'
  $permissions['node:oa_space:moderate content from draft to needs_review'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:oa_space:moderate content from draft to published'
  $permissions['node:oa_space:moderate content from draft to published'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:oa_space:moderate content from needs_review to draft'
  $permissions['node:oa_space:moderate content from needs_review to draft'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:oa_space:moderate content from needs_review to published'
  $permissions['node:oa_space:moderate content from needs_review to published'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  return $permissions;
}
