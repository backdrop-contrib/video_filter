/**
 * @file
 * TinyMCE video filter plugin.
 */
(function () {

  'use strict';

  /**
   * Constructs the token to insert from submitted data.
   */
  const buildToken = function (data) {
    let embedStr = '';
    embedStr += 'video:' + data.videourl.value;
    if (data.width) {
      embedStr += ' width:' + data.width;
    }
    if (data.height) {
      embedStr += ' height:' + data.height;
    }
    if (data.align != 'none') {
      embedStr += ' align:' + data.align;
    }
    if (data.autoplay) {
      embedStr += ' autoplay:1';
    }
    return '[' + embedStr + ']';
  }

  /**
   * Returns configuration for the TinyMCE dialog.
   */
  const getDialogConfig = function () {
    let editor = tinymce.activeEditor;
    let dialogConfig = {
      title: editor.options.get('videoFilterTooltip'),
      onSubmit: function (api) {
        let data = api.getData();
        if (data.videourl.value) {
          let token = buildToken(data);
          editor.execCommand('mceInsertContent', false, token);
        }
        api.close();
      },
      body: {
        type: 'panel',
        items: [
          {
            name: 'videourl',
            type: 'urlinput',
            label: 'Url',
          },
          {
            name: 'width',
            type: 'input',
            label: 'Width',
            inputMode: 'numeric'
          },
          {
            name: 'height',
            type: 'input',
            label: 'Height',
            inputMode: 'numeric'
          },
          {
            name: 'align',
            type: 'selectbox',
            label: 'Align',
            size: 1,
            items: [
              { value: 'none', text: 'None' },
              { value: 'left', text: 'Left' },
              { value: 'right', text: 'Right' },
              { value: 'center', text: 'Center' }
            ]
          },
          {
            name: 'autoplay',
            type: 'checkbox',
            label: 'Autoplay'
          },
          {
            type: 'htmlpanel',
            html: '<iframe style="width:100%;" src="' + editor.options.get('videoFilterInstructionUrl') + '"></iframe>'
          }
        ]
      },
      buttons: [
        {
          type: 'cancel',
          name: 'closeButton',
          text: 'Cancel'
        },
        {
          type: 'submit',
          name: 'submitButton',
          text: 'Insert',
          buttonType: 'primary'
        }
      ]
    };
    return dialogConfig;
  };

  tinymce.PluginManager.add('video_filter', function (editor, url) {
    editor.ui.registry.addButton('video_filter', {
      icon: 'embed',
      tooltip: editor.options.get('videoFilterTooltip'),
      onAction: function () {
        let config = getDialogConfig();
        editor.windowManager.open(config);
      },
    });

    editor.ui.registry.addMenuItem('video_filter', {
      icon: 'embed',
      text: editor.options.get('videoFilterTooltip'),
      onAction: function () {
        let config = getDialogConfig();
        editor.windowManager.open(config);
      }
    });
  });

})();
