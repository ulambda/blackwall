#include "../include/blackwall/blackwall.hpp"
#include <iostream>

#define PRINT(X) std::cout<<X<<std::endl;

void test_1(){
    double input[] = {2};
    double iw[] = {1};
    BLKW::Neuron ni(1, iw, 0, BLKW::identity);
    double nio = ni.output(input);
    PRINT(nio);

    double hw[] = {2};
    BLKW::Neuron nh1(1, hw, 0, BLKW::identity);
    BLKW::Neuron nh2(1, hw, 0, BLKW::identity);
    BLKW::Neuron nh3(1, hw, 0, BLKW::identity);

    double nh1o = nh1.output(input);
    PRINT(nh1o);
    double nh2o = nh2.output(input);
    PRINT(nh2o);
    double nh3o = nh3.output(input);
    PRINT(nh3o);

    double ow[] = {1, 1, 1};
    BLKW::Neuron no(3, ow, 0, BLKW::sigmoid);
    double noo = no.output(new double[3]{nh1o, nh2o, nh3o});
    PRINT(noo);
}

int main(void){
    test_1();
    return 0;
}