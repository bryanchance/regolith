# ===| Macros |================================================================

build_macro_mkPaths()
SETUP_FINAL_TARGET()
AURA_DEFINES()

# =============================================================================

# ===| User Nginx Instance SystemD Unit |======================================

build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/nginx.service.in
    ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-nginx.service
    ${varAuraDefines}
)

# =============================================================================

# ===| User Nginx Server Configuration |=======================================

build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/nginx.conf.in
    ${FINAL_TARGET}/nginx.conf
    ${varAuraDefines}
)

# =============================================================================

# ===| addons.palemoon.org |===================================================

# Set Variables to be used as Preprocessor defines
set(varRootDomain "palemoon.org")
set(varSubDomain "addons")
set(varNginxDefines
    ${varAuraDefines}
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubDomain}"
    -DNGX_ENABLE_SSL=1
    -DNGX_SSL_CERT="${varSubDomain}.${varRootDomain}"
    -DNGX_ENABLE_CLOUDFLARE=1
    -DNGX_INCLUDE="${mk_srcdir}/${varSubDomain}.${varRootDomain}.vhost.inc"
    -DNGX_ENABLE_PHP=1
    -DNGX_ENABLE_CMSMS=1
    -DPHP_VERSION_56=1
)

# Proxy file
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.proxy
    ${varNginxDefines}
)

# VHost file
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.vhost
    ${varNginxDefines}
)

# =============================================================================

# ===| dev.addons.palemoon.org |===============================================

# Set Variables to be used as Preprocessor defines
set(varRootDomain "palemoon.org")
set(varSubDomain "dev.addons")
set(varNginxDefines
    ${varAuraDefines}
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubDomain}"
    -DNGX_OVERRIDE_SUBDOMAIN="testing"
    -DNGX_ENABLE_SSL=1
    -DNGX_SSL_CERT="addons.palemoon.org"
    -DNGX_ENABLE_PHP=1
    -DPHP_VERSION_70=1
)

# Proxy file
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.proxy
    ${varNginxDefines}
)

# VHost file
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.vhost
    ${varNginxDefines}
)

# =============================================================================

# ===| developer.palemoon.org |===================================================

# Set Variables to be used as Preprocessor defines
set(varRootDomain "palemoon.org")
set(varSubDomain "developer")
set(varNginxDefines
    ${varAuraDefines}
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubDomain}"
    -DNGX_ENABLE_SSL=1
    -DNGX_SSL_CERT="${varSubDomain}.${varRootDomain}"
    -DNGX_ENABLE_CLOUDFLARE=1
    -DNGX_ENABLE_PHP=1
    -DNGX_ENABLE_PHP_404=1
    -DNGX_ENABLE_ENANO=1
    -DPHP_VERSION_56=1
)

# Proxy file
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.proxy
    ${varNginxDefines}
)

# VHost file
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.vhost
    ${varNginxDefines}
)

# =============================================================================