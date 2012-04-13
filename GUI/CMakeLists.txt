
file(GLOB Qt_GUI_sources *.cpp *.cxx)
file(GLOB Qt_GUI_headers *.h)
file(GLOB Qt_GUI_resources *.qrc)
file(GLOB Qt_GUI_ui *.ui)

QT4_WRAP_CPP(Qt_GUI_headers_MOC ${Qt_GUI_headers})
QT4_WRAP_UI(Qt_GUI_headers_UI ${Qt_GUI_ui})
QT4_ADD_RESOURCES(Qt_GUI_sources_RC ${Qt_GUI_resources})

add_library(TBSE_GUI SHARED ${Qt_GUI_sources} ${Qt_GUI_headers} ${Qt_GUI_headers_MOC} ${Qt_GUI_sources_RC} ${Qt_GUI_headers_UI})
target_link_libraries (TBSE_GUI TBSE_Core ${QT_LIBRARIES})
install(TARGETS TBSE_GUI DESTINATION bin)

add_subdirectory(2DGUI)
