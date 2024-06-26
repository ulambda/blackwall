#ifndef NEURON_HPP
#define NEURON_HPP

#include "activation_function.hpp"
#include <memory>

namespace BLKW{
    class Neuron{
        private:
            int size; //specifies the number of inputs the neuron accepts and the number of weights it has
            std::shared_ptr<double[]> weights; //pointer to a dynamiclly allocated array of weights
            double bias; //additive parameter that offsets how string the weighted sum needs to be for the neuron to fire
            double const (*activation_function)(double); //pointer to the activiation function the neuron uses

        public:
            /**
             * @brief default constructor initializes a neuron with size of 1, a weight of 1, and a bias of 0.
             * @note mainly used for Neurons in the input layer.
             */
            Neuron();

            /**
             * @brief parameterized constructor creates a neuron that accepts a specified number of inputs and initializes the weights and bias with random values.
             * @param size number of inputs the neuron accepts
             * @note preferred way to create neurons
             */
            Neuron(int size);

            /**
             * @brief copy constructor for copying the weights and bias of another neuron.
             * @param other pointer to the neuron to copy
             */
            Neuron(const Neuron * other);

            /**
             * @brief parameterized constructor for manually setting the weights and bias of a neuron and the activation function.
             * @param size number of inputs the neuron accepts
             * @param weights array of weights for the neuron
             * @param bias bias of the neuron
             * @param activation_function pointer to the activation function the neuron uses
             * @note should only be used for testing
             */
            Neuron(int size, double weights[], double bias, double const (*activation_function)(double));

            ~Neuron();

            /**
             * @brief feeds the inputs into the neuron and returns the output
             * @param inputs array of inputs
             * @return output of the neuron
             */
            double output(double inputs[]);
            
            void set_size(int size);


            void set_activation_function(double const (*activation_function)(double));

            void randomize();

            std::string to_string();

            

    };
}

#endif // NEURON_HPP