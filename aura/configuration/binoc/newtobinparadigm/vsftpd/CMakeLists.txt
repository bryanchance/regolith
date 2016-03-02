mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

pyPreprocess(vsftpd.service aura-${AURA_USER_CLASS}-${AURA_USER_NAME}-vsftpd.service)
pyPreprocess(vsftpd.conf vsftpd.conf)
pyPreprocess(vsftpd.pam vsftpd.pam)