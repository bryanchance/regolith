build_macro_mkPaths()
SETUP_FINAL_TARGET()



# System PHP systemd Service
build_func_preprocess(${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php.service.in ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-php.service  -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}")

build_func_preprocess(${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php.conf.in ${FINAL_TARGET}/php.conf  -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}")

# PHP56 systemd Service
build_func_preprocess(${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php.service.in ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-php56.service  -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DPHP_VERSION_56=1)

build_func_preprocess(${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php.conf.in ${FINAL_TARGET}/php56.conf  -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DPHP_VERSION_56=1)

# PHP70 systemd Service
build_func_preprocess(${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php.service.in ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-php70.service  -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DPHP_VERSION_70=1)

build_func_preprocess(${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php.conf.in ${FINAL_TARGET}/php70.conf  -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DPHP_VERSION_70=1)

build_func_preprocess(${mk_depth}/projects/${BUILD_PROJECT}/templates/php/php.ini.in ${FINAL_TARGET}/php.ini)