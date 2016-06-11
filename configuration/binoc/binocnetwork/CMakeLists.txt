mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# Set information about this user
set(varUserName "binocnetwork")

add_subdirectory(nginx)
add_subdirectory(php)