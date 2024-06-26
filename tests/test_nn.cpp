#include "../include/blackwall/blackwall.hpp"
#include <iostream>

int main(void){

    std::cout<<"hello world"<<std::endl;

    BLKW::NeuralNetwork nn(1, {2, 3}, 1);

    nn.print();


    return 0;
}
