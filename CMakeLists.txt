cmake_minimum_required(VERSION 3.2)
project(IndiewriterBackend)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
set(CMAKE_BUILD_TYPE Debug)

add_executable(tests tests/test.cpp) 
add_executable(server_runner runner/main.cpp)

# <------------ add hiredis dependency --------------->
find_path(HIREDIS_HEADER hiredis)
target_include_directories(server_runner PUBLIC ${HIREDIS_HEADER})
target_include_directories(tests PUBLIC ${HIREDIS_HEADER})

find_library(HIREDIS_LIB hiredis)
target_link_libraries(server_runner PUBLIC ${HIREDIS_LIB})
target_link_libraries(tests PUBLIC ${HIREDIS_LIB})

# <------------ add redis-plus-plus dependency -------------->
# NOTE: this should be *sw* NOT *redis++*
find_path(REDIS_PLUS_PLUS_HEADER sw)
target_include_directories(server_runner PUBLIC ${REDIS_PLUS_PLUS_HEADER})
target_include_directories(tests PUBLIC ${REDIS_PLUS_PLUS_HEADER})

find_library(REDIS_PLUS_PLUS_LIB redis++)
target_link_libraries(server_runner PUBLIC ${REDIS_PLUS_PLUS_LIB})
target_link_libraries(tests PUBLIC ${REDIS_PLUS_PLUS_LIB})


add_subdirectory(src)
target_link_libraries(server_runner PUBLIC server)
target_link_libraries(tests PUBLIC  packets server)

add_subdirectory(lib/Catch2)
target_link_libraries(tests PUBLIC Catch2::Catch2WithMain)


find_package(Threads REQUIRED)
target_link_libraries(server_runner PUBLIC Threads::Threads)
target_link_libraries(tests PUBLIC Threads::Threads)

find_package(OpenSSL REQUIRED)
target_link_libraries(server_runner PUBLIC OpenSSL::SSL)
target_link_libraries(tests PUBLIC OpenSSL::SSL)


target_compile_options(tests PUBLIC -pthread -g )
target_compile_options(server_runner PUBLIC -pthread -g)


include(CTest)
include(Catch)
catch_discover_tests(tests)
SET (CMAKE_CXX_COMPILER "/usr/bin/clang++")