/**
 * @file
 * Backdrop Link plugin.
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
      //const config = editor.config.get('videoFilter');

      // Add the videoFilter command.
      editor.commands.add('videoFilter', new VideoFilterCommand(editor));
      const videoFilterCommand = editor.commands.get('videoFilter');

      editor.ui.componentFactory.add('videoFilter', () => {
        const button = new CKEditor5.ui.ButtonView();

        button.set({
          label: editor.config.get('videoFilterLabel'),
          tooltip: true,
          icon: '<svg xmlns="http://www.w3.org/2000/svg" width="32" height="32" fill="#000000" viewBox="0 0 256 256"><path d="M164.44,105.34l-48-32A8,8,0,0,0,104,80v64a8,8,0,0,0,12.44,6.66l48-32a8,8,0,0,0,0-13.32ZM120,129.05V95l25.58,17ZM216,40H40A16,16,0,0,0,24,56V168a16,16,0,0,0,16,16H216a16,16,0,0,0,16-16V56A16,16,0,0,0,216,40Zm0,128H40V56H216V168Zm16,40a8,8,0,0,1-8,8H32a8,8,0,0,1,0-16H224A8,8,0,0,1,232,208Z"></path></svg>',
          // isToggleable: true,
          // isOn: false
        });

        button.on('execute', () => {
          // Remove focus from the toolbar button when opening the dialog.
          // Otherwise, the button may receive focus again after closing the
          // dialog.
          button.element.blur();
          // See VideoFilterCommand::execute().
          videoFilterCommand.execute();
        });

        return button;
      });
    }
  }

  // Expose the plugin to the CKEditor5 namespace.
  CKEditor5.videoFilter = {
    'VideoFilter': VideoFilter
  };

  /**
 * CKEditor command that opens the video filter editing dialog.
 */
  class VideoFilterCommand extends CKEditor5.core.Command {
    /**
     * @inheritdoc
     */
    refresh() {
      const editor = this.editor;
    }

    /**
     * @inheritdoc
     */
    execute() {
      const editor = this.editor;
      const config = editor.config.get('videoFilter');
      const selection = editor.model.document.selection;

      //const extraAttributes = new Map(Object.entries(config.extraAttributes));
      const dialogSettings = {
        dialogClass: 'editor-video-dialog'
      };

      // Pull in existing values from the model to be sent to the dialog.
      let existingValues = {
        'href': '',
      };

      // Prepare a save callback to be used upon saving the dialog.
      const saveCallback = function (returnValues) {
      }

      Backdrop.ckeditor5.openDialog(editor, config.dialogUrl, existingValues, saveCallback, dialogSettings);
    }
  }

})(Backdrop, CKEditor5);
