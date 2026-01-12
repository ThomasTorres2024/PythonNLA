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
void testMatrixConstructor(bool verb)
{

    // trying vectors of different sizes
    std::vector<std::vector<double>> m1 = {{
                                               1,
                                               0,
                                               0,
                                           },
                                           {0, 1, 0},
                                           {0, 0, 1}};
    std::vector<std::vector<double>> m2 = {{1}, {0}, {0}};
    std::vector<std::vector<double>> m3 = {{1, 0, 0}};

    Matrix<double> testMatrix1(&m1);
    Matrix<double> testMatrix2(&m2);
    Matrix<double> testMatrix3(&m3);

    testMatrix1.print();
    std::cout << "\n";
    testMatrix2.print();
    std::cout << "\n";
    testMatrix3.print();
    std::cout << "\n";

    // test methods for random initialization

    Matrix<float> randomMatrix1(3, 3, -1.1, 2.3);
    Matrix<int> randomMatrix2(1, 5, -1000, 1000);
    Matrix<double> randomMatrix3(5, 3, 2.21273723, 2.2122);

    // print random matrix results
    randomMatrix1.print();
    std::cout << "\n";
    randomMatrix2.print();
    std::cout << "\n";
    randomMatrix3.print();
    std::cout << "\n";

    // identity matrices test
    Matrix<float> id1(1);
    Matrix<int> id2(5);
    Matrix<double> id3(7);

    // print random matrix results
    id1.print();
    std::cout << "\n";
    id2.print();
    std::cout << "\n";
    id3.print();
    std::cout << "\n";

    // solid value constructor test
    Matrix<float> solid1(1.0001,5,3);
    Matrix<int> solid2(67,2,3);
    Matrix<double> solid3(3.141592653,7,8);


    solid1.print();
    std::cout << "\n";
    solid2.print();
    std::cout << "\n";
    solid3.print();
    std::cout << "\n";

}
