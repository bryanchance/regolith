mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# System Nginx systemd Service
pyPreprocess(${mk_depth}/aura/templates/php/php.service.in aura-${varUserClass}-${varUserName}-php.service -Fsubstitution -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}")

pyPreprocess(${mk_depth}/aura/templates/php/php.conf.in php.conf -Fsubstitution -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}")

pyPreprocess(${mk_depth}/aura/templates/php/php.ini.in php.ini)