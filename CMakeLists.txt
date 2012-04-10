cmake_minimum_required (VERSION 2.6)
project (TBSE)

set (TBSE_VERSION_MAJOR 0)
set (TBSE_VERSION_MINOR 0)

FIND_PACKAGE(Git)

GIT_TREE_INFO( . TBSE_GIT )

FIND_PACKAGE(Boost REQUIRED)

link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )

FIND_PACKAGE(Qt4 REQUIRED)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

configure_file (
  "${PROJECT_SOURCE_DIR}/TBSE_config.h.in"
  "${PROJECT_BINARY_DIR}/TBSE_config.h"
  )

add_subdirectory(Core)
add_subdirectory(GUI)

file(GLOB TBSE_sources *.cpp)
file(GLOB TBSE_headers *.h)

add_executable(TBSE ${TBSE_sources} ${TBSE_headers})
target_link_libraries (TBSE TBSE_Core)
install(TARGETS TBSE DESTINATION bin)
