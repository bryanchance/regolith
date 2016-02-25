mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# System Nginx systemd Service
pyPreprocess(${mk_depth}/aura/templates/nginx/nginx.service.in aura-${varUserClass}-${varUserName}-nginx.service -Fsubstitution -DAURA_VERSION="${varTargetAuraVersion}" -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DNGX_GLOBAL)

# Userscope Nginx Server Instance
pyPreprocess(${mk_depth}/aura/templates/nginx/nginx.conf.in nginx.conf -Fsubstitution -DAURA_VERSION="${varTargetAuraVersion}" -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DNGX_GLOBAL)

add_subdirectory(certs)