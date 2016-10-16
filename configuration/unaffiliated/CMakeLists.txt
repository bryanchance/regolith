# Set the user class
set(varUserClass "unaffiliated")

# Add subdirectories

if(varTargetServerQuartz)
    add_subdirectory(dovedesign)
    add_subdirectory(kokomosaferefuge)
    add_subdirectory(sagexpo)
elseif(varTargetServerRegolith)
    add_subdirectory(simplehosted)
endif()
