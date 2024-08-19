#include "../include/blackwall/neuron.hpp"
#include "../include/blackwall/activation_function.hpp"
#include <stdexcept>
#include <random>



namespace BLKW{

    // Neuron::Neuron(int size, double weights[], double bias, double const (*activation_function)(double)) {
    //     this->size = size;
    //     this->weights = new double[size];
    //     for(int i = 0; i < size; i++)
    //         this->weights[i] = weights[i];
    //     this->bias = bias;
    //     this->activation_function = activation_function;
    // }

    Neuron::Neuron(int size, double weights[], double bias, ActivationFunction::Type activation_function_type) {
        this->size = size;
        this->weights = new double[size];
        for(int i = 0; i < size; i++)
            this->weights[i] = weights[i];
        this->bias = bias;
        this->activation_function_type = activation_function_type;
    }

    Neuron::Neuron() : BLKW::Neuron(1, new double[1]{1}, 0, ActivationFunction::Type::IDENTITY) {}

    Neuron::Neuron(const Neuron *other) : Neuron(other->size, other->weights, other->bias, other->activation_function_type) {}

    Neuron::Neuron(int size) : Neuron(size, new double[size], 0, ActivationFunction::Type::IDENTITY) {
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
        this->activation_function_type = other.activation_function_type;
        return *this;
    }

    double Neuron::output(double inputs[]) const{
        double sum = 0;
        for(int i = 0; i < size; i++)
            sum += inputs[i] * weights[i];
        double z = sum + bias;
        const double (*activation_function)(double) = ActivationFunction::get_activation_function(activation_function_type);
        double y = activation_function(z);
        return y;
    }

    double Neuron::output(const std::vector<double>& inputs) const{
        if(inputs.size() != size)
            throw std::invalid_argument("neuron exepcted " + std::to_string(size) + " inputs but got " + std::to_string(inputs.size()) + " inputs.");
        
        double sum = 0;
        for(int i = 0; i < size; i++)
            sum += inputs[i] * weights[i];
        double z = sum + bias;
        const double (*activation_function)(double) = ActivationFunction::get_activation_function(activation_function_type);
        double y = activation_function(z);
        return y;
    }

    std::string Neuron::to_string() const{
        std::string str = "{";
        str += std::to_string(bias) + ", ";
        for(int i = 0 ; i < size ; i++)
            str += std::to_string(weights[i]) + ",";
        str.pop_back();
        str += "}";

        return str;
    }

    int Neuron::get_size() const{
        return size;
    }

    void Neuron::set_activation_function(ActivationFunction::Type activation_function_type){
        this->activation_function_type = activation_function_type;
    }
}
