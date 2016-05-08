# This function will send the file to the preprocessor and output it to the eq objdir..
# Because this is not *yet* a replacement for MozBuild we will just copy the output to to dist/bin using
# the same directory structure as it is laid out in "source".

### This makes heavy use of mk_paths() which roughly duplicates the variables used in autohell/mozilla.
### mk_topsrcdir is the absolute path for the top source directory
### mk_srcdir is the absolute path for the current source directory
### mk_topobjdir is the absolute path for the top object directory
### mk_objdir is the absolute path for the current object directory
### mk_depth is the relative difference between the current source directory and the topsrcdir/ eg. ../../..
### mk_relpath is named path between the current source/obj directory from top src/obj eg. app/base/content


# Current usage: pyPreprocess(nginx.conf.in nginx.conf -Fsubstitution -DNGX_USER="root")
function(pyPreprocess varInputFile varOutputFile)
  # Remove the semicolon separator from the list of arguments we haven't directly said exist..
  # Namely the ones (primarily defines) we want to pass to the preprocessor
  string (REPLACE ";" " " varDefines "${ARGN}")

  # Add some random numbers so that target depends are unique because bananas.. or something.
  string(RANDOM LENGTH 10 ALPHABET 0123456789 varNumber)
  set(varOutputDepend PP_${varNumber}_${varOutputFile})

  # Create the custom command
  # XXX: It would be nice if we could get this damned thing to do a foreach from a list in and of its self somehow...
  # XXX: TODO - MAKE varOutputFile based on varInputFile and strip out '.in' extension
  add_custom_command (
    WORKING_DIRECTORY ${mk_srcdir}
    COMMAND python ${mk_depth}/config/preprocessor/Preprocessor.py ${mk_srcdir}/${varInputFile} ${varDefines} -o ${mk_objdir}/${varOutputFile}.pp
    COMMAND cp -v ${mk_objdir}/${varOutputFile}.pp ${CMAKE_INSTALL_PREFIX}/${mk_relpath}/${varOutputFile}
    DEPENDS ${varOutputDepend}
    OUTPUT ${mk_objdir}/${varOutputFile}.pp
    OUTPUT ${CMAKE_INSTALL_PREFIX}/${mk_relpath}/${varOutputFile}
  )

  # Attach the command to a target
  add_custom_target (
    ${varOutputDepend}
    ALL
    DEPENDS ${mk_objdir}/${varOutputFile}.pp ${CMAKE_INSTALL_PREFIX}/${mk_relpath}/${varOutputFile}
  )
  
endfunction(pyPreprocess)