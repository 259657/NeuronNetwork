
#ifndef NEURONNETWORK_NET_H
#define NEURONNETWORK_NET_H

#include "Neuron.h"
#include <vector>
#include <algorithm>

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

    //sum of [waga*input]+bios

     void ForwardNetwork();

};


#endif //NEURONNETWORK_NET_H
