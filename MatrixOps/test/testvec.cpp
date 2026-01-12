/**
 * @brief Test file for matrix math library 
 * @author Charles Booth
 * @date 1-11-26 
 */

#include <iostream> 
#include "Vec.h"

void testVectorInit();


int main(int argc, char* argv[]){
    testVectorInit();
    return 0; 
}


/**
 * @brief Tests that vector initializations occur as expected 
 */
void testVectorInit(){
    Vec<double> v1(std::vector<double>{1.0, 2.0, 3.0, 4.0});
}