/**
 * @brief Test methods for matrix util class
 * @date 1-15-26
 * @author Thomas Torres
 */

#include <iostream>
#include <cassert>
#include "Vec.h"
#include "Matrix.h"
#include <cmath>
#include <vector>
#include <MatrixUtil.h>

void testMatrixOps(bool verb);

int main(int argc, char **argv)
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

    Matrix<double> nextMatrix = sum(&testMatrix1,&testMatrix2);
    
    nextMatrix.print();
                                        
    return 0;
}
