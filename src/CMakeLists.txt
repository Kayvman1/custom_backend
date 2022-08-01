add_library(packets     packets/packets.cpp)
add_library(ring_buffer ring_buffer/ring_buffer.cpp)

target_include_directories(ring_buffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(packets     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
