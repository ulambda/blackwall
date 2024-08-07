# Blackwall
 A high level machine learning library for C++ which provides implementations for machine learning models, data processing functions and data structures.

## Getting Started
 Start using the library in your project by including the blackwall.hpp header file in `include/blackwall/blackwall.hpp`. 
 All classes and functions are apart of the BLKW namespace.
 
 Example: 
 ```cpp
 #include "lib/blackwall/include/blackwall/blackwall.hpp"
 
 int main(){
    BLWK::Tenser<double> train_X = new BLKW::Tenser<double>({4,2});
    BLWK::Tenser<double> train_y = new BLKW::Tenser<double>({4});
    
    BLKW::Model nn = new BLKW::NeuralNetwork(2, {2}, 1);
    
    nn.train(train_X, train_y);

    BLWK::Tenser<double> output = nn.feed(BLKW::Tenser<double>({1,1}));
    output.print();

    return 0;
 }
 ```