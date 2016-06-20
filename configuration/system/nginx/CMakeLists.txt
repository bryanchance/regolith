build_macro_mkPaths()
SETUP_FINAL_TARGET()
AURA_DEFINES()

# Copy files wholesale
set(SOURCE_FILES
    ${mk_srcdir}/mime-types.inc
    ${mk_srcdir}/standard-php.inc
)

COPY_TO_DIST("${SOURCE_FILES}")

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

add_subdirectory(certs)