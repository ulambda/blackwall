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


void test3(){
    BLKW::NeuralNetwork nn(3, {3, 3}, 3);

    double train_X [3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    double train_y [3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    double* xptr [3]{train_X[0], train_X[1], train_X[2]};
    double* yptr [3]{train_y[0], train_y[1], train_y[2]};



    nn.train(xptr, yptr);

    PRINT("test 3 passed");
}

int main(void){
    //test1();
    //test2();
    test3();
    return 0;
}
