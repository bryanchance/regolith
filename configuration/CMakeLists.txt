build_macro_mkPaths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# Set directories

### These are always included
### Subdirectories under 'binoc' are specific to BinOC save for 'binocnetwork' as it is global
add_subdirectory(system)
add_subdirectory(binoc)

### These are specific to BinOC
if(varTargetServerQuartz)
	add_subdirectory(staff)
	add_subdirectory(unaffiliated)
elseif(varTargetServerRegolith)
	add_subdirectory(mcp)
endif()