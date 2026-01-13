/**
 * @brief Test file for vector class in Matrix math library
 * @author Charles Booth, Thomas Torres
 * @date 1-11-26
 */

#include <iostream>
#include <cassert>
#include "Vec.h"
#include <cmath>

void testVectorInit(bool verb);

int main(int argc, char *argv[])
{

    testVectorInit(true);
    return 0;
}

/**
 * @brief Tests that vector initializations occur as expected
 * @param[in] verb - If we should print the results of the debugging
 */
void testVectorInit(bool verb)
{

    /*
        Really cluttered code here, sorry for the random functions and such, just testing out methods. 
    */

    //tests for doubles 
    // std::vector<double> v1 = {1.0, 2.0, 3.0};
    // std::vector<double> v2 = {-1.0,-2.0,-3.0};
    // std::vector<double> v3 = {0.0, 0.0, 0.0};

    // //initialize using this method 
    // Vec<double> testVec1(v1);
    // Vec<double> testVec2(v2);
    // Vec<double> testVec3=zeros<double>(3);

    // // test for norms 
    // double norm_v1_euclid = 0;
    // for (auto v : v1)
    // {
    //     norm_v1_euclid += v * v;
    // }
    // norm_v1_euclid = sqrt(norm_v1_euclid);

    // if (verb)
    // {
    //     std::cout << "Difference in L2 Norms: " << norm_v1_euclid - testVec1.norm() << "\n";
    // }
    
    // assert(testVec1.norm() == norm_v1_euclid);
    // size_t testVecSize = 3;

    // int upper = 10;
    // int lower = 1;

    // Vec<double> v1 = randn<double>(10, 0, 100);
    // v1.print();

    // Vec<int> testVec2(testVecSize, lower, upper);
    // testVec2.print();

    // double upper2 = 10;
    // double lower2 = 1;

    // Vec<double> testVec3(testVecSize, lower2, upper2);
    // testVec3.print();

    // Vec<int> testVec3(3,4);
    // testVec3.print();


    std::cout << "\n";
}