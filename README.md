# Blackwall
 A high level machine learning library for C++. 
 This library provides implementations for machine learning models, data processing functions and data structures.

## Getting Started
 Start using the library in your project by including the blackwall.hpp header file in `include/blackwall/blackwall.hpp`. 
 All classes and functions are apart of the BLKW namespace.
 EG:
 ```cpp
 #include "lib/blackwall/include/blackwall/blackwall.hpp"
 int main(){
    BLWK::Tenser<double> train_X = new BLKW::Tenser<double>({{0, 0}, {0, 1}, {1, 0}, {1, 1}});
    BLWK::Tenser<double> train_y = new BLKW::Tenser<double>({{0}, {1}, {1}, {0}});
    
    BLKW::Model nn = new BLKW::NeuralNetwork(2, {2}, 1);
    
    nn.train(train_X, train_y);

    BLWK::Tenser<double> output = nn.feed(BLKW::Tenser<double>({1,1}));
    output.print();

    return 0;
 }
 ```
