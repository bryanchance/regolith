mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# Userscope Nginx systemd Service
py_pp(${mk_depth}/aura/templates/nginx/nginx.service.in aura-${varUserClass}-${varUserName}-nginx.service -Fsubstitution -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}")

# Userscope Nginx Server Instance
py_pp(${mk_depth}/aura/templates/nginx/nginx.conf.in nginx.conf -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}")

# Proxy file for mattatobin.com
set(varDomain "mattatobin.com")
py_pp(${mk_depth}/aura/templates/nginx/standard.proxy.in www.${varDomain}.proxy -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DNGX_DOMAIN="${varDomain}" -DNGX_MAINDOMAIN=1)

# VHOST for mattatobin.com
set(varSubdomain "www")
set(varRootDomain "mattatobin.com")
set(varDomain ${varRootDomain})
py_pp(${mk_depth}/aura/templates/nginx/standard.vhost.in www.${varDomain}.vhost -Fsubstitution -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DNGX_DOMAIN="${varDomain}" -DNGX_ROOTDOMAIN="${varRootDomain}" -DNGX_SUBDOMAIN="${varSubdomain}" -DNGX_ENABLE_PHP=1 -DNGX_ENABLE_CMSMS=1)

# Proxy file for personal.mattatobin.com
set(varDomain "personal.mattatobin.com")
py_pp(${mk_depth}/aura/templates/nginx/standard.proxy.in ${varDomain}.proxy -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DNGX_DOMAIN="${varDomain}")

# VHOST for personal.mattatobin.com
set(varSubdomain "personal")
set(varRootDomain "mattatobin.com")
set(varDomain "${varSubdomain}.${varRootDomain}")
py_pp(${mk_depth}/aura/templates/nginx/standard.vhost.in ${varDomain}.vhost -Fsubstitution -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DNGX_DOMAIN="${varDomain}" -DNGX_ROOTDOMAIN="${varRootDomain}" -DNGX_SUBDOMAIN="${varSubdomain}" -DNGX_ENABLE_PHP=1)