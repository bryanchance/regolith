        # Directories virtual or otherwise should have a trailing slash
        rewrite ^([^.]*[^/])$ $1/ redirect;
        
        # Some block I can't remember why I set.. Likely to avoid caching..
        # Could be reduced to JUST XPI because XPI files pulled from cache have no sec info and tend to die
        location ~*  \.(jpg|jpeg|png|gif|ico|css|js|xml|xpi)$ {
            expires -1;
        }

        # Do not allow access to any file or folder starting with just a dot
        location ~* (\/\.(.*)) {
            log_not_found off; return 404;
        }
        
        # Only allow access to specific file extensions from inside the datastore
        location ~* (\/datastore\/(.*)\.(?!(xpi|png|xml|rdf)$)) {
            log_not_found off; return 404;
        }

        location ~* ^\/datastore/(.*)\.xpi$ {
            internal;
        }
