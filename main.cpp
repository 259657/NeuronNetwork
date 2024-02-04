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

//Window Neuron(800,600);
//Neuron.run();
//Neuron n;
//n.rand_num();
Net siec(2,3,1);
siec.Print_layer(0);




    return 0;
}
