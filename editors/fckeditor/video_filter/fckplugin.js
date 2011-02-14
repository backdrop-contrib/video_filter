// $Id$

if(typeof Drupal != 'undefined') {
  var path = Drupal.settings.video_filter.url.wysiwyg_fckeditor;
  var basePath =  Drupal.settings.basePath;
} else {
  var basePath =  video_filter_basePath;
  var path = basePath + video_filter_url_fckeditor;
}

FCKCommands.RegisterCommand( 'video_filter', new FCKDialogCommand( 'video_filter', '&nbsp;', path, 580, 480 ) ) ;

var oVideoFilterItem = new FCKToolbarButton( 'video_filter', 'video_filter');
oVideoFilterItem.IconPath = basePath + 'sites/all/modules/video_filter/editors/fckeditor/video_filter/video_filter.png';
FCKToolbarItems.RegisterItem( 'video_filter', oVideoFilterItem );