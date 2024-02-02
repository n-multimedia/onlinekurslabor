## [HTML Mail](https://www.drupal.org/project/htmlmail)
Lets you theme your messages the same way you theme the rest of your website.

### [Requirement](http://www.dict.org/bin/Dict?Form=Dict2&Database=*&Query=requirement)

*   [Mail System 7.x-2.x](https://www.drupal.org/project/mailsystem)

### [Installation](https://www.drupal.org/documentation/install/modules-themes/modules-7)

The following additional modules, while not required, are highly recommended:

*   [Echo](https://www.drupal.org/project/echo)

    :   Wraps your messages in a drupal theme.  Now you can "brand" your
         messages with the same logo, header, fonts, and styles as your website.

*   [Emogrifier](https://www.drupal.org/project/emogrifier)

    :   Converts stylesheets to inline style rules, for consistent display on
        mobile devices and webmail.

*   [Mail MIME](https://www.drupal.org/project/mailmime)

    :   Provides a text/plain alternative to text/html emails, and automatically
        converts image references to inline image attachments.

*   [Pathologic](https://www.drupal.org/project/pathologic)

    :   Converts urls from relative to absolute, so clickable links in your
        email messages work as intended.

*   [Transliteration](https://www.drupal.org/project/filter_transliteration)

    :   Converts non-ASCII characters to their US-ASCII equivalents, such
        as from Microsoft "smart-quotes" to regular quotes.

    :   *Also available as a [patch](https://www.drupal.org/node/1095278#comment-4219530).*

### [Updating from previous versions](https://www.drupal.org/node/250790)

The [7.x-2.x](https://www.drupal.org/node/1106064) branch shares 94% of its code
with the [6.x-2.x](https://www.drupal.org/node/1119548) branch, but only 15% of
its code with the [7.x-1.x](https://www.drupal.org/node/355250) branch, and a tiny
8% of its code with the [6.x-1.x](https://www.drupal.org/node/329828) branch.

Let your compatibility expectations be adjusted accordingly.

*   Check the module dependencies, as they have changed.  The latest version of
    [HTML Mail](https://www.drupal.org/project/htmlmail) depends on the
    [Mail System](https://www.drupal.org/project/mailsystem) module (7.x-2.2 or later)
    and will not work without it.

*   Run `update.php` *immediately* after uploading new code.

*   The user-interface for adding email header and footer text has been removed.
    Headers and footers may be added by template files and/or by enabling the
    [Echo](https://www.drupal.org/project/echo) module.

*   Any customized filters should be carefully tested, as some of the template
    variables have changed.  Full documentation is provided both on the module
    configuration page (Click on the <u>Instructions</u> link) and as comments
    within the `htmlmail.tpl.php` file itself.

*   The following options have been removed from the module settings page.  In
    their place, any combination of
    [over 200 filter modules](https://www.drupal.org/project/modules/?filters=type%3Aproject_project%20tid%3A63%20hash%3A1hbejm%20-bs_project_sandbox%3A1%20bs_project_has_releases%3A1)
    may be used to create an email-specific
    [text format](https://www.drupal.org/node/778976)
    for post-template filtering.

    *   [Line break converter](https://api.drupal.org/api/drupal/modules%21filter%21filter.module/function/_filter_autop/7.x)
    *   [URL Filter](https://api.drupal.org/api/drupal/modules%21filter%21filter.module/function/_filter_url/7.x)
    *   [Relative Path to Absolute URLs](https://www.drupal.org/project/rel_to_abs)
    *   [Emogrifier](http://www.pelagodesign.com/sidecar/emogrifier/)
    *   [Token support](https://www.drupal.org/project/token)

*   Full MIME handling, including automatic generation of a plaintext
    alternative part and conversion of image references to inline image
    attachments, is available simply by enabling the
    [Mail MIME](https://www.drupal.org/project/mailmime) module.

### [Configuration](https://www.drupal.org/files/images/htmlmail_settings_2.thumbnail.png)

Visit the [Mail System](https://www.drupal.org/project/mailsystem) settings page at
<u>admin/config/system/mailsystem</u>
to select which parts of Drupal will use
[HTML Mail](https://www.drupal.org/project/htmlmail)
instead of the
[default](https://api.drupal.org/api/drupal/modules%21system%21system.mail.inc/class/DefaultMailSystem/7.x)
[mail system](https://api.drupal.org/api/drupal/includes%21mail.inc/function/drupal_mail_system/7.x).

Visit the [HTML Mail](https://www.drupal.org/project/htmlmail) settings page at
<u>admin/config/system/htmlmail</u>
to select a theme and post-filter for your messages.

### [Theming](https://www.drupal.org/documentation/theme)

The email message text goes through three transformations before sending:

1.  <h3>Template File</h3>

    A template file is applied to your message header, subject, and body text.
    The default template is the included `htmlmail.tpl.php` file.  You may copy
    this file to your <cite>email theme</cite> directory (selected below), and
    use it to customize the contents and formatting of your messages. The
    comments within that file contain complete documentation on its usage.

2.  <h3>Theming</h3>

    You may choose a theme that will hold your templates from Step 1 above. If
    the [Echo](https://www.drupal.org/project/echo) module is installed, this theme
    will also be used to wrap your templated text in a webpage.  You use any one
    of [over 800](https://www.drupal.org/project/themes) themes to style your
    messages, or [create your own](https://www.drupal.org/documentation/theme) for
    even more power and flexibility.

3.  <h3>Post-filtering</h3>

    You may choose a
    [text format](https://www.drupal.org/node/778976)
    to be used for filtering email messages *after* theming.
    This allows you to use any combination of
    [over 200 filter modules](https://www.drupal.org/project/modules/?filters=type%3Aproject_project%20tid%3A63%20hash%3A1hbejm%20-bs_project_sandbox%3A1%20bs_project_has_releases%3A1)
    to make final changes to your message before sending.

    Here is a recommended configuration:

    *   [Emogrifier](https://www.drupal.org/project/emogrifier)
        Converts stylesheets to inline style rules for consistent display on
        mobile devices and webmail.

    *   [Transliteration](https://www.drupal.org/project/filter_transliteration)
        Converts non-ASCII text to US-ASCII equivalents.  This helps prevent
        Microsoft "smart-quotes" from appearing as question-marks in
        Mozilla Thunderbird.

    *   [Pathologic](https://www.drupal.org/project/pathologic)
        Converts relative URLS to absolute URLS so that clickable links in
        your message will work as intended.

### Troubleshooting
 
*   Check the [online documentation](https://www.drupal.org/node/1124376),
    especially the [screenshots](https://www.drupal.org/node/1124934).

*   There is a special documentation page for
    [Using HTML Mail together with SMTP Authentication Support](https://www.drupal.org/node/1200142).

*   [Simplenews](https://www.drupal.org/project/simplenews) users attempting advanced
    theming should read [this page](https://www.drupal.org/node/1260178).

*   Double-check the [Mail System](https://www.drupal.org/project/mailsystem)
    module settings and and make sure you selected
    <u><code>HTMLMailSystem</code></u> for your
    <u>Site-wide default mail system</u>.

*   Try selecting the <u><code>[ ]</code> *(Optional)* Debug</u> checkbox
    at the [HTML Mail](https://www.drupal.org/project/htmlmail) module
    settings page and re-sending your message.

*   Clear your cache after changing any <u><code>.tpl.php</code></u>
    files.

*   If you use a post-filter, make sure your filter settings page looks like
    [this](https://www.drupal.org/node/1130960).

*   Visit the [issue queue](https://www.drupal.org/project/issues/htmlmail)
    for support and feature requests.

### Related Modules

**Echo**
:   https://www.drupal.org/project/echo

**Emogrifier**
:   https://www.drupal.org/project/emogrifier

**HTML Purifier**
:   https://www.drupal.org/project/htmlpurifier

**htmLawed**
:   https://www.drupal.org/project/htmlawed

**Mail MIME**
:   https://www.drupal.org/project/mailmime

**Mail System**
:   https://www.drupal.org/project/mailsystem

**Pathologic**
:   https://www.drupal.org/project/pathologic

**Transliteration**
:   https://www.drupal.org/project/transliteration

### [Documentation](https://www.drupal.org/project/documentation)
 
**[HTML Mail](https://www.drupal.org/node/1124376)

**[filter.module](https://api.drupal.org/api/drupal/modules%21filter%21filter.module/6.x)**
:   [api.drupal.org/api/drupal/modules%21filter%21filter.module](https://api.drupal.org/api/drupal/modules%21filter%21filter.module/7.x)
:   [api.drupal.org/api/drupal/modules%21filter%21filter.module/group/standard_filters/7](https://api.drupal.org/api/drupal/modules%21filter%21filter.module/group/standard_filters/7.x)

**[Installing contributed modules](https://www.drupal.org/documentation/install/modules-themes/modules-7)**
:   [drupal.org/documentation/install/modules-themes/modules-7](https://www.drupal.org/documentation/install/modules-themes/modules-7)

**[Theming guide](https://www.drupal.org/documentation/theme)**
:   [drupal.org/documentation/theme](https://www.drupal.org/documentation/theme)

### Original Author

*   [Chris Herberte](https://www.drupal.org/user/1171)

### Current Maintainer

*   [Bob Vincent](https://www.drupal.org/user/36148)
