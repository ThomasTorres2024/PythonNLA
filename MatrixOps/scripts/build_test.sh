#Author Thomas Torres
#Date 1/11/26
#Build method for test class for vector ops

#g++ -std=c++23 -IMatrixOps/include MatrixOps/src/Vector.cpp MatrixOps/test/testvec.cpp  -o test

test_vector_name="$test_vec"
test_vector_name="$test_matrix"

g++ -std=c++23 -IMatrixOps/include MatrixOps/test/test_vec.cpp  -o test_vec

g++ -std=c++23 -IMatrixOps/include MatrixOps/test/test_matrix.cpp  -o test_matrix