# file      : buildfile
# license   : curl License; see accompanying COPYING file

# Glue buildfile that "pulls" all the packages.

import pkgs = {*/ -upstream/}
./: $pkgs
