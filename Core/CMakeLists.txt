
set(Core_sources gui_registry.cpp plugin.cpp registry.cpp core_model.cpp)
set(Core_headers core_model.h gui_registry.h iplayer.h plugin.h registry.h TBSE_Core_config.h template_registry.h terrain_element.h)

add_library(TBSE_Core SHARED ${Core_sources} ${Core_headers} )

if(UNIX)
  target_link_libraries (TBSE_Core boost_filesystem)
endif()

if(WIN32)
  install(TARGETS TBSE_Core DESTINATION bin)
else()
  install(TARGETS TBSE_Core DESTINATION lib)
endif()
