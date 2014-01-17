<?php
/**
 * @file
 * oa_workbench_test.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_workbench_test_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function oa_workbench_test_node_info() {
  $items = array(
    'oa_workbench_test_content' => array(
      'name' => t('Workbench content'),
      'base' => 'node_content',
      'description' => t('An example content type used for test purposes.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
