/**
 * @brief Abstract tensor class, intends to create child classes for Matrices, and vectors.
 * The Matrix, Vector, and Scalar classes inherit from this operation, as all are respectively 
 * rank 2, rank 1, and rank 0 tensors that have the same fundamental operations. 
 * 
 * @date 12/23/25
 */

class AbstractTensor<T> 
{
public:
    virtual double area() = 0; // Pure virtual function

};