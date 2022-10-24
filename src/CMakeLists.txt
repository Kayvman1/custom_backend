add_subdirectory(ring_buffer)

add_library(packets         packets/packets.cpp)
add_library(server          server/server.cpp)
add_library(handlers        server/packet_handlers.cpp)
add_library(posts           posts/post.cpp)
add_library(accounts        accounts/account.cpp)




target_include_directories(ring_buffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(packets     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(server      PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(handlers    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(posts       PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(accounts    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


target_link_libraries(server PUBLIC virtual_socket packets handlers ring_buffer)
target_link_libraries(packets PUBLIC accounts posts)



set(CMAKE_BUILD_TYPE Debug)