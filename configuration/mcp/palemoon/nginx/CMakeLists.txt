build_macro_mkPaths()
SETUP_FINAL_TARGET()



# Userscope Nginx systemd Service
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/nginx.service.in
    ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-nginx.service
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
)

# Userscope Nginx Server Instance
build_func_preprocess(
${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/nginx.conf.in
    nginx.conf
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_IPV4="${varSystemIPv4}"
    -DAURA_IPV6="${varSystemIPv6}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
)

# Proxy file for addons.palemoon.org
set(varDomain "addons.palemoon.org")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${varDomain}.proxy
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_IPV4="${varSystemIPv4}" 
    -DAURA_IPV6="${varSystemIPv6}"
    -DAURA_USER_CLASS="${varUserClass}" 
    -DAURA_USER_NAME="${varUserName}"
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ENABLE_SSL=1
    -DNGX_SSL_CERT="${varDomain}"
    -DNGX_ENABLE_CLOUDFLARE=1
)

# VHOST for addons.palemoon.org
set(varSubdomain "addons")
set(varRootDomain "palemoon.org")
set(varDomain "${varSubdomain}.${varRootDomain}")
build_func_preprocess(
    ${varDomain}.vhost.in
    ${varDomain}.vhost
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
    -DNGX_ENABLE_PHP=1
    -DPHP_VERSION_56=1
)

# Proxy file for dev.addons.palemoon.org
set(varDomain "dev.addons.palemoon.org")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${varDomain}.proxy
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_IPV4="${varSystemIPv4}"
    -DAURA_IPV6="${varSystemIPv6}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ENABLE_SSL=1
    -DNGX_SSL_CERT="addons.palemoon.org"
)

# VHOST for dev.addons.palemoon.org
set(varSubdomain "dev.addons")
set(varRootDomain "palemoon.org")
set(varDomain "${varSubdomain}.${varRootDomain}")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${varDomain}.vhost
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
    -DNGX_OVERRIDE_SUBDOMAIN="testing"
    -DNGX_ENABLE_PHP=1
    -DPHP_VERSION_70=1
)

# Proxy file for developer.palemoon.org
set(varDomain "developer.palemoon.org")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${varDomain}.proxy
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_IPV4="${varSystemIPv4}"
    -DAURA_IPV6="${varSystemIPv6}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ENABLE_SSL=1
    -DNGX_SSL_CERT="${varDomain}"
)

# VHOST for developer.palemoon.org
set(varSubdomain "developer")
set(varRootDomain "palemoon.org")
set(varDomain "${varSubdomain}.${varRootDomain}")
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${varDomain}.vhost
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
    -DNGX_DOMAIN="${varDomain}"
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubdomain}"
    -DNGX_ENABLE_PHP=1
    -DPHP_VERSION_56=1
    -DNGX_ENABLE_PHP_404=1
    -DNGX_ENABLE_ENANO=1
)