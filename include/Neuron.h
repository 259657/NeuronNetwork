//
// Created by PRO on 04.02.2024.
//

#ifndef NEURONNETWORK_NEURON_H
#define NEURONNETWORK_NEURON_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <sstream>
#include <iomanip>

class Neuron  {
//
    double value;
    double sum;
    std::vector<double> weightout;
    sf::Text text;
    sf::Font font;
    double error;//eror w outpucie to wynik - oczekiwana wartosc.
                 // w hidden error to eroor z poprzedzajacego neurona * waga

public:
    Neuron(){
        sum = 0;
        error = 0;
        this->value =0;
        if (!font.loadFromFile("../Font/dogicapixel.ttf")) {
            std::cerr << "Błąd wczytywania czcionki!" << std::endl;
        }
        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color(128, 128, 128));
        text.setPosition(0,  0);

    };

// r - prymitywny rodzaj neurona
    Neuron(int r){
    sum = 0;
    error = 0;





    if(r == 1){
       // std::cout<<"TU"<<std::endl;
        this->value = 0;
    }else if (r == 0){
       // std::cout<<"TEN"<<std::endl;
        this->value =( std::rand() % 2) ;
    }else
        this->value = rand_num();
    };
    //

    double rand_num();
    double getValue() const {return  value;};
    double getErr() const {return  error;};
    double getSum() const {return  sum;};
    double getWeight(size_t i) const {return  weightout[i];};
    size_t getWeight_siz() const {return  weightout.size();};
    void setValue(double val)  {value = val;};
    void setSum(double val)  {sum = val;};
    void setErr(double val)  {error = val;};
    void setWeight(double val,size_t witch)  {weightout[witch] = val;};
    void initWeightOut(size_t i);
    void PrintWeightOut();
//sum = (weights * an-1) + bios
    void SumAndBias(double weight, double neuron);

    void setText(){

        std::ostringstream ss;
        ss << std::fixed << std::setprecision(2) << this->value;
        std::string str = ss.str();
        text.setString(str);
    };

    void setTextPosition(float x, float y){
        text.setPosition(x,  y);

    };
    sf::Text getTExt(){
        return text;
    };

    void getPos(){
        std::cout<<text.getPosition().x<<" "<<text.getPosition().y<<std::endl;
    };

    void setFont(const sf::Font& f){
        font = f;
        if (!font.loadFromFile("../Font/dogicapixel.ttf")) {
            std::cerr << "Błąd wczytywania czcionki!" << std::endl;
        }
        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Red);
        text.setPosition(0,  0);


    };

};


#endif //NEURONNETWORK_NEURON_H
