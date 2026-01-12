# Use 
To use and test any of the heavily WIP methods, simply execute from the root directory:
(At the moment we only are testing things)
```
	#this one works:
	MatrixOps/scripts/build_test.sh

	#this is nothing atm
    # bash MatrixOps/scripts/build.sh
```

And then to execute the code without any parameters (parameters are WIP, also again we only have tests atm) run from root:
```
	#for vec test class 
	./test_vec

	#for matrix text class
	./test_matrix

    bash MatrixOps/scripts/exec.sh 
```

# Current Plans 
We decided to not use inheritance, there isn't enough overlap between the classes without just implementing
everything as a Matrix, so, there will be no more abstract tensor here.

```mermaid
classDiagram
    Matrix : -size_t row
    Matrix : -size_t col
    Matrix : -vector[vector[T]] matrix_vals
	
    Matrix : +sum()
    Matrix : +diff()
    Matrix : +scale()
    Matrix : +prod()
    Matrix : +norm()
    Matrix : + (Uniform Distribution [a,b] Constructor) Matrix(size_t row, size_t col, T a, T b)
    Matrix : + (Random Integer Constructor on [a,b]) Matrix(size_t row, size_t col, int a, int b)
    Matrix : + (Identity Constructor) Matrix(size_t n)
    Matrix : + (Zero Constructor) Matrix(size_t row, size_t col)
    Matrix : + (2d Vec Constructor) Matrix(vector[vector[T]] info)
	
	
    Matrix : +row()
    Matrix : +col()
    Matrix : +frobenius()
    Matrix : +SVD()
    
    Vector : -size
    Vector : -vector[T] vector_vals
    
    Vector : + (Uniform Distribution [a,b] Constructor) Vector(size_t size, T a, T b)
    Vector : + (Random Integer Constructor on [a,b]) Vector(size_t size, int a, int b)
    Vector : + (Identity Constructor) Vector(size_t size, size_t position)
    Vector : + (Zero Constructor) Vector(size_t size)
    Vector : + (Vec Constructor) Vector(vector[T] info)
	
	Vector : +sum()
    Vector : +diff()
    Vector : +scale()
    Vector : +prod()
    Vector : +norm()
    Vector : +size()
    Vector : +l1_norm()
    Vector : +lp_norm(int p)
    
    
    
```


# Motivation

I wanted to provide an implementation of a lot of the algorithms I saw in my NLA course for fun with numpy. I hope to go further with a lot of the code here and potentially extend it to some lower level code I can put in a python wrapper. I included some TeX notes with everything as well since 




