
        # Deal with Add-ons Manager Integration
        # Figure out if we are requesting something for the Add-ons Manager

        location ~* ^/integration/addon-manager/internal/discover {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/?component=discover;
        }

        location ~* ^/integration/addon-manager/internal/update {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/?component=aus&$args;
        }

        # Send 'internal' Add-ons Manager requests to API
        location ~* ^/integration/addon-manager/internal/(get|recommended|search) {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/?component=integration&type=internal&request=$1&$args;
        }

        # Send 'external' Add-ons Manager requests to API
        location ~* ^/integration/addon-manager/external/(recommended|searchplugins|themes|search|devtools) {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/?component=integration&type=external&request=$1&$args;
        }
        
        # Deal with permaxpi requests
        # This is used by the migration wizard
        location ~* /permaxpi/(.*) {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/?component=download&id=permaxpi-$1;
        }

        # Directories virtual or otherwise should have a trailing slash
        rewrite ^([^.]*[^/])$ $1/ redirect;

        # URL Changes
        location ~* ^/(firefox|resources)/incompatible/ {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/incompatible/;
        }
        
        location ~* ^/more/search-plugins/ {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/search-plugins/;
        }

        location ~* ^/extensions/(alerts-and-updates|appearance|download-management|feeds-news-and-blogging|privacy-and-security|search-tools|social-and-communication|web-development|other)/(.*) {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/extensions/$2;
        }
        
        location ~* ^/themes/complete(\/(.*)|\/) {
            return 302 $http_x_real_scheme://@NGX_SUBDOMAIN@.@NGX_ROOTDOMAIN@/themes/$2;
        }
        
        location /feed {
            return 302 http://forum.palemoon.org/feed.php?f=44&t=6144;
        }

        # Some block I can't remember why I set.. Likely to avoid caching..
        # Could be reduced to JUST XPI because XPI files pulled from cache have no sec info and tend to die
        location ~*  \.(jpg|jpeg|png|gif|ico|css|js|xml|xpi)$ {
            expires -1;
        }
        
        # Don't allow access to any file or folder starting with just a dot
        # Also, don't allow any execution of php from inside the datastore
        location ~* ^\/(\.|(phoebus|datastore)\/(.*)\.php$) {
            log_not_found off; return 404;
        }