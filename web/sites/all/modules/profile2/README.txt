
--------------------------------------------------------------------------------
                              Profile2
--------------------------------------------------------------------------------

Maintainers:
 * Wolfgang Ziegler (fago), nuppla@zites.net
 * Joachim Noreiko (joachim), joachim.n+drupal@gmail.com
 * Rick Jones (RickJ), rick@activeservice.uk


This module is designed to be the successor of the core profile module. In
contrast to the core module this module provides a new, fieldable 'profile'
entity - leverage the power of fields!


Installation
-------------

 * Copy the whole profile2 directory to your modules directory and
   activate the module.


Usage
-----

 * Go to /admin/structure/profiles for managing profile types.
 * By default users' profile information is displayed on the
   account view page (/user/X). The relative positioning can be
   controlled using Account Settings -> Manage Display
   (/admin/config/people/accounts/display)

Profile titles
--------------

A new feature in 7.x-1.6 gives each profile an unambiguous title.
Previously, profile titles defaulted to the profile type, which was
ambiguous, and contained other bugs. In this release the default
profile title is "<type> profile for <user>".

This format is a translatable string, so can be easily customised.
If you have locales installed you can use that, otherwise the
String Overrides module provides a simple way to replace text in
the current language.

The string to override is "@type profile for @user". To simulate
the previous behaviour (without the bugs), just use "@type".

Major new release: 7.x.2.x
--------------------------

This release incorporates revisions, in the same style as core node revisions.
It also includes a profile2_diff sub-module to show differences between revisions.
This requires the diff module, and integrates with it, displaying revisions in the
same style. It also co-operates with 7.x.2.x of the User Revision module, providing
a consistent UI for revisions and diffs of user accounts and profiles.

When profile2_diff is installed it adds another sub-tab under the Entities tab
of the Diff settings form (admin/config/content/diff/entities). The only non-field
value that can be selected for diff-ing is the profile title. Enabling this only
makes sense if the option to edit the profile title is enabled (available via the
profile2_page sub-module - see below).

The profile2_diff sub-module also supports viewing changes before saving when editing,
see the Diff module for more details.

--------------------------------------------------------------------------------
                              Profile pages
--------------------------------------------------------------------------------
Maintainers:
 * Wolfgang Ziegler (fago), nuppla@zites.net
 * Rick Jones (RickJ), rick@activeservice.uk

This module provides alternative ways for users to view and edit their profiles.
There are two options, instead of integrating with the user account page.

1. Generate a separate page for users to view and edit their profiles.

2. Display the profile in a separate sub-tab of the account page.
   In this case the editing mode of the profile is unchanged.

These options are mutually exclusive, but are set per profile type, so different
profiles can display in different ways.

New in version 7.x-1.7:
If mode 1 is chosen, there is an addtional option to allow the profile title
to be edited directly in the profile edit form. In this case, the profile
title is displayed directly, and overrides the generated title described above.


Installation
-------------

 * Once profile2 is installed, just enable the "Profile2 pages" sub-module.


Usage
-----
 * The module's options may be enabled per profile-type by checking one of the
   checkboxes "Provide a separate page for editing profiles." or
   "Provide a separate tab for viewing profiles." in the profile type's settings.
 * In the first case, users with sufficient permissions (check user permissions)
   receive a menu item in their user menu, next to the "My account" menu item.
