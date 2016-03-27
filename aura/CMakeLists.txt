mk_paths()

# Set variables about the build

### Set some nifty vars
set(varTargetAuraVersion "4.0b3")

### If the build script has a blank variable that is passed as a define then target "Quartz" 
if (NOT CMK_SERVER_TARGET)
set (CMK_SERVER_TARGET "quartz")
endif ()

### If the build script variable is not blank then evaluate it
if (CMK_SERVER_TARGET)
	if(CMK_SERVER_TARGET MATCHES "quartz")
		set(varTargetServerQuartz 1)
		set(varTargetServerRegolith)
	elseif(CMK_SERVER_TARGET MATCHES "regolith")
		set(varTargetServerQuartz)
		set(varTargetServerRegolith 1)
	else()
    message( FATAL_ERROR "You did not specify a valid target server." )
	endif()
else()
  message( FATAL_ERROR "You did not specify a target server." )
endif()

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