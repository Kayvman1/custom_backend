add_library(
    ring_buffer SHARED
    ring_buffer.cpp
    ring_buffer.h
)

target_include_directories(ring_buffer          PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
