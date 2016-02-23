mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

add_subdirectory(fossamail)
add_subdirectory(palemoon)
add_subdirectory(productions)
