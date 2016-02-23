mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

add_subdirectory(bind)
add_subdirectory(etc)
add_subdirectory(mysql)
add_subdirectory(nginx)
add_subdirectory(php)
