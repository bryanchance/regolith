build_macro_mkPaths()
SETUP_FINAL_TARGET()
AURA_DEFINES()

# Copy files wholesale
set(SOURCE_FILES
    ${mk_srcdir}/capture
    ${mk_srcdir}/files
    ${mk_srcdir}/mattatobin
    ${mk_srcdir}/private
)

COPY_TO_DIST("${SOURCE_FILES}")