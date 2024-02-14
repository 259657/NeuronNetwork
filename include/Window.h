#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <sstream>

#include "Net.h"

#ifndef NEURONNETWORK_WINDOW_H
#define NEURONNETWORK_WINDOW_H


class Window {


    int width;
    int  height;
    bool is_mouse = false;

    Net * Terminal_Network;

    sf::RenderWindow* window;
    sf::CircleShape circle;


    sf::Event event;
    sf::Text text;
    sf::Font font;
   // sf::Vertex line;

    sf::VertexArray border;
    //std::vector<std::vector<sf::CircleShape>> Hidden;


    std::vector<std::vector<sf::CircleShape>> All;
    std::vector<std::vector<sf::VertexArray>> lines;

    std::vector<sf::CircleShape> dots;

    sf::Image out_image;
    sf::Sprite out_spirite;
    sf::Texture out_texture;

    //std::vector<>



public:
    Window(int w, int h);
    Window(int w, int h,int input_neurons , int hidden_layer,int hidden_neurons , int output_neurons,bool is_mouse);
    ~Window();
    void run();
    void render();
    void update();

    void set_vec(size_t count,int pos_X,int pos_y,std::vector<sf::CircleShape>& v,size_t i);

    Net getNet(){ return *Terminal_Network;};

    int get_w();
    int get_h();

    template <typename T>
    void print_vec(std::vector<T>& v);
    void connect(std::vector<sf::CircleShape>& start,std::vector<sf::CircleShape>& end,std::vector<sf::VertexArray>& con, sf::Color c,size_t wich_layer, bool is_init);
    void initBorder();

};


#endif //NEURONNETWORK_WINDOW_H
