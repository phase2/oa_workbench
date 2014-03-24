<?php
/**
 * @file
 * oa_workbench.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function oa_workbench_workbench_moderation_export_transitions() {
  $items = array(
    'draft:published' => array(
      'name' => 'Publish Immediately',
      'from_name' => 'draft',
      'to_name' => 'published',
    ),
  );
  return $items;
}
