<?php
/**
 * @file
 * oa_workbench_section_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_workbench_section_profile_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
