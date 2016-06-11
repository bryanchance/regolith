build_macro_mkPaths()
SETUP_FINAL_TARGET()


file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${FINAL_TARGET}/session)

# php-fpm pool config
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php-pool.conf.in
    ${FINAL_TARGET}/php56-pool.conf
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DPHP_VERSION_56=1
)