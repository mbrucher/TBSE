set(Qt_GUI_sources main.cpp main_window.cpp)
set(Qt_GUI_headers main.h TBSE_GUI_config.h)
set(Qt_GUI_moc_headers main_window.h)
set(Qt_GUI_resources resources.qrc)
set(Qt_GUI_ui main_window.ui)

QT4_WRAP_CPP(Qt_GUI_moc_sources ${Qt_GUI_moc_headers})
QT4_WRAP_UI(Qt_GUI_headers_UI ${Qt_GUI_ui})
QT4_ADD_RESOURCES(Qt_GUI_sources_RC ${Qt_GUI_resources})

add_library(TBSE_GUI SHARED ${Qt_GUI_sources} ${Qt_GUI_headers} ${Qt_GUI_moc_sources} ${Qt_GUI_sources_RC} ${Qt_GUI_headers_UI} ${Qt_GUI_moc_headers})
target_link_libraries (TBSE_GUI TBSE_Core ${QT_LIBRARIES})

if(WIN32)
  install(TARGETS TBSE_GUI DESTINATION bin)
else()
  install(TARGETS TBSE_GUI DESTINATION lib)
endif()

add_subdirectory(2DGUI)
