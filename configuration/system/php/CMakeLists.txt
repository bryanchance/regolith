build_macro_mkPaths()
SETUP_FINAL_TARGET()
AURA_DEFINES()

# Copy files wholesale
set(SOURCE_FILES
    ${mk_srcdir}/php.ini
)

COPY_TO_DIST("${SOURCE_FILES}")


# System PHP systemd Service
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php.service.in
    ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-php.service
    ${varAuraDefines}
)

build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php.conf.in
    ${FINAL_TARGET}/php.conf
    ${varAuraDefines}
)

# PHP56 systemd Service
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php.service.in
    ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-php56.service
    ${varAuraDefines}
    -DPHP_VERSION_56=1
)

build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php.conf.in
    ${FINAL_TARGET}/php56.conf
    ${varAuraDefines}
    -DPHP_VERSION_56=1
)

# PHP70 systemd Service
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php.service.in
    ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-php70.service
    ${varAuraDefines}
    -DPHP_VERSION_70=1
)

build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php.conf.in
    ${FINAL_TARGET}/php70.conf
    ${varAuraDefines}
    -DPHP_VERSION_70=1
)