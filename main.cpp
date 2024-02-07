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
Net siec(2,3,1);

siec.Print_layer(0);
//siec.Print_layer(1);
//siec.Print_layer(2);
siec.ForwardNetwork();
siec.BackNetwork(1.0);

std::cout<<"Po funkcji"<<std::endl;
    //siec.Print_layer(0);
 //   siec.Print_layer(1);
    siec.Print_layer(2);


    // Wykorzystac do testów ustawianie binarnie inputów i wynik
    int x = 1; //0001
    int y = 1; //0001

    int z = x ^ y;
    std::cout<<"Z  "<<z<<std::endl;

    return 0;
}
