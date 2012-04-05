
file(GLOB Core_sources *.cpp)
file(GLOB Core_headers *.h)

add_library(TGSE_Core SHARED ${Core_sources} ${Core_headers} )

if(UNIX)
  target_link_libraries (TGSE_Core boost_filesystem)
endif()

if(WIN32)
  install(TARGETS TGSE_Core DESTINATION bin)
else()
  install(TARGETS TGSE_Core DESTINATION lib)
endif()
