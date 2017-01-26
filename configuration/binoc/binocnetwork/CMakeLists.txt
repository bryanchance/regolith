# Set information about this user
set(varUserName "binocnetwork")
set(varUserID "1200")

add_subdirectory(nginx)
if(varTargetServerQuartz)
    add_subdirectory(apache)
endif()
add_subdirectory(php)