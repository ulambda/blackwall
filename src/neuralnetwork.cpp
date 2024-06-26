#include "../include/blackwall/neuralnetwork.hpp"
#include "../include/blackwall/neuron.hpp"
#include "../include/blackwall/tenser.hpp"
#include <iostream>

namespace BLKW{


    NeuralNetwork::NeuralNetwork(int input_size, std::initializer_list<int> hidden_sizes, int output_size){
        int previous_size = 1;
        Layer *prev_layer = nullptr;  

        input_layer = {input_size, new Neuron[input_size]};
        for(int i = 0 ; i < input_size ; i++){
            input_layer.neurons[i] = Neuron(1, new double[1]{1}, 0, &ActivationFunction::identity);
        }
        previous_size = input_layer.size;
        prev_layer = &input_layer;

        for(int hidden_size : hidden_sizes){
            Layer hidden_layer = {hidden_size, new Neuron[hidden_size]};
            for(int i = 0 ; i < hidden_size ; i++){
                hidden_layer.neurons[i] = Neuron(previous_size);
            }

            prev_layer->next = &hidden_layer;
            hidden_layer.prev = prev_layer;
            prev_layer = &hidden_layer;
           
            hidden_layers.push_back(hidden_layer);
            previous_size = hidden_size;
        }

        output_layer = {output_size, new Neuron[output_size]};
        for(int i = 0 ; i < output_size ; i++){
            output_layer.neurons[i] = Neuron(previous_size);
        }
        prev_layer->next = &output_layer;
        output_layer.prev = prev_layer;
        previous_size = output_layer.size;
    }

    NeuralNetwork::~NeuralNetwork(){
        Layer *current_layer = &input_layer;
        Layer *next_layer = current_layer->next;
        while(current_layer != nullptr){
            delete[] current_layer->neurons;
            delete current_layer;
            current_layer = next_layer;
            if(next_layer != nullptr)
                next_layer = next_layer->next;

        }
    }


    void NeuralNetwork::print(){
        std::cout<<"input layer: [";
        for(int i = 0 ; i < input_layer.size ; i++)
            std::cout<<input_layer.neurons[i].to_string()<<",";
        
        std::cout<<"]" << std::endl;

        int hidden_layer_index = 0;
        for(Layer hidden_layer : hidden_layers){    
            std::cout<<"hidden layer " << hidden_layer_index <<": [";
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

    int NeuralNetwork::output_size(){
        return output_layer.size;
    }



    double* NeuralNetwork::feed(double inputs[]){
        Layer *current_layer = &input_layer; // Declare and initialize the input_layer variable
    
        double *current_inputs = inputs;
    
        double *current_outputs = new double[current_layer->size];
    
        while(current_layer != nullptr){
            for(int i = 0 ; i < current_layer->size ; i++){
                current_outputs[i] = current_layer->neurons[i].output(current_inputs);
            }
            current_inputs = current_outputs;
            current_layer = current_layer->next;
        }
    
        return current_outputs;
    }

    Tenser<double> NeuralNetwork::feed(const Tenser<double>& input){ 
        if(input.depth() != 1 || input.size() != input_layer.size)
            throw std::runtime_error("Invalid input dimensions");

        Layer* layer = &input_layer;
        Tenser<double> inputs(input);
        Tenser<double> outputs = Tenser<double>({layer->size});
        while(layer != nullptr){
            for(int i = 0 ; i < layer->size ; i++)
                (*outputs[{i}]) = layer->neurons[i].output(inputs[{i}]);
                //outputs.replace({i}, layer->neurons[i].output(inputs[{i}]));
            inputs = outputs;
            layer = layer->next;
        }
        return outputs;
    }

    void NeuralNetwork::train(const double* train_X[], const double* train_y[]){
        
    }

    void NeuralNetwork::train(const Tenser<double>& training_set){}


    void NeuralNetwork::test(const Tenser<double>& training_set){}
}
    