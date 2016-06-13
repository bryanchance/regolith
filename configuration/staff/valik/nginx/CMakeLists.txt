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

# Proxy file for Sever Subdomain
set(varDomain "valik.staff.binocnetwork.com")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/${varDomain}.proxy
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
)

# VHOST for Sever Subdomain
set(varSubdomain "valik.staff")
set(varRootDomain "binocnetwork.com")
set(varDomain "${varSubdomain}.${varRootDomain}")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${FINAL_TARGET}/${varDomain}.vhost
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
    -DNGX_OVERRIDE_SUBDOMAIN="hosted"
    -DNGX_ENABLE_PHP=1
    -DPHP_VERSION_56=1
)
