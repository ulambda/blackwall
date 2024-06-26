#include "../include/blackwall/activation_function.hpp"

namespace BLKW{
    double const ActivationFunction::identity(double x){
        return x;
    }

    double const ActivationFunction::sigmoid(double x){
        return 1.0 / (1.0 + std::exp(-x));
    }

    double const ActivationFunction::tanh(double x){
        return std::tanh(x);
    }

    double const ActivationFunction::relu(double x){
        return x > 0 ? x : 0;
    }

    double const ActivationFunction::softmax(double x){
        return std::exp(x) / std::exp(x);
    }

    double const ActivationFunction::step(double x){
        return x > 0 ? 1 : 0;
    }
}