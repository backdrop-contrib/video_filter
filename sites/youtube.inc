<?php
// $Id$

function video_filter_youtube($video) {
	video_filter_dimensions($video, 425, 355);
	
	if ($video['playlist']) {
		
		if ($xml = @simplexml_load_file('http://gdata.youtube.com/feeds/playlists/'.$video['playlist'])) {
                
			if (count($xml->entry)) {
				$random = rand(0, count($xml->entry) - 1);
				
				if ($xml->entry[$random]->link['href']) {
					$source = substr($xml->entry[$random]->link['href'], 31);
				  
				} else {
					$source = substr($xml->entry[$random]->link[0]['href'], 31);
				}
			}
		}
	}
	
	$video['source'] = preg_replace('/^.*\?v=(.+)(&.+)?$/', '\\1', $video['source']);
	
	$output = '<object type="application/x-shockwave-flash" width="'.$video['width'].'" height="'.$video['height'].'" data="http://www.youtube.com/v/'.$video['source'].($video['autoplay'] ? '&autoplay=1' : '').'"><param name="movie" value="http://www.youtube.com/v/'.$video['source'].($video['autoplay'] ? '&autoplay=1' : '').'" /><param name="wmode" value="transparent" /></object>';
	
	return $output;
}

?>