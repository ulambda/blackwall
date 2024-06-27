#ifndef NEURON_HPP
#define NEURON_HPP

#include "activation_function.hpp"
#include <memory>

namespace BLKW{
    /**
     * Represents the mathmatical model of a single neuron with methods.
     */
    class Neuron{
        private:
            int size; //specifies the number of inputs the neuron accepts and the number of weights it has
            //std::shared_ptr<double[]> weights; //pointer to a dynamiclly allocated array of weights
            double *weights = nullptr; //pointer to a dynamiclly allocated array of weights
            double bias; //additive parameter that offsets how string the weighted sum needs to be for the neuron to fire
            double const (*activation_function)(double) = nullptr; //pointer to the activiation function the neuron uses

        public:

            /**
             * @brief parameterized constructor for manually setting the weights and bias of a neuron and the activation function.
             * @param size number of inputs the neuron accepts
             * @param weights array of weights for the neuron
             * @param bias bias of the neuron
             * @param activation_function pointer to the activation function the neuron uses
             */
            Neuron(int size, double weights[], double bias, double const (*activation_function)(double));

            /**
             * @brief parameterized constructor creates a neuron that accepts a specified number of inputs and initializes the weights and bias with random values.
             * @param size number of inputs the neuron accepts
             * @note preferred way to create neurons
             */
            Neuron(int size);

            /**
             * @brief default constructor initializes a neuron with size of 1, a weight of 1, and a bias of 0.
             */
            Neuron();

            /**
             * @brief copy constructor for copying the weights and bias of another neuron.
             * @param other pointer to the neuron to copy
             */
            Neuron(const Neuron *other);

            /**
             * @brief destructor deallocates memory of neuron weights
             */
            ~Neuron();

            /**
             * @brief copy assignment operator for copying the weights and bias of another neuron.
             * @param other pointer to the neuron to copy
             * @return reference to the neuron
             */
            Neuron& operator=(const Neuron& other);

            /**
             * @brief feeds the inputs into the neuron and returns the output
             * @param inputs array of inputs
             * @return output of the neuron
             */
            double output(double inputs[]);
            
            /**
             * @brief sets the activation function of the neuron
             * @param activation_function pointer to an activation function
             */
            void set_activation_function(double const (*activation_function)(double));
            
            /**
             * @brief returns a string representation of the neuron
             * @return string representation of the neuron
             * @note first value is always the bias, then the rest are its weights
             */
            std::string to_string();
    };
}

#endif // NEURON_HPP