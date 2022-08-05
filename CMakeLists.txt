cmake_minimum_required(VERSION 3.10)

project(IndiewriterBackend
        LANGUAGES C CXX)

set(CMAKE_CXX_20)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_subdirectory(lib/Catch2)
add_subdirectory(src)

add_executable(tests tests/test.cpp)
add_executable(server_runner runner/main.cpp)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain Threads::Threads packets ring_buffer server)
target_compile_options(tests PRIVATE -pthread -g)

target_link_libraries(server_runner PRIVATE Threads::Threads packets ring_buffer server)
target_compile_options(server_runner PRIVATE -pthread -g)


include(CTest)
include(Catch)
catch_discover_tests(tests)
