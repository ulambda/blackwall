#include "../include/blackwall/blackwall.hpp"
#include <iostream>
#include <cassert>

#define PRINT(x) std::cout << (x) << std::endl;



void test1(){
    BLKW::NeuralNetwork nn(3, {2, 3}, 1);
    // nn.print();
    std::vector<double> inputs = {1.0, 2.0, 3.0};

    std::vector predict = nn.feed(inputs);

    
    // std::cout<<"outputs: [";
    // for(int i = 0 ; i < nn.output_size() ; i++)
    //     std::cout<<"{"<<predict[i]<<"}";
    // std::cout<<"]";
    // std::cout<<"\n";
    PRINT("test 1 passed");
}

// void test2(){
//     BLKW::NeuralNetwork nn(1, {2, 3}, 3);
//     BLKW::Tenser<double> input = BLKW::Tenser<double>::ones({1});
//     BLKW::Tenser<double> output = nn.feed(input);
//     PRINT("test 2 passed");
// }


void test3(){


    //xor problem
    BLKW::NeuralNetwork nn(2, {2}, 1);
    std::vector<std::vector<double>> inputs = {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };
    std::vector<std::vector<double>> outputs = {
        {0}, {1}, {1}, {0}
    };
    nn.train(inputs, outputs);
    PRINT("test 3 passed");
}

void test4(){
    BLKW::NeuralNetwork nn(2, {2}, 1);
    std::vector<std::vector<double>> inputs = {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };
    std::vector<std::vector<double>> outputs = {
        {0}, {1}, {1}, {0}
    };
    
    std::vector out = nn.feed(inputs[0]);
    
    std::cout<<"outputs: [";
    for(int i = 0 ; i < nn.output_size() ; i++)
        std::cout<<"{"<<out[i]<<"}";
    std::cout<<"]";
    std::cout<<"\n";

    PRINT("test 4 passed");

}

/**
 * tests the training process to see if the error is correct
 */

void test5(){
    BLKW::NeuralNetwork nn(2, {2}, 1);
    std::vector<std::vector<double>> inputs = {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };
    std::vector<std::vector<double>> outputs = {
        {0}, {1}, {1}, {0}
    };
    nn.train(inputs, outputs);
    std::cout<<"\n";

    PRINT("test 5 passed");

}

void test6(){
    BLKW::NeuralNetwork nn(2, {2}, 1);
    std::vector<std::vector<double>> inputs = {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
    };
    std::vector<std::vector<double>> outputs = {
        {0}, {1}, {1}, {0}
    };
    int acc = nn.test(inputs, outputs);
    std::cout<<"accuracy: "<<acc<<"\n";
    PRINT("test 6 passed");
}

int main(void){
    //test1();
    //test3();
    //test4();
    //test5();
    test6();
    return 0;
}
