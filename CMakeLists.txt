cmake_minimum_required (VERSION 2.6)
project (TBSE)

set (TBSE_VERSION_MAJOR 0)
set (TBSE_VERSION_MINOR 0)

FIND_PACKAGE(GIT)

GIT_TREE_INFO( . TBSE_GIT )

FIND_PACKAGE(BOOST REQUIRED)

link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )

FIND_PACKAGE(QT4 REQUIRED)

configure_file (
  "${PROJECT_SOURCE_DIR}/TBSE_config.h.in"
  "${PROJECT_BINARY_DIR}/TBSE_config.h"
  )

add_subdirectory(Core)
  
add_executable(TGSE *.cpp *.h)
target_link_libraries (TGSE TGSE_Core)
