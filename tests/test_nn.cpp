#include "../include/blackwall/blackwall.hpp"
#include <iostream>

int main(void){
    BLKW::NeuralNetwork nn(1, {2, 3}, 3);
    nn.print();

    double *predict = nn.feed_forward(new double[1]{1});

    std::cout<<"outputs: [";
    for(int i = 0 ; i < nn.output_size() ; i++)
        std::cout<<"{"<<predict[i]<<"}";
    std::cout<<"]";

    return 0;
}
