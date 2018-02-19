//


#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <stdio.h>
#include "battleship2.0.h"

using x=size_t;
using y=size_t;


TEST_CASE("getLength after constructing works properly") {
    size_t length=3;
    Ships destroyer(3);
    INFO("Length should be three");
    REQUIRE(destroyer.getLength()==3);
    Ships airCarrier(5);
    INFO("Length should be 5");
    REQUIRE(airCarrier.getLength()==5);
}
TEST_CASE("Checks if getCoordinates after constructing returns correctly") {
    Ships destroyer(3);
    auto vec0=destroyer.getCoordinates();
    pair<x,y> p0(0,0);
    pair<x,y> p1(1,0);
    pair<x,y> p2(2,0);
    INFO("The coordinates of the first boat should be (0,0); (1,0); (2,0)");
    REQUIRE(vec0[0].first==p0.first);
    REQUIRE(vec0[1].first==p1.first);
    REQUIRE(vec0[2].first==p2.first);
    REQUIRE(vec0[0].second==p0.second);
    REQUIRE(vec0[1].second==p1.second);
    REQUIRE(vec0[2].second==p2.second);
}
TEST_CASE("Checks if checkHit returns correctly") {
    Ships tugboat(2);
    pair<x, y> c1(1,0);
    pair<x, y> c2(0,0);
    pair<x,y> c3(-1,2);
    Ships destroyer(3);
    {
    INFO("Firing at coordinates (1,0) should return true");
    REQUIRE(tugboat.checkHit(c1) == true);
    }
    {
    INFO("Firing at coordinates (0,0) should return true");
    REQUIRE(tugboat.checkHit(c2) == true);
    }
    {
    INFO("Should return false since not on board");
    REQUIRE(tugboat.checkHit(c3) == false);
    }
    //Checking if new boat is spawned below old
    pair<x,y> p0(0,1);
    pair<x,y> p1(1,1);
    pair<x,y> p2(2,1);
    {
    INFO("Firing at previous coordinates (1,0) should return false");
    REQUIRE(destroyer.checkHit(c1) == false);
    }
    {
    INFO("Firing at previous coordinates (0,0) should return false");
    REQUIRE(destroyer.checkHit(c2) == false);
    }
    {
    INFO("Firing at coordinates of newly constructed destroyer: (0,1) \n Should return true");
    REQUIRE(destroyer.checkHit(p0) == true);
    }
    {
    INFO("Firing at coordinates of newly constructed destroyer: (1,1) \n Should return true");
    REQUIRE(destroyer.checkHit(p1) == true);
    }
    {
    INFO("Firing at coordinates of newly constructed destroyer: (2,1) \n Should return true");
    REQUIRE(destroyer.checkHit(p2) == true);
    }
    
}
TEST_CASE("Checks if ifTaken returns correctly") {
    Ships submarine(2);
    pair<x, y> c1(1,0);
    pair<x, y> c2(0,0);
    pair<x,y> c3(-1,2);
    {
    INFO("Firing at coordinates (1,0) should return true");
    REQUIRE(submarine.ifTaken(c1) == true);
    }
    {
    INFO("Firing at coordinates (0,0) should return true");
    REQUIRE(submarine.ifTaken(c2) == true);
    }
    {
    INFO("Should return false since not on board");
    REQUIRE(submarine.ifTaken(c3) == false);
    }
}
TEST_CASE("Checks if updateOrientation works properly")
{
    Ships s0(2);
    Ships s1(3);
    {
    INFO("Checking if newly constructed orientation is horizontal(0)");
    REQUIRE(s0.getOrientation()== 0);
    REQUIRE(s1.getOrientation()==0);
    }
    {
        s0.updateOrientation();
        INFO("Updated orientation of ship, should be vertical(1) now");
        REQUIRE(s0.getOrientation()==1);
        INFO("Orientation of s1 should still be horizontal(0)");
        REQUIRE(s1.getOrientation()==0);
        s1.updateOrientation();
        INFO("Orientation of s1 should be vertical now(1)")
        REQUIRE(s1.getOrientation()==1);
    }
}











