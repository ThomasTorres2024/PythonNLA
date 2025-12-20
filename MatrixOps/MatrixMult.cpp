#include <iostream>
#include <vector>

std::vector<std::vector<double>> NaiveMatrixMult(std::vector<std::vector<double>> A, std::vector<std::vector<double>>);

/**
 * @brief For testing matrix multiplication methods
 */
int main()
{

    return 0;
}

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

    // otherwise perform computation
    size_t ARowCount = A->size();
    size_t AColCount = A->at(0).size();
    size_t BRowCount = B->size();
    size_t BColCount = B->at(0).size();

    // resulting matrix should be of size of rows of a by cols of B:
    std::vector<std::vector<double>> res(ARowCount, std::vector<double>(BColCount));
    for(size_t i = 0; i < ARowCount;i++){
        double curr = 0; 
        std::vector<double> currRow = A->at(i);
        for(size_t j = 0; j < BColCount;j++){
            std::vector<double> currCol = B->at(j);
        }
    }

    return res;
}