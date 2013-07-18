CONTENTS OF THIS FILE
=====================

* Introduction
* Installation
* Usage
* Related modules
* Troubleshooting
* Maintainers

Introduction
============
The freelinking module implements a filter for the easier creation of HTML
links to other pages in the site or external sites with a wiki style format
such as [[pluginname:identifier]].

For example: [[nodetitle:page one]] becomes:
<a href="/node/1" title="page one" class="freelink freelink-nodetitle freelink-internal">page one</a>

There are plenty of plugins to use (Google search, Drupal search, Drupal
projects, Wikipedia...) and there is an API to add new plugins. Read PLUGIN.txt
for more instructions regarding how to add new plugin.

Installation
===========
1. Download and enable the module.
2. Optionally configure the module at admin/config/content/freelinking
3. Go to Configuration > Text Formats and activate Freelinking filter at Filtered HTML
   and Full HTML filters.
4. Clean the cache.
5. Edit a node or open a new one and type in the body the above example to verify that
   it works.

Usage
=====
Normally you will type [[pluginname:target|title]]. The title is optional and if you
do not specity a plugin name the default one configured at Freelinking Settings page will be used.

Here is an example of each plugin:

Nodetitle: [[nodetitle:First page]] becomes
<a class="freelink freelink-nodetitle freelink-internal" title="node/1" href="/node/1">test</a>

Drupal.org project: [[drupalproject:freelinking]] becomes
<a class="freelink freelink-drupalproject freelink-external"
  href="http://drupal.org/project/freelinking">freelinking</a>

Drupal.org nid: [[drupalorgnid:1]] becomes
<a class="freelink freelink-drupalorgnid freelink-external"
  href="http://drupal.org/node/1">Drupal.org: "About Drupal"</a>

Search: [[search:test]] becomes
<a class="freelink freelink-search freelink-internal" title="search/node/test"
  href="/search/node/test">test</a>

Node nid: [[nid:2]] becomes
<a class="freelink freelink-nid freelink-internal" title="node/2" href="/node/2">First page</a>

Google search: [[google:drupal]] becomes
<a class="freelink freelink-google freelink-external" title="http://www.google.com/search"
  href="http://www.google.com/search?q=drupal&hl=en">Google Search "drupal"</a>

File: [[file:logo.png]] becomes
<a class="freelink freelink-file freelink-internal"
  href="http://drupal7.localhost/sites/drupal7.localhost/files/logo.png">logo.png</a>

Wikisource, Wiktionary, Wikibooks, Wikinews and Wikipedia: [[wikipedia:Main Page]] becomes
<a class="freelink freelink-wikipedia freelink-external"
  href="http://en.wikipedia.org/wiki/Main_Page">Main_Page</a>

User profile: [[u:1]] becomes
<a class="freelink freelink-user freelink-internal" title="user/1" href="/user/1">admin</a>

Related modules
===============
* Freelinking offers a Freelinking Prepopulate submodule that provides a "create node"
  plugin. Nodetitle may use this to provide links to create content that does
  not exist. This submodule requires Prepopulate.
* Freelinking for casetracker adds a plugin "case" to provide a detailed status of a case tracker case.
  http://drupal.org/project/freelinking_casetracker

Troubleshooting
==============
If you do not see freelinking working at all. There must be some conflict with other input
formats. Try first to disable all other input formats and only leave Freelinking activated.
Clean the cache and then test editing a node with a freelink and save it. If it works, try
adding other input formats until you get to the right order in which they have to be in
order to work correctly.

Maintainers
===========
* eafarris <eafarris@gmail.com> (Original Creator)
* grayside <grayside@gmail.com>
* juampy   http://drupal.org/user/682736
