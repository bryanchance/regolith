mk_paths()

# Set variables about the build

### Set some nifty vars
set(varTargetAuraVersion "4.0a1")

### Which configuration do we build?
set(varTargetServerQuartz 1)
set(varTargetServerRegolith)

### Server Specific Info
if(varTargetServerQuartz)
	set(varSystemIPv4 "173.44.61.231")
	set(varSystemIPv6 "2607:ff48:1:302::dc50:5a24")
	set(varSystemServerName "quartz.server.binocnetwork.com")
elseif(varTargetServerRegolith)
	set(varSystemIPv4 "173.44.61.210")
	set(varSystemIPv6 "2607:ff48:1:302::53cf:d149")
	set(varSystemServerName "regolith.server.binocnetwork.com")
endif()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})
add_subdirectory(configuration)