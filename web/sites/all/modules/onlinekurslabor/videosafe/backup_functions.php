<?php
/*HIER BEFINDEN SICH BLOSS EIN PAAR FUNKTIONSVARIANTEN FALLS MAN WAS AUSPROBIEREN MUSS:
NIX WAS BENUTZT WIRD
 *  */

/**
 * checkt ob der html5-parameter GET-Parameter RANGES gesetzt ist,
 * was bedeutet, dass der Aufruf von einem Player und nicht von einem file-download kommt
 * @return bool is_streaming
 */
function _videosafe_is_video_streaming() {

  if (!_videosafe_headers_getRanges()) {
    return FALSE;
  }
  return TRUE;

}

/**
 * get Http-Range-Definitions. Used by html5-players
 * @return array<String> $ranges
 */
function _videosafe_headers_getRanges() {
  return preg_match('/^bytes=((\d*-\d*,? ?)+)$/', @$_SERVER['HTTP_RANGE'], $matches) ? $matches[1] : array();
}
/**
 * sends content to the user's browser using the http-range-info
 * thank you mobiforge https://mobiforge.com/design-development/content-delivery-mobile-devices
 * and thomtom https://bitbucket.org/thomthom/php-resumable-download-server/src/8713d54809617b24a63065ef3e5afd998288ad36/index.php?fileviewer=file-view-default
 */
function _videosafe_downloadRange($file_path) {
  $fp = @fopen($file_path, 'rb');

  $size = filesize($file_path); // File size
  $length = $size;           // Content length
  $start = 0;               // Start byte
  $end = $size - 1;       // End byte
  // Now that we've gotten so far without errors we send the accept range header
  /* At the moment we only support single ranges.
   * Multiple ranges requires some more work to ensure it works correctly
   * and comply with the spesifications: http://www.w3.org/Protocols/rfc2616/rfc2616-sec19.html#sec19.2
   *
   * Multirange support annouces itself with:
   * header('Accept-Ranges: bytes');
   *
   * Multirange content must be sent with multipart/byteranges mediatype,
   * (mediatype = mimetype)
   * as well as a boundry header to indicate the various chunks of data.
   */
  // das ist ein fix fuer den iE, damit er nicht immer die ganze datei laden muss
  $http_range = (isset($_SERVER["HTTP_RANGE"])) ? $_SERVER["HTTP_RANGE"] : "bytes=0-"; 
  header("Accept-Ranges: 0-$length");
  // header('Accept-Ranges: bytes');
  // multipart/byteranges
  // http://www.w3.org/Protocols/rfc2616/rfc2616-sec19.html#sec19.2
  if ($http_range) {
    $c_start = $start;
    $c_end = $end;

    // Extract the range string
    list(, $range) = explode('=', $http_range, 2);
    // Make sure the client hasn't sent us a multibyte range
    if (strpos($range, ',') !== FALSE) {
      // (?) Shoud this be issued here, or should the first
      // range be used? Or should the header be ignored and
      // we output the whole content?
      header('HTTP/1.1 416 Requested Range Not Satisfiable');
      header("Content-Range: bytes $start-$end/$size");
      // (?) Echo some info to the client?
      exit;
    } // fim do if
    // If the range starts with an '-' we start from the beginning
    // If not, we forward the file pointer
    // And make sure to get the end byte if spesified
    if ($range{0} == '-') {
      // The n-number of the last bytes is requested
      $c_start = $size - substr($range, 1);
    }
    else {
      $range = explode('-', $range);
      $c_start = $range[0];
      $c_end = (isset($range[1]) && is_numeric($range[1])) ? $range[1] : $size;
    } // fim do if
    /* Check the range and make sure it's treated according to the specs.
     * http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html
     */
    // End bytes can not be larger than $end.
    $c_end = ($c_end > $end) ? $end : $c_end;
    // Validate the requested range and return an error if it's not correct.
    if ($c_start > $c_end || $c_start > $size - 1 || $c_end >= $size) {
      header('HTTP/1.1 416 Requested Range Not Satisfiable');
      header("Content-Range: bytes $start-$end/$size");
      // (?) Echo some info to the client?
      exit;
    } // fim do if

    $start = $c_start;
    $end = $c_end;
    $length = $end - $start + 1; // Calculate new content length
    fseek($fp, $start);
    header('HTTP/1.1 206 Partial Content');
  } // fim do if

  // Notify the client the byte range we'll be outputting
  header("Content-Range: bytes $start-$end/$size");
  header("Content-Length: $length");

  // Start buffered download
  $buffer = 1024 * 8;
  while (!feof($fp) && ($p = ftell($fp)) <= $end) {
    if ($p + $buffer > $end) {
      // In case we're only outputtin a chunk, make sure we don't
      // read past the length
      $buffer = $end - $p + 1;
    } // fim do if

    set_time_limit(0); // Reset time limit for big files
    echo fread($fp, $buffer);
    flush(); // Free up memory. Otherwise large files will trigger PHP's memory limit.
  } // fim do while

  fclose($fp);
} // fim do function




function range_download($file) {

	$fp = @fopen($file, 'rb');

	$size   = filesize($file); // File size
	$length = $size;           // Content length
	$start  = 0;               // Start byte
	$end    = $size - 1;       // End byte
	// Now that we've gotten so far without errors we send the accept range header
	/* At the moment we only support single ranges.
	 * Multiple ranges requires some more work to ensure it works correctly
	 * and comply with the spesifications: http://www.w3.org/Protocols/rfc2616/rfc2616-sec19.html#sec19.2
	 *
	 * Multirange support annouces itself with:
	 * header('Accept-Ranges: bytes');
	 *
	 * Multirange content must be sent with multipart/byteranges mediatype,
	 * (mediatype = mimetype)
	 * as well as a boundry header to indicate the various chunks of data.
	 */
	header("Accept-Ranges: 0-$length");
	// header('Accept-Ranges: bytes');
	// multipart/byteranges
	// http://www.w3.org/Protocols/rfc2616/rfc2616-sec19.html#sec19.2
	if (isset($_SERVER['HTTP_RANGE'])) {

		$c_start = $start;
		$c_end   = $end;
		// Extract the range string
		list(, $range) = explode('=', $_SERVER['HTTP_RANGE'], 2);
		// Make sure the client hasn't sent us a multibyte range
		if (strpos($range, ',') !== false) {

			// (?) Shoud this be issued here, or should the first
			// range be used? Or should the header be ignored and
			// we output the whole content?
			header('HTTP/1.1 416 Requested Range Not Satisfiable');
			header("Content-Range: bytes $start-$end/$size");
			// (?) Echo some info to the client?
			exit;
		}
		// If the range starts with an '-' we start from the beginning
		// If not, we forward the file pointer
		// And make sure to get the end byte if spesified
		if ($range0 == '-') {

			// The n-number of the last bytes is requested
			$c_start = $size - substr($range, 1);
		}
		else {

			$range  = explode('-', $range);
			$c_start = $range[0];
			$c_end   = (isset($range[1]) && is_numeric($range[1])) ? $range[1] : $size;
		}
		/* Check the range and make sure it's treated according to the specs.
		 * http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html
		 */
		// End bytes can not be larger than $end.
		$c_end = ($c_end > $end) ? $end : $c_end;
		// Validate the requested range and return an error if it's not correct.
		if ($c_start > $c_end || $c_start > $size - 1 || $c_end >= $size) {

			header('HTTP/1.1 416 Requested Range Not Satisfiable');
			header("Content-Range: bytes $start-$end/$size");
			// (?) Echo some info to the client?
			exit;
		}
		$start  = $c_start;
		$end    = $c_end;
		$length = $end - $start + 1; // Calculate new content length
		fseek($fp, $start);
		header('HTTP/1.1 206 Partial Content');
	}
	// Notify the client the byte range we'll be outputting
	header("Content-Range: bytes $start-$end/$size");
	header("Content-Length: $length");

	// Start buffered download
	$buffer = 1024 * 8;
	while(!feof($fp) && ($p = ftell($fp)) <= $end) {

		if ($p + $buffer > $end) {

			// In case we're only outputtin a chunk, make sure we don't
			// read past the length
			$buffer = $end - $p + 1;
		}
		set_time_limit(0); // Reset time limit for big files
		echo fread($fp, $buffer);
		flush(); // Free up memory. Otherwise large files will trigger PHP's memory limit.
	}

	fclose($fp);

}
/*
if (isset($_SERVER['HTTP_RANGE']))  {
	range_download($file);
} else {
	readfile( $file );
}
*/



 function serveFile($filename, $filename_output = false, $mime = 'application/octet-stream')
{
    $buffer_size = 8192;
    $expiry = 90; //days
    if(!file_exists($filename))
    {
        throw new Exception('File not found: ' . $filename);
    }
    if(!is_readable($filename))
    {
        throw new Exception('File not readable: ' . $filename);
    }

    header_remove('Cache-Control');
    header_remove('Pragma');

    $byte_offset = 0;
    $filesize_bytes = $filesize_original = filesize($filename);

    header('Accept-Ranges: bytes', true);
    header('Content-Type: ' . $mime, true);

    if($filename_output)
    {
        header('Content-Disposition: attachment; filename="' . $filename_output . '"');
    }

    // Content-Range header for byte offsets
    if (isset($_SERVER['HTTP_RANGE']) && preg_match('%bytes=(\d+)-(\d+)?%i', $_SERVER['HTTP_RANGE'], $match))
    {
        $byte_offset = (int) $match[1];//Offset signifies where we should begin to read the file            
        if (isset($match[2]))//Length is for how long we should read the file according to the browser, and can never go beyond the file size
        {
            $filesize_bytes = min((int) $match[2], $filesize_bytes - $byte_offset);
        }
        header("HTTP/1.1 206 Partial content");
        header(sprintf('Content-Range: bytes %d-%d/%d', $byte_offset, $filesize_bytes - 1, $filesize_original)); ### Decrease by 1 on byte-length since this definition is zero-based index of bytes being sent
    }

    $byte_range = $filesize_bytes - $byte_offset;

    header('Content-Length: ' . $byte_range);
    header('Expires: ' . date('D, d M Y H:i:s', time() + 60 * 60 * 24 * $expiry) . ' GMT');

    $buffer = '';
    $bytes_remaining = $byte_range;

    $handle = fopen($filename, 'r');
    if(!$handle)
    {
        throw new Exception("Could not get handle for file: " .  $filename);
    }
    if (fseek($handle, $byte_offset, SEEK_SET) == -1)
    {
        throw new Exception("Could not seek to byte offset %d", $byte_offset);
    }

    while ($bytes_remaining > 0)
    {
        $chunksize_requested = min($buffer_size, $bytes_remaining);
        $buffer = fread($handle, $chunksize_requested);
        $chunksize_real = strlen($buffer);
        if ($chunksize_real == 0)
        {
            break;
        }
        $bytes_remaining -= $chunksize_real;
        echo $buffer;
        flush();
    }
}

/*  function _videosafe_create_file_url($file_object)
  {
       return file_create_url($file_object->uri).'?'.drupal_random_key(6) ;
  }*/
     


/*

This code is released under the Simplified BSD License:

Copyright 2004 Razvan Florian. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are
permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this list of
      conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright notice, this list
      of conditions and the following disclaimer in the documentation and/or other materials
      provided with the distribution.

THIS SOFTWARE IS PROVIDED BY Razvan Florian ''AS IS'' AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Razvan Florian OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those of the
authors and should not be interpreted as representing official policies, either expressed
or implied, of Razvan Florian.

http://www.coneural.org/florian/papers/04_byteserving.php

*/

function set_range($range, $filesize, &$first, &$last){
  /*
  Sets the first and last bytes of a range, given a range expressed as a string 
  and the size of the file.

  If the end of the range is not specified, or the end of the range is greater 
  than the length of the file, $last is set as the end of the file.

  If the begining of the range is not specified, the meaning of the value after 
  the dash is "get the last n bytes of the file".

  If $first is greater than $last, the range is not satisfiable, and we should 
  return a response with a status of 416 (Requested range not satisfiable).

  Examples:
  $range='0-499', $filesize=1000 => $first=0, $last=499 .
  $range='500-', $filesize=1000 => $first=500, $last=999 .
  $range='500-1200', $filesize=1000 => $first=500, $last=999 .
  $range='-200', $filesize=1000 => $first=800, $last=999 .

  */
  $dash=strpos($range,'-');
  $first=trim(substr($range,0,$dash));
  $last=trim(substr($range,$dash+1));
  if ($first=='') {
    //suffix byte range: gets last n bytes
    $suffix=$last;
    $last=$filesize-1;
    $first=$filesize-$suffix;
    if($first<0) $first=0;
  } else {
    if ($last=='' || $last>$filesize-1) $last=$filesize-1;
  }
  if($first>$last){
    //unsatisfiable range
    header("Status: 416 Requested range not satisfiable");
    header("Content-Range: */$filesize");
    exit;
  }
}

function buffered_read($file, $bytes, $buffer_size=1024){
  /*
  Outputs up to $bytes from the file $file to standard output, $buffer_size bytes at a time.
  */
  $bytes_left=$bytes;
  while($bytes_left>0 && !feof($file)){
    if($bytes_left>$buffer_size)
      $bytes_to_read=$buffer_size;
    else
      $bytes_to_read=$bytes_left;
    $bytes_left-=$bytes_to_read;
    $contents=fread($file, $bytes_to_read);
    echo $contents;
    flush();
  }
}

function byteserve($filename){
  /*
  Byteserves the file $filename.  

  When there is a request for a single range, the content is transmitted 
  with a Content-Range header, and a Content-Length header showing the number 
  of bytes actually transferred.

  When there is a request for multiple ranges, these are transmitted as a 
  multipart message. The multipart media type used for this purpose is 
  "multipart/byteranges".
  */

  $filesize=filesize($filename);
  $file=fopen($filename,"rb");

  $ranges=NULL;
  if ($_SERVER['REQUEST_METHOD']=='GET' && isset($_SERVER['HTTP_RANGE']) && $range=stristr(trim($_SERVER['HTTP_RANGE']),'bytes=')){
    $range=substr($range,6);
    $boundary='g45d64df96bmdf4sdgh45hf5';//set a random boundary
    $ranges=explode(',',$range);
  }

  if($ranges && count($ranges)){
    header("HTTP/1.1 206 Partial content");
    header("Accept-Ranges: bytes");
    if(count($ranges)>1){
      /*
      More than one range is requested. 
      */

      //compute content length
      $content_length=0;
      foreach ($ranges as $range){
        set_range($range, $filesize, $first, $last);
        $content_length+=strlen("\r\n--$boundary\r\n");
        $content_length+=strlen("Content-type: application/pdf\r\n");
        $content_length+=strlen("Content-range: bytes $first-$last/$filesize\r\n\r\n");
        $content_length+=$last-$first+1;          
      }
      $content_length+=strlen("\r\n--$boundary--\r\n");

      //output headers
      header("Content-Length: $content_length");
      //see http://httpd.apache.org/docs/misc/known_client_problems.html for an discussion of x-byteranges vs. byteranges
      header("Content-Type: multipart/x-byteranges; boundary=$boundary");

      //output the content
      foreach ($ranges as $range){
        set_range($range, $filesize, $first, $last);
        echo "\r\n--$boundary\r\n";
        echo "Content-type: application/pdf\r\n";
        echo "Content-range: bytes $first-$last/$filesize\r\n\r\n";
        fseek($file,$first);
        buffered_read ($file, $last-$first+1);          
      }
      echo "\r\n--$boundary--\r\n";
    } else {
      /*
      A single range is requested.
      */
      $range=$ranges[0];
      set_range($range, $filesize, $first, $last);  
      header("Content-Length: ".($last-$first+1) );
      header("Content-Range: bytes $first-$last/$filesize");
      header("Content-Type: application/pdf");  
      fseek($file,$first);
      buffered_read($file, $last-$first+1);
    }
  } else{
    //no byteserving
    header("Accept-Ranges: bytes");
    header("Content-Length: $filesize");
    header("Content-Type: application/pdf");
    readfile($filename);
  }
  fclose($file);
}

function serve($filename, $download=0){
  //Just serves the file without byteserving
  //if $download=true, then the save file dialog appears
  $filesize=filesize($filename);
  header("Content-Length: $filesize");
  header("Content-Type: application/pdf");
  $filename_parts=pathinfo($filename);
  if($download) header('Content-disposition: attachment; filename='.$filename_parts['basename']);
  readfile($filename);
}

//unset magic quotes; otherwise, file contents will be modified
#+#set_magic_quotes_runtime(0);

//do not send cache limiter header
#ini_set('session.cache_limiter','none');


#$filename='myfile.pdf'; //this is the PDF file that will be byteserved
#byteserve($filename); //byteserve it!





//https://gist.github.com/benvium/3749316
function rangeblub($location)
{
      if (!file_exists($location))
  {
    header ("HTTP/1.1 404 Not Found");
    return;
  }
   
  $size  = filesize($location);
  $time  = date('r', filemtime($location));
   
  $fm = @fopen($location, 'rb');
  if (!$fm)
  {
    header ("HTTP/1.1 505 Internal server error");
    return;
  }
   
  $begin  = 0;
  $end  = $size - 1;
   
  if (isset($_SERVER['HTTP_RANGE']))
  {
    if (preg_match('/bytes=\h*(\d+)-(\d*)[\D.*]?/i', $_SERVER['HTTP_RANGE'], $matches))
    {
    $begin  = intval($matches[1]);
    if (!empty($matches[2]))
    {
      $end  = intval($matches[2]);
    }
    }
  }
  if (isset($_SERVER['HTTP_RANGE']))
  {
    header('HTTP/1.1 206 Partial Content');
  }
  else
  {
    header('HTTP/1.1 200 OK');
  }
    
  header('Cache-Control: public, must-revalidate, max-age=0');
  header('Pragma: no-cache');  
  header('Accept-Ranges: bytes');
  header('Content-Length:' . (($end - $begin) + 1));
  if (isset($_SERVER['HTTP_RANGE']))
  {
    header("Content-Range: bytes $begin-$end/$size");
  }
  header("Content-Disposition: inline; filename=$filename");
  header("Content-Transfer-Encoding: binary");
  header("Last-Modified: $time");
   
  $cur  = $begin;
  fseek($fm, $begin, 0);
  $breakposition = 2405290;
   
  while(!feof($fm) && $cur <= $end && (connection_status() == 0))
  {
        if ($cur <= $breakposition || isset($_SERVER['HTTP_RANGE'])) {
            print fread($fm, min(1024 * 16, ($end - $cur) + 1));
            $cur += 1024 * 16;
        }
        else {
          /*  if (@ $_SESSION['videosafe']['unallowed_access'] ++ == 2)
           #     header('Location: http://okldev2.naumenko-multimedia.de/sites/all/modules/onlinekurslabor/custom_general/modules/onlinekurslabor_access/assets/video/403_dl.mp4');
          #  else*/
            
           /*bewirkt folgendes: An gewisser Stelle (o.g. breakposition) bricht der Transfer ab.
            HTML5-Player hat nun einen Schnipsel und fordert erneut Daten an. Diesmal aber mit range-Parameter, da er vom 
            Server ja gesagt bekommen hat, dass das auch geht.*/
                exit;
        }
    }
}
/**
 * Convert a PHP ini shorthand byte value to an integer byte value. 
 * 
 * @see http://php.net/manual/en/function.ini-get.php 
 * @see http://php.net/manual/en/faq.using.php#faq.using.shorthandbytes 
 * 
 * @param string $value An PHP ini byte value, either shorthand or ordinary. 
 * @return int Value in bytes. 
 //nur benötigt falls ini_set nötig wird
function _videosafe_bytes_to_int($value) {
    $value = trim($value);
    $last = strtolower($value[strlen($value) - 1]);

    switch ($last) {
        // Note: the `break` statement is left out on purpose! 
        case 'g':
            $value *= 1024;
        case 'm':
            $value *= 1024;
        case 'k':
            $value *= 1024;
    }

    return $value;
}
*/