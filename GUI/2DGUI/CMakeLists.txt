
file(GLOB Qt_2DGUI_sources auto_register.cpp scene_model.cpp scene_view.cpp hexagon_item.cpp)
file(GLOB Qt_2DGUI_headers hexagon_item.h)
file(GLOB Qt_2DGUI_moc_headers scene_model.h scene_view.h)
file(GLOB Qt_2DGUI_resources resources_2dgui.qrc)
file(GLOB Qt_2DGUI_ui )

QT4_WRAP_CPP(Qt_2DGUI_moc_sources ${Qt_2DGUI_moc_headers})
QT4_WRAP_UI(Qt_2DGUI_headers_UI ${Qt_2DGUI_ui})
QT4_ADD_RESOURCES(Qt_2DGUI_sources_RC ${Qt_2DGUI_resources})

add_library(TBSE_Qt_2DGUI SHARED ${Qt_2DGUI_sources} ${Qt_2DGUI_headers} ${Qt_2DGUI_moc_sources} ${Qt_2DGUI_moc_headers} ${Qt_2DGUI_sources_RC} ${Qt_2DGUI_headers_UI})
target_link_libraries (TBSE_Qt_2DGUI TBSE_Core TBSE_GUI ${QT_LIBRARIES})
install(TARGETS TBSE_Qt_2DGUI DESTINATION lib/plugins)
