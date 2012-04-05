
file(GLOB Qt_2DGUI_sources *.cpp)
file(GLOB Qt_2DGUI_headers *.h)
file(GLOB Qt_2DGUI_resources *.qrc)
QT4_WRAP_CPP(Qt_2DGUI_headers_MOC ${Qt_2DGUI_headers})
QT4_ADD_RESOURCES(Qt_2DGUI_sources_RC ${Qt_2DGUI_resources})

add_library(TGSE_Qt_2DGUI SHARED ${Qt_2DGUI_sources} ${Qt_2DGUI_headers} ${Qt_2DGUI_headers_MOC} ${Qt_2DGUI_sources_RC})
target_link_libraries (TGSE_Qt_2DGUI TGSE_Core ${QT_LIBRARIES})
install(TARGETS TGSE_Qt_2DGUI DESTINATION lib/plugins)
