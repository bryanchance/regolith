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

# Proxy file for royalgeekworld.com
set(varDomain "royalgeekworld.com")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/www.${varDomain}.proxy
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_MAINDOMAIN=1
)

# VHOST for royalgeekworld.com
set(varSubdomain "www")
set(varRootDomain "royalgeekworld.com")
set(varDomain ${varRootDomain})
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${FINAL_TARGET}/www.${varDomain}.vhost
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
    -DNGX_ENABLE_PHP=1
    -DNGX_ENABLE_ENANO=1
)

# Proxy file for ccfans.royalgeekworld.com
set(varDomain "ccfans.royalgeekworld.com")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/${varDomain}.proxy
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
)

# VHOST for ccfans.royalgeekworld.com
set(varSubdomain "ccfans")
set(varRootDomain "royalgeekworld.com")
set(varDomain "${varSubdomain}.${varRootDomain}")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${FINAL_TARGET}/${varDomain}.vhost
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
    -DNGX_ENABLE_PHP=1
    -DNGX_ENABLE_ENANO=1
)