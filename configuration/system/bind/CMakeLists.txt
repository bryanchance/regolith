build_macro_mkPaths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# Set vars
set(varBindNS1 "ns1.binocnetwork.com")
set(varBindNS2 "ns2.binocnetwork.com")
set(varBindConfPrefix "aura/configuration/system/bind")

# BIND Service
build_func_preprocess(bind.service.in aura-${varUserClass}-${varUserName}-bind.service -Fsubstitution -DAURA_USER_CLASS="${varUserClass}" -DAURA_USER_NAME="${varUserName}" -DBIND_CONF_PREFIX="${varBindConfPrefix}")

# Preprocess Main BIND Files
build_func_preprocess(named.conf.in named.conf -Fsubstitution -DBIND_CONF_PREFIX="${varBindConfPrefix}")
build_func_preprocess(named.inc.in named.inc -Fsubstitution -DBIND_CONF_PREFIX="${varBindConfPrefix}")

# Preprocess zones for class: binoc
set(varBindDomain "binocnetwork.com")
build_func_preprocess(${varBindDomain}.zone.in ${varBindDomain}.zone -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DBIND_NS1="${varBindNS1}" -DBIND_NS2="${varBindNS2}" -DBIND_DOMAIN="${varBindDomain}")

set(varBindDomain "binocglobal.com")
build_func_preprocess(standard.zone.in ${varBindDomain}.zone -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DBIND_NS1="${varBindNS1}" -DBIND_NS2="${varBindNS2}" -DBIND_DOMAIN="${varBindDomain}")

set(varBindDomain "binaryoutcast.com")
build_func_preprocess(${varBindDomain}.zone.in ${varBindDomain}.zone -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DBIND_NS1="${varBindNS1}" -DBIND_NS2="${varBindNS2}" -DBIND_DOMAIN="${varBindDomain}")

set(varBindDomain "mattatobin.com")
build_func_preprocess(${varBindDomain}.zone.in ${varBindDomain}.zone -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DBIND_NS1="${varBindNS1}" -DBIND_NS2="${varBindNS2}" -DBIND_DOMAIN="${varBindDomain}")

set(varBindDomain "royalgeekworld.com")
build_func_preprocess(${varBindDomain}.zone.in ${varBindDomain}.zone -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DBIND_NS1="${varBindNS1}" -DBIND_NS2="${varBindNS2}" -DBIND_DOMAIN="${varBindDomain}")

set(varBindDomain "royalgeekworld.net")
build_func_preprocess(${varBindDomain}.zone.in ${varBindDomain}.zone -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DBIND_NS1="${varBindNS1}" -DBIND_NS2="${varBindNS2}" -DBIND_DOMAIN="${varBindDomain}")

# Preprocess zones for class: staff

# Preprocess zones for class: unaffiliated
### Add zones for kokomosaferefuge and dovedesign

set(varBindDomain "susantobinart.com")
build_func_preprocess(standard.zone.in ${varBindDomain}.zone -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DBIND_NS1="${varBindNS1}" -DBIND_NS2="${varBindNS2}" -DBIND_DOMAIN="${varBindDomain}")

set(varBindDomain "kokomosaferefuge.org")
build_func_preprocess(standard.zone.in ${varBindDomain}.zone -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DBIND_NS1="${varBindNS1}" -DBIND_NS2="${varBindNS2}" -DBIND_DOMAIN="${varBindDomain}")

# Preprocess zones for domains not on Quartz