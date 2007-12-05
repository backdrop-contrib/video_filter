<?php

function video_filter_google($video) {
	video_filter_dimensions($video, 400, 326);
	
	$video['source'] = strstr($video['source'], '?docid=') ? substr($video['source'], strpos($video['source'], '?docid=') + 9, strpos($video['source'], '&')) : $video['source'];
	
	$output = '<embed style="width:'.$video['width'].'px; height:'.$video['height'].'px;" id="VideoPlayback" type="application/x-shockwave-flash" src="http://video.google.com/googleplayer.swf?docId='.$video['source'].'&hl=en" flashvars=""> </embed>';
	
	return $output;
}

?>