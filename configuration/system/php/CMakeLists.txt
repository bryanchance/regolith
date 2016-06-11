mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# System PHP systemd Service
pyPreprocess(${mk_depth}/aura/templates/php/php.service.in aura-${varUserClass}-${varUserName}-php.service -Fsubstitution -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}")

pyPreprocess(${mk_depth}/aura/templates/php/php.conf.in php.conf -Fsubstitution -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}")

# PHP56 systemd Service
pyPreprocess(${mk_depth}/aura/templates/php/php.service.in aura-${varUserClass}-${varUserName}-php56.service -Fsubstitution -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DPHP_VERSION_56=1)

pyPreprocess(${mk_depth}/aura/templates/php/php.conf.in php56.conf -Fsubstitution -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DPHP_VERSION_56=1)

# PHP70 systemd Service
pyPreprocess(${mk_depth}/aura/templates/php/php.service.in aura-${varUserClass}-${varUserName}-php70.service -Fsubstitution -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DPHP_VERSION_70=1)

pyPreprocess(${mk_depth}/aura/templates/php/php.conf.in php70.conf -Fsubstitution -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DPHP_VERSION_70=1)

pyPreprocess(${mk_depth}/aura/templates/php/php.ini.in php.ini)