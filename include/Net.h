
#ifndef NEURONNETWORK_NET_H
#define NEURONNETWORK_NET_H

#include "Neuron.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

class Net {
    int input,  hidden,  output;
    std::vector<Neuron> in;
    std::vector<Neuron> hide;
    std::vector<Neuron> out;

    std::vector<std::vector<Neuron>> all;
   // double RM;//Root Mean  Error
    sf::Text text_tot_err;
    sf::Font font;
    double total_error;
    double learning_rate;
    double exp_val;


public:
    Net(int input , int hidden , int output);
    Net(int input_neurons , int hidden_layer,int hidden_neurons , int output_neurons);

    void Print_layer(int number);
    void Print_Answer();
    void Print_all_layer();

    void initNeuronsInLayer(size_t number_of_neurons,size_t which_layer);
    void initWeight(std::vector<Neuron>& in , std::vector<Neuron> & out);

    void setExpValue_XOR();
    void setIntAndOutValue();
    void TestNet(int first,int second);


    double getTot_err() const {return total_error;};
    double getLastNeuron() const {return all.back()[0].getValue();};
    size_t getSize(){return all.size();};
    std::vector<Neuron> getLayer(size_t Layer){return  all[Layer];};

     std::vector<Neuron>* getLayerr(size_t j) {return &all[j];};

    size_t getLayerSize(size_t Layer){return  all[Layer].size();};

    //sum of [waga*input]+bias
    void ForwardNetwork();
    void BackNetwork();

    double ActivationFunction(int function , bool is_backprop,double sum_of_neuron);
    double NormalizedTanhFunction(bool is_backprop,double sum_of_neuron);// Wartosci pomiedzy -1 a 1 przydatne w hidden layers
    double SigmoidFunction(bool is_backprop,double x);// Wartosci pomiędzy 0 a 1 przydatne  w binary ? chyba ?
    //void ReLuFunction(); max(0,x)

    void setText_Tot_Err(){

        std::ostringstream ss;
        ss << this->total_error;
        std::string str = ss.str();
        text_tot_err.setString(str);
    };
    sf::Text getTExt_Tot_Err(){
        return text_tot_err;
    };
    void setFont(const sf::Font& f){
        font = f;
        if (!font.loadFromFile("../Font/dogicapixel.ttf")) {
            std::cerr << "Błąd wczytywania czcionki!" << std::endl;
        }
        text_tot_err.setFont(font);
        text_tot_err.setCharacterSize(20);
        text_tot_err.setFillColor(sf::Color::Red);
        text_tot_err.setPosition(0,  0);


    };

};


#endif //NEURONNETWORK_NET_H
