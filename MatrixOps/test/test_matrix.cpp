/**
 * @brief Test file for matrix class in Matrix math library
 * @author Thomas Torres
 * @date 1-12-26
 */

#include <iostream>
#include <cassert>
#include "Vec.h"
#include "Matrix.h"
#include <cmath>

void testMatrixConstructor(bool verb);

int main(int argc, char *argv[])
{

    testMatrixConstructor(true);
    return 0;
}

/**
 * @brief Tests that vector initializations occur as expected
 * @param[in] verb - If we should print the results of the debugging
 */
void testMatrixConstructor(bool verb){

    //trying vectors of different sizes 
    std::vector<std::vector<double>> m1={{1,0,0,},{0,1,0},{0,0,1}};
    std::vector<std::vector<double>> m2={{1},{0},{0}};
    std::vector<std::vector<double>> m3={{1,0,0}};

    Matrix<double> testMatrix1(&m1); 
    Matrix<double> testMatrix2(&m2); 
    Matrix<double> testMatrix3(&m3); 
    
    testMatrix1.print();
    std::cout<<"\n";
    testMatrix2.print();
    std::cout<<"\n";
    testMatrix3.print();

    //other constructor methods 
    
}
