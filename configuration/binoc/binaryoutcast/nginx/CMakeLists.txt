build_macro_mkPaths()
SETUP_FINAL_TARGET()
AURA_DEFINES()


# Userscope Nginx systemd Service
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/nginx.service.in
    ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-nginx.service
    ${varAuraDefines}
)

# Userscope Nginx Server Instance
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/nginx.conf.in
    ${FINAL_TARGET}/nginx.conf
    ${varAuraDefines}
)

# Proxy file for binaryoutcast.com
set(varDomain "binaryoutcast.com")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/www.${varDomain}.proxy
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_MAINDOMAIN=1
)

# VHOST for binaryoutcast.com
set(varSubdomain "www")
set(varRootDomain "binaryoutcast.com")
set(varDomain ${varRootDomain})
build_func_preprocess(
    www.${varDomain}.vhost.in
    ${FINAL_TARGET}/www.${varDomain}.vhost
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
)

# Proxy file for techcentral.binaryoutcast.com
set(varDomain "techcentral.binaryoutcast.com")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/${varDomain}.proxy
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
)

# VHOST for techcentral.binaryoutcast.com
set(varSubdomain "techcentral")
set(varRootDomain "binaryoutcast.com")
set(varDomain "${varSubdomain}.${varRootDomain}")
build_func_preprocess(
    ${varDomain}.vhost.in
    ${FINAL_TARGET}/${varDomain}.vhost
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
)

# Proxy file for repository.binaryoutcast.com
set(varDomain "repository.binaryoutcast.com")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/${varDomain}.proxy
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
)

# VHOST for repository.binaryoutcast.com
set(varSubdomain "repository")
set(varRootDomain "binaryoutcast.com")
set(varDomain "${varSubdomain}.${varRootDomain}")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${FINAL_TARGET}/${varDomain}.vhost
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
    -DNGX_ENABLE_PHP=1
    -DPHP_VERSION_56=1
)