<?php
// $Id$

function video_filter_codec_info()
{
	$codecs = array();
	
	$codecs['youtube'] = array(
		'name' => t('YouTube'),
		'callback' => 'video_filter_youtube',
		'regexp' => '/youtube\.com\/watch\?v=([a-z0-9]+)/i',
		'ratio' => 425 / 355,
	);
	$codecs['google'] = array(
		'name' => t('Google Video'),
		'callback' => 'video_filter_google',
		'regexp' => '/video\.google\.com\/videoplay\?docid=(\-?[0-9]+)/',
		'ratio' => 400 / 326,
	);
	$codecs['godtube'] = array(
		'name' => t('GodTube'),
		'callback' => 'video_filter_godtube',
		'regexp' => '/godtube\.com\/view_video\.php\?viewkey=([a-z0-9]+)/',
		'ratio' => 300 / 270,
	);
	
	return $codecs;
}

function video_filter_youtube($video) {
	$video['source'] = 'http://www.youtube.com/v/'.$video['codec']['matches'][1].($video['autoplay'] ? '&autoplay=1' : '');
	
	return video_filter_flash($video);
}

function video_filter_google($video) {
	$video['source'] = 'http://video.google.com/googleplayer.swf?docId='.$video['codec']['matches'][1];
	
	return video_filter_flash($video);
}

function video_filter_godtube($video) {
	$video['source'] = 'http://www.godtube.com/flvplayer.swf?viewkey='.$video['codec']['matches'][1];
	
	return video_filter_flash($video);
}

?>