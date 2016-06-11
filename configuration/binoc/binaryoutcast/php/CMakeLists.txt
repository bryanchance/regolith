build_macro_mkPaths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})
file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath}/session)

# php-fpm pool config
pyPreprocess(
    ${mk_depth}/aura/templates/php/php-pool.conf.in
    php-pool.conf -Fsubstitution
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DPHP_ENABLE_LARGE_POOL=1
)

# php-fpm pool config
pyPreprocess(
    ${mk_depth}/aura/templates/php/php-pool.conf.in
    php56-pool.conf
    -Fsubstitution
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DPHP_ENABLE_LARGE_POOL=1
    -DPHP_VERSION_56
)

# php-fpm pool config
pyPreprocess(
    ${mk_depth}/aura/templates/php/php-pool.conf.in
    php70-pool.conf
    -Fsubstitution
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DPHP_ENABLE_LARGE_POOL=1
    -DPHP_VERSION_70
)