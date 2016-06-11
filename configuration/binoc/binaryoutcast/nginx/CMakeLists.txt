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

# Proxy file for binaryoutcast.com
set(varDomain "binaryoutcast.com")
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

# VHOST for binaryoutcast.com
set(varSubdomain "www")
set(varRootDomain "binaryoutcast.com")
set(varDomain ${varRootDomain})
pyPreprocess(
    www.${varDomain}.vhost.in
    www.${varDomain}.vhost
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
)

# Proxy file for techcentral.binaryoutcast.com
set(varDomain "techcentral.binaryoutcast.com")
pyPreprocess(
    ${mk_depth}/aura/templates/nginx/standard.proxy.in
    ${varDomain}.proxy
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_IPV4="${varSystemIPv4}"
    -DAURA_IPV6="${varSystemIPv6}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DNGX_DOMAIN="${varDomain}"
)

# VHOST for techcentral.binaryoutcast.com
set(varSubdomain "techcentral")
set(varRootDomain "binaryoutcast.com")
set(varDomain "${varSubdomain}.${varRootDomain}")
pyPreprocess(
    ${varDomain}.vhost.in
    ${varDomain}.vhost
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
)

# Proxy file for repository.binaryoutcast.com
set(varDomain "repository.binaryoutcast.com")
pyPreprocess(
    ${mk_depth}/aura/templates/nginx/standard.proxy.in
    ${varDomain}.proxy
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_IPV4="${varSystemIPv4}"
    -DAURA_IPV6="${varSystemIPv6}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DNGX_DOMAIN="${varDomain}"
)

# VHOST for repository.binaryoutcast.com
set(varSubdomain "repository")
set(varRootDomain "binaryoutcast.com")
set(varDomain "${varSubdomain}.${varRootDomain}")
pyPreprocess(
    ${mk_depth}/aura/templates/nginx/standard.vhost.in
    ${varDomain}.vhost
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
    -DNGX_ENABLE_PHP=1
)