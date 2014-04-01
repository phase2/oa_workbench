<?php

/**
 * @file
 * Workbench moderation state form for the node.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Node form workbench moderation state'),
  'icon' => 'icon_node_form.png',
  'description' => t('Workbench moderation state on the Node form.'),
  'required context' => new ctools_context_required(t('Form'), 'node_form'),
  'category' => t('Form'),
);

function oa_workbench_oa_workbench_moderation_state_content_type_render($subtype, $conf, $panel_args, &$context) {
  $block = new stdClass();

  $block->title = t('Workflow');
  $block->module = t('node_form');
  $block->delta = 'oa_workbench_moderation_state';

  if (isset($context->form)) {
    $element = NULL;
    if (isset($context->form['options']['workbench_moderation_state_new'])) {
      $element = $context->form['options']['workbench_moderation_state_new'];
      unset($context->form['options']['workbench_moderation_state_new']);
    }
    elseif (isset($context->form['revision_information']['workbench_moderation_state_new'])) {
      $element = $context->form['revision_information']['workbench_moderation_state_new'];
      unset($context->form['revision_information']['workbench_moderation_state_new']);
    }
    if (!empty($element)) {
      $block->content['options']['workbench_moderation_state_new'] = $element;
    }
  }
  else {
    $block->content = t('Workbench moderation state.');
  }
  return $block;
}

function oa_workbench_oa_workbench_moderation_state_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" node form workbench moderation state', array('@s' => $context->identifier));
}

function oa_workbench_oa_workbench_moderation_state_content_type_edit_form($form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
  return $form;
}
