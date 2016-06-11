build_macro_mkPaths()
SETUP_FINAL_TARGET()



build_func_preprocess(vsftpd.service aura-${varUserClass}-${varUserName}-vsftpd.service)
build_func_preprocess(vsftpd.conf vsftpd.conf)
build_func_preprocess(vsftpd.pam vsftpd.pam)

add_subdirectory(users)