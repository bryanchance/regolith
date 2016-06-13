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

# Proxy file for susantobinart.com
set(varDomain "susantobinart.com")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/www.${varDomain}.proxy
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_MAINDOMAIN=1
)

# VHOST for susantobinart.com
set(varSubdomain "www")
set(varRootDomain "susantobinart.com")
set(varDomain ${varRootDomain})
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${FINAL_TARGET}/www.${varDomain}.vhost
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
)