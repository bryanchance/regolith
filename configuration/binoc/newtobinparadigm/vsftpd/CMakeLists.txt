build_macro_mkPaths()
SETUP_FINAL_TARGET()
AURA_DEFINES()


build_func_preprocess(
    vsftpd.service
    ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-vsftpd.service
    ${varAuraDefines}
)

build_func_preprocess(
    vsftpd.conf
    ${FINAL_TARGET}/vsftpd.conf
    ${varAuraDefines}
)

build_func_preprocess(
    vsftpd.pam
    ${FINAL_TARGET}/vsftpd.pam
    ${varAuraDefines}
)

add_subdirectory(users)