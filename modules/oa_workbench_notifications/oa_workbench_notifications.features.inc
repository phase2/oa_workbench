<?php
/**
 * @file
 * oa_workbench_notifications.features.inc
 */

/**
 * Implements hook_default_message_type().
 */
function oa_workbench_notifications_default_message_type() {
  $items = array();
  $items['oa_workbench_transition_notification'] = entity_import('message_type', '{
    "name" : "oa_workbench_transition_notification",
    "description" : "Workflow Transition",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "[message:field-oa-node-ref:title] transitioned to workflow state [message:field_oa_message_workflow_new]",
          "format" : "plain_text",
          "safe_value" : "\u003Cp\u003E[message:field-oa-node-ref:title] transitioned to workflow state [message:field_oa_message_workflow_new]\u003C\/p\u003E\n"
        },
        {
          "value" : "\u003Ca href=\u0022[message:field-oa-node-ref:url:absolute]\u0022\u003E[message:field-oa-node-ref:title]\u003C\/a\u003E transitioned from workflow state \u003Cem\u003E[message:field_oa_message_workflow_prev]\u003C\/em\u003E to \u003Cem\u003E[message:field_oa_message_workflow_new].\u003C\/em\u003E",
          "format" : "full_html",
          "safe_value" : "\u003Ca href=\u0022[message:field-oa-node-ref:url:absolute]\u0022\u003E[message:field-oa-node-ref:title]\u003C\/a\u003E transitioned from workflow state \u003Cem\u003E[message:field_oa_message_workflow_prev]\u003C\/em\u003E to \u003Cem\u003E[message:field_oa_message_workflow_new].\u003C\/em\u003E"
        }
      ]
    }
  }');
  return $items;
}
