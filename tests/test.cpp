#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include "../src/packets/packets.h"

unsigned int Factorial(unsigned int number)
{
    return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[factorial]")
{
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
    std::cout << "hi\n";
}

TEST_CASE("SerializeMYAss", "[serialize]")
{
    std::cout << "MYAss\n";
    REQUIRE(1==2);
    REQUIRE(true);
}

TEST_CASE("SerializeMYAss2", "[serialize]")
{
    std::cout << "MYAss2\n";
    REQUIRE(true);
}

TEST_CASE("SerializeLoginRequest", "[serialize]")
{
    login_request* msg1 = new login_request;
    msg1->id = 10;
    msg1->username = "Hello";
    msg1->password = "World!";

    uint8_t* buf = (uint8_t*)malloc(100);
    login_request* msg2 = new login_request;

    login_request::pack(msg1, buf);
    login_request::unpack(msg2, buf);

    REQUIRE(msg1->id == msg2->id);
    REQUIRE(msg1->username == msg2->username);
    REQUIRE(msg1->password == msg2->password);
}






