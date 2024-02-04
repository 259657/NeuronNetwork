//
// Created by PRO on 04.02.2024.
//

#include "../include/Neuron.h"

double Neuron::rand_num() {

    double wylosowana_liczba =( (double)std::rand() / RAND_MAX );
   return  wylosowana_liczba;
   //std::cout<<"Wartosc neurona :"<<value<<std::endl;

}

double Neuron::activation_fun(std::vector<Neuron>& in ,std::vector<Neuron>& out) {


    for(size_t i = 0 ; i < in.size(); i++){
    // weightout

    }
}

void Neuron::initWeightOut(size_t siz) {
    for(size_t i = 0 ; i < siz; i++){
        weightout.push_back(rand_num());
    }
}
void Neuron::initWeightInt(size_t siz) {
    for(size_t i = 0 ; i < siz; i++){
        weightin.push_back(rand_num());
    }
}

void Neuron::PrintWeightOut() {

    for(size_t i = 0;i < weightout.size(); i++  ){
        std::cout<<i+1<<".weight ="<<weightout[i]<<std::endl;
    }

}
