add_library(packets     packets/packets.cpp)
add_library(ring_buffer ring_buffer/ring_buffer.cpp)
add_library(virtual_socket ring_buffer/virtual_socket.cpp)
add_library(server      server/server.cpp)

target_include_directories(ring_buffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(packets     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(server      PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_BUILD_TYPE Debug)