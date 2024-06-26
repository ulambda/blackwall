#ifndef NERUALNETWORK_HPP
#define NERUALNETWORK_HPP

#include "model.hpp"
#include "neuron.hpp"
#include <iostream>


namespace BLKW {
    class NeuralNetwork : public Model{
        public:
            struct Layer{
                int size;
                Neuron* neurons;
            };

            Layer input_layer;
            std::vector<Layer> hidden_layers;
            Layer output_layer;

            struct {
                int epochs;
                double learning_rate;
                int batch = 1;
            } hyperparams;

        private:


        public: 
            /**
             * @brief parameterized constructor for creating a neural network with a specified number of inputs, hidden layers, and outputs.
             * @param input_size number of neurons in the input layer
             * @param hidden_sizes list of the number of neurons in each hidden layer, number of integers in the list will be the number of hidden layers and each integer represents the number of neurons in the layer
             * @param output_size number of neurons in the output layer
             */
            NeuralNetwork(int input_size, std::initializer_list<int> hidden_sizes, int output_size);

            void train(Tenser<double> training_set);
            Tenser<double> feed(Tenser<double> input);
            void test(Tenser<double> training_set);

            double* feed_forward(double inputs[]);
            void print();
            void export_params();
    };
}

#endif // NERUALNETWORK_HPP