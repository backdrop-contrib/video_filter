<?php

function video_filter_godtube($video) {
	$video['source']	= strstr($video['source'], '?viewkey=') ? substr($video['source'], strpos($video['source'], '?viewkey=') + 9, strpos($video['source'], '&')) : $video['source'];
	$video['width']		= $width ? $width : ($height ? ($height / (270/330)) : 330);
	$video['height']	= $height ? $height : ($width ? ($width * (270/330)) : 270);
	
	$output = '<embed src="http://www.godtube.com/flvplayer.swf" flashvars="viewkey='.$video['source'].'" width="330" height="270" menu="false" allowscriptaccess="always" type="application/x-shockwave-flash"></embed>';
	
	return $output;
}

?>