# Use 
To use and test any of the heavily WIP methods, simply execute from the root directory:
``` 
    bash MatrixOps/scripts/build.sh
```

And then to execute the code without any parameters (parameters are WIP):

```
    bash MatrixOps/scripts/exec.sh 
```

# Current Plans 

Implement AbstractTensor class as such 

```mermaid
classDiagram
    AbstractTensor <|-- Matrix
    AbstractTensor <|-- Vector
    AbstractTensor <|-- Scalar
    

    AbstractTensor : +sum()
    AbstractTensor : +diff()
    AbstractTensor : +scale()
    AbstractTensor : +prod()
    AbstractTensor : +norm()
    
    Matrix : -size_t row
    Matrix : -size_t col
    Matrix : -vector(vector(T)) matrix_vals
    
    Matrix : +row()
    Matrix : +col()
    Matrix : +frobenius()
    Matrix : +SVD()
    
    Vector : -size
    
    Vector : +size()
    Vector : +l1_norm()
    Vector : +lp_norm(int p)
    
    
    
```

# Motivation

I wanted to provide an implementation of a lot of the algorithms I saw in my NLA course for fun with numpy. I hope to go further with a lot of the code here and potentially extend it to some lower level code I can put in a python wrapper. I included some TeX notes with everything as well since 
