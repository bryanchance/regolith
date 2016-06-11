build_macro_mkPaths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

pyPreprocess(capture capture)
pyPreprocess(files files)
pyPreprocess(mattatobin mattatobin)
pyPreprocess(private private)