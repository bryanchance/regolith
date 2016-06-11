build_macro_mkPaths()
SETUP_FINAL_TARGET()



# Userscope Nginx systemd Service
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/nginx.service.in
    ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-nginx.service
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
)

# Userscope Nginx Server Instance
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/nginx.conf.in
    ${FINAL_TARGET}/nginx.conf
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_IPV4="${varSystemIPv4}"
    -DAURA_IPV6="${varSystemIPv6}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
)

if(varTargetServerQuartz)
# Proxy file for binocnetwork.com
    set(varDomain "binocnetwork.com")
    build_func_preprocess(
        ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
        ${FINAL_TARGET}/www.${varDomain}.proxy
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
    build_func_preprocess(
        ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
        ${FINAL_TARGET}/www.${varDomain}.vhost
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
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/${varDomain}.proxy
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
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${FINAL_TARGET}/${varDomain}.vhost
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
