add_subdirectory(ring_buffer)

add_library(packets         packets/packets.cpp)
add_library(server          server/server.cpp)



target_include_directories(ring_buffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(packets     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(server      PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(server PUBLIC virtual_socket packets)


set(CMAKE_BUILD_TYPE Debug)