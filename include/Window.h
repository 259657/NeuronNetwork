#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "Net.h"

#ifndef NEURONNETWORK_WINDOW_H
#define NEURONNETWORK_WINDOW_H


class Window {


    int width;
    int  height;

    Net * Terminal_Network;

    sf::RenderWindow* window;
    sf::CircleShape circle;


    sf::Event event;



    std::vector<std::vector<sf::CircleShape>> Hidden;


    std::vector<std::vector<sf::CircleShape>> All;
    std::vector<std::vector<sf::VertexArray>> lines;





public:
    Window(int w, int h);
    Window(int w, int h,int input_neurons , int hidden_layer,int hidden_neurons , int output_neurons);
    ~Window();
    void run();
    void render();
    void update();

    void set_vec(size_t count,int pos_X,int pos_y,std::vector<sf::CircleShape>& v);

    Net getNet(){ return *Terminal_Network;};

    int get_w();
    int get_h();

    template <typename T>
    void print_vec(std::vector<T>& v);
    void connect(std::vector<sf::CircleShape>& start,std::vector<sf::CircleShape>& end,std::vector<sf::VertexArray>& con, sf::Color c);


};


#endif //NEURONNETWORK_WINDOW_H
