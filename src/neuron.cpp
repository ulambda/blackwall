#include "../include/blackwall/neuron.hpp"
#include <stdexcept>
#include <random>

namespace BLKW{

    Neuron::Neuron(int size, double weights[], double bias, double const (*activation_function)(double)) {
        this->size = size;
        this->weights = std::shared_ptr<double[]>(new double[size]);
        for(int i = 0; i < size; i++)
            this->weights.get()[i] = weights[i];
        this->bias = bias;
        this->activation_function = activation_function;
    }

    Neuron::Neuron() : Neuron(1, new double[1]{1}, 0, &ActivationFunction::identity) {}

    Neuron::Neuron(const Neuron * other) : Neuron(other->size, other->weights.get(), other->bias, other->activation_function) {}

    Neuron::Neuron(int size) : Neuron(size, new double[size], 0, &ActivationFunction::identity) {
        std::random_device random;
        std::mt19937 generator(random());
        std::uniform_real_distribution<double> distribution(0.0, 1.0);

        for(int i = 0; i < size; i++)
            this->weights.get()[i] = distribution(generator);

        this->bias = distribution(generator);
    }

    Neuron::~Neuron(){
        //delete[] weights.get();
    }

    double Neuron::output(double inputs[]){
        double sum = 0;
        for(int i = 0; i < size; i++)
            sum += inputs[i] * weights[i];
        double z = sum + bias;
        double y = activation_function(z);
        return y;
    }


    void Neuron::set_size(int size){
        this->size = size;
        this->weights = std::shared_ptr<double[]>(new double[size]);
    }


    void Neuron::randomize(){
        std::random_device random;
        std::mt19937 generator(random());
        std::uniform_real_distribution<double> distribution(0.0, 1.0);
        for(int i = 0 ; i < size ; i++)
            weights[i] = distribution(generator);
    }

    std::string Neuron::to_string(){
        std::string str = "{";
        for(int i = 0 ; i < size ; i++)
            str += std::to_string(weights[i]) + ",";
        str += "}";
        return str;
    }
}
