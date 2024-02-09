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

//Window Neuron(800,800);
//Neuron.run();
//Neuron n;
//n.rand_num();

    Net siec(2,1,3,1);

    siec.Print_all_layer();


//Net siec(2,3,1);



siec.Print_layer(0);
int i =0;
do{
    siec.ForwardNetwork();
   // siec.Print_Answer();
    siec.BackNetwork();
   // siec.Print_Answer();
   // std::cout<<siec.getTot_err()<<std::endl;
    i++;

}while(i < 2000);//siec.getTot_err() >= 0.0001);
std::cout<<"Po funkcji Back"<<std::endl;

   // siec.Print_all_layer();
    std::cout<< "Total err po "<<i<<" ";
    siec.Print_Answer();

   // std::cout<< "Total err po "<<i<<" iteracjach : "<<siec.getTot_err();



//double x = 0.0;
   // std::cout<<"Wynik mianownika :"<<exp(x)/(exp(2*x) + 2*exp(x)+1) <<" Dla x= "<<x<<std::endl;
    return 0;
}



