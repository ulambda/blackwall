#include "../include/blackwall/activation_function.hpp"

namespace BLKW{

    const double (*ActivationFunction::get_activation_function(Type type))(double){
        switch(type){
            case Type::IDENTITY: return &identity;
            case Type::SIGMOID: return &sigmoid;
            case Type::TANH: return &tanh;
            case Type::RELU: return &relu;
            case Type::SOFTMAX: return &softmax;
            case Type::STEP: return &step;
            default: throw std::invalid_argument("activation function type not recognized");
        }
    }

    const double (*ActivationFunction::get_activation_function_derivative(Type type))(double){
        switch(type){
            case Type::IDENTITY: return &identity_derivative;
            case Type::SIGMOID: return &sigmoid_derivative;
            case Type::TANH: return &tanh_derivative;
            case Type::RELU: return &relu_derivative;
            case Type::SOFTMAX: return &softmax_derivative;
            case Type::STEP: return &step_derivative;
            default: throw std::invalid_argument("activation function type not recognized");
        }
    }

    double const ActivationFunction::identity(double x){
        return x;
    }

    double const ActivationFunction::identity_derivative(double x){
        return 1;
    }

    double const ActivationFunction::sigmoid(double x){
        return 1.0 / (1.0 + std::exp(-x));
    }

    double const ActivationFunction::sigmoid_derivative(double x){
        return sigmoid(x) * (1 - sigmoid(x));
    }

    double const ActivationFunction::tanh(double x){
        return std::tanh(x);
    }

    double const ActivationFunction::tanh_derivative(double x){
        return 1 - std::pow(tanh(x), 2);
    }

    double const ActivationFunction::relu(double x){
        return x > 0 ? x : 0;
    }

    double const ActivationFunction::relu_derivative(double x){
        return x > 0 ? 1 : 0;
    }

    double const ActivationFunction::softmax(double x){
        return std::exp(x) / std::exp(x);
    }

    double const ActivationFunction::softmax_derivative(double x){
        return softmax(x) * (1 - softmax(x));
    }

    double const ActivationFunction::step(double x){
        return x > 0 ? 1 : 0;
    }

    double const ActivationFunction::step_derivative(double x){
        return 0;
    }
}