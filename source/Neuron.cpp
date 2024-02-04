//
// Created by PRO on 04.02.2024.
//

#include "../include/Neuron.h"

void Neuron::rand_num() {

    double wylosowana_liczba =( (double)std::rand() / RAND_MAX );
   this->value = wylosowana_liczba;
   std::cout<<"Wartosc neurona :"<<value<<std::endl;

}
