
file(GLOB Qt_2DGUI_sources auto_register.cpp scene_model.cpp scene_view.cpp)
file(GLOB Qt_2DGUI_headers )
file(GLOB Qt_2DGUI_moc_headers scene_model.h scene_view.h)
file(GLOB Qt_2DGUI_resources )
file(GLOB Qt_2DGUI_ui )

QT4_WRAP_CPP(Qt_2DGUI_moc_sources ${Qt_2DGUI_moc_headers})
QT4_WRAP_UI(Qt_2DGUI_headers_UI ${Qt_2DGUI_ui})
QT4_ADD_RESOURCES(Qt_2DGUI_sources_RC ${Qt_2DGUI_resources})

add_library(TBSE_Qt_2DGUI SHARED ${Qt_2DGUI_sources} ${Qt_2DGUI_headers} ${Qt_2DGUI_moc_sources} ${Qt_2DGUI_moc_headers} ${Qt_2DGUI_sources_RC} ${Qt_2DGUI_headers_UI})
target_link_libraries (TBSE_Qt_2DGUI TBSE_Core TBSE_GUI ${QT_LIBRARIES})
install(TARGETS TBSE_Qt_2DGUI DESTINATION lib/plugins)
