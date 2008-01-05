<?php

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

	if ($video['autoplay']) {
		$output = '<embed src="http://www.youtube.com/v/'.$video['source'].'&rel=1&autoplay=1" type="application/x-shockwave-flash" wmode="transparent" width="'.$video['width'].'" height="'.$video['height'].'"></embed>';
	  
	} else {
		$output = '<object width="'.$video['width'].'" height="'.$video['height'].'"><param name="movie" value="http://www.youtube.com/v/'.$video['source'].'&rel=1"></param><param name="wmode" value="transparent"></param><embed src="http://www.youtube.com/v/'.$video['source'].'&rel=1" type="application/x-shockwave-flash" wmode="transparent" width="'.$video['width'].'" height="'.$video['height'].'"></embed></object>';
	}
	
	return $output;
}

?>