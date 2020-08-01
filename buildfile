# file      : buildfile
# license   : cURL License; see accompanying COPYING file

# Glue buildfile that "pulls" all the packages.

import pkgs = {*/ -upstream/}
./: $pkgs
