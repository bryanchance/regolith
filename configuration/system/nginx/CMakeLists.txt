build_macro_mkPaths()
SETUP_FINAL_TARGET()
AURA_DEFINES()


# System Nginx systemd Service
build_func_preprocess(${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/nginx.service.in ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-nginx.service  -DAURA_VERSION="${varTargetAuraVersion}" -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DNGX_GLOBAL)

# Userscope Nginx Server Instance
build_func_preprocess(${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/nginx.conf.in ${FINAL_TARGET}/nginx.conf  -DAURA_VERSION="${varTargetAuraVersion}" -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DNGX_GLOBAL)

# Use build_func_preprocess to copy files (This would be better served by another function but I want this to happen in 'build time' instead of 'configure time')
build_func_preprocess(mime-types.inc ${FINAL_TARGET}/mime-types.inc)
build_func_preprocess(standard-php.inc ${FINAL_TARGET}/standard-php.inc)

add_subdirectory(certs)