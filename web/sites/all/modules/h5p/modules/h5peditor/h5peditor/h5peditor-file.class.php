<?php

class H5peditorFile {

  private $result, $field, $files_directory, $interface;

  public $type, $name, $path, $mime, $size;

  function __construct($interface, $files_directory) {
    $field = filter_input(INPUT_POST, 'field', FILTER_SANITIZE_STRING, FILTER_FLAG_NO_ENCODE_QUOTES);

    // Check for file upload.
    if ($field === NULL || empty($_FILES) || !isset($_FILES['file'])) {
      return;
    }

    $this->interface = $interface;

    // Create a new result object.
    $this->result = new stdClass();

    // Set directory.
    $this->files_directory = $files_directory;

    // Create the temporary directory if it doesn't exist.
    $dirs = array ('', '/files', '/images', '/videos', '/audios');
    foreach ($dirs as $dir) {
      if (!H5PDefaultStorage::dirReady($this->files_directory . $dir)) {
        $this->result->error = $this->interface->t('Unable to create directory.');
        return;
      }
    }

    // Get the field.
    $this->field = json_decode($field);

    // Check if uploaded base64 encoded file
    if (isset($_POST) && isset($_POST['dataURI']) && $_POST['dataURI'] !== '') {
      $data = $_POST['dataURI'];

      // Extract data from string
      list($type, $data) = explode(';', $data);
      list(, $data)      = explode(',', $data);
      $this->data = base64_decode($data);

      // Extract file type and extension
      list(, $type) = explode(':', $type);
      list(, $extension) = explode('/', $type);
      $this->type = $type;
      $this->extension = $extension;
      $this->size = strlen($this->data);
    }
    else {

      // Handle temporarily uploaded form file
      if (function_exists('finfo_file')) {
        $finfo = finfo_open(FILEINFO_MIME_TYPE);
        $this->type = finfo_file($finfo, $_FILES['file']['tmp_name']);
        finfo_close($finfo);
      }
      elseif (function_exists('mime_content_type')) {
        // Deprecated, only when finfo isn't available.
        $this->type = mime_content_type($_FILES['file']['tmp_name']);
      }
      else {
        $this->type = $_FILES['file']['type'];
      }

      $this->extension = pathinfo($_FILES['file']['name'], PATHINFO_EXTENSION);
      $this->size = $_FILES['file']['size'];
    }
  }

  /**
   *
   * @return boolean
   */
  public function isLoaded() {
    return is_object($this->result);
  }

  /**
   * Check current file up agains mime types and extensions in the given list.
   *
   * @param array $mimes List to check against.
   * @return boolean
   */
  public function check($mimes) {
    $ext = strtolower($this->extension);
    foreach ($mimes as $mime => $extension) {
      if (is_array($extension)) {
        // Multiple extensions
        if (in_array($ext, $extension)) {
          $this->type = $mime;
          return TRUE;
        }
      }
      elseif (/*$this->type === $mime && */$ext === $extension) {
        // TODO: Either remove everything that has to do with mime types, or make it work
        // Currently we're experiencing trouble with mime types on different servers...
        $this->type = $mime;
        return TRUE;
      }
    }
    return FALSE;
  }

  /**
   * Validate the file.
   *
   * @return boolean
   */
  public function validate() {
    if (isset($this->result->error)) {
      return FALSE;
    }

    // Check for field type.
    if (!isset($this->field->type)) {
      $this->result->error = $this->interface->t('Unable to get field type.');
      return FALSE;
    }

    // Check if mime type is allowed.
    if ((isset($this->field->mimes) && !in_array($this->type, $this->field->mimes)) || substr($this->extension, 0, 3) === 'php') {
      $this->result->error = $this->interface->t("File type isn't allowed.");
      return FALSE;
    }

    // Type specific validations.
    switch ($this->field->type) {
      default:
        $this->result->error = $this->interface->t('Invalid field type.');
        return FALSE;

      case 'image':
        $allowed = array(
          'image/png' => 'png',
          'image/jpeg' => array('jpg', 'jpeg'),
          'image/gif' => 'gif',
        );
        if (!$this->check($allowed)) {
          $this->result->error = $this->interface->t('Invalid image file format. Use jpg, png or gif.');
          return FALSE;
        }

        // Get image size from base64 string
        if (isset($this->data)) {

          if (!function_exists('getimagesizefromstring')) {
            $uri = 'data://application/octet-stream;base64,'  . base64_encode($this->data);
            $image =  getimagesize($uri);
          }
          else {
            $image = getimagesizefromstring($this->data);
          }
        }
        else {
          // Image size from temp file
          $image = @getimagesize($_FILES['file']['tmp_name']);
        }

        if (!$image) {
          $this->result->error = $this->interface->t('File is not an image.');
          return FALSE;
        }

        $this->result->width = $image[0];
        $this->result->height = $image[1];
        $this->result->mime = $this->type;
        break;

      case 'audio':
        $allowed = array(
          'audio/mpeg' => 'mp3',
          'audio/mp3' => 'mp3',
          'audio/x-wav' => 'wav',
          'audio/wav' => 'wav',
          //'application/ogg' => 'ogg',
          'audio/ogg' => 'ogg',
          //'video/ogg' => 'ogg',
        );
        if (!$this->check($allowed)) {
          $this->result->error = $this->interface->t('Invalid audio file format. Use mp3 or wav.');
          return FALSE;

        }

        $this->result->mime = $this->type;
        break;

      case 'video':
        $allowed = array(
          'video/mp4' => 'mp4',
          'video/webm' => 'webm',
         // 'application/ogg' => 'ogv',
          'video/ogg' => 'ogv',
        );
        if (!$this->check($allowed)) {
          $this->result->error = $this->interface->t('Invalid video file format. Use mp4 or webm.');
          return FALSE;
        }

        $this->result->mime = $this->type;
        break;

      case 'file':
        // TODO: Try to get file extension for type and check that it matches the current extension.
        $this->result->mime = $this->type;
    }

    return TRUE;
  }

  public function copy() {
    $matches = array();
    preg_match('/([a-z0-9]{1,})$/i', $_FILES['file']['name'], $matches);

    $this->name = uniqid($this->field->name . '-');

    // Add extension to name
    if (isset($this->data)) {
      $this->name .= '.' . $this->extension;
    }
    else if (isset($matches[0])) {
      $this->name .= '.' . $matches[0];
    }

    $this->name = $this->field->type . 's/' . $this->name;
    $this->path = $this->files_directory . '/' . $this->name;

    // Save file to path
    if (isset($this->data)) {
      // Store base64 file to new path
      if (file_put_contents($this->path, $this->data) == FALSE) {
        $this->result->error = $this->interface->t('Could not save file.');
      }
    }
    else {
      // Copy tmp file to new path
      if (!copy($_FILES['file']['tmp_name'], $this->path)) {
        $this->result->error = $this->interface->t('Could not copy file.');
        return FALSE;
      }
    }

    $this->result->path = $this->name;
    return TRUE;
  }

  public function getResult() {
    return json_encode($this->result);
  }
}
