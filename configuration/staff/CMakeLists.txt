mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# Set the user class
set(varUserClass "staff")

add_subdirectory(valik)