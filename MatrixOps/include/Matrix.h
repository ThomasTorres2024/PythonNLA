#pragma once
#include "Matrix.h"
#include "Vec.h"
#include <vector>
#include <cmath>
#include <random>
#include <limits>

/**
 * @brief Implementation of Matrix class with NLA focus. Supports matrix-Vec operations,
 * intended to be used for implementing NLA algorithms.
 *
 * @name Thomas Torres, Charles Booth
 * @date 1/12/26
 */

template <typename T>
class Matrix
{
public:
    // constructors

    /**
     * @brief Constructor for matrix with 2d vector
     * @param[in] vals pointer to 2d vec of values for the array
     */
    Matrix(std::vector<std::vector<T>> *vals);

    /**
     * @brief Constructor for matrix for size (r x c), unif distribution
     * on [a,b]
     * @param[in] rows - Number of Rows
     * @param[in] cols - Number of columns
     * @param[in] a - Lower bound for uniform dist
     * @param[in] b- Upper bound for uniform dist
     */
    Matrix(size_t rows, size_t cols, T a, T b);

    /**
     * @brief Constructor for identity matrix of size (n x n)
     * @param[in] n - Parameter n for (n x n) identity
     */
    Matrix(size_t n);

    /**
     * @brief Constructor for matrix of 1 solid value for matrix of size
     * (row x cols)
     * @param[in] val - Value to be repeated
     * @param[in] rows - Number of Rows
     * @param[in] cols - Number of columns
     */
    Matrix(T val, size_t rows, size_t cols);

    // matrix ops

    /**
     * @brief Returns the sum of the current matrix and incoming matrix if m
     * if the matrices are of conformable shape
     * @param[in] m Pointer to another matrix
     */
    Matrix sum(Matrix *m);

    /**
     * @brief Returns the difference of the current matrix and incoming matrix if m
     * and the current matrices are conformable
     * @param[in] m Pointer to another matrix
     */
    Matrix diff(Matrix *m);

    /**
     * @brief Scales the current vector by some amount, T
     * @param[in] scalar - Scalar value t
     */
    void scale(T scalar);

    /**
     * @brief Computes the product between a matrix and another matrix m,
     * computes them in order (Current x m)
     * @param[in] m Pointer to another matrix
     * @return Resulting matrix from (Current x m)
     */
    Matrix prod(Matrix *m);

    // matrix vector ops

    // /**
    //  * @brief Computes the product between a matrix and another vector v,
    //  * computes them in order (Current x v)
    //  * @param[in] m Pointer to another vector
    //  * @return Resulting matrix from (Current x v)
    //  */
    // Matrix prod(Vec *v);

    // accessors

    /**
     * @brief Computes the L2 matrix norm of the matrix
     * @return The L2 norm of the matrix
     */
    double norm();

    /**
     * @brief Computes the Frobenius norm of the matrix
     * @return The frobenius norm of the matrix
     */
    double frobenius();

    /**
     * @brief Returns the number of rows in the matrix
     * @return The number of rows
     */
    size_t getRow();

    /**
     * @brief Returns the number of cols in the matrix
     * @return The number of cols
     */
    size_t getCol();

    /**
     * @brief Prints the matrix to console
     */
    void print();

    /**
     * @brief Returns the value at the index of the matrix
     * @param[in] i - The row of the value
     * @param[in] j - The column of the value
     * @return The value at the index
     */
    T at(size_t i, size_t j);

    // mutators

    /**
     * @brief Returns the value at the index of the matrix
     * @param[in] i - The row of the value
     * @param[in] j - The column of the value
     * @return The value at the index
     */
    void set(T val, size_t i, size_t j);

    // Overloaded Operators

    /**
     * @brief Operator overload for difference of 2 matrices
     * @param[in] m matrix to add
     * @return Resulting matrix from the difference of 2 matrices
     */
    Matrix operator+(Matrix m);

    /**
     * @brief Operator overload for difference of 2 matrices
     * @param[in] m matrix to subtract
     * @return Resulting matrix from the difference of 2 matrices
     */
    Matrix operator-(Matrix m);

    // /**
    //  * @brief Scales elements of the matrix by some calar
    //  * @param[in] scalar matrix scaled by this value
    //  */
    // template <typename T>
    // void operator*(T scalar);

    /**
     * @brief Operator overload for product of 2 matrices
     * @param[in] Matrix to multiple current matrix by of conformable size
     * @return Resulting matrix from the product of 2 matrices
     */
    Matrix operator*(Matrix m);

private:
    size_t row;
    size_t col;
    std::vector<std::vector<T>> matrix_vals;
};

////////////////////
// Constructors
////////////////////

/**
 * @brief Constructor for matrix with 2d vector
 * @param[in] vals pointer to 2d vec of values for the array
 */
template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> *vals)
{
    this->matrix_vals = std::vector<std::vector<T>>(*vals);
    this->row = matrix_vals.size();
    this->col = matrix_vals.at(0).size();
}

/**
 * @brief Constructor for matrix for size (r x c), unif distribution
 * on [a,b]
 * @param[in] rows - Number of Rows
 * @param[in] cols - Number of columns
 * @param[in] a - Lower bound for uniform dist
 * @param[in] b- Upper bound for uniform dist
 */
template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, T a, T b)
{

    // initialize to all 0's
    this->matrix_vals = std::vector<std::vector<T>>(rows, std::vector<T>(cols, 0));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> uni_dist(a, b);

    // initialize random devices and set vals
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            matrix_vals.at(i).at(j) = uni_dist(gen);
        }
    }

    // set other vals
    this->row = rows;
    this->col = cols;
}

/**
 * @brief Constructor for identity matrix of size (n x n)
 * @param[in] n - Parameter n for (n x n) identity
 */
template <typename T>
Matrix<T>::Matrix(size_t n)
{
    this->matrix_vals = std::vector<std::vector<T>>(n, std::vector<T>(n, 0));
    for (size_t i = 0; i < n; i++)
    {
        this->matrix_vals.at(i).at(i) = 1;
    }

    this->row = n;
    this->col = n;
};

/**
 * @brief Constructor for matrix of 1 solid value for matrix of size
 * (row x cols)
 * @param[in] val - Value to be repeated
 * @param[in] rows - Number of Rows
 * @param[in] cols - Number of columns
 */
template <typename T>
Matrix<T>::Matrix(T val, size_t rows, size_t cols)
{
    // initialize to all 0's
    this->matrix_vals = std::vector<std::vector<T>>(rows, std::vector<T>(cols, val));

    this->row = rows;
    this->col = cols;
}

////////////////////
// Matrix Ops
////////////////////

/**
 * @brief Returns the sum of the current matrix and incoming matrix if m
 * if the matrices are of conformable shape
 * @param[in] m Pointer to another matrix
 */
template <typename T>
Matrix<T> Matrix<T>::sum(Matrix *m)
{

    size_t row = m->getRow();
    size_t col = m->getCol();

    // initialize to 0s when made
    Matrix<T> res(0, row, col);

    // sum 2 matrices
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            res.set(m->at(i, j) + this->at(i, j), i, j);
        }
    }

    return res;
}

/**
 * @brief Returns the difference of the current matrix and incoming matrix if m
 * and the current matrices are conformable
 * @param[in] m Pointer to another matrix
 */
template <typename T>
Matrix<T> Matrix<T>::diff(Matrix *m)
{

    size_t row = m->getRow();
    size_t col = m->getCol();

    // initialize to 0s when made
    Matrix<T> res(0, row, col);

    // sum 2 matrices
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            res.set(this->at(i, j) - m->at(i, j), i, j);
        }
    }

    return res;
}

/**
 * @brief Scales the current vector by some amount, T
 * @param[in] scalar - Scalar value t
 */
template <typename T>
void Matrix<T>::scale(T scalar)
{

    for (size_t i = 0; i < this->row; i++)
    {
        for (size_t j = 0; j < this->col; j++)
        {
            this->matrix_vals.at(i).at(j) *= scalar;
        }
    }
}

/**
 * @brief Implementation of matrix mult as essentially by the book definition
 * @param[in] m Pointer to another matrix
 * @return Resulting matrix from (Current x m)
 */
template <typename T>
Matrix<T> Matrix<T>::prod(Matrix<T> *m)
{

    Matrix<T> nextMatrix(0, this->row, m->col);

    for (size_t i = 0; i < this->row; i++)
    {

        for (size_t j = 0; j < m->col; j++)
        {

            T curr = 0;

            // do dot product between rows and cols
            for (size_t k = 0; k < this->col; k++)
            {
                curr += this->at(i, k) * m->at(k, j);
            }

            // update new value
            nextMatrix.set(curr, i, j);
        }
    }

    return nextMatrix;
}

////////////////////
// Accessors
////////////////////

/**
 * @brief Returns the value at the index of the matrix
 * @param[in] i - The row of the value
 * @param[in] j - The column of the value
 * @return The value at the index
 */
template <typename T>
T Matrix<T>::at(size_t i, size_t j)
{
    return this->matrix_vals.at(i).at(j);
}

/**
 * @brief Prints the matrix to console
 */
template <typename T>
void Matrix<T>::print()
{
    for (auto row : this->matrix_vals)
    {
        for (auto entry : row)
        {
            std::cout << entry << " ";
        }
        std::cout << "\n";
    }
}

/**
 * @brief Computes the Frobenius norm of the matrix
 * @return The frobenius norm of the matrix
 */
template <typename T>
double Matrix<T>::frobenius()
{
    // for now i'm using a lazy by definition way to go about it
    // maybe computing SVD and doing the singular values is quicker, this is just the
    // easy way for now

    double res = 0;

    for (auto row : this->matrix_vals)
    {
        for (auto v : row)
        {
            res += v * v;
        }
    }

    return sqrt(res);
}

/**
 * @brief Returns the number of rows in the matrix
 * @return The number of rows
 */
template <typename T>
size_t Matrix<T>::getRow()
{
    return this->row;
}

/**
 * @brief Returns the number of cols in the matrix
 * @return The number of cols
 */
template <typename T>
size_t Matrix<T>::getCol()
{
    return this->col;
}

////////////////////
// Mutators
////////////////////
/**
 * @brief Returns the value at the index of the matrix
 * @param[in] i - The row of the value
 * @param[in] j - The column of the value
 * @return The value at the index
 */
template <typename T>
void Matrix<T>::set(T val, size_t i, size_t j)
{
    this->matrix_vals.at(i).at(j) = val;
}

//////////////////////////////
// Overloaded Expressions
//////////////////////////////

/**
 * @brief Operator overload for addition of 2 matrices
 * @param[in] Another matrix to add
 * @return Resulting matrix from the sum of 2 matrices
 */
template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> m)
{
    return this->sum(m);
}

/**
 * @brief Operator overload for difference of 2 matrices
 * @param[in] Another matrix to add
 * @return Resulting matrix from the difference of 2 matrices
 */
template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> m)
{
    return this->diff(m);
}

/**
 * @brief Scales elements of the matrix by some calar
 * @param[in] scalar matrix scaled by this value
 */
template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> m)
{
    return this->scale(scalar);
}

// /**
//  * @brief Scales elements of the matrix by some calar
//  * @param[in] scalar matrix scaled by this value
//  */
// template <typename T>
// void Matrix<T>::operator*(T scalar)
// {
//     return this->scale(scalar);
// }