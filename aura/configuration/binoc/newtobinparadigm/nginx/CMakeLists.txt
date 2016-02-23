mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

py_pp(${mk_depth}/aura/templates/nginx/nginx.conf.in nginx.conf -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DAURA_USER_CLASS="binoc" -DAURA_USER_NAME="newtobinparadigm")

py_pp(${mk_depth}/aura/templates/nginx/standard.proxy.in www.mattatobin.com.proxy -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DAURA_USER_CLASS="binoc" -DAURA_USER_NAME="newtobinparadigm" -DNGX_DOMAIN="mattatobin.com" -DNGX_MAINDOMAIN=1)