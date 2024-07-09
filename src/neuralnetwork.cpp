#include "../include/blackwall/neuralnetwork.hpp"
#include "../include/blackwall/neuron.hpp"
#include "../include/blackwall/tenser.hpp"
#include <iostream>

namespace BLKW{

    NeuralNetwork::NeuralNetwork(int input_size, std::initializer_list<int> hidden_sizes, int output_size){
        int prev_size = 1;
        Layer *prev_layer = nullptr;  
    
        this->input_layer = {input_size, new Neuron[input_size]}; //init input layer of size input_size

        //set neurons in input layer to have 1 input, 0 bias, and identity activation function
        for(int i = 0 ; i < input_size ; i++){
            input_layer.neurons[i] = Neuron(1, new double[1]{1}, 0, &ActivationFunction::identity); 
        }

        prev_size = input_layer.size;
        prev_layer = &input_layer;

        //create hidden layers
        for(int hidden_size : hidden_sizes){
            Layer hidden_layer = {hidden_size, new Neuron[hidden_size]};

            //set neurons of this hidden layer to accept prev_size number of inputs
            for(int i = 0 ; i < hidden_size ; i++){
                hidden_layer.neurons[i] = Neuron(prev_size);
            }

            prev_layer->next = &hidden_layer; //set the previous layer's next member to point to the current hidden layer
            hidden_layer.prev = prev_layer;
            prev_layer = &hidden_layer;
           
            hidden_layers.push_back(hidden_layer);
            prev_size = hidden_size;
        }
    
        this->output_layer = {output_size, new Neuron[output_size]};
        for(int i = 0 ; i < output_size ; i++){
            output_layer.neurons[i] = Neuron(prev_size);
        }
        prev_layer->next = &output_layer;
        output_layer.prev = prev_layer;
    }

    NeuralNetwork::~NeuralNetwork(){}


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

    // double* NeuralNetwork::feed(double input[]){
    //     Layer* current_layer = &hidden_layers[0];
    //     double *current_inputs = input;
    //     double *current_outputs;
    //     while(current_layer != nullptr){
    //         current_outputs = new double[current_layer->size];
    //         for(int i = 0 ; i < current_layer->size ; i++)
    //             current_outputs[i] = current_layer->neurons[i].output(current_inputs);
    //         current_inputs = current_outputs;
    //         current_layer = current_layer->next;
    //     }
    //     return current_outputs;
    // }

    std::vector<double> NeuralNetwork::feed(const std::vector<double>& input){
        if(input.size() != input_layer.size)
            throw std::invalid_argument("input layer expected " + std::to_string(input_layer.size) + " inputs but got " + std::to_string(input.size()) + " inputs.");
    
        Layer* current_layer = &hidden_layers[0];
    
        std::vector<double> current_inputs = input;
    
        while(current_layer != nullptr){
            std::vector<double> current_outputs(current_layer->size);

            for(int i = 0 ; i < current_layer->size ; i++)
                current_outputs[i] = current_layer->neurons[i].output(current_inputs);
            
            current_inputs = current_outputs;
            current_layer = current_layer->next;
        }
        
        return current_inputs;
    }


    Tenser<double> NeuralNetwork::feed(const Tenser<double>& input){ 
        if(input.size() != input_layer.size)
            throw std::invalid_argument("input layer expected " + std::to_string(input_layer.size) + " inputs but got " + std::to_string(input.size()) + " inputs.");

        Layer* layer = &hidden_layers[0];

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

    void NeuralNetwork::train(const std::vector<std::vector<double>>& train_X, const std::vector<std::vector<double>>& train_y){

        for(int i = 0 ; i < train_X.size() ; i++){

            std::vector<double> outputs = feed(train_X[i]);
  
            std::vector<double> targets = train_y[i];

        }
    }




    void NeuralNetwork::train(const Tenser<double>& trainset){

    }

    double NeuralNetwork::test(const Tenser<double>& testset){return 0;}

    double NeuralNetwork::test(const double* test_X[], const double* test_y[]){
        return 0;
    }
}
    