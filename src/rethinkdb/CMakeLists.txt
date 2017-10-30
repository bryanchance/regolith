build_macro_mkPaths()
FIND_FINAL_TARGET()
AURA_DEFINES()

# Copy files wholesale
set(SOURCE_FILES
    ${mk_srcdir}/regolith-phoebus.conf
    ${mk_srcdir}/regolith-rethinkdb.service
)


COPY_TO_DIST("${SOURCE_FILES}")
