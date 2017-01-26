if((BINOC_BUILD) AND (NOT CMAKE_BINARY_DIR MATCHES CMAKE_SOURCE_DIR))
    build_macro_mkPaths()

    set(varTargetAuraVersion "4.0b5")

    # Figure out FINAL_TARGET in a ridiculous way
    macro(SETUP_FINAL_TARGET)
        string(REPLACE "${mk_topsrcdir}/projects/${BUILD_PROJECT}/" "" _PATH_DIFF ${mk_srcdir})

        set(FINAL_TARGET ${_PATH_DIFF})
        file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${FINAL_TARGET})
    endmacro(SETUP_FINAL_TARGET)

    function(COPY_TO_DIST _FILE_LIST)
        foreach(_FILE ${_FILE_LIST})
            string(REPLACE "${mk_topsrcdir}/projects/${BUILD_PROJECT}/" "" _FILE_NAME ${_FILE})
            message(STATUS "Copying: ${_FILE_NAME}")
            file(COPY ${_FILE} DESTINATION "${CMAKE_INSTALL_PREFIX}/${FINAL_TARGET}/")
        endforeach()
    endfunction(COPY_TO_DIST)
    
    ### If the build script has a blank variable that is passed as a define then target "Quartz" 
    if (NOT AURA_SERVER_TARGET)
        set (AURA_SERVER_TARGET "quartz")
    endif ()

    ### AURA_DEFINES
    macro(AURA_DEFINES)
        set(varAuraDefines
            ${varBuildDefines}
            -DAURA_VERSION="${varTargetAuraVersion}"
            -DAURA_IPV4="${varSystemIPv4}"
            -DAURA_IPV6="${varSystemIPv6}"
            -DAURA_USER_CLASS="${varUserClass}"
            -DAURA_USER_NAME="${varUserName}"
            -DAURA_USER_ID="${varUserID}"
            -DAURA_USER_PORT0="${varUserID}0" # Reserved
            -DAURA_USER_PORT1="${varUserID}1" # Icecast
            -DAURA_USER_PORT2="${varUserID}2" # Standard FTP
            -DAURA_USER_PORT3="${varUserID}3" # Not Defined
            -DAURA_USER_PORT4="${varUserID}4" # Not Defined
            -DAURA_USER_PORT5="${varUserID}5" # Not Defined
            -DAURA_USER_PORT6="${varUserID}6" # IRC or ZNC
            -DAURA_USER_PORT7="${varUserID}7" # Alt Webserver or uWSGI
            -DAURA_USER_PORT8="${varUserID}8" # NGINX User Instance
            -DAURA_USER_PORT9="${varUserID}9" # PHP-FPM
        )
    endmacro(AURA_DEFINES)

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
        set(varSystemIPv4 "45.63.2.9")
        set(varSystemIPv6 "2001:19f0:200:2d91::7321:a697")
        set(varSystemServerName "quartz.server.binocnetwork.com")
    elseif(varTargetServerRegolith)
        set(varSystemIPv4 "173.44.61.210")
        set(varSystemIPv6 "2607:ff48:1:302::53cf:d149")
        set(varSystemServerName "regolith.server.binocnetwork.com")
    endif()

    add_subdirectory(configuration)

    build_func_package(aura-configuration-${AURA_SERVER_TARGET}-${varTargetAuraVersion}.zip)
else()
    cmake_minimum_required (VERSION 2.8.11)
    project (aura-infra NONE)

    message(
        FATAL_ERROR
        "\n"
        "*** This project can only be built with the Binary Outcast Build System.\n"
        "*** Please clone https://github.com/binoc-network/build-system.git and then move or re-clone this project into the [build-system]/projects/[this-project] directory.\n"
        "*** Be sure to clean up any build artifacts here before trying to restart your build by executing the axion build script."
    )
endif()