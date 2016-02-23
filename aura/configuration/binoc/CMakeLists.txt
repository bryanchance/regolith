mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

add_subdirectory(binocnetwork)

if(varTargetServerQuartz)
add_subdirectory(binaryoutcast)
add_subdirectory(binocglobal)
add_subdirectory(newtobinparadigm)
add_subdirectory(royalgeekworld)
endif()