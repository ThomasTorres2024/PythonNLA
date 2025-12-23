// #include "MatrixMult.h"
#include <iostream>
#include <vector>
#include <random> //for random matrix creation


/**
 * @brief Checks conditions of matrix multiplication, and throws an error if the size of the matrices does not conform or if the matrices are null.
 * The point of having this as a separate function is to continue to check for new errors. We want to compute A*B in theory
 *
 * @param[in] A - the matrix we are left multiplying
 * @param[in] B - the matrix we are right multiplying
 * @result true Sizes conform nothing is wrong
 * @result false Sizes do not conform, something is wrong, or a matrix is null
 */
bool matrixDimensionsConform(std::vector<std::vector<double>> *A, std::vector<std::vector<double>> *B)
{

    bool sizes_conform = false;

    // check if the vectors are empty or not
    if (A->size() == 0)
    {
        std::cout << "ERROR, matrix A is empty.\n";
    }
    else if (B->size() == 0)
    {
        std::cout << "ERROR, matrix B is empty.\n";
    }
    // check if the vectors are of conformable size and throw error
    else if (A->at(0).size() != B->size())
    {
        std::cout << "ERROR. Matrix sizes do not match. Matrix A is of size: (" << A->size() << "," << A->at(0).size() << ") and matrix B is of size: (" << B->size() << B->at(0).size() << ")\n";
    }
    else
    {
        sizes_conform = true;
    }

    return sizes_conform;
}

/**
 * @brief Creates a vector of zeros of size m x n
 * @param[in] rows - The number of rows in the new matrix
 * @param[in] cols - The number of rows in the new matrix
 *
 * @return matrix of size (m x n) consisting exclusively of zeros
 */
std::vector<std::vector<double>> zeros(size_t rows, size_t cols)
{
    
    std::vector<std::vector<double>> res(rows, std::vector<double>(cols, 0));
    return res;
}

/**
 * @brief Returns identity matrix of corresponding size of n x n
 * @param[in] n - The size of the identity matrix
 *
 * @return Identity matrix of size (n x n)
 */
std::vector<std::vector<double>> eye(size_t n)
{
    std::vector<std::vector<double>> eye_zeros = zeros(n, n);
    //make diagonal of 1's 
    for (size_t i = 0; i < n; i++)
    {
        eye_zeros.at(i).at(i) = 1;
    }
    return eye_zeros;
}

/**
 * @brief Generates a matrix of size of (n x m) of ints with completely random entries 
 */
std::vector<std::vector<double>> rand_n(size_t n, size_t m){

    std::vector<std::vector<double>> result;

    return result;

}

/**
 * @brief Generates a matrix of size of (n x m) with completely random entries from the uniform distribution
 */
std::vector<std::vector<double>> rand(size_t n, size_t m){


    std::vector<std::vector<double>> result;

    return result;
}

/**
 * @brief Generates a matrix of size of (n x m) with completely random entries from the uniform distribution, with entries 
 * randomly sampled from the uniform distribution on U ~ [lower, upper]
 */
std::vector<std::vector<double>> rand_unif(size_t n, size_t m, double lower, double upper){

    std::vector<std::vector<double>> result;

    return result;
}

/**
 * @brief Implementation of matrix mult as essentially by the book definition
 *
 * @param[in] A - the matrix we are left multiplying
 * @param[in] B - the matrix we are right multiplying
 * @result Resulting matrix product
 *
 */
std::vector<std::vector<double>> NaiveMatrixMult(std::vector<std::vector<double>> *A, std::vector<std::vector<double>> *B)
{

    // check if the vectors are empty or not
    matrixDimensionsConform(A, B);

    // resulting matrix should be of size of rows of a by cols of B:
    std::vector<std::vector<double>> res(A->size(), std::vector<double>(B->at(0).size()));

    // iterate over rows
    for (size_t i = 0; i < A->size(); i++)
    {

        // iterate over cols
        std::vector<double> currRow = A->at(i);
        for (size_t j = 0; j < B->at(0).size(); j++)
        {
            double curr = 0;
            std::vector<double> currCol = B->at(j);

            // do dot product between rows and cols
            for (size_t k = 0; k < currCol.size(); k++)
            {
                curr += currRow.at(k) * currCol.at(k);
            }
            res.at(i).at(j) = curr;
        }
    }

    return res;
}

int main(){

    std::vector<std::vector<double>> id = zeros(3,4);

    for (auto row: id){
        for (auto num: row){
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
    return 0;
}