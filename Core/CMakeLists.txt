
set(Core_sources gui_registry.cpp plugin.cpp registry.cpp)
set(Core_headers gui_registry.h plugin.h registry.h TBSE_Core_config.h template_registry.h)

add_library(TBSE_Core SHARED ${Core_sources} ${Core_headers} )

if(UNIX)
  target_link_libraries (TBSE_Core boost_filesystem)
endif()

if(WIN32)
  install(TARGETS TBSE_Core DESTINATION bin)
else()
  install(TARGETS TBSE_Core DESTINATION lib)
endif()
