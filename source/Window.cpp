//
// Created by PRO on 30.01.2024.
//

#include "../include/Window.h"


Window::Window(int w, int h): width(w),height(h) {

    window = new sf::RenderWindow(sf::VideoMode(width, height), "Neuron");
    circle.setRadius(40);
    circle.setFillColor(sf::Color(250, 250, 250));




}

Window::~Window() {

}

void Window::set_vec(int c, int pos_X,int pos_Y , std::vector<sf::CircleShape>& v) {

    int w_mid = pos_X / 2 - 50;
    int h_mid =pos_Y;
    for(int i = 0; i < c; i++) {

        circle.setPosition(w_mid, h_mid+i*170);
        v.push_back(circle);

    }

}




template <typename  T>

void Window::print_vec(std::vector<T> &v) {
    for(size_t i  = 0 ; i < v.size();i++){
        // std::cout << "Wsp srodka kola: (" << middle[i].getPosition().x << ", " << middle[i].getPosition().y << ")" << std::endl;
        //window->draw(middle[i]);
        window->draw(v[i]);
    }
}


void Window::render() {
    window->clear(sf::Color::Black);
    print_vec(front);
    print_vec(middle);
    print_vec(end);
    print_vec(line_start);
    print_vec(line_end);

    // draw everything here...
    //window->draw(circle);

    // end the current frame
    window->display();
}
void Window::update() {

    while (window->pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window->close();
    }
}


void Window::run() {
    set_vec(2,width/4,150,front);
    set_vec(3,width,50,middle);
    set_vec(2,1.7*width,150,end);
    connect(front,middle,line_start,sf::Color::Red);
    connect(middle,end,line_end,sf::Color::Blue);

    while (window->isOpen())
    {
      //  std::cout << "Wsp srodka kola: (" << srodek_kola.x << ", " << srodek_kola.y << ")" << std::endl;
       update();
       render();


    }

}

int Window::get_w() {
    return width;
}

int Window::get_h() {
    return height;
}
//do kazdego koła połacz linia
void Window::connect(std::vector<sf::CircleShape> &start, std::vector<sf::CircleShape> &end,std::vector<sf::VertexArray>& con,sf::Color c) {
    sf::VertexArray line(sf::LinesStrip, 2);

    for(size_t i = 0 ; i < start.size(); i ++){

        for(size_t j = 0 ; j < end.size(); j ++){


            line[0].position = sf::Vector2f(start[i].getPosition().x+40, start[i].getPosition().y+40); // Początek linii
            line[1].position = sf::Vector2f(end[j].getPosition().x+40, end[j].getPosition().y+40); // Koniec linii
            line[0].color = c;
            line[1].color = c;

            con.push_back(line);

        }

    }



}











