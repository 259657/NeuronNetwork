//
// Created by PRO on 04.02.2024.
//

#ifndef NEURONNETWORK_NEURON_H
#define NEURONNETWORK_NEURON_H

#include <vector>
#include <cstdlib>
#include <iostream>

class Neuron  {
//
    double value;
    std::vector<double> weightin;
    std::vector<double> weightout;
public:
// r - prymitywny rodzaj neurona
    Neuron(int r){
    if(r == 1){
        this->value = 0;
    }else
        this->value = rand_num();
    };
    //
    double activation_fun(std::vector<Neuron>& in , std::vector<Neuron> & out);
    double rand_num();
    double getValue() const {return  value;};
    void setValue(double val)  {value = val;};
    void initWeightOut(size_t i);
    void initWeightInt(size_t i);
    void PrintWeightOut();

};


#endif //NEURONNETWORK_NEURON_H
