        rewrite ^([^.]*[^/])$ $1/ redirect;

        location ~* /techcentral/(.*) {
            return 302 http://techcentral.binaryoutcast.com/$1;
        }
        location /software/projects/pm4xp {
            return 302 http://binaryoutcast.com/projects/pm4xp/;
        }