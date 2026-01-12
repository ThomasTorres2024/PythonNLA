#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <cassert>
#include "Vec.h"
#include "Matrix.h"
#include <cmath>
#include <vector>


TEST_CASE("Vector initialization and operations", "[vector]"){
    std::vector<double> v1 = {1.0, 2.0, 3.0};
    std::vector<double> v2 = {4.0, 5.0, 6.0};
    std::vector<int> v3 = {1,2,3};

    Vec<double> testVec1(v1);
    Vec<double> testVec2(v2);
    Vec<int> testVec3(v3);
    testVec3.print();

    REQUIRE(testVec1.getSize() == 3);
    REQUIRE(testVec1.getSize() == 3);
    
}
