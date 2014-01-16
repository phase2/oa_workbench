<?php
/**
 * @file
 * Administration pages and forms for the Open Atrium Workbench Access module.
 */

/**
 * Form constructor for the Group permissions form.
 *
 * Internally it uses _oa_workbench_access_permissions_form() to build the
 * actual form and handle submit.
 *
 * @see _oa_workbench_access_permissions_form()
 * @see _oa_workbench_access_permissions_form_submit()
 */
function oa_workbench_access_group_permissions_form($form, &$form_state) {
  $message  = '<p>' . t('Please select which Groups have permission to perform each transition.') . '</p>';
  $message .= '<p>' . t('<em>Warning: In order to perform a transition, the user must also have a role with the <a href="!url">permission to perform the transation</a>.</em>', array('!url' => url('admin/people/permissions#module-workbench_moderation'))) . '</p>';

  $form['message'] = array(
    '#markup' => $message
  );

  $groups = oa_core_get_all_groups();
  $transitions = workbench_moderation_transitions();

  return _oa_workbench_access_permissions_form($form, $form_state, 'oa_group', t('Groups'), $groups, $transitions);
}

/**
 * Internal form constructor for both the Group and Team permissions forms.
 *
 * @param string $node_type
 *   The machine name of the node type of the group.
 * @param string $groups_label
 *   The label to use for the groups field.
 * @param array $groups
 *   An array of nodes representing each of the available groups.
 * @param array $transitions
 *   An array of transition objects, each with from_name and to_name
 *   properties that reference moderation states.
 *
 * @see _oa_workbench_access_permissions_form_submit()
 * @see oa_workbench_access_group_permissions_form()
 * @see oa_workbench_access_team_permissions_form()
 *
 * @ingroup forms
 */
function _oa_workbench_access_permissions_form($form, &$form_state, $node_type, $group_label, $groups, $transitions) {
  // Load the current values from the database.
  $result = db_select('oa_workbench_access', 'a')
    ->fields('a', array('nid', 'from_name', 'to_name'))
    ->condition('type', $node_type, '=')
    ->execute();
  $values = array();
  foreach ($result as $value) {
    $name = $value->from_name . '-' . $value->to_name;
    // The form needed by #default_value for a multiple select.
    $values[$name][$value->nid] = $value->nid;
  }

  $form['node_type'] = array(
    '#type' => 'value',
    '#value' => $node_type,
  );

  $group_options = array();
  foreach ($groups as $group) {
    $group_options[$group->nid] = $group->title;
  }

  // Put each of the transitions on the form with a list of Groups that can
  // do them. This will be themed into a table.
  $form['transitions'] = array(
    '#tree' => TRUE,
    '#theme' => 'oa_workbench_access_permissions_form',
  );
  foreach ($transitions as $transition) {
    $name = $transition->from_name . '-' . $transition->to_name;

    $form['transitions'][$name]['name'] = array(
      '#type' => 'item',
      '#title' => t('Transition'),
      '#markup' => t('From %from_state to %to_state', array(
        '%from_state' => workbench_moderation_state_label($transition->from_name),
        '%to_state' => workbench_moderation_state_label($transition->to_name),
      )),
    );

    $form['transitions'][$name]['groups'] = array(
      '#type' => 'select',
      '#title' => $group_label,
      '#multiple' => TRUE,
      '#options' => $group_options,
      '#default_value' => isset($values[$name]) ? $values[$name] : array(),
      '#attributes' => array(
        'class' => array('chosen-widget'),
      ),
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save permissions'),
  );

  $form['#submit'][] = '_oa_workbench_access_permissions_form_submit';
  return $form;
}

/**
 * Form submission handler for both the Group and Team permissions forms.
 *
 * @see _oa_workbench_access_permissions_form()
 * @see oa_workbench_access_group_permissions_form()
 * @see oa_workbench_access_team_permissions_form()
 */
function _oa_workbench_access_permissions_form_submit($form, &$form_state) {
  // Delete all existing permissions.
  db_delete('oa_workbench_access')->execute();

  // Then build them back up!
  foreach ($form_state['values']['transitions'] as $name => $transition) {
    list ($from_name, $to_name) = explode('-', $name);
    foreach ($transition['groups'] as $nid) {
      db_insert('oa_workbench_access')
        ->fields(array(
          'nid' => $nid,
          'type' => $form_state['values']['node_type'],
          'from_name' => $from_name,
          'to_name' => $to_name,
        ))
        ->execute();
    }
  }

  drupal_set_message(t('The changes have been saved.'));
}
