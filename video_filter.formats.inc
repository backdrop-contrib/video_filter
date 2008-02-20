<?php
// $Id$

function video_filter_videoformat_info()
{
	$sites = array();
	
	$sites['youtube'] = array(
		'name' => t('YouTube'),
		'callback' => 'video_filter_youtube',
		'regexp' => '/youtube\.com\/watch\?v=([a-z0-9]+)/i',
		'ratio' => 425 / 355,
	);
	$sites['google'] = array(
		'name' => t('Google Video'),
		'callback' => 'video_filter_google',
		'regexp' => '/video\.google\.com\/videoplay\?docid=(\-?[0-9]+)/',
		'ratio' => 400 / 326,
	);
	$sites['godtube'] = array(
		'name' => t('GodTube'),
		'callback' => 'video_filter_godtube',
		'regexp' => '/godtube\.com\/view_video\.php\?viewkey=([a-z0-9]+)/',
		'ratio' => 300 / 270,
	);
	
	return $sites;
}

function video_filter_youtube($video, $matches, $delta = null) {
	$video['source'] = 'http://www.youtube.com/v/'.$matches[1].($video['autoplay'] ? '&autoplay=1' : '');
	
	return video_filter_flash($video);
}

function video_filter_google($video, $matches, $delta = null) {
	$video['source'] = 'http://video.google.com/googleplayer.swf?docId='.$matches[1];
	
	return video_filter_flash($video);
}

function video_filter_godtube($video, $matches, $delta = null) {
	$video['source'] = 'http://www.godtube.com/flvplayer.swf?viewkey='.$matches[1];
	
	return video_filter_flash($video);
}

?>