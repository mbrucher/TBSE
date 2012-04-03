
file(GLOB Qt_2DGUI_sources *.cpp)
file(GLOB Qt_2DGUI_headers *.h)
QT4_WRAP_CPP(Qt_2DGUI_headers_MOC ${Qt_2DGUI_headers})

add_library(TGSE_Qt_2DGUI SHARED ${Qt_2DGUI_sources} ${Qt_2DGUI_headers} ${Qt_2DGUI_headers_MOC} )
target_link_libraries (TGSE_Qt_2DGUI TGSE_Core ${QT_LIBRARIES})
install(TARGETS TGSE_Qt_2DGUI DESTINATION lib/plugins)
