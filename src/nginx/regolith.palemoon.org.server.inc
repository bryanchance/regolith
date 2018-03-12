
        # Deal with Add-ons Manager Integration
        location ~* /phpmyadmin/ {
            auth_basic "Regolith";
            auth_basic_user_file /regolith/secure/htpasswd/regolith-admin.htpasswd;
            try_files $uri/ $uri =404;
            
#ifdef NGX_ENABLE_PHP
            location ~ \.php$ {
                include /@AURA_USER_NAME@/config/nginx/standard-php.inc;
#ifndef NGX_ENABLE_PHP_404
                fastcgi_intercept_errors on;
                error_page 404 = @404;
                error_page 501 = @501;
#endif
#ifdef PHP_VERSION_70
                fastcgi_pass 127.0.0.1:@AURA_USER_PORT9@;
#else
                fastcgi_pass unix:/var/run/aura-@AURA_USER_CLASS@-@AURA_USER_NAME@-php.socket;
#endif
            }
#endif
        }