# ===| Macros |================================================================

build_macro_mkPaths()
SETUP_FINAL_TARGET()
AURA_DEFINES()

# =============================================================================

# ===| User Apache Instance SystemD Unit |=====================================

build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/apache/apache.service.in
    ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-apache.service
    ${varAuraDefines}
)

# =============================================================================

# ===| User Apache Server Configuration |======================================

build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/apache/apache.conf.in
    ${FINAL_TARGET}/apache.conf
    ${varAuraDefines}
)

# =============================================================================

# ===| xr.service.binocnetwork.com |===========================================
if(varTargetServerQuartz)
    # Set Variables to be used as Preprocessor defines
    set(varRootDomain "binocnetwork.com")
    set(varSubDomain "xr.service")
    set(varApacheDefines
        ${varAuraDefines}
        -DAPACHE_ROOTDOMAIN="${varRootDomain}"
        -DAPACHE_SUBDOMAIN="${varSubDomain}"
        -DAPACHE_OVERRIDE_SUBDOMAIN="xr"
        -DAPACHE_ENABLE_PERL=1
        -DAPACHE_ENABLE_MXR=1
    )

    # VHost file
    build_func_preprocess(
        ${mk_depth}/projects/${BUILD_PROJECT}/templates/apache/standard.vhost.in
        ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.vhost
        ${varApacheDefines}
    )
endif()
# =============================================================================