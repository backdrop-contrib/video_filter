<?php

function video_filter_godtube($video) {
	video_filter_dimensions($video, 300, 270);
	
	$video['source'] = preg_replace('/^.*\?viewkey=(.+)(&.+)?$/', '\\1', $video['source']);
	
	$output = '<embed src="http://www.godtube.com/flvplayer.swf" flashvars="viewkey='.$video['source'].'" width="'.$video['width'].'" height="'.$video['height'].'" menu="false" allowscriptaccess="always" type="application/x-shockwave-flash"></embed>';
	
	/* In Development
	return video_filter_ufo(array(
		'movie'		=> 'http://www.godtube.com/flvplayer.swf',
		'flashvars'	=> $video['source'],
		'width'		=> $video['width'],
		'height'	=> $video['height'],
	));
	*/
	
	return $output;
}

?>