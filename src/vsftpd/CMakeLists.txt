build_macro_mkPaths()
FIND_FINAL_TARGET()
AURA_DEFINES()

# Copy files wholesale
set(SOURCE_FILES
    ${mk_srcdir}/vsftpd.conf
    ${mk_srcdir}/vsftpd.pam
)

COPY_TO_DIST("${SOURCE_FILES}")

build_func_preprocess(
    vsftpd.service
    ${FINAL_TARGET}/${varUserName}-vsftpd.service
    ${varAuraDefines}
)