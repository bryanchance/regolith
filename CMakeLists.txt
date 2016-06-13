build_macro_mkPaths()

set(varTargetAuraVersion "4.0b5")

# Figure out FINAL_TARGET in a ridiculous way
macro(SETUP_FINAL_TARGET)
    string(REPLACE "${mk_topsrcdir}/projects/${BUILD_PROJECT}/" "" _PATH_DIFF ${mk_srcdir})

    set(FINAL_TARGET ${_PATH_DIFF})
    file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${FINAL_TARGET})
endmacro(SETUP_FINAL_TARGET)

### If the build script has a blank variable that is passed as a define then target "Quartz" 
if (NOT AURA_SERVER_TARGET)
set (AURA_SERVER_TARGET "quartz")
endif ()

### If the build script variable is not blank then evaluate it
if (AURA_SERVER_TARGET)
	if(AURA_SERVER_TARGET MATCHES "quartz")
		set(varTargetServerQuartz 1)
		set(varTargetServerRegolith)
	elseif(AURA_SERVER_TARGET MATCHES "regolith")
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

add_subdirectory(configuration)

build_func_package(aura-configuration-${AURA_SERVER_TARGET}-${varTargetAuraVersion}.zip)