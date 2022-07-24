cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_13)

project(IndiewriterBackend)

add_subdirectory(lib/Catch2)
add_subdirectory(src)
add_executable(tests tests/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain packets)

include(CTest)
include(Catch)
catch_discover_tests(tests)


# set(CMAKE_BUILD_TYPE Release) <- comment out such lines 