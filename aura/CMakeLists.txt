mk_paths()

# Set common variables
set(varGlobalSystemIPv4 "173.44.61.231")
set(varGlobalSystemIPv6 "2607:ff48:1:302::dc50:5a24")

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})
add_subdirectory(configuration)