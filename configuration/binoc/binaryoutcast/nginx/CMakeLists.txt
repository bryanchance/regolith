# ===| Notes |=================================================================

# Nginx Configuration is generated using the Python C-Style Preprocessor and a
# series of variables and lists with entries passed as defines.
#
# The preprocessor function build_func_preprocess takes at least two arguments
# (inputFile and outputFile) as well as any number of defines. It is
# recommended to at least pass varAuraDefines as these contain foundational
# defines derived from variables that are set further up the line.

# Each UNIX user needs to have one user instance Nginx SystemD service unit
# file and a user instance Nginx Server conf file. Just pass varAuraDefines 
# as the third argument to the preprocessor function build_func_preprocess.

# Three variables need to be set for each site: varRootDomain, varSubDomain,
# and varNginxDefines which is a list that can also include varAuraDefines.

# varRootDomain is always set to the TLD ie binaryoutcast.com
# varSubDomain is set to the subdomain of the TLD or www if the configuration
# is for the TLD its self.
# varNginxDefines is a list of c-style defines to be then passed to the
# preprocessor function. They should be in the following format
# -DVARIABLE="value" or -DVARIABLE=1

# Preprocessor Defines for standard proxy and standard vhost are as follows:
# -DNGX_ROOTDOMAIN - Set to ${varRootDomain}
# -DNGX_SUBDOMAIN - Set to ${varSubDomain}
# -DNGX_OVERRIDE_SUBDOMAIN - Set value to the target webroot if the directory
# is different than the actual subdomain
# -DNGX_MAINDOMAIN - Set to 1 if this is the TLD
# -DNGX_ENABLE_SSL - Set to 1 to enable SSL Support
# -DNGX_SSL_CERT - Set value to the name of the .crt file without the extension
# -DNGX_ENABLE_CLOUDFLARE - Set to 1 if behind CloudFlare so that you get the
# real IP address of the client
# -DNGX_ENABLE_AUTOINDEX - Set to 1 to enable AutoIndex on this site
# -DNGX_INCLUDE - Set value to the path of additional Nginx directives to be
# included in the vhost file
# -DNGX_ENABLE_PHP - Set to 1 if PHP should be enabled on this site
# -DNGX_ENABLE_PHP_404 - Set to 1 if PHP should handle 404s errors from PHP
# -DNGX_ENABLE_CMSMS - Set to 1 if CMS Made Simple is used on this site
# -DNGX_ENABLE_WORDPRESS - Set to 1 if Wordpress is used on this site
# -DNGX_ENABLE_ENANO - Set to 1 if Enano CMS is used on this site
# -DPHP_VERSION_56 - Set to 1 if PHP 5.6 is desired rather than system default
# -DPHP_VERSION_70 - Set to 1 if PHP 7.x is desired rather than system default

# =============================================================================

# ===| Macros |================================================================

build_macro_mkPaths()
SETUP_FINAL_TARGET()
AURA_DEFINES()

# =============================================================================

# ===| User Nginx Instance SystemD Unit |======================================

build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/nginx.service.in
    ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-nginx.service
    ${varAuraDefines}
)

# =============================================================================

# ===| User Nginx Server Configuration |=======================================

build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/nginx.conf.in
    ${FINAL_TARGET}/nginx.conf
    ${varAuraDefines}
)

# =============================================================================

# ===| www.binaryoutcast.com |=================================================

# Set Variables to be used as Preprocessor defines
set(varRootDomain "binaryoutcast.com")
set(varSubDomain "www")
set(varNginxDefines
    ${varAuraDefines}
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubDomain}"
    -DNGX_MAINDOMAIN=1
    -DNGX_INCLUDE="${mk_srcdir}/${varSubDomain}.${varRootDomain}.vhost.inc"
    -DNGX_ENABLE_PHP=1
    -DNGX_ENABLE_CMSMS=1
    -DPHP_VERSION_56=1
)

# Proxy file
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.proxy
    ${varNginxDefines}
)

# VHost file
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.vhost
    ${varNginxDefines}
)

# =============================================================================

# ===| techcentral.binaryoutcast.com |=========================================

# Set Variables to be used as Preprocessor defines
set(varRootDomain "binaryoutcast.com")
set(varSubDomain "techcentral")
set(varNginxDefines
    ${varAuraDefines}
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubDomain}"
    -DNGX_ENABLE_PHP=1
    -DNGX_ENABLE_WORDPRESS=1
    -DPHP_VERSION_70=1
)

# Proxy file
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.proxy
    ${varNginxDefines}
)

# VHost file
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.vhost
    ${varNginxDefines}
)

# =============================================================================

# ===| repository.binaryoutcast.com |==========================================

set(varRootDomain "binaryoutcast.com")
set(varSubDomain "repository")
set(varNginxDefines
    ${varAuraDefines}
    -DNGX_ROOTDOMAIN="${varRootDomain}"
    -DNGX_SUBDOMAIN="${varSubDomain}"
    -DNGX_ENABLE_PHP=1
    -DPHP_VERSION_70=1
)

# Proxy file
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.proxy.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.proxy
    ${varNginxDefines}
)

# VHost file
build_func_preprocess(
    ${mk_depth}/projects/${BUILD_PROJECT}/templates/nginx/standard.vhost.in
    ${FINAL_TARGET}/${varSubDomain}.${varRootDomain}.vhost
    ${varNginxDefines}
)

# =============================================================================