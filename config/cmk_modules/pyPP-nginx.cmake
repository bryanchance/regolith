# This function relies on function pyPreprocess() see config/cmk_modules/pyPreprocess.cmake for usage

function(pyPP_nginx varRole varMode)
    # Remove the semicolon separator from the list of arguments we haven't directly said exist...
    string (REPLACE ";" " " varDefines "${ARGN}")

    # Find out if the 3rd argument is an input file
    # If it is then we want to do logic on it to get varInputFile set to the input file
    if(${ARGC} GREATER "2")
        if(${ARGV2} MATCHES "(\-XINPUT_FILE\=\"(.*)\")")
            set(varInputFile ${ARGV2})
            string(REPLACE "\-XINPUT_FILE\=" "" varInputFile ${varInputFile})
            string(REPLACE "\"" "" varInputFile ${varInputFile})
            string(REPLACE ${ARGV2} "" varDefines ${varDefines})
        endif()
    endif()
    
    # NGINX has four types of files (roles) that need preprocessed.
    # Service, Server, Proxy, and VHost
    # VHost is special since this may use standard vhost or custom vhost
    if(varRole MATCHES "-XROLE=\"service\"")
        pyPreprocess(
            ${mk_depth}/aura/templates/nginx/nginx.service.in
            aura-${varUserClass}-${varUserName}-nginx.service
            -Fsubstitution
            -DAURA_VERSION="${varTargetAuraVersion}"
            -DAURA_USER_CLASS="${varUserClass}"
            -DAURA_USER_NAME="${varUserName}"
            ${varDefines}
        )
    elseif(varRole MATCHES "-XROLE=\"server\"")
        pyPreprocess(
            ${mk_depth}/aura/templates/nginx/nginx.conf.in
            nginx.conf
            -Fsubstitution
            -DAURA_VERSION="${varTargetAuraVersion}"
            -DAURA_IPV4="${varSystemIPv4}"
            -DAURA_IPV6="${varSystemIPv6}"
            -DAURA_USER_CLASS="${varUserClass}"
            -DAURA_USER_NAME="${varUserName}"
            ${varDefines}
        )
    elseif(varRole MATCHES "-XROLE=\"proxy\"")
        pyPreprocess(
            ${mk_depth}/aura/templates/nginx/standard.proxy.in
            www.${varDomain}.proxy
            -Fsubstitution
            -DAURA_VERSION="${varTargetAuraVersion}"
            -DAURA_IPV4="${varSystemIPv4}"
            -DAURA_IPV6="${varSystemIPv6}"
            -DAURA_USER_CLASS="${varUserClass}"
            -DAURA_USER_NAME="${varUserName}"
            -DNGX_DOMAIN="${varDomain}"
            ${varDefines}
         )
    elseif(varRole MATCHES "-XROLE=\"vhost\"")
        if(varMode MATCHES "-XMODE=\"standard\"")
            pyPreprocess(
                ${mk_depth}/aura/templates/nginx/standard.vhost.in
                ${varSubdomain}.${varRootDomain}.vhost
                -Fsubstitution
                -DAURA_VERSION="${varTargetAuraVersion}"
                -DAURA_USER_CLASS="${varUserClass}"
                -DAURA_USER_NAME="${varUserName}"
                -DNGX_DOMAIN="${varDomain}"
                -DNGX_ROOTDOMAIN="${varRootDomain}"
                -DNGX_SUBDOMAIN="${varSubdomain}"
                ${varDefines}
            )
        elseif(varMode MATCHES "-XMODE=\"custom\"")
            pyPreprocess(
                ${varInputFile}
                ${varSubdomain}.${varRootDomain}.vhost
                -Fsubstitution
                -DAURA_VERSION="${varTargetAuraVersion}"
                -DAURA_USER_CLASS="${varUserClass}"
                -DAURA_USER_NAME="${varUserName}"
                -DNGX_DOMAIN="${varDomain}"
                -DNGX_ROOTDOMAIN="${varRootDomain}"
                -DNGX_SUBDOMAIN="${varSubdomain}"
                ${varDefines}
            )
        endif()
    endif()
endfunction(pyPP_nginx)