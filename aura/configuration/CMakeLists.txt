mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

add_subdirectory(system)

add_subdirectory(binoc)
add_subdirectory(staff)
add_subdirectory(unaffiliated)

add_subdirectory(mcp)
