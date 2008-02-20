<?php
// $Id$

function video_filter_godtube($video) {
	video_filter_dimensions($video, 300, 270);
	
	$video['source'] = preg_replace('/^.*\?viewkey=(.+)(&.+)?$/', '\\1', $video['source']);
	
	$output = '<object type="application/x-shockwave-flash" width="'.$video['width'].'" height="'.$video['height'].'" data="http://www.godtube.com/flvplayer.swf?viewkey='.$video['source'].'"><param name="movie" value="http://www.godtube.com/flvplayer.swf?viewkey='.$video['source'].'&hl=en" /><param name="wmode" value="transparent" /></object>';
		
	return $output;
}

?>