#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "Net.h"

#ifndef NEURONNETWORK_WINDOW_H
#define NEURONNETWORK_WINDOW_H


class Window {


    int width;
    int  height;

    Net  * siec;

    sf::RenderWindow* window;
    sf::CircleShape circle;


    sf::Event event;

    std::vector<sf::CircleShape> middle;
    std::vector<sf::CircleShape> front;
    std::vector<sf::CircleShape> end;

    std::vector<sf::VertexArray> line_start;
    std::vector<sf::VertexArray> line_end;



public:
    Window(int w, int h);
    ~Window();
    void run();
    void render();
    void update();
    void set_vec(int count,int pos_X,int pos_y,std::vector<sf::CircleShape>& v);

    void set_vec_end(int count);
    void set_vec_front(int count);
    int get_w();
    int get_h();
    template <typename T>
    void print_vec(std::vector<T>& v);

    void connect(std::vector<sf::CircleShape>& start,std::vector<sf::CircleShape>& end,std::vector<sf::VertexArray>& con, sf::Color c);


};


#endif //NEURONNETWORK_WINDOW_H
