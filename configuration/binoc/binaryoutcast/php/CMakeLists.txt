build_macro_mkPaths()
SETUP_FINAL_TARGET()
AURA_DEFINES()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${FINAL_TARGET}/session)

# php-fpm pool config
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php-pool.conf.in
    ${FINAL_TARGET}/php-pool.conf 
    ${varAuraDefines}
    -DPHP_ENABLE_LARGE_POOL=1
)

# php-fpm pool config
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php-pool.conf.in
    ${FINAL_TARGET}/php56-pool.conf
    ${varAuraDefines}
    -DPHP_ENABLE_LARGE_POOL=1
    -DPHP_VERSION_56
)

# php-fpm pool config
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php-pool.conf.in
    ${FINAL_TARGET}/php70-pool.conf
    ${varAuraDefines}
    -DPHP_ENABLE_LARGE_POOL=1
    -DPHP_VERSION_70
)