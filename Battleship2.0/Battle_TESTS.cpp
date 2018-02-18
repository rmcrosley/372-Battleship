//


#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <stdio.h>
#include "battleship2.0.h"
#include <utility>
using std::pair;

using x=size_t;
using y=size_t;


TEST_CASE("Constructor working properly") {
    size_t length=3;
    Ships destroyer(3);
    INFO("Length should be three");
    REQUIRE(destroyer.getLength()==3);
    Ships airCarrier(5);
    INFO("Length should be 5");
    REQUIRE(airCarrier.getLength()==5);
}
TEST_CASE("Checks if getCoordinates returns correctly") {
    
}
TEST_CASE("Checks if checkHit returns correctly") {
    Ships tugboat(2);
    pair<x, y> IWasHit1(1,2);
    INFO("Should return true if hit");
    REQUIRE(tugboat.checkHit(IWasHit1) == true);
    pair<x, y> IWasHit2(0,2);
    INFO("Should return true if hit");
    REQUIRE(tugboat.checkHit(IWasHit2) == true);
    pair<x,y> IWasNotHit(-1,2);
    INFO("Should return false since not on board");
    REQUIRE(tugboat.checkHit(IWasNotHit) == false);
}












