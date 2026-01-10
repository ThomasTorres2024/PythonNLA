/**
 * @brief Implementation of vector class with NLA focus. Supports matrix-vector operations,
 * intended to be used for implementing NLA algorithms.
 *
 * @name Thomas Torres
 * @date 1/9/26
 */

#include <vector>
#include "AbstractTensor.h"
#include "Vec.h"
#include <cmath>

// Constructors

/**
 * @brief Constructor for the Vec class given a vector of vals
 * @param[in] vals - A vector of all of the values
 */
template <typename T>
Vec<T>::Vec(std::vector<T> vals)
{
    this->vec_elements = vals;
    this->size = vec_elements.size();
}

/**
 * @brief Constructor for fixed-size array for Vec class
 * @param[in] vals - Pointer to array of T
 */
template <typename T>
Vec<T>::Vec(T *vals, size_t num_vals)
{
    this->vec_elements = std::vector<T>(num_vals);
    for (size_t i = 0; i < num_vals; i++)
    {
        vec_elements.push_back(vals[i]);
    }
}

// Mutators

/**
 * @brief Scales each value of the vector by some amount
 * @param[in] scaler - A scaler which scales the vector by some amount
 */
template <typename T>
void Vec<T>::scale(T scaler)
{

    // 0 case, use util class to speed this up
    if (scaler == 0)
    {
        this->vec_elements = std::vector<T>(this->vec_elements.size(), 0);
        return;
    }

    // otherwise normally scale
    for (size_t i = 0; i < this->vec_elements.size(); i++)
    {
        vec_elements.at(i) *= scaler;
    }
}

/**
 * @brief Performs inplace hadamard product on vector given another vector
 * of corresponding size
 */
template <typename T>
void Vec<T>::hada(Vec<T> v2)
{
    for (size_t i = 0; i < v2.size(); i++)
    {
        this->vec_elements.at(i) = (this->at(i) * v2.at(i))
    }
}

// Accessors

/**
 * @brief Returns the size of the vector
 * @return Number of elements in the vector
 */
template <typename T>
size_t Vec<T>::getSize()
{
    return this->size;
}

/**
 * @brief Returns the position of the vector at some given
 * index
 * @return value of the entry at the corresponding index
 */
template <typename T>
T Vec<T>::at(size_t index)
{
    return this->eleme
}

/**
 * @brief Computes the l2/Euclidean norm of the vector
 * @return The value of the euclidean norm of the vector
 */
template <typename T>
T Vec<T>::norm()
{
    T total = 0;
    for (auto v : this->vec_elements)
    {
        total += v * v;
    }
    return sqrt(total);
}

/**
 * @brief Computes the l1/manhattan norm of the vector
 * @return The value of the l1 norm of the vector
 */
template <typename T>
T Vec<T>::manhattan()
{
    T total = 0;
    for (auto v : this->vec_elements)
    {
        total += abs(v);
    }
    return total;
}

/**
 * @brief Computes the infinity norm of the vector
 * @return The value of the norm of the vector
 */
template <typename T>
T Vec<T>::infty_norm()
{
    T max = 0;
    for (auto v : this->vec_elements)
    {
        if (abs(v) > max)
        {
            max = abs(v);
        }
    }
    return max;
}

/**
 * @brief Computes the p norm of the vector, intended for
 * p>2, for p=2 use "norm", for p=1 use "manhattan", for
 * infinity use "infty_norm"
 * @return The value of the norm of the vector
 */
template <typename T>
T Vec<T>::p_norm(size_t p)
{
    T total = 0;
    for (auto v : this->vec_elements)
    {
        total += pow(v, p);
    }
    return total;
}

/**
 * @brief Creates identical copy of the current vector
 * @return Identical copy of the vector as a separate object
 */
template <typename T>
Vec<T> Vec<T>::clone()
{
    return Vec<T>(this->vec_elements());
}

// Vector/Vector Ops

/**
 * @brief Adds two vectors together, and produces a new vector as a result
 * @param[in] v2 New vector of matching size
 * @return New vector created from adding 2 vectors together
 */
template <typename T>
Vec<T> Vec<T>::add(const Vec<T> v2)
{

    // create vec of zeros
    Vec<T> nextVector = Vec<T>(0, v2.size());

    for (size_t i = 0; i < v2.size(); i++)
    {
        nextVector.at(i) = this->at(i) + v2.at(i);
    }

    return nextVector;
}

/**
 * @brief Subtracts v2 from v1 (this vec), returns v1-v2,
 * and produces a new vector as a result
 * @param[in] v2 New vector of matching size
 * @return The vector formed by doing v1-v2
 */
template <typename T>
Vec<T> Vec<T>::diff(const Vec<T> v2)
{

    // create vec of zeros
    Vec<T> nextVector = Vec<T>(0, v2.size());

    for (size_t i = 0; i < v2.size(); i++)
    {
        nextVector.at(i) = this->at(i) - v2.at(i);
    }

    return nextVector;
}

/**
 * @brief Performs dot product between 2 vectors of conformable size
 * @param[in] v2 New vector of matching new
 * @return the result of doing the dot product between v1 and v2
 */
template <typename T>
T Vec<T>::dot(Vec<T> v2)
{
    T res = 0;
    for (size_t i = 0; i < v2.size(); i++)
    {
        res += this->at(i) * v2->at(i);
    }
    return res;
}



// Operators

/**
 * @brief Operator overload for addition of 2 vectors
 * @param[in] v2 A vector to add to this current vector
 * @return Resulting vector from the sum of 2 vectors
 */
template <typename T>
Vec<T> Vec<T>::operator+(Vec t2)
{
    return this->add(t2);
}

/**
 * @brief Operator overload for difference of 2 vectors
 * @param[in] v2 A vector to add to this current vector
 * @return Resulting vector from the diff of 2 vectors (v1-v2)
 */
template <typename T>
Vec<T> Vec<T>::operator-(Vec t2)
{
    return this->diff(t2);
}

/**
 * @brief Operator overload for scaling a vector by some amount
 * @param[in] scale A vector to add to this current vector
 * @return Resulting vector from the diff of 2 vectors (v1-v2)
 */
template <typename T>
void Vec<T>::operator*(T scale)
{
    return this->scale(scale);
}

/**
 * @brief Operator overload for dot product operation
 * @param[in] v A vector of the same size to do a dot product with vector
 * @return The dot product between v1 (curr vector) and v 
 */
template <typename T>
T Vec<T>::operator*(Vec<T> v)
{
    return this->dot(v);
}

// Static Vector Operations
/**
 * @brief Creates a vector of zeros with n many elements
 * @return A corresponding zero vector with n many elements
 */
template <typename T>
Vec<T> zeros(size_t n)
{
    return Vec<T>(0, n);
}