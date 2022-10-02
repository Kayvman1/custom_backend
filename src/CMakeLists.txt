add_subdirectory(ring_buffer)

add_library(packets         packets/packets.cpp)
add_library(server          server/server.cpp)
add_library(handlers        server/packet_handlers.cpp)




target_include_directories(ring_buffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(packets     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(server      PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(handlers    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(handlers PRIVATE)
target_link_libraries(server PUBLIC virtual_socket packets handlers)



set(CMAKE_BUILD_TYPE Debug)