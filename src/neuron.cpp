#include "../include/blackwall/neuron.hpp"

namespace BLKW{
    Neuron::Neuron(){
        this->size = 0;
        this->weights = nullptr;
        this->bias = 0;
    }

    Neuron::Neuron(int size, double weights[], double bias){
        this->size = size;
        this->weights = weights;
        this->bias = bias;
    }

    Neuron::Neuron(int size, double weights[], double bias, double (*activation_function)(double)){
        this->size = size;
        this->weights = weights;
        this->bias = bias;
        this->activation_function = activation_function;
    }

    double Neuron::output(double inputs[]){
        double sum = 0;
        for(int i = 0; i < size; i++)
            sum += inputs[i] * weights[i];
        
        double z = sum + bias;
        return activation_function(sum);
    }
}
