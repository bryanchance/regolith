build_macro_mkPaths()
SETUP_FINAL_TARGET()



# Set the user class
set(varUserClass "binoc")

# Add subdirectories
add_subdirectory(binocnetwork)

if(varTargetServerQuartz)
add_subdirectory(binaryoutcast)
add_subdirectory(newtobinparadigm)
add_subdirectory(royalgeekworld)
endif()