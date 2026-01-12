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
#include <vector>

void testMatrixConstructor(bool verb);
void testMatrixOps(bool verb);
void testMatrixOverloads(bool verb);

int main(int argc, char *argv[])
{

    // all of these passed so far
    testMatrixConstructor(true);
    testMatrixOps(true);
    return 0;
}

/**
 * @brief Tests that matrix operations occur as expected, assuming that the dimensions here are all valid, 
 * we are using the expressions in cpp here 
 * @param[in] verb - If we should print the results of the debugging
 */
// void testMatrixOps(bool verb)
// {

// }

/**
 * @brief Tests that matrix operations occur as expected, assuming that the dimensions here are all valid
 * @param[in] verb - If we should print the results of the debugging
 */
void testMatrixOps(bool verb)
{

    std::vector<std::vector<double>> m1 = {{
                                               1,
                                               0,
                                               0,
                                           },
                                           {0, 1, 0},
                                           {0, 0, 1},
                                           {1, 2, 3}};
    std::vector<std::vector<double>> m2 = {{
                                               1,
                                               1,
                                               1,
                                           },
                                           {1, 1, 1},
                                           {1, 1, 1},
                                           {1, 1, 1}};

    Matrix<double> testMatrix1(&m1);
    Matrix<double> testMatrix2(&m2);

    Matrix<double> matrix3 = testMatrix1.sum(&testMatrix1);
    Matrix<double> matrix4 = testMatrix1.sum(&testMatrix2);

    std::cout << "Testing sum\n:";

    // print results
    if (verb)
    {
        matrix3.print();
        std::cout << "\n";
        matrix4.print();
        std::cout << "\n";

        std::cout << "------------------------\n";
        std::cout << "\n Testing difference: \n";
    }
    Matrix<double> m1diff = testMatrix1.diff(&testMatrix1);
    Matrix<double> m2diff = testMatrix1.diff(&testMatrix2);

    if (verb)
    {
        m1diff.print();
        std::cout << "\n";
        m2diff.print();
        std::cout << "\n";

        std::cout << "------------------------\n";
        std::cout << "\n Testing Scaling: \n";
    }
    double s1 = 0;
    double s2 = 300;

    testMatrix1.scale(s1);
    testMatrix2.scale(s2);
    if (verb)
    {
        testMatrix1.print();
        std::cout << "\n";
        testMatrix2.print();
        std::cout << "\n";
    }
    // Matrix<double> matrix3 = testMatrix1.sum(&testMatrix1);
    // Matrix<double> matrix4 = testMatrix1.sum(&testMatrix2);

    std::vector<std::vector<double>> diag1 = {{1, 0, 0}, {0, 2, 0}, {0, 0, 3}};
    std::vector<std::vector<double>> weird1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<double>> weird2{{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};

    std::vector<std::vector<double>> threeX2Vec{{10, 11}, {13, 14},{15,16}};
    std::vector<std::vector<double>> twoX2Vec{{10, 11}, {13, 14}};

    Matrix<double> matrixDiag1(&diag1);
    Matrix<double> myEye(3);
    Matrix<double> sameValue(1, 3, 3);
    Matrix<double> weirdMatrix1(&weird1);
    Matrix<double> weirdMatrix2(&weird2);

    Matrix<double> threeX2Matrix(&threeX2Vec);
    Matrix<double> twoX2Matrix(&twoX2Vec);

    Matrix<double> prod1 = myEye.prod(&matrixDiag1);
    Matrix<double> prod2 = matrixDiag1.prod(&matrixDiag1);
    Matrix<double> prod3 = sameValue.prod(&matrixDiag1);
    Matrix<double> prodWeird = weirdMatrix1.prod(&weirdMatrix2);

    Matrix<double> prodOf2By2=threeX2Matrix.prod(&twoX2Matrix);

    if (verb)
    {
        prod1.print();
        std::cout << "\n";

        prod2.print();
        std::cout << "\n";

        prod3.print();
        std::cout << "\n";

        prodWeird.print();
        std::cout << "\n";

        prodOf2By2.print();
        std::cout << "\n";
    }
}

/**
 * @brief Tests that matrix initializations occur as expected
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

    if (verb)
    {
        testMatrix1.print();
        std::cout << "\n";
        testMatrix2.print();
        std::cout << "\n";
        testMatrix3.print();
        std::cout << "\n";
    }

    // test methods for random initialization

    Matrix<float> randomMatrix1(3, 3, -1.1, 2.3);
    Matrix<int> randomMatrix2(1, 5, -1000, 1000);
    Matrix<double> randomMatrix3(5, 3, 2.21273723, 2.2122);

    // print random matrix results
    if (verb)
    {
        randomMatrix1.print();
        std::cout << "\n";
        randomMatrix2.print();
        std::cout << "\n";
        randomMatrix3.print();
        std::cout << "\n";
    }
    // identity matrices test
    Matrix<float> id1(1);
    Matrix<int> id2(5);
    Matrix<double> id3(7);

    // print random matrix results
    if (verb)
    {
        id1.print();
        std::cout << "\n";
        id2.print();
        std::cout << "\n";
        id3.print();
        std::cout << "\n";
    }
    // solid value constructor test
    Matrix<float> solid1(1.0001, 5, 3);
    Matrix<int> solid2(67, 2, 3);
    Matrix<double> solid3(3.141592653, 7, 8);

    if (verb)
    {
        solid1.print();
        std::cout << "\n";
        solid2.print();
        std::cout << "\n";
        solid3.print();
        std::cout << "\n";
    }
}
