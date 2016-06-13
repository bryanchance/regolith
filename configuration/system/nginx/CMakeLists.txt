build_macro_mkPaths()
SETUP_FINAL_TARGET()
AURA_DEFINES()


# System Nginx systemd Service
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/nginx.service.in
    ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-nginx.service
    ${varAuraDefines}
    -DNGX_GLOBAL=1
)

# Userscope Nginx Server Instance
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/nginx.conf.in
    ${FINAL_TARGET}/nginx.conf
    ${varAuraDefines}
    -DNGX_GLOBAL=1
)

# Use build_func_preprocess to copy files (This would be better served by another function but I want this to happen in 'build time' instead of 'configure time')
build_func_preprocess(
    mime-types.inc
    ${FINAL_TARGET}/mime-types.inc
    ${varAuraDefines}
)
build_func_preprocess(
    standard-php.inc
    ${FINAL_TARGET}/standard-php.inc
    ${varAuraDefines}
)

add_subdirectory(certs)