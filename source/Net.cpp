//
// Created by PRO on 04.02.2024.
//

#include "../include/Net.h"


Net::Net(int input, int hidden, int output) : input(input),hidden(hidden),output(output) {
        int sum = std::max( input, hidden );
        sum = std::max(sum,output);
        // std::cout<<"Sum "<<sum<<std::endl;

        for(int j = 0 ; j < sum;j++){
            if(j < input){
                in.push_back(Neuron(0));
            }
            if(j < hidden){
                hide.push_back(Neuron(1));
            }
            if(j < output){
                out.push_back(Neuron(1));
            }
        }

        all.push_back(in);
        all.push_back(hide);
        all.push_back(out);
        for(size_t j = 0 ; j < all.size()-1;j++){
            initWeight(all[j],all[j+1]);
        }

}

void Net::Print_layer(int number) {
    std::cout<<"Warstwa : "<<number<<std::endl;
for(size_t i = 0 ; i < all[number].size();i++ )
    {
    std::cout<<"Wartosc Neurona "<<all[number][i].getValue()<<std::endl;
    std::cout<<"Wagi "<<i+1<<std::endl;
    all[number][i].PrintWeightOut();
        std::cout<<std::endl;
}


}

void Net::initWeight(std::vector<Neuron>& in , std::vector<Neuron> & out) {

    for(size_t i = 0 ; i < in.size(); i ++){
            in[i].initWeightOut(out.size());
        }

}


