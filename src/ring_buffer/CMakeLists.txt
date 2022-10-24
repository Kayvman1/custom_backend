add_library(
    ring_buffer SHARED
    ring_buffer.cpp
    ring_buffer.h
)

add_library(
    virtual_socket  SHARED
    virtual_socket.cpp 
    virtual_socket.h
)
target_include_directories(virtual_socket       PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(ring_buffer          PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries     (virtual_socket       PUBLIC ring_buffer)
