add_library(packets packets/packets.cpp)

target_include_directories(packets PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_BUILD_TYPE Debug) 