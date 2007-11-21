<?php

function video_filter_godtube($video) {
	$video['source']	= strstr($video['source'], '?viewkey=') ? substr($video['source'], strpos($video['source'], '?viewkey=') + 9, strpos($video['source'], '&')) : $video['source'];
	$video['width']		= $video['width'] ? $video['width'] : ($video['height'] ? ($video['height'] / (270/330)) : 330);
	$video['height']	= $video['height'] ? $video['height'] : ($video['width'] ? ($video['width'] * (270/330)) : 270);
	
	$output = '<embed src="http://www.godtube.com/flvplayer.swf" flashvars="viewkey='.$video['source'].'" width="330" height="270" menu="false" allowscriptaccess="always" type="application/x-shockwave-flash"></embed>';
	
	return $output;
}

?>