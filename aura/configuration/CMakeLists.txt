mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# Set variables about the build
### Which configuration do we build?
set(varBuildBinOC 1)
set(varBuildMCP)

### Server Specific Info
if(varBuildBinOC)
	set(varSystemIPv4 "173.44.61.231")
	set(varSystemIPv6 "2607:ff48:1:302::dc50:5a24")
	set(varSystemServerName "quartz.server.binocnetwork.com")
elseif(varBuildMCP)
	set(varSystemIPv4 "173.44.61.210")
	set(varSystemIPv6 "2607:ff48:1:302::53cf:d149")
	set(varSystemServerName "regolith.server.binocnetwork.com")
endif()

# Set directories

### These are always included
### Subdirectories under 'binoc' are specific to BinOC save for 'binocnetwork' as it is global
add_subdirectory(system)
add_subdirectory(binoc)

### These are specific to BinOC
if(varBuildBinOC)
	add_subdirectory(staff)
	add_subdirectory(unaffiliated)
elseif(varBuildMCP)
	add_subdirectory(mcp)
endif()