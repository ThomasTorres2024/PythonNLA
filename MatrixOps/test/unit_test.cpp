#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <cassert>
#include "Vec.h"
#include "Matrix.h"
#include <cmath>
#include <vector>


TEST_CASE("Vector size tests", "[vector]"){
    std::vector<double> v1 = {1.2, 2.0, 3.0};
    std::vector<double> v2 = {4.0, 5.0, 6.0};

    Vec<double> doubleVec(v1);
    Vec<double> intVec(v2);
    Vec<int> repVec(3,4);
    size_t vec4_size = 4;
    int vec4_up = 20;
    int vec4_lo = 1;

    size_t vec5_size = 4;
    double vec5_up = 20;
    double vec5_lo = 1;

    Vec<int> unifVecInt(vec4_size, vec4_lo, vec4_up);
    Vec<double> unifVecDoub(vec5_size, vec5_lo, vec5_up);

    Vec<int> randIntVec = randn<int>(4, 1, 20);
    Vec<double> randDoubVec = randn<double>(4, 1, 20);

    size_t zero_size = 4;

    Vec<int> zerosIntVec = zeros<int>(zero_size);
    Vec<double> zerosDoubVec = zeros<double>(zero_size); 

    doubleVec.print();
    intVec.print();
    repVec.print();
    unifVecInt.print();
    unifVecDoub.print();
    randIntVec.print();
    randDoubVec.print();
    zerosIntVec.print();
    zerosDoubVec.print();

    REQUIRE(doubleVec.getSize() == 3);
    REQUIRE(intVec.getSize() == 3);
    REQUIRE(repVec.getSize() == 4);
    REQUIRE(unifVecInt.getSize() == 4);
    REQUIRE(unifVecDoub.getSize() == 4);
    REQUIRE(randIntVec.getSize() == 4);
    REQUIRE(randDoubVec.getSize() == 4);
    REQUIRE(zerosIntVec.getSize() == 4);
    REQUIRE(zerosDoubVec.getSize() == 4);
}
