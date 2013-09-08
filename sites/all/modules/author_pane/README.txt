
CONTENTS OF THIS FILE
-----------------------------------------------------------------------------------------
 * Introduction
 * Installation
 * Usage

INTRODUCTION
-----------------------------------------------------------------------------------------
Author Pane (http://drupal.org/project/author_pane) provides information about the author
of a node, comment, or page. From core, it collects the user picture, name, join
date, online status, contact link, and profile information. In addition, it gathers data
from many user related contributed modules and puts it together in a modifiable template
file.

INSTALLATION
-----------------------------------------------------------------------------------------
1. Copy the entire author_pane module directory into your normal directory for modules,
   usually sites/all/modules.

2. Enable the Author Pane module in ?q=admin/build/modules.

USAGE
-----------------------------------------------------------------------------------------
Advanced Forum:
If you have Advanced Forum installed, it will make use of Author Pane automatically on
forum posts. Advanced Forum provides its own Author Pane template and CSS so it can be
styled specifically for use in the forums.

Advanced Profile Kit:
If you have Advanced Profile Kit installed, it will make use of Author Pane automatically
on the default user page variant. Advanced Profile Kit provides its own Author Pane
template so it can be styled specifically for use on profile pages. Please note that if
you remove and re-add the Author Pane content type, you will need to edit the pane
settings and put "advanced_profile" back in the "Caller" field.

CTools content pane:
If you have Page Manager (from CTools) installed, you can add the Author Pane content
pane to any page variant. It requires the user context. You can choose an imagecache
preset to use for the user picture. You can also use the "caller" field to give this
instance a unique ID that can be accessed from the preprocess functions and the template
file.

Block:
There is an Author Pane block provided that you can enable. The block will show up on
user/NN, blog/NN, and node/NN where the node type is one that you allow in the block
config. If you want to exclude it from one of those page types, use the core block
visibility option. Exclusion of the /edit page happens automatically. 

The block is disabled by default and must be enabled. Further options are available by
configuring the block:

* Node types to display on - Check on which node types the block should be shown. The
  block will show in the region it is placed, not literally on the node, and only on
  full node view pages. (ie: node/42 not when the node is part of a view)

* User picture preset - This is the Imagecache preset that will be used to format the
  user picture. Leave blank to show the full sized picture. Requires Imagecache module.

Theme function:
You can call the theme function directly and print the author pane anywhere in your code.
You must have a fully loaded user object to pass into the function. The rest of the
parameters are optional.

<?php
print theme('author_pane', $account, $caller, $picture_preset, $context, $disable_css);
?>

Parameters:
$account - The fully loaded user object. If all you have is a UID, you can get the object
with $account = user_load($uid); where $uid is a variable holding the user id.

$caller - (optional) This is an ID you can pass in as a way to track who is calling the
function. If you use Author Pane on your user profiles, on your blog pages, and in your
forums, you may want to display slightly different information in each Author Pane. By
passing in the caller, you can tell from within the preprocess functions where this is
going to be displayed.

$picture_preset - (optional) This is an imagecache picture preset that, if given, and
if imagecache is enabled, will be used to size the user picture on the author pane.

$context - (optional) This is usually a node or comment object and gives the context of
where the Author Pane has been placed so information from that context is available to
the template and preprocesses.

$disable_css - (optional) Because the Author Pane preprocess gets called after the code
that calls it, the Author Pane CSS file will be loaded last and clobber any earlier CSS.
This option tells Author Pane not to load its CSS so it uses the CSS of the caller. This
is mainly intended for Advanced Forum because the styles include Author Pane styling but
can be used for custom purposes as well.







