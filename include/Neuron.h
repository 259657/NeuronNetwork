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
    double sum;
    std::vector<double> weightout;
    double error;//eror w outpucie to wynik - oczekiwana wartosc.
                 // w hidden error to eroor z poprzedzajacego neurona * waga
public:
// r - prymitywny rodzaj neurona
    Neuron(int r){
    sum = 0;
    error = 0;
    if(r == 1){
        this->value = 0;
    }else if (r == 0){
        this->value =( std::rand() % 2) ;
    }else
        this->value = rand_num();
    };
    //

    double rand_num();
    double getValue() const {return  value;};
    double getErr() const {return  error;};
    double getSum() const {return  sum;};
    double getWeight(size_t i) const {return  weightout[i];};
    size_t getWeight_siz() const {return  weightout.size();};
    void setValue(double val)  {value = val;};
    void setSum(double val)  {sum = val;};
    void setErr(double val)  {error = val;};
    void setWeight(double val,size_t witch)  {weightout[witch] = val;};
    void initWeightOut(size_t i);
    void PrintWeightOut();
//sum = (weights * an-1) + bios
    void SumAndBias(double weight, double neuron);


};


#endif //NEURONNETWORK_NEURON_H
