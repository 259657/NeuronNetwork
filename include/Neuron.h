//
// Created by PRO on 04.02.2024.
//

#ifndef NEURONNETWORK_NEURON_H
#define NEURONNETWORK_NEURON_H

#include <vector>
#include <cstdlib>
#include <iostream>

class Neuron  {

    double value;
    //std::vector<double> weightin;
   // std::vector<double> weightout;
public:

    Neuron(){
        //this->value = 0;
        rand_num();
    };
    double activation_fun(std::vector<Neuron>);
    void rand_num();
    double getValue() const {return  value;};

};


#endif //NEURONNETWORK_NEURON_H
