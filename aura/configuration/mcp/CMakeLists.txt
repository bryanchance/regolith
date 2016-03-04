mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# Set the user class
set(varUserClass "mcp")

# Add subdirectories
add_subdirectory(palemoon)

# add_subdirectory(fossamail)
# add_subdirectory(productions)
