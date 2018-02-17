//


#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <stdio.h>
#include "battleship2.0.h"

using x=size_t;
using y=size_t;


TEST_CASE("Constructor working properly") {
    size_t length=3;
    Ships destroyer(3);
    INFO("Length should be three");
    REQUIRE(destroyer.getLength()==2);
    Ships airCarrier(5);
    INFO("Length should be 5");
    REQUIRE(airCarrier.getLength()==5);
}
TEST_CASE("Checks if getCoordinates returns correctly") {

}










