cmake_minimum_required(VERSION 3.2)
#SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")
project(IndiewriterBackend)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)


add_subdirectory(lib/Catch2)
add_subdirectory(src)

add_executable(tests tests/test.cpp) 
add_executable(server_runner runner/main.cpp)

find_path(HIREDIS_HEADER hiredis)
target_include_directories(server_runner PUBLIC ${HIREDIS_HEADER})
find_library(HIREDIS_LIB hiredis)
target_link_libraries(server_runner PUBLIC ${HIREDIS_LIB})

# <------------ add hiredis dependency --------------->
find_path(HIREDIS_HEADER hiredis)
target_include_directories(server_runner PUBLIC ${HIREDIS_HEADER})

find_library(HIREDIS_LIB hiredis)
target_link_libraries(server_runner PUBLIC ${HIREDIS_LIB})

# <------------ add redis-plus-plus dependency -------------->
# NOTE: this should be *sw* NOT *redis++*
find_path(REDIS_PLUS_PLUS_HEADER sw)
target_include_directories(server_runner PUBLIC ${REDIS_PLUS_PLUS_HEADER})

find_library(REDIS_PLUS_PLUS_LIB redis++)
target_link_libraries(server_runner PUBLIC ${REDIS_PLUS_PLUS_LIB})


target_link_libraries(server_runner PUBLIC Threads::Threads packets ring_buffer server virtual_socket )

target_link_libraries(tests PUBLIC Catch2::Catch2WithMain Threads::Threads packets ring_buffer 
server virtual_socket)


target_compile_options(tests PUBLIC -pthread -g -lhiredis -lredis++  -std=c++17)

target_compile_options(server_runner PUBLIC -pthread -g -lhiredis -lredis++  -std=c++17 )



target_compile_features(server_runner PRIVATE cxx_std_17)

target_compile_features(tests PRIVATE cxx_std_17)


include(CTest)
include(Catch)
catch_discover_tests(tests)
