build_macro_mkPaths()
SETUP_FINAL_TARGET()
AURA_DEFINES()


build_func_preprocess(
    capture
    ${FINAL_TARGET}/capture
    ${varAuraDefines}
)

build_func_preprocess(
    files
    ${FINAL_TARGET}/files
    ${varAuraDefines}
)

build_func_preprocess(
    mattatobin
    ${FINAL_TARGET}/mattatobin
    ${varAuraDefines}
)

build_func_preprocess(
    private
    ${FINAL_TARGET}/private
    ${varAuraDefines}
)