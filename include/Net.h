
#ifndef NEURONNETWORK_NET_H
#define NEURONNETWORK_NET_H

#include "Neuron.h"
#include <vector>
#include <algorithm>
#include <cmath>

class Net {
    int input,  hidden,  output;
    std::vector<Neuron> in;
    std::vector<Neuron> hide;
    std::vector<Neuron> out;

    std::vector<std::vector<Neuron>> all;
   // double RM;//Root Mean  Error
    double total_error;
    double learning_rate;
    double exp_val;


public:
    Net(int input , int hidden , int output);
    Net(int input_neurons , int hidden_layer,int hidden_neurons , int output_neurons);

    void Print_layer(int number);
    void Print_Answer();
    void Print_all_layer();

    void initNeuronsInLayer(size_t number_of_neurons,size_t which_layer);
    void initWeight(std::vector<Neuron>& in , std::vector<Neuron> & out);

    //sum of [waga*input]+bias
    void ForwardNetwork();
    void setExpValue_XOR();
    void BackNetwork();

    double getTot_err() const {return total_error;};
    size_t getSize(){return all.size();};

    std::vector<Neuron> getLayer(size_t Layer){return  all[Layer];};
    size_t getLayerSize(size_t Layer){return  all[Layer].size();};
    double ActivationFunction(int function , bool is_backprop,double sum_of_neuron);


    double TanhFunction(bool is_backprop,double sum_of_neuron);// Wartosci pomiedzy -1 a 1 przydatne w hidden layers
    double SigmoidFunction(bool is_backprop,double x);// Wartosci pomiędzy 0 a 1 przydatne  w binary ? chyba ?
    //void ReLuFunction(); max(0,x)
};


#endif //NEURONNETWORK_NET_H
