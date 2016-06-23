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

# ===| www.royalgeekworld.com |================================================

# Set Variables to be used as Preprocessor defines
set(varRootDomain "royalgeekworld.com")
set(varSubDomain "www")
set(varNginxDefines
    ${varAuraDefines}
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubDomain}"
    -DNGX_MAINDOMAIN=1
    -DNGX_ENABLE_PHP=1
    -DNGX_ENABLE_PHP_404=1
    -DNGX_ENABLE_ENANO=1
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

# ===| ccfans.royalgeekworld.com |=============================================

# Set Variables to be used as Preprocessor defines
set(varRootDomain "royalgeekworld.com")
set(varSubDomain "ccfans")
set(varNginxDefines
    ${varAuraDefines}
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubDomain}"
    -DNGX_ENABLE_PHP=1
    -DNGX_ENABLE_PHP_404=1
    -DNGX_ENABLE_ENANO=1
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

