
file(GLOB Core_sources *.cpp)
file(GLOB Core_headers *.h)

add_library(TGSE_Core SHARED ${Core_sources} ${Core_headers} )
install(TARGETS TGSE_Core DESTINATION bin)
