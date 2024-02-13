//
// Created by PRO on 30.01.2024.
//

#include "../include/Window.h"


Window::Window(int w, int h): width(w),height(h) {

    window = new sf::RenderWindow(sf::VideoMode(width, height), "Neuron");
    circle.setRadius(40);
    circle.setFillColor(sf::Color(250, 250, 250));
    circle.setOutlineColor(sf::Color(128, 128, 128));
    circle.setOutlineThickness(-2);

}
Window::Window(int w, int h, int input_neurons, int hidden_layer, int hidden_neurons, int output_neurons):width(w),height(h) ,Terminal_Network(new Net(input_neurons,hidden_layer,hidden_neurons,output_neurons)) {
    window = new sf::RenderWindow(sf::VideoMode(width, height), "Neuron");
    circle.setRadius(40);
    circle.setFillColor(sf::Color(250, 250, 250));
    circle.setOutlineColor(sf::Color( 100, 100, 100));
    circle.setOutlineThickness(4);
    //Hidden.resize(Terminal_Network->getSize()-2);
    All.resize(Terminal_Network->getSize());
    lines.resize(All.size()-1);
    Terminal_Network->setFont(font);


}

Window::~Window() {

}

void Window::set_vec(size_t c, int pos_X,int pos_Y , std::vector<sf::CircleShape>& v,size_t j) {

    int w_mid = pos_X/((Terminal_Network->getSize()+1)*2);
    int h_mid =pos_Y/4;
     std::vector<Neuron> &tmp = *Terminal_Network->getLayerr(j);
    circle.setOutlineColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
    for(size_t  i = 0; i < c; i++) {

        circle.setPosition(w_mid*(j+1), (h_mid+i*400)/c);

        tmp[i].setFont(font);
        tmp[i].setText();
        tmp[i].setTextPosition(circle.getPosition().x + circle.getRadius()/2-5, circle.getPosition().y + circle.getRadius()/2);
        //tmp[i].getPos();
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
    for(size_t z = 0; z < All.size(); z++){
        std::vector<Neuron> &tmp = *Terminal_Network->getLayerr(z);
        for(auto & k : tmp){
           // k.getPos();
            window->draw(k.getTExt());
        }
    }
    window->draw(Terminal_Network->getTExt_Tot_Err());
    for(auto & i : lines){
        print_vec(i);
    }

        print_vec(dots);


    //window->draw(text);
    // draw everything here...
    //window->draw(circle);

    // end the current frame
    window->display();
}
int tes = 0;
bool enterPressed = false;
void Window::update() {
//    Terminal_Network->setIntAndOutValue();
//    Terminal_Network->ForwardNetwork();
//    Terminal_Network->BackNetwork();

    while (window->pollEvent(event)) {

        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed) {
            window->close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Q) {
                std::cout << "Q key was pressed!" << std::endl;
                Terminal_Network->TestNet(1, 1);

                enterPressed = true;


            }
            if (event.key.code == sf::Keyboard::W) {
                std::cout << "W key was pressed!" << std::endl;
                Terminal_Network->TestNet(0, 0);

                enterPressed = true;


            }
            if (event.key.code == sf::Keyboard::E) {
                std::cout << "E key was pressed!" << std::endl;
                Terminal_Network->TestNet(1, 0);

                enterPressed = true;


            }
            if (event.key.code == sf::Keyboard::R) {
                std::cout << "R key was pressed!" << std::endl;
                Terminal_Network->TestNet(0, 1);

                enterPressed = true;


            }
            if (event.key.code == sf::Keyboard::Space) {
                if (!enterPressed) {
                    enterPressed = true;
                } else
                    enterPressed = false;

            }


        }
        else if (event.type == sf::Event::MouseButtonPressed) {

            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

                // Tworzymy kropkę
                sf::CircleShape dot(5); // Rozmiar kropki
                dot.setFillColor(sf::Color::White); // Kolor kropki
                dot.setPosition(sf::Vector2f(mousePosition)); // Ustawienie pozycji kropki
                dot.setOutlineColor(sf::Color( 100, 100, 100));
                dot.setOutlineThickness(2);
                dots.push_back(dot);
                // Rysujemy kropkę na ekranie

            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);

                // Tworzymy kropkę
                sf::CircleShape dot(5); // Rozmiar kropki
                dot.setFillColor(sf::Color::Black); // Kolor kropki
                dot.setPosition(sf::Vector2f(mousePosition)); // Ustawienie pozycji kropki
                dot.setOutlineColor(sf::Color( 100, 100, 100));
                dot.setOutlineThickness(2);
                dots.push_back(dot);
                // Rysujemy kropkę na ekranie

            }

        }


    }
    if (!enterPressed) {
        Terminal_Network->setIntAndOutValue();
        Terminal_Network->ForwardNetwork();
        Terminal_Network->BackNetwork();
        ++tes;
        std::cout << tes << std::endl;
    }
    if (tes % 100 ==0) {


    for (size_t i = 0; i < All.size() - 1; i++) {

        connect(All[i], All[i + 1], lines[i], sf::Color(rand() % 255, rand() % 255, rand() % 255), i, false);
    }
}



}


void Window::run() {

    for(size_t i = 0 ; i < All.size();i++){

        set_vec(Terminal_Network->getLayerSize(i),width,height,All[i], i);


        //set_vec(Terminal_Network->getLayerSize(i),(i+1)*150,height,All[i], i);
    }
    for(size_t i = 0 ; i < All.size()-1;i++){

            connect(All[i],All[i+1],lines[i],sf::Color(rand() % 255, rand() % 255, rand() % 255),i, true);
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
void Window::connect(std::vector<sf::CircleShape> &start, std::vector<sf::CircleShape> &end,std::vector<sf::VertexArray>& con,sf::Color c,size_t wich_layer, bool is_init) {
    sf::VertexArray line(sf::LinesStrip, 2);


   int t = 0;
    for(size_t i = 0 ; i < start.size(); i ++){
        std::vector<Neuron> tmp = Terminal_Network->getLayer(wich_layer);
        for(size_t j = 0 ; j < end.size(); j ++) {

            // std::cout<<tmp[i].getWeight(j)<<std::endl;
            if (tmp[i].getWeight(j) < 0) {
                c = sf::Color::Red;
            } else if (tmp[i].getWeight(j) > 0) {
                c = sf::Color::Green;
            }

            line[0].position = sf::Vector2f(start[i].getPosition().x + 40,start[i].getPosition().y + 40); // Początek linii
            line[1].position = sf::Vector2f(end[j].getPosition().x + 40, end[j].getPosition().y + 40); // Koniec linii
            line[0].color = c;
            line[1].color = c;


            t++;
        if(is_init){
             con.push_back(line);
            // std::cout<<" linia "<<i<<" na pozycji "<<j<<" ma "<<con.size()<<" t "<<t<<std::endl;
            }
        }
    if(!is_init){
        con[t-1] = line;
    }

    }



}













