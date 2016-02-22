# This macro tries to add some autohell conveniences to the cmake build system..
# This mostly exists just to have autohell/mozilla's $DEPTH but why not expand it a bit for consistency.

### mk_topsrcdir is the absolute path for the top source directory
### mk_srcdir is the absolute path for the current source directory
### mk_topobjdir is the absolute path for the top object directory
### mk_objdir is the absolute path for the current source directory
### mk_depth is the relative difference between the current source directory and the topsrcdir/ eg. ../../..
### mk_relpath is named path between the current source/obj directory from top src/obj eg. app/base/content

macro(mk_paths)
  # Makefile vars
  set(mk_topsrcdir ${CMAKE_SOURCE_DIR})
  set(mk_srcdir ${CMAKE_CURRENT_SOURCE_DIR})
  set(mk_topobjdir ${CMAKE_BINARY_DIR})
  set(mk_objdir ${CMAKE_CURRENT_BINARY_DIR})
  set(mk_VPATH ${CMAKE_SOURCE_DIR})

  # figure out DEPTH
    if (mk_topsrcdir STREQUAL mk_srcdir)
      set(mk_depth ".")
    else()
      set(mk_depth ${mk_srcdir})
      string(REPLACE "${mk_topsrcdir}/" "" mk_depth ${mk_srcdir})
      if (mk_depth MATCHES "([^\/]+)")
        string(REGEX REPLACE "([^\/]+)" ".." mk_depth ${mk_depth})
      else()
        set(mk_depth "..")
      endif()
    endif()
    
  # figure out relpath
    if (mk_topsrcdir STREQUAL mk_srcdir)
      set(mk_relpath ".")
    else()
      set(mk_relpath ${mk_srcdir})
      string(REPLACE "${mk_topsrcdir}/" "" mk_relpath ${mk_srcdir})
    endif()
    
    message(${mk_topobjdir}/${mk_relpath})
endmacro(mk_paths)