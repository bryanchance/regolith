build_macro_mkPaths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# Set information about this user
set(varUserName "dovedesign")

# Add Subdirectories
add_subdirectory(nginx)
add_subdirectory(php)