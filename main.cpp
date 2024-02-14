#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "include/Window.h"
#include "include/Neuron.h"
#include "include/Net.h"
#include <ctime>

int main() {
    srand( time( NULL ) );
    std::cout << "Hello, World!" << std::endl;
//
Window Graphic(1600,600,2,2,4,1, true);
    Graphic.getNet().Print_layer(0);
Graphic.run();


/*
    Net siec(2,1,4,1);
  //  siec.Print_all_layer();

siec.Print_layer(0);
int i =0;
double max,min;

max = min = 0.0;

do{
    siec.setIntAndOutValue();
    siec.ForwardNetwork();
   // siec.Print_Answer();
    siec.BackNetwork();
    //siec.Print_Answer();
   // std::cout<<siec.getTot_err()<<std::endl;
   if(siec.getLastNeuron() < 0.5){
       min = siec.getLastNeuron();
   }
   else if(siec.getLastNeuron() > max)
   {
       max = siec.getLastNeuron();

   }
    i++;

}while(i<250000); //siec.getTot_err() >= 0.00003);
    siec.Print_Answer();
    std::cout<<"Min "<<min<<" Max "<<max<<std::endl;
    std::cout<<"I "<<i<<std::endl;

   // std::cout<<"Po funkcji Back"<<std::endl;
   // siec.Print_all_layer();
   // std::cout<< "Total err po "<<i<<" ";
   // siec.Print_Answer();
    std::cout<< "TESTY "<<std::endl;
    siec.TestNet(1,0);//1

    siec.TestNet(0,1);//1

    siec.TestNet(0,0);//0

    siec.TestNet(1,1);//0

    */

}



