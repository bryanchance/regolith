
        # Deal with Add-ons Manager Integration
        # Figure out if we are requesting something for the Add-ons Manager

        location ~* ^/integration/addon-manager/internal/discover {
            return 302 http://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/?component=discover;
        }

        # AUS in Tycho does not seem to like location blocks with returns as the parser seems to error out on a
        # momenterary nginx status html instead of checking the final responce as 26 and older does.
        # This may be due to the security policy bs regarding orgin nonsense. Either way this solution works and is backwards compatible with 26 and older.
        # There may need to be additional location/return logic that needs to use old style rewrite to succeed. Thus far AUS is the only picky one.
        rewrite ^/integration/addon-manager/internal/update https://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/?component=aus&$args redirect;

        # Send 'internal' Add-ons Manager requests to API
        location ~* ^/integration/addon-manager/internal/(get|recommended|search) {
            return 302 https://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/?component=integration&type=internal&request=$1&$args;
        }

        # Send 'external' Add-ons Manager requests to API
        location ~* ^/integration/addon-manager/external/(recommended|searchplugins|themes|search|devtools) {
            return 302 https://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/?component=integration&type=external&request=$1&$args;
        }

        location ~* ^/(firefox|resources)/incompatible {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/incompatible/;
        }

        location ~* ^/more/search-plugins {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/search-plugins/;
        }

        location ~* ^/extensions/category/all/$ {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/extensions/;
        }

        location ~* ^\/extensions\/category\/(.*)/$ {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/extensions/$1/;
        }

        # See Phoebus 32b839c8844df8d1e8b546d12bc645349d16c668 for not catgeory redirect to /addon

        location ~* ^/themes/complete/$ {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/themes/;
        }

        location ~* ^/(extensions|themes)/(.*)/(.*)/ {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/addon/$3/;
        }

        location ~* ^/themes/(.*)/$ {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/addon/$1/;
        }

        location ~* ^/phoebus/datastore/pm-admin/(.*) {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/datastore/pm-admin/$1;
        }

        # Directories virtual or otherwise should have a trailing slash
        rewrite ^([^.]*[^/])$ $1/ redirect;
        
        # Some block I can't remember why I set.. Likely to avoid caching..
        # Could be reduced to JUST XPI because XPI files pulled from cache have no sec info and tend to die
        location ~*  \.(jpg|jpeg|png|gif|ico|css|js|xml|xpi)$ {
            expires -1;
        }

        # Don't allow access to any file or folder starting with just a dot
        # Also, don't allow any execution of php from inside the datastore
        location ~* (\/(\.(.*)|(phoebus|datastore)\/(.*)\.(php|tpl|xhtml)$)) {
            log_not_found off; return 404;
        }

        location ~* ^\/datastore/(.*)\.xpi$ {
            internal;
        }
