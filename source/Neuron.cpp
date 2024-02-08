//
// Created by PRO on 04.02.2024.
//

#include "../include/Neuron.h"

double Neuron::rand_num() {

    double wylosowana_liczba =( (double)std::rand() / RAND_MAX );//0 - 1
    wylosowana_liczba = (wylosowana_liczba*2)-1; //-1 - 1
   return  wylosowana_liczba;
   //std::cout<<"Wartosc neurona :"<<value<<std::endl;

}



void Neuron::initWeightOut(size_t siz) {
    for(size_t i = 0 ; i < siz; i++){
        weightout.push_back(rand_num());
    }
}

void Neuron::PrintWeightOut() {

    for(size_t i = 0;i < weightout.size(); i++  ){
        std::cout<<i+1<<".weight ="<<weightout[i]<<std::endl;
    }

}

void Neuron::SumAndBias(double weight, double neuron) {

    this->value += weight*neuron;
}

