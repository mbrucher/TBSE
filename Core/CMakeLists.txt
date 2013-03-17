set(Core_sources gui_registry.cpp plugin.cpp core_model.cpp terrain_element.cpp)
set(Core_headers base_building.h base_unit.h building.h gui_registry.h iplayer.h plugin.h TBSE_Core_config.h template_registry.h terrain_element.h terrain_modifier.h unit.h weapon.h)
set(Core_moc_headers core_model.h)

QT4_WRAP_CPP(Qt_Core_moc_sources ${Core_moc_headers})

add_library(TBSE_Core SHARED ${Core_sources} ${Qt_Core_moc_sources} ${Core_headers} ${Core_moc_headers} )

if(WIN32)
  target_link_libraries (TBSE_Core ${QT_LIBRARIES})
else()
  target_link_libraries (TBSE_Core boost_filesystem boost_system ${QT_LIBRARIES})
endif()

if(WIN32)
  install(TARGETS TBSE_Core DESTINATION bin)
else()
  install(TARGETS TBSE_Core DESTINATION lib)
endif()
