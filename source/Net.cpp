//
// Created by PRO on 04.02.2024.
//

#include "../include/Net.h"


Net::Net(int input, int hidden, int output) {
        int sum = std::max( input, hidden );
        sum = std::max(sum,output);
        // std::cout<<"Sum "<<sum<<std::endl;

        for(int j = 0 ; j < sum;j++){
            if(j < input){
                in.push_back(Neuron());
            }
            if(j < hidden){
                hide.push_back(Neuron());
            }
            if(j < output){
                out.push_back(Neuron());
            }
        }
        all.push_back(in);
        all.push_back(hide);
        all.push_back(out);

}

void Net::Print_layer(int number) {

for(size_t i = 0 ; i < all[number].size();i++ )
    {
    std::cout<<"Wartosc Neurona "<<all[number][i].getValue()<<std::endl;
}


}


