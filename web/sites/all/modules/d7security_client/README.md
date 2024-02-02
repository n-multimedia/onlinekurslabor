# D7Security Client

This module allows Drupal 7 site maintainers to get update status information about modules that are unsupported on drupal.org but are supported by the D7Security team at <https://gitlab.com/d7security/d7security> .

It replaces the URLs for fetching update status XML for a list of modules
at <https://gitlab.com/d7security/d7security/-/blob/main/supported_projects.txt> .

Please report any issues for this module at <https://gitlab.com/d7security/d7security_client>

Check the [D7Security wiki](https://gitlab.com/d7security/d7security/-/wikis/home) for more documentation.

## Checking unpackaged contrib modules

It is important that all contrib projects on your Drupal 7 site have the "project" key set in their info files. Otherwise the Update module will not check if updates are available.

The D7Security client module can help you get notifications about such enabled unpackaged modules. Set the variable `d7security_client_check_missing_project_info` to `1`, for example with drush:

```sh
drush vset d7security_client_check_missing_project_info 1 -y
```

If you have a name collision with a custom module that has the same name as a contributed module then you can set the "version" key in your custom module's info file. All modules that have a version set will be ignored.

Add a version like this to the info file:

```ini
; This is a custom module that has the same name as a contrib module. Set the
; version key so that update checking is not performed by the D7Security client
; module.
version = 7.x-1.0
```
