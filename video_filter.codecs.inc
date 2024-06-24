<?php

/**
 * @file
 * This file contains all codecs provided by Video Filter.
 */

/**
 * Implements hook_codec_info().
 */
function video_filter_codec_info() {
  $codecs = array();

  $codecs['archive'] = array(
    'name' => t('Archive.org'),
    'sample_url' => '//www.archive.org/details/DrupalconBoston2008-TheStateOfDrupal',
    'callback' => 'video_filter_archive',
    'html5_callback' => 'video_filter_archive',
    'regexp' => '/archive\.org\/details\/([\w\-_\.]+)/i',
    'ratio' => 4 / 3,
  );

  $codecs['candidcareer'] = array(
    'name' => t('Candid Career'),
    'sample_url' => '//www.candidcareer.com/embed.php?vkey=ed5fdd900a274930252f&shared=CandidCareer&uid=30',
    'callback' => 'video_filter_candidcareer',
    'regexp' => '/candidcareer\.com\/embed\.php\?vkey=([a-zA-Z0-9\-_&;]+)shared=([a-zA-Z0-9\-_&;]+)uid=([a-zA-Z0-9\-_&;]+)/',
    'ratio' => 16 / 9,
    'control_bar_height' => 20,
  );

  $codecs['coub'] = array(
    'name' => t('Coub'),
    'sample_url' => '//coub.com/view/b7ghv',
    'callback' => 'video_filter_coub',
    'html5_callback' => 'video_filter_coub',
    'regexp' => '/coub\.com\/view\/([a-z0-9]+)/i',
    'ratio' => 4 / 3,
  );

  $codecs['dailymotion'] = array(
    'name' => t('DailyMotion'),
    'sample_url' => '//www.dailymotion.com/video/some_video_title',
    'callback' => 'video_filter_dailymotion',
    'html5_callback' => 'video_filter_dailymotion_html5',
    'regexp' => '/dailymotion\.com\/video\/([a-z0-9\-_]+)/i',
    'ratio' => 4 / 3,
    'control_bar_height' => 20,
  );

  $codecs['democracynow_fullshow'] = array(
    'name' => t('DemocracyNow Fullshow'),
    'sample_url' => '//www.democracynow.org/shows/2015/3/20',
    'callback' => 'video_filter_democracynow_fullshow',
    'regexp' => '/democracynow\.org\/shows\/([0-9]+)\/([0-9]+)\/([0-9]+)/',
    'ratio' => 16 / 9,
    'control_bar_height' => 0,
  );

  $codecs['democracynow_story'] = array(
    'name' => t('DemocracyNow Story'),
    'sample_url' => '//www.democracynow.org/2015/3/23/yemen_in_crisis_us_closes_key',
    'callback' => 'video_filter_democracynow_story',
    'regexp' => '/democracynow\.org\/([0-9]+)\/([0-9]+)\/([0-9]+)\/([a-zA-Z0-9\-_]+)/',
    'ratio' => 16 / 9,
    'control_bar_height' => 0,
  );

  $codecs['flickr_slideshows'] = array(
    'name' => t('Flickr'),
    'sample_url' => '//www.flickr.com/photos/username',
    'callback' => 'video_filter_flickr_slideshows',
    'regexp' => '/flickr\.com\/photos\/([a-zA-Z0-9@_\-]+)\/?/i',
    'ratio' => 4 / 3,
    'control_bar_height' => 0,
  );

  $codecs['foxnews'] = array(
    'name' => t('Fox News'),
    'sample_url' => '//video.foxnews.com/v/123456/the-title/',
    'callback' => 'video_filter_foxnews',
    'html5_callback' => 'video_filter_foxnews',
    'regexp' => '/video\.foxnews\.com\/v\/([0-9]+)\/([a-zA-Z0-9\-]+)/i',
    'ratio' => 466 / 263,
    'control_bar_height' => 0,
  );

  $codecs['gametrailers'] = array(
    'name' => t('Game Trailers'),
    'sample_url' => '//www.gametrailers.com/video/some-title/12345',
    'callback' => 'video_filter_gametrailers',
    'regexp' => array(
      '/gametrailers\.com\/player\/([0-9]+)/',
      '/gametrailers\.com\/video\/([a-z0-9\-_]+)\/([0-9]+)/',
    ),
    'ratio' => 16 / 9,
  );

  $codecs['giphy'] = array(
    'name' => t('Giphy'),
    'sample_url' => '//giphy.com/gifs/disney-kids-peter-pan-[gif-id]',
    'callback' => 'video_filter_giphy',
    'html5_callback' => 'video_filter_giphy',
    'regexp' => '/giphy\.com\/gifs\/(([a-zA-Z0-9\-]+)\-|)([a-zA-Z0-9]+)/i',
    'ratio' => 16 / 9,
  );

  $codecs['godtube'] = array(
    'name' => t('GodTube'),
    'sample_url' => '//www.godtube.com/watch/?v=123abc',
    'callback' => 'video_filter_godtube',
    'regexp' => '/godtube\.com\/watch\/\?v=([a-z0-9\-_]+)/i',
    'ratio' => 400 / 283,
    'control_bar_height' => 40,
  );

  $codecs['instagram'] = array(
    'name' => t('Instagram'),
    'callback' => 'video_filter_instagram',
    'sample_url' => '//instagram.com/p/uN1qUeId',
    'regexp' => array(
      '/instagram\.com\/p\/([a-z0-9\-_]+)/i',
      '/instagr.am\/p\/([a-z0-9\-_]+)/i',
    ),
    'ratio' => 612 / 710,
  );

  $codecs['mailru'] = array(
    'name' => t('Mail.Ru'),
    'sample_url' => '//my.mail.ru/v/semenikhin_denis/video/_groupvideo/[video-id].html',
    'callback' => 'video_filter_mailru',
    'html5_callback' => 'video_filter_mailru',
    'regexp' => '/my\.mail\.ru\/v\/(.*)\/([0-9]+)\.html/i',
    'ratio' => 16 / 9,
    'control_bar_height' => 0,
  );

  $codecs['myvideo'] = array(
    'name' => t('MyVideo'),
    'sample_url' => '//www.myvideo.de/filme/story-title-1234567890',
    'html5_callback' => 'video_filter_myvideo',
    'callback' => 'video_filter_myvideo',
    'regexp' => array(
      '/myvideo\.de\/(.+)\-([0-9]+)/i',
    ),
    'ratio' => 400 / 283,
  );

  $codecs['rutube'] = array(
    'name' => t('Rutube'),
    'sample_url' => '//rutube.ru/video/c80617086143e80ee08f760a2e9cbf43/?pl_type=source&pl_id=8188',
    'html5_callback' => 'video_filter_rutube',
    'callback' => 'video_filter_rutube',
    'regexp' => array(
      '/rutube\.ru\/(.*)/i',
    ),
    'ratio' => 16 / 9,
  );

  $codecs['slideshare'] = array(
    'name' => t('Slideshare'),
    'sample_url' => '//slideshare.net/1759622',
    'callback' => 'video_filter_slideshare',
    'instructions' => t('You need to construct your own URL, using the "Wordpress Embed" code from Slideshare, extract the "id", and form the URL like this: slideshare.net/1759622'),
    'regexp' => array(
      '/slideshare\.net\/\?id=([a-z0-9]+)/',
      '/slideshare\.net\/([a-z0-9]+)/',
    ),
    'ratio' => 425 / 355,
  );

  $codecs['soundcloud'] = array(
    'name' => t('SoundCloud'),
    'sample_url' => '//soundcloud.com/bigbabydram/broccoli',
    'callback' => 'video_filter_soundcloud',
    'instructions' => t(''),
    'regexp' => array(
      '/soundcloud\.com\/([a-z0-9]+)\/([a-z0-9]+)/',
    ),
    'ratio' => 4 / 3,
  );

  $codecs['teachertube'] = array(
    'name' => t('Teachertube'),
    'sample_url' => '//www.teachertube.com/videos/video-title-VIDEOID',
    'callback' => 'video_filter_teachertube',
    'regexp' => '/teachertube\.com\/videos\/([-a-zA-Z0-9]*)-([0-9]+)/i',
    'ratio' => 16 / 9,
  );

  $codecs['ted'] = array(
    'name' => t('TED'),
    'sample_url' => '//www.ted.com/talks/[story-title]',
    'instructions' => t('Click in Embed and copy the "Link to this talk" link and paste here.'),
    'callback' => 'video_filter_ted',
    'html5_callback' => 'video_filter_ted',
    'regexp' => '/ted\.com\/talks\/lang\/([a-zA-Z]+)\/([a-zA-Z0-9\-_]+)(\.html)?/',
    'ratio' => 4 / 3,
  );

  $codecs['twitch'] = array(
    'name' => t('Twitch'),
    'sample_url' => '//www.twitch.tv/uN1qUe-I_d',
    'callback' => 'video_filter_twitch',
    'regexp' => '/twitch\.tv\/([a-z0-9\-_]+)/i',
    'ratio' => 16 / 9,
  );

  $codecs['ustream'] = array(
    'name' => t('Ustream'),
    'sample_url' => '//www.ustream.tv/recorded/111212121212',
    'html5_callback' => 'video_filter_ustream',
    'callback' => 'video_filter_ustream',
    'regexp' => '/ustream\.tv\/recorded\/([0-9]+)/i',
    'ratio' => 16 / 9,
  );

  $codecs['vimeo'] = array(
    'name' => t('Vimeo'),
    'sample_url' => '//vimeo.com/123456',
    'instructions' => t('Unlisted Vimeo video URLs also include a privacy hash that is required for embedding to work. E.g. <code>//vimeo.com/123456/82e9Bae2d1</code>'),
    'callback' => 'video_filter_vimeo_html5',
    'html5_callback' => 'video_filter_vimeo_html5',
    'regexp' => array(
      '/vimeo\.com\/([0-9]+)[\/]*([a-z0-9]*)/i',
    ),
    'ratio' => 16 / 9,
    'control_bar_height' => 0,
  );

  $codecs['whatchado'] = array(
    'name' => t('whatchado'),
    'sample_url' => '//www.whatchado.com/en/stories/some-title',
    'callback' => 'video_filter_whatchado',
    'regexp' => array(
      '/whatchado\.com\/[a-z]{2}\/stories\/([\w\-_]+)/i',
      '/whatchado\.com\/[a-z]{2}\/([\w\-_]+)/i',
    ),
    'ratio' => 960 / 540,
  );

  $codecs['wistia'] = array(
    'name' => t('Wistia'),
    'sample_url' => '//wistia.com/medias/9pj9n6ftlk',
    'callback' => 'video_filter_wistia_html5',
    'html5_callback' => 'video_filter_wistia_html5',
    'regexp' => '@https?://(.+\.)?(wistia\.(com|net)|wi\.st)/((m|medias|projects)|embed/(iframe|playlists))/([a-zA-Z0-9]+)@',
  );

  $codecs['youku'] = array(
    'name' => t('YouKu'),
    'sample_url' => '//v.youku.com/v_show/id_XNjgzNDM4MzIw.html',
    'callback' => 'video_filter_youku_html5',
    'html5_callback' => 'video_filter_youku_html5',
    'regexp' => array(
      '/youku\.com\/v_show\/id_([a-z0-9\-_=]+)\.html/i',
      '/youku\.com\/player\.php\/sid\/([a-z0-9\-_=]+)/i',
    ),
    'ratio' => 16 / 9,
    'control_bar_height' => 50,
  );

  $codecs['youtube'] = array(
    'name' => t('YouTube'),
    'sample_url' => '//www.youtube.com/watch?v=uN1qUeId',
    'callback' => 'video_filter_youtube_html5',
    'html5_callback' => 'video_filter_youtube_html5',
    'regexp' => array(
      '/youtube\.com\/watch\?.*?v=([a-z0-9\-_]+)/i',
      '/youtu.be\/([a-z0-9\-_]+)/i',
      '/youtube\.com\/v\/([a-z0-9\-_]+)/i',
      '/youtube\.com\/embed\/([a-z0-9\-_]+)/i',
      '/youtube-nocookie\.com\/embed\/([a-z0-9\-_]+)/i',
    ),
    'ratio' => 16 / 9,
    'control_bar_height' => 0,
  );

  $codecs['youtube_playlist'] = array(
    'name' => t('YouTube (Playlist)'),
    'sample_url' => '//www.youtube.com/playlist?list=uN1qUeId',
    'callback' => 'video_filter_youtube_playlist_html5',
    'regexp' => array(
      '/youtube\.com\/playlist\?list=([a-z0-9\-_]+)/i',
    ),
    'ratio' => 16 / 9,
    'control_bar_height' => 0,
  );

  return $codecs;
}

/**
 * Callback for Archive.org codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_archive($video) {
  $video['source'] = '//www.archive.org/embed/' . $video['codec']['matches'][1];

  return video_filter_iframe($video);
}

/**
 * Callback for Candid Career codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_candidcareer($video) {
  // Their urls contain & symbols which Backdrop is encoding, so decode those.
  $decoded = decode_entities($video['codec']['matches'][0]);
  $video['source'] = '//' . $decoded;
  $video['attributes']['marginwidth'] = 0;
  $video['attributes']['marginheight'] = 0;
  return video_filter_iframe($video);
}

/**
 * HTML5 callback for Coub codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_coub($video) {
  $attributes = array(
    'autostart' => !empty($video['autoplay']) ? 'autoplay=true' : 'autoplay=false',
    'originalSize' => !empty($video['originalSize']) ? 'originalSize=true' : 'originalSize=false',
    'startWithHD' => !empty($video['startWithHD']) ? 'startWithHD=true' : 'startWithHD=false',
    'muted' => !empty($video['muted']) ? 'muted=true' : 'muted=false',
  );
  $video['source'] = '//coub.com/embed/' . $video['codec']['matches'][1] . '?' . implode('&', $attributes);

  return video_filter_iframe($video);
}

/**
 * HTML5 callback for DailyMotion codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_dailymotion_html5($video) {
  $attributes = array(
    'autoplay' => $video['autoplay'] ? 'autoplay=1' : 'autoplay=0',
  );
  $video['source'] = '//www.dailymotion.com/embed/video/' . $video['codec']['matches'][1] . '?' . implode('&amp;', $attributes);

  return video_filter_iframe($video);
}

/**
 * Callback for Flickr codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_flickr_slideshows($video) {
  $html = &backdrop_static(__FUNCTION__);
  $id = $video['source'];
  if ($cache = cache_get('video_filter_flickr:' . $id)) {
    $html = $cache->data;
  }
  else {
    $endpoint = 'https://www.flickr.com/services/oembed';
    $options = array(
      'url' => $video['source'],
      'format' => 'json',
    );
    $data = video_filter_oembed_request($endpoint, $options);

    if (!empty($data['html'])) {
      $html = $data['html'];
    }
    cache_set('video_filter_flickr:' . $id, $html, 'cache');
  }
  return $html;
}

/**
 * Callback for DemocracyNow Fullshow codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_democracynow_fullshow($video) {
  $video['source'] = '//www.democracynow.org/embed/show/' . $video['codec']['matches'][0];
  // The above is pulling in the url part of the regex, so we need to do a
  // search and replace to remove it.
  $toomuch = array("//www.democracynow.org/embed/show/democracynow.org/shows/");
  $justright = array("//www.democracynow.org/embed/show/");
  $replaced = str_replace($toomuch, $justright, $video);
  $video = $replaced;

  return video_filter_iframe($video);
}

/**
 * Callback for DemocracyNow story codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_democracynow_story($video) {
  $video['source'] = '//www.democracynow.org/embed/story/' . $video['codec']['matches'][0];
  // The above is pulling in the url part of the regex, so we need to do a
  // search and replace to remove it.
  $toomuch = array("//www.democracynow.org/embed/story/democracynow.org/");
  $justright = array("//www.democracynow.org/embed/story/");
  $replaced = str_replace($toomuch, $justright, $video);
  $video = $replaced;

  return video_filter_iframe($video);
}

/**
 * Callback for Ted.com codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_ted($video) {
  $video['source'] = '//embed.ted.com/talks/' . $video['codec']['matches'][3] . '.html';
  return video_filter_iframe($video);
}

/**
 * Callback for Fox News codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_foxnews($video) {
  $video_id = $video['codec']['matches'][1];
  $html = '<script type="text/javascript" src="//video.foxnews.com/v/embed.js?id=' . $video_id . '&w=' . $video['width'] . '&h=' . $video['height'] . '"></script>';
  return $html;
}

/**
 * Callback for Game Trailers codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_gametrailers($video) {
  if (is_numeric($video['codec']['matches'][1])) {
    $match = $video['codec']['matches'][1];
  }
  elseif (is_numeric($video['codec']['matches'][2])) {
    $match = $video['codec']['matches'][2];
  }
  $video['source'] = '//media.mtvnservices.com/embed/mgid:moses:video:gametrailers.com:' . $match;

  return video_filter_iframe($video);
}

/**
 * Callback for Giphy codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_giphy($video) {
  $video['source'] = '//giphy.com/embed/' . $video['codec']['matches'][3];

  return video_filter_iframe($video);
}

/**
 * Callback for GodTube codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_godtube($video) {
  $video['source'] = '//www.godtube.com/embed/watch/' . $video['codec']['matches'][1];

  return video_filter_iframe($video);
}

/**
 * Callback for Instagram codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_instagram($video) {
  $html = &backdrop_static(__FUNCTION__);
  $id = $video['codec']['matches'][1];
  if ($cache = cache_get('video_filter_instagram:' . $id)) {
    $html = $cache->data;
  }
  else {
    $endpoint = 'https://api.instagram.com/oembed';
    $options = array(
      'url' => '//instagr.am/p/' . $id,
    );
    $data = video_filter_oembed_request($endpoint, $options);
    if (!empty($data['html'])) {
      $html = $data['html'];
    }
    cache_set('video_filter_instagram:' . $id, $html, 'cache');
  }
  return $html;
}

/**
 * Callback for Mail.Ru codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_mailru($video) {
  $attributes = array(
    'autoplay' => !empty($video['autoplay']) ? 'autoplay=' . (int) $video['autoplay'] : '',
  );
  $video['source'] = '//videoapi.my.mail.ru/videos/embed/v/' . $video['codec']['matches'][1] . '/' . $video['codec']['matches'][2] . '.html?' . implode('&', $attributes);
  return video_filter_iframe($video);
}

/**
 * Callback for MyVideo codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_myvideo($video) {
  $video['source'] = '//www.myvideo.de/embedded/public/' . $video['codec']['matches'][2];
  return video_filter_iframe($video);
}

/**
 * Callback for Rutube codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_rutube($video) {
  $attributes = array(
    'skinColor' => (isset($video['skinColor']) && !empty($video['standardColor'])) ? 'skinColor=' . (string) $video['skinColor'] : '',
    'sTitle' => (isset($video['sTitle']) && $video['sTitle'] == 1) ? 'sTitle=true' : 'sTitle=false',
    'sAuthor' => (isset($video['sAuthor']) && $video['sAuthor'] == 1) ? 'sAuthor=true' : 'sAuthor=false',
    'bmstart' => (isset($video['bmstart']) && $video['bmstart'] > 1) ? 'bmstart=' . (int) $video['bmstart'] : 'bmstart=false',
  );
  $endpoint = '//rutube.ru/api/oembed';
  $options = array(
    'url' => $video['source'],
    'format' => 'json',
  );
  $data = video_filter_oembed_request($endpoint, $options);
  if (!empty($data['html'])) {
    if (preg_match('/src="([^"]+)"/', $data['html'], $match)) {
      $video['source'] = $match[1] . '?' . implode('&', $attributes);
      return video_filter_iframe($video);
    }
  }
}

/**
 * Callback for Slideshare codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_slideshare($video) {
  $video['source'] = '//www.slideshare.net/slideshow/embed_code/' . $video['codec']['matches'][1];

  return video_filter_iframe($video);
}

/**
 * Callback for Soundcloud codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_soundcloud($video) {
  $html = &backdrop_static(__FUNCTION__);
  $id = $video['codec']['matches'][1] . '/' . $video['codec']['matches'][2];
  if ($cache = cache_get('video_filter_soundcloud:' . $id)) {
    $html = $cache->data;
  }
  else {
    $endpoint = 'http://soundcloud.com/oembed';
    $options = array(
      'url' => $video['source'],
      'format' => 'json',
    );
    $data = video_filter_oembed_request($endpoint, $options);

    if (!empty($data['html'])) {
      $html = $data['html'];
    }
    cache_set('video_filter_soundcloud:' . $id, $html, 'cache');
  }
  return $html;
}

/**
 * Callback for Twitch codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_twitch($video) {
  $video['source'] = '//player.twitch.tv/?channel=' . $video['codec']['matches'][1] ;
  return video_filter_iframe($video);
}

/**
 * Callback for Teachertube codec.
 *
 * @todo upgrade to iframe.
 *
 * @see video_filter_codec_info()
 */
function video_filter_teachertube($video) {
  $video['source'] = '//www.teachertube.com/embed/videos/' . $video['codec']['matches'][2];

  return video_filter_iframe($video);
}

/**
 * Callback for Ustream codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_ustream($video) {
  $attributes = array(
    'html5ui' => 'html5ui',
    'autoplay' => isset($video['autoplay']) ? 'autoplay=' . (int) $video['autoplay'] : 'autoplay=0',
  );
  $video['source'] = '//www.ustream.tv/embed/recorded/' . $video['codec']['matches'][1] . '?' . implode('&', $attributes);
  return video_filter_iframe($video);
}

/**
 * HTML5 callback for Vimeo codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_vimeo_html5($video) {
  $attributes = array(
    'autopause' => isset($video['autopause']) ? 'autopause=' . (int) $video['autopause'] : 'autopause=1',
    'autoplay' => isset($video['autoplay']) ? 'autoplay=' . (int) $video['autoplay'] : 'autoplay=0',
    'badge' => isset($video['badge']) ? 'badge=' . (int) $video['badge'] : 'badge=1',
    'byline' => isset($video['byline']) ? 'byline=' . (int) $video['byline'] : 'byline=1',
    'loop' => isset($video['loop']) ? 'loop=' . (int) $video['loop'] : 'loop=0',
    'portrait' => isset($video['portrait']) ? 'portrait=' . (int) $video['portrait'] : 'portrait=1',
    'title' => isset($video['title']) ? 'autopause=' . (int) $video['title'] : 'autopause=1',
    'fullscreen' => isset($video['fullscreen']) ? 'fullscreen=' . (int) $video['fullscreen'] : 'fullscreen=1',
  );
  if (!empty($video['codec']['matches'][2])) {
    $attributes['h'] = 'h=' . $video['codec']['matches'][2];
  }
  if (!empty($video['privacy']) || preg_match('/\?dnt=1/', $video['source'])) {
    $attributes['dnt'] = 'dnt=1';
  }
  if (!empty($video['color'])) {
    $attributes['color'] = (string) $video['color'];
  }
  $video['source'] = '//player.vimeo.com/video/' . $video['codec']['matches'][1] . '?' . implode('&', $attributes);

  return video_filter_iframe($video);
}

/**
 * Callback for Whatchadoo codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_whatchado($video) {
  $video['source'] = '//www.whatchado.com/embed/player/' . $video['codec']['matches'][1];

  return video_filter_iframe($video);
}

/**
 * HTML5 callback for YouKu codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_youku_html5($video) {
  $attributes = array();
  $video['source'] = '//player.youku.com/embed/' . $video['codec']['matches'][1] . '?' . implode('&amp;', $attributes);

  return video_filter_iframe($video);
}

/**
 * HTML5 callback for YouTube codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_youtube_html5($video) {
  $attributes = array(
    'modestbranding' => !empty($video['modestbranding']) ? 'modestbranding=1' : 'modestbranding=0',
    'html5' => 'html5=1',
    'rel' => $video['related'] ? 'rel=1' : 'rel=0',
    'autoplay' => $video['autoplay'] ? 'autoplay=1' : 'autoplay=0',
    'wmode' => 'wmode=opaque',
    'loop' => !empty($video['loop']) ? 'loop=1' : 'loop=0',
    'controls' => !empty($video['controls']) ? 'controls=1' : (!isset($video['controls']) ? 'controls=1' : 'controls=0'),
    'autohide' => !empty($video['autohide']) ? 'autohide=1' : 'autohide=0',
    'showinfo' => !empty($video['showinfo']) ? 'showinfo=1' : 'showinfo=0',
    'theme' => !empty($video['theme']) ? 'theme=' . $video['theme'] : 'theme=dark',
    'color' => !empty($video['color']) ? 'color=' . $video['color'] : 'color=red',
    'enablejsapi' => !empty($video['enablejsapi']) ? 'enablejsapi=' . (int) $video['enablejsapi'] : 'enablejsapi=0',
  );

  if (!empty($video['loop'])) {
    $attributes['playlist'] = 'playlist=' . $video['codec']['matches'][1];
  }

  if (preg_match('/[\?|&]t=((?<minutes>\d+m)?(?<seconds>\d+s?)?)/', $video['source'], $matches)) {
    $attributes['start'] = 'start=' . (preg_replace("/[^0-9]/", "", $matches['minutes']) * 60 + (preg_replace("/[^0-9]/", "", $matches['seconds'])));
  }
  if (!empty($video['start'])) {
    if (preg_match('/((?<minutes>\d+m)?(?<seconds>\d+s?)?)/', $video['start'], $matches)) {
      $attributes['start'] = 'start=' . (preg_replace("/[^0-9]/", "", $matches['minutes']) * 60 + (preg_replace("/[^0-9]/", "", $matches['seconds'])));
    }
  }
  $domain = (!empty($video['privacy']) || preg_match('/youtube-nocookie\.com/', $video['source'])) ? '//www.youtube-nocookie.com/embed/' : '//www.youtube.com/embed/';
  $video['source'] = $domain . $video['codec']['matches'][1] . '?' . implode('&amp;', $attributes);

  return video_filter_iframe($video);
}

/**
 * HTML5 callback for YouTube (Playlist) codec.
 *
 * @see video_filter_codec_info()
 */
function video_filter_youtube_playlist_html5($video) {
  $attributes = array(
    'rel' => $video['related'] ? 'rel=1' : 'rel=0',
    'autoplay' => $video['autoplay'] ? 'autoplay=1' : 'autoplay=0',
    'wmode' => 'wmode=opaque',
  );
  $video['source'] = '//www.youtube.com/embed/videoseries?list=' . $video['codec']['matches'][1] . '&amp;' . implode('&amp;', $attributes);

  return video_filter_iframe($video);
}

/**
 * Callback for Wistia codec.
 *
 * Adapted from the media_wistia module.
 *
 * @see video_filter_codec_info()
 */
function video_filter_wistia_html5($video) {
  $video_code = $video['codec']['matches'][7];
  $matches = $video['codec']['matches'];
  $embed_type = ($matches[4] == 'projects' || $matches[6] == 'playlists') ? 'playlists' : 'iframe';

  // Get embed code via oEmbed.
  $endpoint = '//fast.wistia.com/oembed';
  $options = array(
    'url' => "//fast.wistia.com/embed/{$embed_type}/{$video_code}",
    'width' => $video['width'],
    'height' => $video['height'],
  );
  $data = video_filter_oembed_request($endpoint, $options);
  $html = $data['html'];

  // See if the video source is already an iframe src.
  $pattern = '@https?://fast.wistia.(com|net)/embed/(iframe|playlists)/[a-zA-Z0-9]+\?+.+@';
  $matches = array();
  if (preg_match($pattern, $video['source'], $matches)) {
    // Replace the oEmbed iframe src with that provided in the token, in order
    // to support embed builder URLs.
    $pattern = '@https?://fast.wistia.(com|net)/embed/(iframe|playlists)/[a-zA-Z0-9]+\?[^"]+@';
    $replacement = $matches[0];
    $html = preg_replace($pattern, $replacement, $html);
  }

  return $html;
}
