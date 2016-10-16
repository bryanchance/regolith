# Set directories

### These are always included
### Subdirectories under 'binoc' are specific to BinOC save for 'binocnetwork' as it is global
add_subdirectory(system)
add_subdirectory(binoc)
add_subdirectory(unaffiliated)

### These are specific to BinOC
if(varTargetServerQuartz)
    add_subdirectory(staff)
elseif(varTargetServerRegolith)
    add_subdirectory(mcp)
endif()