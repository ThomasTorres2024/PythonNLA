#pragma once

/**
 * @brief Implementation of Vec class with NLA focus. Supports matrix-Vec operations,
 * intended to be used for implementing NLA algorithms.
 *
 * @name Thomas Torres, Charles Booth
 * @date 1/9/26
 */

// includes from other classes
#include "AbstractTensor.h"
#include "Matrix.h"

// includes for this class
#include <vector>

template <typename T>
class Vec : public AbstractTensor<T>
{
public:
    // different constructor types

    /**
     * @brief Constructor for the Vec class given a vector of vals
     * @param[in] vals - A vector of all of the values
     */
    Vec(std::vector<T> vals);

    /**
     * @brief Constructor for fixed-size array
     * @param[in] vals - Pointer to array of T
     */
    Vec(T *vals, size_t num_vals);

    /**
     * @brief Constructor for a single value given n copies of it
     * @param[in] val Value to copy
     * @param[in] copies Number of values to copy in
     */
    Vec(T val, size_t copies);

    // Random Constructors

    /**
     * @brief Constructor for random ints, uniform distribution
     * from lower to upper
     * @param[in] size - Size of vector
     * @param[in] lower - lower bound 
     * @param[in] upper - upper bound 
     */
    Vec(size_t size, int lower, int upper);

    /**
     * @brief Constructor for random vals from lower to uppwer
     * @param[in] lower - lower bound 
     * @param[in] upper - upper bound 
     */
    Vec(size_t size, double lower, double upper);

    // underlying operations used by the operators

    /**
     * @brief Adds two vectors together, and produces a new vector as a result
     * @param[in] v2 New vector of matching size
     * @return New vector created from adding 2 vectors together
     */
    Vec add(Vec v2);

    /**
     * @brief Subtracts v2 from v1 (this vec), returns v1-v2,
     * and produces a new vector as a result
     * @param[in] v2 New vector of matching size
     * @return The vector formed by doing v1-v2
     */
    Vec diff(Vec v2);

    /**
     * @brief Performs dot product between 2 vectors of conformable size
     * @param[in] v2 New vector of matching new
     * @return the result of doing the dot product between v1 and v2
     */
    T dot(Vec v2);

    // Mutators

    void scale(T scalar);

    // accessors

    /**
     * @brief Performs inplace hadamard product
     */
    void hada(Vec<T> v2);

    /**
     * @brief Computes the l2/Euclidean norm of the vector
     * @return The value of the norm of the vector
     */
    T norm();

    /**
     * @brief Computes the l1 norm of the vector
     * @return the l1 norm of the vector
     */
    T manhattan();

    /**
     * @brief Computes the infinity norm of the vector
     * @return the infinity norm of the vector
     */
    T infty_norm();

    /**
     * @brief Computes the p norm of the vector
     */
    T p_norm(size_t p);

    // operations for clean matrix math
    Vec operator+(Vec v2);
    Vec operator-(Vec v2);

    // for scaling
    void operator*(T scalar);

    // for dot product
    T operator*(Vec v2);

    ////////////
    // Acessors//
    ////////////

    /**
     * @brief Returns the size of the vector
     * @return Number of elements in the vector
     */
    size_t getSize();

    /**
     * @brief Returns the position of the vector at some given
     * index
     * @return value of the entry at the corresponding index
     */
    Vec<T> at(size_t index);

    /**
     * @brief Creates identical copy of the current vector
     */
    Vec<T> clone();

    // vector to vector operations

    // matrix vec operations

private:
    std::vector<T> vec_elements;
    size_t size;
};

// Out of class methods for vectors

/**
 * @brief Creates a vector of zeros with n many elements
 * @return A corresponding zero vector with n many elements
 */
template <typename T>
Vec<T> zeros(size_t n);

/**
 * @brief Creates a vector of zeros with n many elements
 * @return A corresponding zero vector with n many elements
 */
template <typename T>
Vec<T> randn(size_t n, int lowerBound, int upperBound);

/**
 * @brief Creates a vector of zeros with n many elements
 * @return A corresponding zero vector with n many elements
 */
template <typename T>
Vec<T> rand_unif(size_t n, double lower, double upper);