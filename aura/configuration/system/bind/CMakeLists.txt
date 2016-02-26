mk_paths()

file(MAKE_DIRECTORY ${CMAKE_INSTALL_PREFIX}/${mk_relpath})

# Set nameservers
set(varBindNS1 "ns1.binocnetwork.com")
set(varBindNS2 "ns2.binocnetwork.com")

# Preprocess Main BIND Files
pyPreprocess(named.conf.in named.conf)
pyPreprocess(named.inc.in named.inc)

# Preprocess zones for class: binoc
set(varBindDomain "binocnetwork.com")
pyPreprocess(${varBindDomain}.zone.in ${varBindDomain}.zone -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DBIND_NS1="${varBindNS1}" -DBIND_NS2="${varBindNS2}" -DBIND_DOMAIN="${varBindDomain}")

set(varBindDomain "binocglobal.com")
pyPreprocess(standard.zone.in ${varBindDomain}.zone -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DBIND_NS1="${varBindNS1}" -DBIND_NS2="${varBindNS2}" -DBIND_DOMAIN="${varBindDomain}")

set(varBindDomain "binaryoutcast.com")
pyPreprocess(${varBindDomain}.zone.in ${varBindDomain}.zone -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DBIND_NS1="${varBindNS1}" -DBIND_NS2="${varBindNS2}" -DBIND_DOMAIN="${varBindDomain}")

set(varBindDomain "mattatobin.com")
pyPreprocess(${varBindDomain}.zone.in ${varBindDomain}.zone -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DBIND_NS1="${varBindNS1}" -DBIND_NS2="${varBindNS2}" -DBIND_DOMAIN="${varBindDomain}")

set(varBindDomain "royalgeekworld.com")
pyPreprocess(${varBindDomain}.zone.in ${varBindDomain}.zone -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DBIND_NS1="${varBindNS1}" -DBIND_NS2="${varBindNS2}" -DBIND_DOMAIN="${varBindDomain}")

set(varBindDomain "royalgeekworld.net")
pyPreprocess(${varBindDomain}.zone.in ${varBindDomain}.zone -Fsubstitution -DAURA_IPV4="${varSystemIPv4}" -DAURA_IPV6="${varSystemIPv6}" -DBIND_NS1="${varBindNS1}" -DBIND_NS2="${varBindNS2}" -DBIND_DOMAIN="${varBindDomain}")

# Preprocess zones for class: staff

# Preprocess zones for class: unaffiliated
### Add zones for kokomosaferefuge and dovedesign

# Preprocess zones for domains not on Quartz