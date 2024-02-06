//
// Created by PRO on 04.02.2024.
//

#include "../include/Net.h"

//xor 00;11 = 0
Net::Net(int input, int hidden, int output) : input(input),hidden(hidden),output(output) {
        int sum = std::max( input, hidden );
        sum = std::max(sum,output);
        // std::cout<<"Sum "<<sum<<std::endl;

        for(int j = 0 ; j < sum;j++){
            if(j < input){
               // in.push_back(Neuron(0));
                in.emplace_back(0);
            }
            if(j < hidden){
               // hide.push_back(Neuron(1));
                hide.emplace_back(1);
            }
            if(j < output){
                //out.push_back(Neuron(1));
                out.emplace_back(1);
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

void Net::initWeight(std::vector<Neuron>& vec_in , std::vector<Neuron> & vec_out) {

    for(size_t i = 0 ; i < vec_in.size(); i ++){
        vec_in[i].initWeightOut(vec_out.size());
        }

}

void Net::ForwardNetwork() {
//std::cout<<all.size()<<std::endl;
    for(size_t i = 1; i != all.size();i++){// warstwa
        for(size_t j = 0 ; j != all[i].size();j++){//który neuron w warstwie aktualnej
            for(size_t z = 0; z != all[i-1].size();z++){//popzednie neurony

                all[i][j].SumAndBios(all[i-1][z].getWeight(j) ,all[i-1][z].getValue());
               // std::cout<<"Value"<<all[i-1][z].getValue()<<std::endl;
                //std::cout<<"Waga"<<all[i-1][z].getWeight(j)<<std::endl;

            }
            if(i !=all.size()-1) {//ostatnia warstwa nie potrzebuje baiosu poniewaz problem nie jest az tak skomplikowany
                all[i][j].SumAndBios(1, 1);//biios
            }
            all[i][j].setValue(ActivationFunction(0,false,all[i][j].getValue()));

        }
    }
}

void Net::BackNetwork() {

}

double Net::ActivationFunction(int function, bool is_backprop,double sum_of_neuron) {

    switch (function) {
        case 0 :
           return SigmoidFunction(is_backprop, sum_of_neuron);

        case 1 :
            return TanhFunction(is_backprop, sum_of_neuron);

        default:
            std::cout<<"Nie ma takiej funkcji w kodzie"<<std::endl;
            return -99;
    }

}

double Net::SigmoidFunction(bool is_backprop, double x) {

    if(is_backprop == 0){
        return 1/(1+exp(-x));
    }else{
        return exp(x)/(exp(2*x) + 2*exp(x)+1);
    }

}

double Net::TanhFunction(bool is_backprop, double sum_of_neuron) {
    return 0;
}




