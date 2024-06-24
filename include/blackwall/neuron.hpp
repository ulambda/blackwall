#ifndef NEURON_HPP
#define NEURON_HPP

#include "activation_function.hpp"

namespace BLKW{
    class Neuron{
        private:
            int size; //number of inputs the neuron accepts
            const double* weights; //pointer to the first weight in the array of weights the neuron contains 
            double bias;
            double (*activation_function)(double) = &identity; //pointer to the activiation function used, set to identity by default

        public:
            Neuron();
            Neuron(int size, double weights[], double bias);
            Neuron(int size, double weights[], double bias, double (*activation_function)(double));
            double output(double inputs[]);
    };
}

#endif // NEURON_HPP