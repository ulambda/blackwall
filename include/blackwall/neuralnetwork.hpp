#ifndef NERUALNETWORK_HPP
#define NERUALNETWORK_HPP

#include "model.hpp"
#include "neuron.hpp"
#include <iostream>


namespace BLKW {
    /**
     * @brief A simple, high level implementation of a Vanilla Neural Nework. 
     * @note also called a Forward Feeding Neural Network, Deep Neural Network or Multi-layer Perception 
     */
    class NeuralNetwork : public Model{
        public:
            struct Layer{
                int size;
                Neuron *neurons;
                Layer *next = nullptr;
                Layer *prev = nullptr;
            };

            struct {
                int epochs = 1;
                double learning_rate = 0.01;
                int batch_size = 1;
            } hyperparams;

        private:
            int input_layer_size;
            std::vector<Layer> hidden_layers;
            Layer output_layer;

        public: 
            /**
             * @brief parameterized constructor for creating a neural network with a specified number of inputs, hidden layers, and outputs.
             * @param input_size number of neurons in the input layer
             * @param hidden_sizes list of the number of neurons in each hidden layer, number of integers in the list will be the number of hidden layers and each integer represents the number of neurons in the layer
             * @param output_size number of neurons in the output layer
             */
            NeuralNetwork(int input_size, std::initializer_list<int> hidden_sizes, int output_size);

            /**
             * destructor for the neural network that deallocates the memory used by all the neurons in the network
             */
            ~NeuralNetwork();  

            /**
             * @brief prints the weights and biases for each the neurons in the network by layer
             * @note the first weight in the list is always the bias
             */     
            void print();

            /**
             * @brief returns the number of outputs in the output layer
             * @return the number of neurons in the output layer
             */
            int output_size();            
            
            /**
             * @brief feeds forward the inpust into the network and returns the output
             * @param input the input to the network
             * @return the output of the network
             */
            Tenser<double> feed(const Tenser<double>& input);

            /**
             * @brief feeds forward the inpust into the network and returns the output
             * @param input the input to the network
             * @return the output of the network
             */
            std::vector<double> feed(const std::vector<double>& input);

            /**
             * @brief trains the network on a dataset
             * @param trainset the dataset to train the network on
             */
            void train(const Tenser<double>& trainset);

            /**
             * @brief trains the network on a dataset
             * @param train_X the input dataset to train the network on
             * @param train_y the output dataset to train the network on
             */
            void train(const std::vector<std::vector<double>>& train_X, const std::vector<std::vector<double>>& train_y);
            
            /**
             * @brief tests the network on a dataset
             * @param testset the dataset to test the network on
             * @return the accuracy of the network
             */
            double test(const Tenser<double>& testset);
            double test(const std::vector<std::vector<double>>& test_X, const std::vector<std::vector<double>>& test_y);
            void gradient_search(const std::vector<std::vector<double>>& train_X, const std::vector<std::vector<double>>& train_y);
    };
}

#endif // NERUALNETWORK_HPP