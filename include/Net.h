
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

public:
    Net(int input , int hidden , int output);
    void Print_layer(int number);
    void initWeight(std::vector<Neuron>& in , std::vector<Neuron> & out);

    //sum of [waga*input]+bias
    void ForwardNetwork();
    void BackNetwork();

    double ActivationFunction(int function , bool is_backprop,double sum_of_neuron);

    double TanhFunction(bool is_backprop,double sum_of_neuron);// Wartosci pomiedzy -1 a 1 przydatne w hidden layers
    double SigmoidFunction(bool is_backprop,double x);// Wartosci pomiędzy 0 a 1 przydatne  w binary ? chyba ?
    //void ReLuFunction(); max(0,x)
};


#endif //NEURONNETWORK_NET_H
