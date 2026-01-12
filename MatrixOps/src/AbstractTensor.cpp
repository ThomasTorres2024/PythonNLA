/**
 * @brief Abstract tensor class, intends to create child classes for Matrices, and vectors.
 * The Matrix, Vector, and Scalar classes inherit from this operation, as all are respectively 
 * rank 2, rank 1, and rank 0 tensors that have the same fundamental operations. 
 * 
 * @date 12/23/25
 */


template<typename T>  class AbstractTensor
{
public:


    //destructor for the abstract class 
    virtual ~AbstractTensor();

    //underlying operations used by the operators 
    virtual AbstractTensor add(const AbstractTensor t2 );
    virtual AbstractTensor diff(const AbstractTensor t2);
    virtual void scale(T scalar);

    virtual double norm();

    //operations for clean matrix math 
    virtual AbstractTensor operator+(const AbstractTensor t2);
    virtual AbstractTensor operator-(const AbstractTensor t2);
    virtual AbstractTensor operator*(const AbstractTensor t2);
    virtual AbstractTensor operator*(T scalar);
};