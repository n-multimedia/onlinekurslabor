<?php


/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

$sleep = $_GET['sleep'];

$starttime = time(); 

if($sleep)
    sleep ($sleep);

// echo "Experiencing problems";exit;

header ('Content-Type: image/png');

$im = @imagecreatetruecolor(800, 800)
      or die('Cannot Initialize new GD image stream');
$text_color = imagecolorallocate($im, 233, 14, 91);
$endtime = time();
imagestring($im, 9, 225, 225,  'This string was generated at '.date('d.m.Y H:i:s'), $text_color);
imagestring($im, 9, 225, 245,  'for '.$_GET['def'], $text_color);
imagestring($im, 9, 225, 285,  'after '.($endtime-$starttime).' seconds', $text_color);
imagepng($im);
imagedestroy($im);