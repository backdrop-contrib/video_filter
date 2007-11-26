<?php

function video_filter_google($video) {
	$video['source']	= strstr($video['source'], '?docid=') ? substr($video['source'], strpos($video['source'], '?docid=') + 9, strpos($video['source'], '&')) : $video['source'];
	$video['width']		= $video['width'] ? $video['width'] : ($video['height'] ? ($video['height'] / (326/400)) : 400);
	$video['height']	= $video['height'] ? $video['height'] : ($video['width'] ? ($video['width'] * (326/400)) : 326);
	
	$output = '<embed style="width:'.$video['width'].'px; height:'.$video['height'].'px;" id="VideoPlayback" type="application/x-shockwave-flash" src="http://video.google.com/googleplayer.swf?docId='.$video['source'].'&hl=en" flashvars=""> </embed>';
	
	return $output;
}

?>