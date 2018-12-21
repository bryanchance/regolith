build_macro_mkPaths()
FIND_FINAL_TARGET()
AURA_DEFINES()

# Copy files wholesale
set(SOURCE_FILES
    ${mk_srcdir}/php.ini
)

COPY_TO_DIST("${SOURCE_FILES}")

# PHP70 systemd Service
build_func_preprocess(
    php.service.in
    ${FINAL_TARGET}/${varUserName}-php70.service
    ${varAuraDefines}
    -DPHP_VERSION_70=1
)

build_func_preprocess(
    php.conf.in
    ${FINAL_TARGET}/php70.conf
    ${varAuraDefines}
    -DPHP_VERSION_70=1
)

# php-fpm pool config
build_func_preprocess(
    php-pool.conf.in
    ${FINAL_TARGET}/php70-pool.conf
    ${varAuraDefines}
    -DPHP_VERSION_70=1
    -DPHP_ENABLE_LARGE_POOL=1
)

# PHP73 systemd Service
build_func_preprocess(
    php.service.in
    ${FINAL_TARGET}/${varUserName}-php73.service
    ${varAuraDefines}
    -DPHP_VERSION_73=1
)

build_func_preprocess(
    php.conf.in
    ${FINAL_TARGET}/php73.conf
    ${varAuraDefines}
    -DPHP_VERSION_73=1
)

# php-fpm pool config
build_func_preprocess(
    php-pool.conf.in
    ${FINAL_TARGET}/php73-pool.conf
    ${varAuraDefines}
    -DPHP_VERSION_73=1
    -DPHP_ENABLE_LARGE_POOL=1
)