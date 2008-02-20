<?php
// $Id$

function video_filter_google($video) {
	video_filter_dimensions($video, 400, 326);
	
	$video['source'] = preg_replace('/^.*\?docid=(.+)(&.+)?$/', '\\1', $video['source']);
	
	$output = '<object type="application/x-shockwave-flash" width="'.$video['width'].'" height="'.$video['height'].'" data="http://video.google.com/googleplayer.swf?docId='.$video['source'].'&hl=en"><param name="movie" value="http://video.google.com/googleplayer.swf?docId='.$video['source'].'&hl=en" /><param name="wmode" value="transparent" /></object>';
	
	return $output;
}

?>