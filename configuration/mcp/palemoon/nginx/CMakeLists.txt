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

# Proxy file for addons.palemoon.org
set(varDomain "addons.palemoon.org")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/${varDomain}.proxy
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ENABLE_SSL=1
    -DNGX_SSL_CERT="${varDomain}"
    -DNGX_ENABLE_CLOUDFLARE=1
)

# VHOST for addons.palemoon.org
set(varSubdomain "addons")
set(varRootDomain "palemoon.org")
set(varDomain "${varSubdomain}.${varRootDomain}")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${FINAL_TARGET}/${varDomain}.vhost
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
    -DNGX_INCLUDE="${mk_srcdir}/${varDomain}.vhost.inc"
    -DNGX_ENABLE_CMSMS=1
    -DNGX_ENABLE_PHP=1
    -DPHP_VERSION_56=1
)

# Proxy file for dev.addons.palemoon.org
set(varDomain "dev.addons.palemoon.org")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/${varDomain}.proxy
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ENABLE_SSL=1
    -DNGX_SSL_CERT="addons.palemoon.org"
)

# VHOST for dev.addons.palemoon.org
set(varSubdomain "dev.addons")
set(varRootDomain "palemoon.org")
set(varDomain "${varSubdomain}.${varRootDomain}")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${FINAL_TARGET}/${varDomain}.vhost
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
    -DNGX_OVERRIDE_SUBDOMAIN="testing"
    -DNGX_ENABLE_PHP=1
    -DPHP_VERSION_70=1
)

# Proxy file for developer.palemoon.org
set(varDomain "developer.palemoon.org")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/${varDomain}.proxy
    ${varAuraDefines}
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ENABLE_SSL=1
    -DNGX_SSL_CERT="${varDomain}"
)

# VHOST for developer.palemoon.org
set(varSubdomain "developer")
set(varRootDomain "palemoon.org")
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
    -DNGX_ENABLE_PHP_404=1
    -DNGX_ENABLE_ENANO=1
)