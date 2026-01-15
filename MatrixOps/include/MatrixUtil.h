#pragma once
#include "Matrix.h"
#include "Vec.h"
#include <vector>
#include <cmath>
#include <random>
#include <limits>

/**
 * @brief Implementation of static matrix operations between different matrix operations
 * intended to be used for implementing NLA algorithms. 
 *
 * @name Thomas Torres, Charles Booth
 * @date 1/15/26
 */

////////////////////////////////////
// function headers
////////////////////////////////////

/**
 * @brief Returns the sum of the current matrix and incoming matrix if m
 * if the matrices are of conformable shape
 * @param[in] m Pointer to another matrix
 * @return The sum of two matrices
 */
template <typename T>
Matrix<T> sum(Matrix<T> *m1, Matrix<T> *m2);

/**
 * @brief Returns the difference of the current matrix and incoming matrix if m
 * if the matrices are of conformable shape
 * @param[in] m Pointer to another matrix
 * @return The difference of two matrices, namely m1-m2
 */
template <typename T>
Matrix<T> diff(Matrix<T> *m1, Matrix<T> *m2);

/**
 * @brief Returns the current matrix with all entries negative
 * @param[in] m Pointer to another
 * @return The matrix with all of its entries inverted
 */
template <typename T>
Matrix<T> neg(Matrix<T> *m);

/**
 * @brief Returns the current matrix with all entries scaled by scalar
 * @param[in] m Pointer to another
 * @return The matrix with all of its entries inverted
 */
template <typename T>
Matrix<T> scale(Matrix<T> *m, T scalar);

/**
 * @brief Returns the current matrix with all entries negative
 * @param[in] m Pointer to another
 * @return The matrix with all of its entries inverted
 */
template <typename T>
Matrix<T> prod(Matrix<T> *m1, Matrix<T> *m2);

////////////////////////////////////
// function implementations
////////////////////////////////////

/**
 * @brief Returns the sum of the current matrix and incoming matrix if m
 * if the matrices are of conformable shape
 * @param[in] m Pointer to another matrix
 * @return THe sum of the two matrices
 */
template <typename T>
Matrix<T> sum(Matrix<T> *m1, Matrix<T> *m2)
{

    size_t row = m1->getRow();
    size_t col = m1->getCol();

    // initialize to 0s when made
    Matrix<T> res(0, row, col);

    // sum 2 matrices
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            res.set(m1->at(i, j) + m2->at(i, j), i, j);
        }
    }

    return res;
}

/**
 * @brief Returns the difference of the current matrix and incoming matrix if m
 * and the current matrices are conformable
 * @param[in] m Pointer to another matrix
 * @return The difference of the 2 matrices, namely m1-m2
 */
template <typename T>
Matrix<T> diff(Matrix<T> *m1, Matrix<T> *m2)
{

    size_t row = m1->getRow();
    size_t col = m1->getCol();

    // initialize to 0s when made
    Matrix<T> res(0, row, col);

    // sum 2 matrices
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            res.set(m1->at(i, j) - m2->at(i, j), i, j);
        }
    }

    return res;
}

/**
 * @brief Returns the current matrix with all entries scaled by scalar
 * @param[in] m Pointer to another
 * @return The matrix with all of its entries inverted
 */
template <typename T>
Matrix<T> scale(Matrix<T> *m, T scalar)
{

    Matrix<T> nextM(0, m->getRow(), m->getCol());

    for (size_t i = 0; i < this->row; i++)
    {
        for (size_t j = 0; j < this->col; j++)
        {
            this->nextM.at(i).at(j) = m->at(i).at(j) scalar;
        }
    }

    return nextM;
}

/**
 * @brief Implementation of matrix mult as essentially by the book definition, 
 * we are doing the product of m1*m2 in this order
 * @param[in] m Pointer to another matrix
 * @return Resulting matrix from (m1 x m2)
 */
template <typename T>
Matrix<T> prod(Matrix<T> *m1, Matrix<T> *m2 )
{

    Matrix<T> nextMatrix(0, m1->row, m2->col);

    for (size_t i = 0; i < m1->row; i++)
    {

        for (size_t j = 0; j < m2->col; j++)
        {

            T curr = 0;

            // do dot product between rows and cols
            for (size_t k = 0; k < m2->col; k++)
            {
                curr += m1->at(i, k) * m2->at(k, j);
            }

            // update new value
            nextMatrix.set(curr, i, j);
        }
    }

    return nextMatrix;
}

/**
 * @brief Computes the product between a matrix and another vector v,
 * computes them in order (Current x v)
 * @param[in] m Pointer to another vector
 * @return Resulting matrix from (Current x v)
 */
template <typename T>
Vec<T> prod(Matrix<T> *m1,  Vec<T> *v)
{

    Vec<T> nextVec = zeros(m->getRow());

    // chooses row
    for (size_t j = 0; j < v->size(); j++)
    {

        T curr = 0;

        // do dot product between rows and cols
        for (size_t k = 0; k < m->col; k++)
        {
            curr += m->at(j, k) * v->at(k);
        }

        // update new value
        nextVec.set(j, curr);
    }

    return nextVec;
};