build_macro_mkPaths()
FIND_FINAL_TARGET()
AURA_DEFINES()

# Set information about this user
set(varUserName "regolith")
set(varUserID "1100")

add_subdirectory(nginx)
add_subdirectory(php)
add_subdirectory(rethinkdb)
add_subdirectory(vsftpd)
