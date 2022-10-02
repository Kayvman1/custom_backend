cmake_minimum_required(VERSION 3.10)

#apt-get install libpq-dev postgresql-server-dev-all
#Before you start using C/C++ PostgreSQL interface, find the pg_hba.conf file in your PostgreSQL installation directory and add the following line −

# IPv4 local connections:
#host    all         all         127.0.0.1/32          md5
#

#   sudo apt-get install libpqxx-dev

project(IndiewriterBackend
        LANGUAGES C CXX)

set(CMAKE_CXX_14)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)



add_subdirectory(lib/Catch2)
add_subdirectory(lib/libpqxx build-pqxx)
add_subdirectory(src)


add_executable(tests tests/test.cpp)
add_executable(server_runner runner/main.cpp)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain Threads::Threads packets ring_buffer server virtual_socket pqxx )
target_compile_options(tests PRIVATE -pthread -g -lpqxx -lpq)

target_link_libraries(server_runner PRIVATE Threads::Threads packets ring_buffer server virtual_socket pqxx )
target_compile_options(server_runner PRIVATE -pthread -g -lpqxx -lpq)


include(CTest)
include(Catch)
catch_discover_tests(tests)
