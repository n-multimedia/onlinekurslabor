Context Redirect provides a "Reaction" for the Context module which redirects to
a configurable internal or external url when the context conditions are met.
The type of redirect issued (301, 302, 303 or 307) can be configured through the
context UI.

The module is very lightweight and is little more than a wrapper around the core
drupal_goto() function for the Context API.

## Comparison with other Drupal modules ##

Context cannot be used to register new paths within Drupal; it can only react to
conditions that have been met for the current user visiting a path that already
exists. If you just want to redirect from a new path to another you could
register the path with Drupal using some method outside of the Context API and
then use Context to perform the redirect but it is (usually) much more elegant
to simply register the path as a redirect in the first place.

If you're not comfortable writing custom code or the hook system (specifically
hook_menu) then check out the Page Manager Redirect module which can handle this
for you, alternatively Panels can achieve the same thing.

If you want to perform redirects for existing paths based on more complicated
conditions than just the current url then, in general, those page callback based
modules won't be flexible enough.

Without writing custom code, using robust and popular contrib modules you're
left with only Rules and/or Context. For the sake of triggering redirects
both modules will work almost identically under the hood so use whichever suits
your current needs best.

## Caveats ##

If your site is only using Drupal core caching, configured entirely through
the Performance configuration screen you can skip this section.

Context is fundamentally a PHP framework for checking existing conditions and
reacting to them. It does this though Drupal's system of "hooks" that have
always provided this functionality for developers writing their own code, but
with a nice point-and-click interface to make it accessible to a wider audience.
In this way Context is very similar to the Rules module.

Because Context is built on hooks it is a flexible and powerful way to manage
redirects. It allows the site builder to react to more subtle conditions
than just a path. For example, a user visiting the home page with a specific
role can be detected and redirected easily.

Unfortunately, redirects triggered by hooks are in danger of being bypassed
completely when Drupal and/or the server environment is configured so that hooks
are not triggered if the current page is cached. This is not the default
configuration of Drupal, you need very specific skills and knowledge to create
this problem for yourself - you should know who you are :P.

Redirects from this module will fail if ALL of the following conditions are met:

- The condition that triggers the redirect will be met by some anonymous users
  but not other.
- The current Drupal site has "fast cache" page caching or equivalent enabled.
  The most common ways of achieving this are:
  => Using the Boost module
  => Manually setting the 'page_cache_invoke_hooks' variable to FALSE in
     settings.php and enabling page caching
  => Installing a server based html cache like Varnish that can bypass Drupal
     completely.
  => Using "Aggressive" page caching in Drupal 6
- The current page is cached
- The cached version of this page is not a redirect, or redirects to the wrong
  url.

A practical example that meets all of these conditions would be a site with
Boost enabled that is attempting to redirect only those anonymous users that
view the site with mobile devices.

Generally though, if all of these conditions are met and you're expecting a PHP
based redirect to work reliably you probably need to rethink your site
architecture and use a server config or client (javascript) based redirection.