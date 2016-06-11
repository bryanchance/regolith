build_macro_mkPaths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# Set the user class
set(varUserClass "unaffiliated")

# Add subdirectories
add_subdirectory(dovedesign)
add_subdirectory(kokomosaferefuge)
