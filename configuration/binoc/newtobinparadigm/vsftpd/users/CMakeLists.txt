build_macro_mkPaths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

build_func_preprocess(capture capture)
build_func_preprocess(files files)
build_func_preprocess(mattatobin mattatobin)
build_func_preprocess(private private)