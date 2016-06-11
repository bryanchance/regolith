build_macro_mkPaths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

build_func_preprocess(vsftpd.service aura-${varUserClass}-${varUserName}-vsftpd.service)
build_func_preprocess(vsftpd.conf vsftpd.conf)
build_func_preprocess(vsftpd.pam vsftpd.pam)
