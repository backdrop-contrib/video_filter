/**
 * @file
 * Backdrop Video Filter plugin.
 */

(function (Backdrop, CKEditor5) {

  "use strict";

  /**
   * The VideoFilter plugin.
   */
  class VideoFilter extends CKEditor5.core.Plugin {
    /**
     * @inheritdoc
     */
    static get pluginName() {
      return 'VideoFilter';
    }

    /**
     * @inheritdoc
     */

    init() {
      const editor = this.editor;

      editor.ui.componentFactory.add('videoFilter', () => {
        const button = new CKEditor5.ui.ButtonView();

        button.set({
          label: editor.config.get('videoFilterLabel'),
          tooltip: 'Select video to embed',
          icon: '<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 256 256"><rect width="256" height="256" fill="none"/><path d="M232,208a8,8,0,0,1-8,8H32a8,8,0,0,1,0-16H224A8,8,0,0,1,232,208Zm0-152V168a16,16,0,0,1-16,16H40a16,16,0,0,1-16-16V56A16,16,0,0,1,40,40H216A16,16,0,0,1,232,56Zm-68,56a8,8,0,0,0-3.41-6.55l-40-28A8,8,0,0,0,108,84v56a8,8,0,0,0,12.59,6.55l40-28A8,8,0,0,0,164,112Z"/></svg>',
        });

        button.on('execute', () => {
          // Remove focus from the toolbar button when opening the dialog.
          // Otherwise, the button may receive focus again after closing the
          // dialog.
          button.element.blur();
          let dialogUrl = editor.config.get('video_filter').dialogUrl;
          let saveCallback = function (returnValue) {
            editor.model.change(function (writer) {
              const insertPosition = editor.model.document.selection.getLastPosition();
              writer.insertText(returnValue, insertPosition);
            });
          };

          Backdrop.ckeditor5.openDialog(editor, dialogUrl, null, saveCallback, {});
        });

        return button;
      });
    }
  }

  // Expose the plugin to the CKEditor5 namespace.
  CKEditor5.videoFilter = {
    'VideoFilter': VideoFilter
  };

})(Backdrop, CKEditor5);
