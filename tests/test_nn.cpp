#include "../include/blackwall/blackwall.hpp"
#include <iostream>
#include <cassert>

#define PRINT(x) std::cout << (x) << std::endl;



void test1(){
    BLKW::NeuralNetwork nn(1, {2, 3}, 3);
    nn.print();
    double *predict = nn.feed(new double[1]{1});
    
    std::cout<<"outputs: [";
    for(int i = 0 ; i < nn.output_size() ; i++)
        std::cout<<"{"<<predict[i]<<"}";
    std::cout<<"]";
    std::cout<<"\n";
    PRINT("test 1 passed");
}

void test2(){
    BLKW::NeuralNetwork nn(1, {2, 3}, 3);
    BLKW::Tenser<double> input = BLKW::Tenser<double>::ones({1});

    BLKW::Tenser<double> output = nn.feed(input);

    PRINT("test 2 passed");
}



int main(void){
    //test1();
    test2();
    return 0;
}
