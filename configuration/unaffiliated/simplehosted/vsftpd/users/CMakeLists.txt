build_macro_mkPaths()
SETUP_FINAL_TARGET()
AURA_DEFINES()

# Copy files wholesale
#set(SOURCE_FILES
#    ${mk_srcdir}/user-template
#)

$COPY_TO_DIST("${SOURCE_FILES}")