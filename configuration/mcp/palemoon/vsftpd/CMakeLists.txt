mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

pyPreprocess(vsftpd.service aura-${varUserClass}-${varUserName}-vsftpd.service)
pyPreprocess(vsftpd.conf vsftpd.conf)
pyPreprocess(vsftpd.pam vsftpd.pam)
