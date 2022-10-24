add_library(
    packet_handlers  SHARED
    packet_handlers.cpp 
    packet_handlers.h
)
add_library(
    client  SHARED
    client.cpp 
    client.h
)
target_include_directories(packet_handlers        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(client                 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries     (packet_handler         PUBLIC client packet_handlers)
