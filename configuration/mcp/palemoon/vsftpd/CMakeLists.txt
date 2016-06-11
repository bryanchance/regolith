build_macro_mkPaths()
SETUP_FINAL_TARGET()



build_func_preprocess(vsftpd.service ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-vsftpd.service)
build_func_preprocess(vsftpd.conf ${FINAL_TARGET}/vsftpd.conf)
build_func_preprocess(vsftpd.pam ${FINAL_TARGET}/vsftpd.pam)
