-- SUMMARY --

  Drupal utilizes draggable tables to handle multiple value forms. It's quite convenient
  for most simple field types. However, for complex field types such form can be cumbersome.
  For example, widget for Image field type can contain preview of a file, upload button, text field for title
  and alt attributes. Sometimes you have a lot of images to be uploaded and the form takes up a lot of space.

  This module integrates the jQuery UI plugins as a replacement for draggable tables
  to make multiple value forms more user friendly.

-- INSTALLATION --

  Install as usual, see http://drupal.org/node/895232 for further information.

-- CONFIGURATION --

  You should enable accordion multiple value widget on the field settings page.
  For example, for nodes it's something like
  admin/structure/types/manage/NODE_TYPE/fields/FIELD_NAME

-- MAINTAINERS --

  Chi - http://drupal.org/user/556138
