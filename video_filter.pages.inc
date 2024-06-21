<?php
/**
 * @file
 * Page and form callbacks.
 */

/**
 * Page callback for file selection form in ckeditor dialog.
 */
function video_filter_select_video_form($form, &$form_state, $format) {
  $form['file_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Video URL'),
    '#maxlength' => 255,
    '#size' => 80,
    '#default_value' => '',
    '#weight' => 1,
  );

  $form['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#maxlength' => 255,
    '#size' => 80,
    '#default_value' => '',
    '#weight' => 2,
  );

  $form['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#maxlength' => 255,
    '#size' => 80,
    '#default_value' => '',
    '#weight' => 3,
  );

  $form['align'] = array(
    '#type' => 'select',
    '#title' => t('Align'),
    '#default_value' => 'none',
    '#options' => array(
      'none' => t('None'),
      'left' => t('Left'),
      'right' => t('Right'),
      'center' => t('Center'),
    ),
    '#weight' => 4,
  );

  $form['autoplay'] = array(
    '#type' => 'checkbox',
    '#title' => t('Autoplay'),
    '#weight' => 5,
  );

  $form += _video_filter_instructions_form();

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Insert'),
    '#ajax' => array(
      'callback' => 'video_filter_select_video_form_save',
      'event' => 'click',
    ),
  );
  // Record the dialog selector that needs to be closed if present.
  if (isset($form_state['input']['dialogOptions']['target'])) {
    $form_state['storage']['dialog_selector'] = $form_state['input']['dialogOptions']['target'];
  }

  return $form;
}

/**
 * Save video selection in ckeditor content.
 */
function video_filter_select_video_form_save($form, &$form_state) {
  $dialog_selector = '#backdrop-dialog';
  if (isset($form_state['storage']['dialog_selector'])) {
    $dialog_selector = $form_state['storage']['dialog_selector'];
  }
  $commands = array();
  $errors = form_get_errors();
  if (!empty($errors)) {
    $error_messages = theme('status_messages');
    $rendered_form = backdrop_render($form);
    $commands[] = ajax_command_remove('.editor-dialog .messages');
    $commands[] = ajax_command_replace('.editor-dialog form', $rendered_form);
    $commands[] = ajax_command_prepend('.editor-dialog .ui-dialog-content', $error_messages);
  }
  else {
    $attributes = array(
      'width' => $form_state['values']['width'],
      'height' => $form_state['values']['height'],
      'align' => $form_state['values']['align'],
      'autoplay' => $form_state['values']['autoplay'],
    );
    $commands[] = array(
      'command' => 'editorDialogSave',
      'values' => _video_filter_build_token($form_state['values']['file_url'], $attributes,
      ),
    );
    $commands[] = ajax_command_close_dialog($dialog_selector);
  }
  return array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
}
