
set(Core_xsd ${CMAKE_CURRENT_SOURCE_DIR}/../Schemas/Core/base_building.xsd
  ${CMAKE_CURRENT_SOURCE_DIR}/../Schemas/Core/base_map.xsd
  ${CMAKE_CURRENT_SOURCE_DIR}/../Schemas/Core/base_unit.xsd
  ${CMAKE_CURRENT_SOURCE_DIR}/../Schemas/Core/weapon.xsd
  )

xsd_to_source( "${Core_xsd}" Core_generated)

set(Core_sources gui_registry.cpp plugin.cpp core_model.cpp terrain_element.cpp xsd_traits.cpp)
set(Core_headers building.h gui_registry.h iplayer.h plugin.h TBSE_Core_config.h template_registry.h terrain_element.h terrain_modifier.h unit.h xsd_traits.h)
set(Core_moc_headers core_model.h)

QT4_WRAP_CPP(Qt_Core_moc_sources ${Core_moc_headers})

add_library(TBSE_Core SHARED ${Core_sources} ${Qt_Core_moc_sources} ${Core_headers} ${Core_moc_headers} ${Core_generated})

if(WIN32)
  target_link_libraries (TBSE_Core ${QT_QTXML_LIBRARIES} ${QT_LIBRARIES})
else()
  target_link_libraries (TBSE_Core boost_filesystem boost_system ${QT_QTXML_LIBRARIES} ${QT_LIBRARIES})
endif()

if(WIN32)
  install(TARGETS TBSE_Core DESTINATION bin)
else()
  install(TARGETS TBSE_Core DESTINATION lib)
endif()
