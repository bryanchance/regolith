# Set the user class
set(varUserClass "system")
set(varUserName "root")

if(varTargetServerQuartz)
	add_subdirectory(bind)
endif()
add_subdirectory(etc)
add_subdirectory(mysql)
add_subdirectory(nginx)
add_subdirectory(php)
