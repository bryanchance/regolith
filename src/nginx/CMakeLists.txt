# ===| Macros |================================================================

build_macro_mkPaths()
FIND_FINAL_TARGET()
AURA_DEFINES()

# =============================================================================

# Copy files wholesale
set(SOURCE_FILES
    ${mk_srcdir}/mime-types.inc
    ${mk_srcdir}/standard-php.inc
)

COPY_TO_DIST("${SOURCE_FILES}")

# ===| Nginx Instance SystemD Unit |===========================================

build_func_preprocess(
    nginx.service.in
    ${FINAL_TARGET}/${varUserName}-nginx.service
    ${varAuraDefines}
)

# =============================================================================

# ===| Nginx Server Configuration |============================================

build_func_preprocess(
    nginx.conf.in
    ${FINAL_TARGET}/nginx.conf
    ${varAuraDefines}
    -DNGX_HIGH_WORKERS=1
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
    -DNGX_SSL_CERT="${varRootDomain}"
    -DNGX_ENABLE_CLOUDFLARE=1
    -DNGX_INCLUDE="${mk_srcdir}/${varSubDomain}.${varRootDomain}.server.inc"
    -DNGX_ENABLE_PHP=1
    -DNGX_ENABLE_PHOEBUS=1
    -DPHP_VERSION_70=1
)

# Server file
build_func_preprocess(
    standard.server.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.server
    ${varNginxDefines}
)

# =============================================================================

# ===| addons-dev.palemoon.org |===============================================

# Set Variables to be used as Preprocessor defines
set(varRootDomain "palemoon.org")
set(varSubDomain "addons-dev")
set(varNginxDefines
    ${varAuraDefines}
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubDomain}"
    -DNGX_ENABLE_SSL=1
    -DNGX_SSL_CERT="${varRootDomain}"
    -DNGX_INCLUDE="${mk_srcdir}/${varSubDomain}.${varRootDomain}.server.inc"
    -DNGX_ENABLE_PHP=1
    -DNGX_ENABLE_PHOEBUS=1
    -DPHP_VERSION_70=1
)

# VHost file
build_func_preprocess(
    standard.server.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.server
    ${varNginxDefines}
)

# =============================================================================

# ===| addons.palemoon.org |===================================================

# Set Variables to be used as Preprocessor defines
set(varRootDomain "hyperbola.info")
set(varSubDomain "iw.addons")
set(varNginxDefines
    ${varAuraDefines}
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubDomain}"
    -DNGX_ENABLE_SSL=1
    -DNGX_SSL_CERT="regolith"
    -DNGX_ENABLE_CLOUDFLARE=1
    -DNGX_INCLUDE="${mk_srcdir}/${varSubDomain}.${varRootDomain}.server.inc"
    -DNGX_ENABLE_PHP=1
    -DNGX_ENABLE_PHOEBUS=1
    -DPHP_VERSION_70=1
)

# Server file
build_func_preprocess(
    standard.server.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.server
    ${varNginxDefines}
)

# =============================================================================

# ===| regolith.palemoon.org |===============================================

# Set Variables to be used as Preprocessor defines
set(varRootDomain "palemoon.org")
set(varSubDomain "regolith")
set(varNginxDefines
    ${varAuraDefines}
    -DNGX_SSL_CERT="${varRootDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubDomain}"
    -DNGX_ENABLE_SSL=1
    -DNGX_SSL_CERT="${varRootDomain}"
    -DNGX_INCLUDE="${mk_srcdir}/${varSubDomain}.${varRootDomain}.server.inc"
    -DNGX_ENABLE_PHP=1
    -DPHP_VERSION_70=1
)

# VHost file
build_func_preprocess(
    standard.server.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.server
    ${varNginxDefines}
)

# =============================================================================
