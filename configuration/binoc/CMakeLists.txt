mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# Set the user class
set(varUserClass "binoc")

# Add subdirectories
add_subdirectory(binocnetwork)

if(varTargetServerQuartz)
add_subdirectory(binaryoutcast)
add_subdirectory(newtobinparadigm)
add_subdirectory(royalgeekworld)
endif()