#include "../include/blackwall/neuron.hpp"
#include <stdexcept>
#include <random>

namespace BLKW{

    Neuron::Neuron(int size, double weights[], double bias, double const (*activation_function)(double)) {
        this->size = size;
        this->weights = new double[size];
        for(int i = 0; i < size; i++)
            this->weights[i] = weights[i];
        this->bias = bias;
        this->activation_function = activation_function;
    }

    Neuron::Neuron() : Neuron(1, new double[1]{1}, 0, &ActivationFunction::identity) {}

    Neuron::Neuron(const Neuron *other) : Neuron(other->size, other->weights, other->bias, other->activation_function) {}

    Neuron::Neuron(int size) : Neuron(size, new double[size], 0, &ActivationFunction::identity) {
        std::random_device random;
        std::mt19937 generator(random());
        std::uniform_real_distribution<double> distribution(0.0, 1.0);

        // std::default_random_engine generator;
        // std::normal_distribution<double> distribution(0.0 , 1.0);

        for(int i = 0; i < size; i++)
            this->weights[i] = distribution(generator);

        this->bias = distribution(generator);
    }

    Neuron::~Neuron(){
        delete[] weights;
    }

    Neuron& Neuron::operator=(const Neuron& other){
        this->size = other.size;
        this->weights = other.weights;
        this->bias = other.bias;
        this->activation_function = other.activation_function;
        return *this;
    }

    double Neuron::output(double inputs[]){
        double sum = 0;
        for(int i = 0; i < size; i++)
            sum += inputs[i] * weights[i];
        double z = sum + bias;
        double y = activation_function(z);
        return y;
    }



    // void Neuron::randomize(){
    //     std::random_device random;
    //     std::mt19937 generator(random());
    //     std::uniform_real_distribution<double> distribution(0.0, 1.0);
    //     for(int i = 0 ; i < size ; i++)
    //         weights[i] = distribution(generator);
    // }

    std::string Neuron::to_string(){
        std::string str = "{";
        str += std::to_string(bias) + ", ";
        for(int i = 0 ; i < size ; i++)
            str += std::to_string(weights[i]) + ",";
        str.pop_back();
        str += "}";

        return str;
    }
}
