add_subdirectory(ring_buffer)

add_library(packets         packets/packets.cpp)
add_library(server          server/server.cpp)
add_library(handlers        server/packet_handlers.cpp)
add_library(posts           posts/post.cpp)
add_library(accounts        accounts/account.cpp)
add_library(client          server/client.cpp)
add_library(lru_cache         lru_cache/lru_cache.cpp)




target_include_directories(ring_buffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(packets     PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(server      PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(handlers    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(posts       PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(accounts    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(client      PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_include_directories(lru_cahce      PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})



target_link_libraries(server PUBLIC  packets handlers ring_buffer client lru_cache)
target_link_libraries(packets PUBLIC accounts posts)

target_link_libraries(handlers PUBLIC  server)
target_compile_options(server PUBLIC -g )

set(CMAKE_BUILD_TYPE Debug)