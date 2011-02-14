/* $Id$ */

##############################################
## ONLY if you use ckeditor WITHOUT wysiwyg ##
##############################################

Installation:

Do the following steps to add video filter button to the CKEditor toolbar:

   1. Open /drupal/modules/ckeditor/ckeditor.config.js

   2. Add button to the toolbar. The button name is: video_filter
      For example if you have a toolbar with an array of buttons defined as follows:

      ['Bold', 'Italic', 'Image']

      simply add the button somewhere in the array:

      ['Bold', 'Italic', 'Image', 'video_filter']

      (remember about single quotes).

    3. Scroll down to the end of the file, right before "};" insert:
      
      // Video_filter plugin.
      config.extraPlugins += (config.extraPlugins ? ',video_filter' : 'video_filter' );
      CKEDITOR.plugins.addExternal('video_filter', Drupal.settings.basePath + 'sites/all/modules/video_filter/editors/ckeditor/');