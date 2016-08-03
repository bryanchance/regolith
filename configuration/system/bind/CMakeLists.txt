build_macro_mkPaths()
SETUP_FINAL_TARGET()
AURA_DEFINES()


# Set vars
set(varBindNS1 "ns1.binocnetwork.com")
set(varBindNS2 "ns2.binocnetwork.com")
set(varBindConfPrefix "aura/configuration/system/bind")

set(varBindDefines
    ${varAuraDefines}
    -DBIND_CONF_PREFIX="${varBindConfPrefix}"
    -DBIND_NS1="${varBindNS1}"
    -DBIND_NS2="${varBindNS2}"
)

# BIND Service
build_func_preprocess(
    bind.service.in
    ${FINAL_TARGET}/aura-${varUserClass}-${varUserName}-bind.service
    ${varBindDefines}
)

# Preprocess Main BIND Files
build_func_preprocess(
    named.conf.in
    ${FINAL_TARGET}/named.conf
    ${varBindDefines}
)

build_func_preprocess(
    named.inc.in
    ${FINAL_TARGET}/named.inc
    ${varBindDefines}
)

# Preprocess zones for class: binoc
set(varBindDomain "binocnetwork.com")
build_func_preprocess(
    ${varBindDomain}.zone.in
    ${FINAL_TARGET}/${varBindDomain}.zone
    ${varBindDefines}
    -DBIND_DOMAIN="${varBindDomain}"
)

set(varBindDomain "binocglobal.com")
build_func_preprocess(
    standard.zone.in
    ${FINAL_TARGET}/${varBindDomain}.zone
    ${varBindDefines}
    -DBIND_DOMAIN="${varBindDomain}"
)

set(varBindDomain "binaryoutcast.com")
build_func_preprocess(
    ${varBindDomain}.zone.in
    ${FINAL_TARGET}/${varBindDomain}.zone
    ${varBindDefines}
    -DBIND_DOMAIN="${varBindDomain}"
)

set(varBindDomain "mattatobin.com")
build_func_preprocess(
    ${varBindDomain}.zone.in
    ${FINAL_TARGET}/${varBindDomain}.zone
    ${varBindDefines}
    -DBIND_DOMAIN="${varBindDomain}"
)

set(varBindDomain "hiddenpalace.zone")
build_func_preprocess(
    standard.zone.in
    ${FINAL_TARGET}/${varBindDomain}.zone
    ${varBindDefines}
    -DBIND_DOMAIN="${varBindDomain}"
)

set(varBindDomain "royalgeekworld.com")
build_func_preprocess(
    ${varBindDomain}.zone.in
    ${FINAL_TARGET}/${varBindDomain}.zone
    ${varBindDefines}
    -DBIND_DOMAIN="${varBindDomain}"
)

set(varBindDomain "royalgeekworld.net")
build_func_preprocess(
    ${varBindDomain}.zone.in
    ${FINAL_TARGET}/${varBindDomain}.zone
    ${varBindDefines}
    -DBIND_DOMAIN="${varBindDomain}"
)

# Preprocess zones for class: staff

# Preprocess zones for class: unaffiliated
### Add zones for kokomosaferefuge and dovedesign

set(varBindDomain "susantobinart.com")
build_func_preprocess(
    standard.zone.in
    ${FINAL_TARGET}/${varBindDomain}.zone
    ${varBindDefines}
    -DBIND_DOMAIN="${varBindDomain}"
)

set(varBindDomain "kokomosaferefuge.org")
build_func_preprocess(
    standard.zone.in
    ${FINAL_TARGET}/${varBindDomain}.zone
    ${varBindDefines}
    -DBIND_DOMAIN="${varBindDomain}"
)

set(varBindDomain "sage2012.org")
build_func_preprocess(
    standard.zone.in
    ${FINAL_TARGET}/${varBindDomain}.zone
    ${varBindDefines}
    -DBIND_DOMAIN="${varBindDomain}"
)
# Preprocess zones for domains not on Quartz