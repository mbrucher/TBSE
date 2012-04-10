
file(GLOB Core_sources *.cpp)
file(GLOB Core_headers *.h)

add_library(TBSE_Core SHARED ${Core_sources} ${Core_headers} )

if(UNIX)
  target_link_libraries (TBSE_Core boost_filesystem)
endif()

if(WIN32)
  install(TARGETS TBSE_Core DESTINATION bin)
else()
  install(TARGETS TBSE_Core DESTINATION lib)
endif()
