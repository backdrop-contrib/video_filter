
var video_filter_dialog = {};

(function ($) {
video_filter_dialog = {
  insert : function() {
    var ed = tinyMCEPopup.editor, e;

    tinyMCEPopup.restoreSelection();
		
    tinyMCEPopup.execCommand("mceBeginUndoLevel");
		
    var file_url = $('#edit-file-url').val();

    // @Todo: validate width and hight is INTs?
    
    if (file_url == "") {
      // File url is empry, we have nothing to insert, close the window
      ed.execCommand('mceRepaint');
      tinyMCEPopup.execCommand("mceEndUndoLevel");
		  tinyMCEPopup.close();
    } 
    else {
      var str = '[video:' + file_url;
      if ($('#edit-width').val() !== '') {
        str += ' width:' + $('#edit-width').val();
      }
      if ($('#edit-height').val() !== '') {
        str += ' height:' + $('#edit-height').val();
      }
      if ($('#edit-align').val() !== 'none') {
        str += ' align:' + $('#edit-align').val();
      }
      if ($('#edit-autoplay').is(':checked')) {
        str += ' autoplay:' + $('#edit-autoplay').val();
      }
      str += ']';

      ed.execCommand('mceInsertContent', false, str);
    }

		tinyMCEPopup.execCommand("mceEndUndoLevel");
		tinyMCEPopup.close();
  }
};

Drupal.behaviors.video_filter_tinymce =  {
  attach: function(context, settings) {
    $('#edit-insert').click(function() {
      video_filter_dialog.insert();
    });

    $('#edit-cancel').click(function() {
      tinyMCEPopup.close();
    });
  }
}

})(jQuery);