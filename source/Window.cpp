//
// Created by PRO on 30.01.2024.
//

#include "../include/Window.h"


Window::Window(int w, int h): width(w),height(h) {

    window = new sf::RenderWindow(sf::VideoMode(width, height), "Neuron");
    circle.setRadius(40);
    circle.setFillColor(sf::Color(250, 250, 250));

}
Window::Window(int w, int h, int input_neurons, int hidden_layer, int hidden_neurons, int output_neurons):width(w),height(h) ,Terminal_Network(new Net(input_neurons,hidden_layer,hidden_neurons,output_neurons)) {
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Neuron");
    circle.setRadius(40);
    circle.setFillColor(sf::Color(250, 250, 250));
    Hidden.resize(Terminal_Network->getSize()-2);
    All.resize(Terminal_Network->getSize());
    lines.resize(All.size()-1);
}

Window::~Window() {

}

void Window::set_vec(size_t c, int pos_X,int pos_Y , std::vector<sf::CircleShape>& v) {

    int w_mid = pos_X;
    int h_mid =pos_Y/4;
    for(size_t  i = 0; i < c; i++) {

        circle.setPosition(w_mid, (h_mid+i*400)/c);
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
    for(auto & i : All){
        print_vec(i);
    }
    for(auto & i : lines){
        print_vec(i);
    }
    //print_vec(All[0]);
   // print_vec(All[2]);
//    print_vec(front);
//    print_vec(middle);
//    print_vec(end);
   // print_vec(line_start);
   // print_vec(line_end);

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

    for(size_t i = 0 ; i < All.size();i++){
        set_vec(Terminal_Network->getLayerSize(i),(i+1)*150,height,All[i]);
    }
    for(size_t i = 0 ; i < All.size()-1;i++){

            connect(All[i],All[i+1],lines[i],sf::Color(rand() % 255, rand() % 255, rand() % 255));
    }

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













