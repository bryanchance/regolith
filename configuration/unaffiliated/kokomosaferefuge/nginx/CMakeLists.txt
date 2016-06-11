mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# Userscope Nginx systemd Service
pyPreprocess(
    ${mk_depth}/aura/templates/nginx/nginx.service.in
    aura-${varUserClass}-${varUserName}-nginx.service
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
)

# Userscope Nginx Server Instance
pyPreprocess(
    ${mk_depth}/aura/templates/nginx/nginx.conf.in
    nginx.conf
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_IPV4="${varSystemIPv4}"
    -DAURA_IPV6="${varSystemIPv6}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
)

# Proxy file for kokomosaferefuge.org
set(varDomain "kokomosaferefuge.org")
pyPreprocess(
    ${mk_depth}/aura/templates/nginx/standard.proxy.in
    www.${varDomain}.proxy
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_IPV4="${varSystemIPv4}"
    -DAURA_IPV6="${varSystemIPv6}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_MAINDOMAIN=1
)

# VHOST for susantobinart.com
set(varSubdomain "www")
set(varRootDomain "kokomosaferefuge.org")
set(varDomain ${varRootDomain})
pyPreprocess(
    ${mk_depth}/aura/templates/nginx/standard.vhost.in
    www.${varDomain}.vhost
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
    -DNGX_ENABLE_PHP=1
    -DNGX_ENABLE_WORDPRESS=1
    -DPHP_VERSION_56=1
)