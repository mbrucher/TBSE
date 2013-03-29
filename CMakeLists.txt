cmake_minimum_required (VERSION 2.6)
project (TBSE)

SET( CMAKE_MODULE_PATH
     "${PROJECT_SOURCE_DIR}/cmake"
     "${CMAKE_MODULE_PATH}" )

set (TBSE_VERSION_MAJOR 0)
set (TBSE_VERSION_MINOR 0)

FIND_PACKAGE(Git)

GIT_TREE_INFO( . TBSE_GIT )

FIND_PACKAGE(Boost REQUIRED)

link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} ${CMAKE_BINARY_DIR} )

set(QT_USE_XML TRUE)

FIND_PACKAGE(Qt4 REQUIRED)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

configure_file (
  "${PROJECT_SOURCE_DIR}/TBSE_config.h.in"
  "${PROJECT_BINARY_DIR}/TBSE_config.h"
  )

function(xsd_to_source Input_List Output_Generated)
 foreach(XSDFILENAME ${Input_List})
  STRING(  REGEX REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}" FILENAME ${XSDFILENAME} )
  STRING(  REGEX REPLACE "Schemas" "Generated" FILE_NAME ${FILENAME} )
  STRING(  REGEX REPLACE "xsd" "h" FILE_NAME_H ${FILE_NAME} )
  STRING(  REGEX REPLACE "xsd" "cpp" FILE_NAME_CPP ${FILE_NAME} )
  ADD_CUSTOM_COMMAND(
   OUTPUT ${FILE_NAME_H} ${FILE_NAME_CPP}
   COMMAND python ${CMAKE_SOURCE_DIR}/Scripts/xsd_to_source.py ${XSDFILENAME}
   DEPENDS ${CMAKE_SOURCE_DIR}/Scripts/xsd_to_source.py
   MAIN_DEPENDENCY ${XSDFILENAME}
   )
 set(FILES ${FILES} ${FILE_NAME_H} ${FILE_NAME_CPP})
 endforeach()
 set(${Output_Generated} ${FILES} PARENT_SCOPE)
endfunction()

add_subdirectory(Core)
add_subdirectory(GUI)

SET(TBSE_sources main.cpp)
SET(TBSE_headers TBSE_config.h)

add_executable(TBSE ${TBSE_sources} ${TBSE_headers})
target_link_libraries (TBSE TBSE_Core TBSE_GUI)
install(TARGETS TBSE DESTINATION bin)
