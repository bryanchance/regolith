mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

if(varTargetServerQuartz)
	add_subdirectory(bind)
endif()
add_subdirectory(etc)
add_subdirectory(mysql)
add_subdirectory(nginx)
add_subdirectory(php)
