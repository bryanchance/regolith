mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# Userscope Nginx systemd Service
pyPreprocess(
    ${mk_depth}/aura/templates/nginx/nginx.service.in
    aura-${varUserClass}-${varUserName}-nginx.service
    -Fsubstitution
    -DAURA_VERSION="${varTargetAuraVersion}"
    -DAURA_USER_CLASS="${varUserClass}"
    -DAURA_USER_NAME="${varUserName}"
)

# Userscope Nginx Server Instance
pyPreprocess(
${mk_depth}/aura/templates/nginx/nginx.conf.in
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
pyPreprocess(
    ${mk_depth}/aura/templates/nginx/standard.proxy.in
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

# VHOST for addons.palemoon.org
set(varSubdomain "addons")
set(varRootDomain "palemoon.org")
set(varDomain "${varSubdomain}.${varRootDomain}")
pyPreprocess(
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
pyPreprocess(
    ${mk_depth}/aura/templates/nginx/standard.proxy.in
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
pyPreprocess(
    ${mk_depth}/aura/templates/nginx/standard.vhost.in
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
pyPreprocess(
    ${mk_depth}/aura/templates/nginx/standard.proxy.in
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
pyPreprocess(
    ${mk_depth}/aura/templates/nginx/standard.vhost.in
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