
file(GLOB Qt_2DGUI_sources *.cpp)
file(GLOB Qt_2DGUI_headers *.h)

add_library(TGSE_Qt_2DGUI SHARED ${Qt_2DGUI_sources} ${Qt_2DGUI_headers} )
target_link_libraries (TGSE_Qt_2DGUI TGSE_Core)
install(TARGETS TGSE_Qt_2DGUI DESTINATION bin)
