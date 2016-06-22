		# Eval scheme manually because we have special cases but otherwise do NOT want content served from HTTP
		# This terrible hack is mainly because of a CMSMS quirk and will be resolved fully with Phoebus
		# $https_x_real_scheme is passed from the .proxy file
		if ($http_x_real_scheme = "http") {
			set $varRedirectToHTTPS "true";
		}
		
		# Special case: Do NOT use https for discover page
		if ($uri ~* "/integration/addon-manager/internal/discover") {
			set $varRedirectToHTTPS "false";
		}
		
		# If not on HTTPS then rewrite to HTTPS
		if ($varRedirectToHTTPS = "true") {
			rewrite  ^/(.*)$ https://@NGX_DOMAIN@/$1;
		}

		# Deal with Add-ons Manager Integration
		# Figure out if we are requesting something for the Add-ons Manager
		location ~* /integration/addon-manager/internal/update {
			return 302 https://@NGX_DOMAIN@/phoebus/services/aus/check.php?$args;
		}
		# Send 'internal' Add-ons Manager requests to API
		location ~* ^/integration/addon-manager/internal/(get|recommended|search) {
			return 302 https://@NGX_DOMAIN@/phoebus/services/api/addonsmanager.php?appID=%7B8de7fcbb-c55c-4fbe-bfc5-fc555c87dbc4%7D&scope=internal&request=$1&$args;
		}
		# Send 'external' Add-ons Manager requests to API
		location ~* ^/integration/addon-manager/external/(recommended|search|themes) {
			return 302 https://@NGX_DOMAIN@/phoebus/services/api/addonsmanager.php?appID=%7B8de7fcbb-c55c-4fbe-bfc5-fc555c87dbc4%7D&scope=external&request=$1&$args;
		}
		
		# Deal with permaxpi requests
		# This is used by the migration wizard (Also later by the AUS script and the main site)
		location ~* /permaxpi/(.*) {
			return 302 https://@NGX_DOMAIN@/phoebus/services/api/getxpi.php?scope=permaxpi&id=$1;
		}

		# URL Changes
		location /firefox/incompatible/ {
			return 302 https://@NGX_DOMAIN@/resources/incompatible/;
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
		location ~* ^/(\.|phoebus\/datastore/(.*)\.php$) {
			log_not_found off; return 404;
		}