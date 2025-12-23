//header guard 
#ifndef MATRIX_MULT_H

// Define MATHUTILS_H to prevent multiple inclusions
#define MATRIX_MULT_H

#include <vector> //for mult  

/**
 * @brief Checks conditions of matrix multiplication, and throws an error if the size of the matrices does not conform or if the matrices are null.
 * The point of having this as a separate function is to continue to check for new errors. We want to compute A*B in theory
 *
 * @param[in] A - the matrix we are left multiplying
 * @param[in] B - the matrix we are right multiplying
 * @result true Sizes conform nothing is wrong
 * @result false Sizes do not conform, something is wrong, or a matrix is null
 */

static bool matrixDimensionsConform(std::vector<std::vector<double>> *A, std::vector<std::vector<double>> *B);


/**
 * @brief Creates a vector of zeros of size m x n 
 * @param[in] rows - The number of rows in the new matrix 
 * @param[in] cols - The number of rows in the new matrix 
 * 
 * @return matrix of size (m x n) consisting exclusively of zeros 
 */
std::vector<std::vector<double>> zeros(size_t rows, size_t cols);

/**
 * @brief Returns identity matrix of corresponding size of n x n 
 * @param[in] n - The size of the identity matrix 
 * 
 * @return Identity matrix of size (n x n)
 */
std::vector<std::vector<double>> eye(size_t n);

/**
 * @brief Implementation of matrix mult as essentially by the book definition
 *
 * @param[in] A - the matrix we are left multiplying
 * @param[in] B - the matrix we are right multiplying
 * @result Resulting matrix product
 *
 */
std::vector<std::vector<double>> NaiveMatrixMult(std::vector<std::vector<double>> *A, std::vector<std::vector<double>> *B);

#endif