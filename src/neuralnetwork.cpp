#include "../include/blackwall/neuralnetwork.hpp"
#include "../include/blackwall/neuron.hpp" // Include the header file that defines the Neuron class
#include <iostream>

namespace BLKW{
    NeuralNetwork::NeuralNetwork(int input_size, std::initializer_list<int> hidden_sizes, int output_size){
        int previous_size = 1;
        input_layer = {input_size, new Neuron[input_size]};
        for(int i = 0 ; i < input_size ; i++){
             //input_layer.neurons[i].set_size(previous_size);
             input_layer.neurons[i].randomize();
        }
        previous_size = input_layer.size;


        for(int hidden_size : hidden_sizes){
            Layer hidden_layer = {hidden_size, new Neuron[input_size]};
            for(int i = 0 ; i < hidden_size ; i++){
                //hidden_layer.neurons[i].set_size(previous_size);
                hidden_layer.neurons[i].randomize();
            }
            hidden_layers.push_back(hidden_layer);
            previous_size = hidden_layer.size;
        }

        output_layer = {output_size, new Neuron[output_size]};
        for(int i = 0 ; i < output_size ; i++){
            //output_layer.neurons[i].set_size(previous_size);
            output_layer.neurons[i].randomize();
        }
        previous_size = output_layer.size;
    }

    void NeuralNetwork::print(){
        std::cout<<"input layer: [";
        for(int i = 0 ; i < input_layer.size ; i++)
            std::cout<<input_layer.neurons[i].to_string()<<",";
        std::cout<<"]" << std::endl;

        int hidden_layer_index = 0;
        for(Layer hidden_layer : hidden_layers){    
            std::cout<<"hidden layer " << hidden_layer_index <<" : [";
            for(int i = 0 ; i < hidden_layer.size ; i++)
                std::cout<<hidden_layer.neurons[i].to_string()<<",";
            std::cout<<"]" << std::endl;
            hidden_layer_index++;
        }

        std::cout<<"output layer: [";
        for(int i = 0 ; i < output_layer.size ; i++)
            std::cout<<output_layer.neurons[i].to_string()<<",";
        std::cout<<"]" << std::endl;

    }

    void NeuralNetwork::train(Tenser<double> training_set){}
    Tenser<double> NeuralNetwork::feed(Tenser<double> input){ return Tenser<double>(); }
    void NeuralNetwork::test(Tenser<double> training_set){}
}
    