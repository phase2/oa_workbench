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
  $form['message'] = array(
    '#markup' => '<p>' . t("We only <em>remove permission</em> to transitions, not add permission if the user role doesn't already have it. So, be sure that some roles <a href='!url'>have permission to perform the transitions</a> in the first place.", array('url' => url('admin/people/permissions#module-workbench_moderation'))) . '</p>',
  );

  $groups = oa_core_get_all_groups();
  $transitions = workbench_moderation_transitions();

  return _oa_workbench_access_permissions_form($form, $form_state, t('Groups'), $groups, $transitions);
}

/**
 * Internal form constructor for both the Group and Team permissions forms.
 *
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
function _oa_workbench_access_permissions_form($form, &$form_state, $group_label, $groups, $transitions) {
  $form['#submit'][] = '_oa_workbench_access_permission_form_submit';

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save permissions'),
  );
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
  // TODO: save to the database.
}
