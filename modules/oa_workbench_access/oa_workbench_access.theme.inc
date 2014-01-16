<?php
/**
 * @file
 * Theme functions for Open Atrium Workbench Access module.
 */

/**
 * Returns HTML for the Group and Team permissions forms.
 */
function theme_oa_workbench_access_permissions_form($variables) {
  $transitions = $variables['transitions'];
  $first = NULL;

  $rows = array();
  foreach (element_children($transitions) as $name) {
    // Capture the first transition to use later.
    if (is_null($first)) {
      $first = $transitions[$name];
    }

    // Remove the individual labels, because they are going into the
    // table header.
    unset(
      $transitions[$name]['name']['#title'],
      $transitions[$name]['groups']['#title']
    );

    // Render them into the table row.
    $rows[] = array(
      drupal_render($transitions[$name]['name']),
      drupal_render($transitions[$name]['groups']),
    );
  }

  if (count($rows) == 0) {
    return '<p>' . t('No transitions available') . '</p>';
  }

  // Build the table header.
  $header = array(
    $first['name']['#title'],
    $first['groups']['#title'],
  );
  // Render the table.
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
  ));
  $output .= drupal_render_children($transitions);
  return $output;
}
