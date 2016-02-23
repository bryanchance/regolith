mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

add_subdirectory(nginx)
add_subdirectory(php)
add_subdirectory(vsftpd)
add_subdirectory(znc)