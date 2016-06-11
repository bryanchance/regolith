build_macro_mkPaths()

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

if(varTargetServerQuartz)
# Proxy file for binocnetwork.com
    set(varDomain "binocnetwork.com")
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

    # VHOST for binocnetwork.com
    set(varSubdomain "www")
    set(varRootDomain "binocnetwork.com")
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
    )
endif()

# Proxy file for Sever Subdomain
if(varTargetServerQuartz)
    set(varDomain "quartz.server.binocnetwork.com")
elseif(varTargetServerRegolith)
    set(varDomain "regolith.server.binocnetwork.com")
endif()
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

# VHOST for Sever Subdomain
if(varTargetServerQuartz)
    set(varSubdomain "quartz.server")
elseif(varTargetServerRegolith)
    set(varSubdomain "regolith.server")
endif()
set(varRootDomain "binocnetwork.com")
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
    -DNGX_OVERRIDE_SUBDOMAIN="operations"
    -DNGX_ENABLE_PHP=1
    -DPHP_VERSION_56=1
)
