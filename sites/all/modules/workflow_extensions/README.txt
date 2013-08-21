
DESCRIPTION
===========
When using Workflow and/or Rules this module comes in handy to help you realise
some common use case scenarios and to spruce up your Workflow interface.
As far as the UI goes this module replaces the traditional workflow radio
buttons by either a drop-down or single-action buttons. The latter feature
context-sensitive labels, potentially employing replacement tokens, if desired,
for a more intuitive user experience. For further flexibility all three UI
styles (radio, drop-down or single-action buttons) are available as a block.

The module also defines some extra tokens that may be used with Rules to invoke
actions, like sending reminder emails, when content was NOT updated or a
workflow did NOT transition state for some time. Using these tokens you won't
need PHP snippets.

Let's say we have a basic workflow with states "draft", "review" and "live".
Traditionally authors and moderators must select the next state by pressing
the correct radio-button and clicking submit. Experience from the field
suggests that not everybody finds this intuitive. Rather than having to think
in terms of state transitions, users prefer to press a button with a an
explanatory label that clearly expresses what is going to happen.
Using this module authors will find on their edit forms clearly labeled buttons,
for instance "Save as draft, don't submit" and "Submit for publication".
In old workflow-speak "Submit for publication" was represented by radio buttons
plus a submit button which would read less intuitively as: transition workflow
state from "draft" to "review".

With this module moderators will see on their edit form buttons like "Reject and
return to author John" (i.e. "review -> draft") and "Publish this" or "Go live
with this!" ("review -> live").
NOTE: requires the Workflow Named Transitions module to be available in D7.

This module also defines a replacement token [node:workflow-state-age], which
when used in a scheduled rule set, makes it easier to invoke actions when
a workflow state NOT transitioned after a specified elapsed time. No PHP code
is required when using this token.
See drupal.org/project/workflow_extensions for full instructions on how
to do this using Rules.

INSTALLATION
============
Installation is like any other module. Uncompress the .tar.gz file and drop it
into the "sites/all/modules" subdirectory.
Visit Administer >> Site building >> Modules, tick the box in front of the
module name and press "Save configuration".
Or use drush.
For full control over the labels to put on your workflow buttons also install
Workflow Named Transitions.

CONFIGURATION
=============
With the Token module installed you may use replacement tokens in your custom
labels, for instance:
  "Reject submission, return to [node:author]" or
  "Transition to [workflow:workflow-name]: [workflow:workflow-new-state-name]"

In addition, there are a couple of self-explanatory configuration options at
Administer >> Site configuration >> Workflow extensions and one permission
at Administer >> User management >> Permissions.

If you have Views enabled, a "Workflow dashboard" menu item will appear in the
navigation menu. This View displays on a single page workflow state transition
forms for all nodes on your system that are subject to workflow. Naturally
you can modify and extend this View to your heart's content.

Finally, this module also makes the state change form used on the Workflow tab
available as a block, giving you more control over where users may change
workflow state. A use-case is a trouble-ticket system, whereby operators can
view the ticket status AND update it on the same page, minimising clicks.
Using the block visibility controls you may place the block on any page that
provides a node context, typically the node/* pages, or more specifically the
node view page. To prevent the Edit and other tabs from also displaying the
block tick "Show if the following PHP code returns TRUE" and enter:

  <?php return !arg(2); ?>

If your theme does not have any block regions to suit your esthetic
requirements, you can instead insert the line below in the node.tpl.php file of
your theme, for instance immediately above (or below) the line containing
"print $content;":

  <?php if (!$teaser) print workflow_extensions_change_state_form($node); ?>

Workflow comments, optional in the Workflow module, may be made mandatory at
the Adminisiter >> Configuration >> Workflow extensions page.

The permission to edit workflow log comments after they've been entered may
be set at Administer >> User management >> Permissions. This 'edit workflow log'
permission comes into play in the Workflow History view, available via the
navigation menu, if you have the Views module enabled. The Workflow History view
presents an edit link for each workflow log comment, provided the user has the
'edit workflow log' permission.

USAGE
=====
Users will find that the workflow radio buttons previously used to instigate
state transitions are now replaced by either a drop-down selector or by more
intuitive single-action buttons, as configured by you at Site configuration >>
Workflow extensions
This applies to the node edit and comment forms, as well as the Workflow tab
node/%/workflow, if enabled at Administer >> Site building >> Workflow >> edit,
section "Workflow tab permissions". It also applies to the "Workflow change
state form" block introduced by this module.

UNINSTALL
=========
Disable and uninstall as per normal at Administer >> Site building >> Modules.
