build_macro_mkPaths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# System Nginx systemd Service
build_func_preprocess(${mk_depth}/aura/templates/nginx/nginx.service.in aura-${varUserClass}-${varUserName}-nginx.service -Fsubstitution -DAURA_VERSION="${varTargetAuraVersion}" -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DNGX_GLOBAL)

# Userscope Nginx Server Instance
build_func_preprocess(${mk_depth}/aura/templates/nginx/nginx.conf.in nginx.conf -Fsubstitution -DAURA_VERSION="${varTargetAuraVersion}" -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DNGX_GLOBAL)

# Use build_func_preprocess to copy files (This would be better served by another function but I want this to happen in 'build time' instead of 'configure time')
build_func_preprocess(mime-types.inc mime-types.inc)
build_func_preprocess(standard-php.inc standard-php.inc)

add_subdirectory(certs)