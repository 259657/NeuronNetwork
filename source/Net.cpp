//
// Created by PRO on 04.02.2024.
//

#include "../include/Net.h"

//xor 00;11 = 0
Net::Net(int input, int hidden, int output) : input(input),hidden(hidden),output(output) {
        int sum = std::max( input, hidden );
        sum = std::max(sum,output);
        learning_rate = 0.03;

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
     setExpValue_XOR();

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

                all[i][j].SumAndBias(all[i-1][z].getWeight(j) ,all[i-1][z].getValue());
               // std::cout<<"Value"<<all[i-1][z].getValue()<<std::endl;
                //std::cout<<"Waga"<<all[i-1][z].getWeight(j)<<std::endl;

            }
            if(i !=all.size()-1) {//ostatnia warstwa nie potrzebuje baiosu poniewaz problem nie jest az tak skomplikowany
                all[i][j].SumAndBias(1, 1);//biios
            }
            all[i][j].setSum(all[i][j].getValue());
            all[i][j].setValue(ActivationFunction(0,false,all[i][j].getValue()));

        }
    }
}
void Net::BackNetwork() {
    total_error = 0.0;

    // Obliczanie błędu dla neuronów w warstwie wyjściowej
    for(size_t i = 0; i < all.back().size(); i++) {
        double output_error = exp_val - all.back()[i].getValue();
        all.back()[i].setErr(output_error * ActivationFunction(0, true, all.back()[i].getSum()));
        //do RMS kwadrat
        total_error += std::pow(output_error , 2);
    }
    //do RMS dzielimy przez iczbe wyjsc
    total_error /= all.back().size();


    // Obliczanie błędu dla warstw ukrytych
    for(int i = all.size() - 2; i >= 0; i--) {
        for (size_t j = 0; j < all[i].size(); j++) {
            double neuron_error = 0.0;
            for(size_t z = 0; z < all[i][j].getWeight_siz(); z++) {
                neuron_error += all[i + 1][z].getErr() * all[i][j].getWeight(z);
            }
            all[i][j].setErr(neuron_error * ActivationFunction(0, true, all[i][j].getSum()));
        }
    }

    // Aktualizacja wag
    for(int i = all.size() - 2; i >= 0; i--) {
        for (size_t j = 0; j < all[i].size(); j++) {
            for(size_t z = 0; z < all[i][j].getWeight_siz(); z++) {
                double new_weight = all[i][j].getWeight(z) + learning_rate * all[i + 1][z].getErr() * all[i][j].getValue();
                all[i][j].setWeight(new_weight, z);
            }
        }
    }
}

 /*void Net::BackNetwork() {

// przliczanie RMS - Root Mean Square Error
    total_error = 0.0;

for(size_t i = 0; i <all.back().size();i++ ){
    std::cout<<std::endl;
    std::cout<<"Oczekiwana "<<exp_val<<" update "<<all.back()[i].getValue()<<std::endl;
    //Przeliczanie wyjsc

    //total_error += std::abs(exp_val - all.back()[i].getValue());
    total_error += std::abs(pow(exp_val - all.back()[i].getValue(),2))/2;
}
    // std::cout<<"Exp val "<<exp_val<<std::endl;
     //std::cout<<"Total  "<<all.back()[0].getValue()<<std::endl;
    //std::cout<<"Wartosc bledu na wyjsciu "<<total_error<<std::endl;
for(size_t i = 0; i <all.back().size();i++ ){

     all.back()[i].setErr(total_error);
     std::cout<<"Wartosc bledu na wyjsciu "<<all.back()[i].getErr()<<std::endl;
    }


    //przeliczanie errorów dla warstw innych niz output

    for(int i = all.size()-2; i >= 0; i--) {
        std::cout<<"Warstwa "<<i;
        for (size_t j = 0; j != all[i].size(); j++) {
            double neuron_error = 0;
            std::cout<<" Neuron "<<j<<std::endl;
            size_t  out_neuron = 0;
            for(size_t z = 0 ; z != all[i][j].getWeight_siz() ; z++ ){
                //tutaj juz wagi

                neuron_error += all[i][j].getErr() + all[i+1][out_neuron].getErr() * all[i][j].getWeight(z);
                std::abs(neuron_error);
                std::cout<<"Wartosc eroora dla poprzedniej warstwy"<<all[i+1][out_neuron].getErr() <<std::endl;
                out_neuron++;
               // std::cout<<"Errr "<<neuron_error <<std::endl;
                // all[i][j].setErr(all[i+1][j].getErr() * all[i][j].getWeight(z) );
            }

            all[i][j].setErr(neuron_error);
           // std::cout<<"Ustawiam dla warstwy nr"<<i<<" dla neurona "<<j<<" :"<<neuron_error <<std::endl;
            for(size_t z = 0 ; z != all[i][j].getWeight_siz() ; z++ ){
                double new_weight = all[i][j].getWeight(z) - learning_rate *  all[i+1][j].getErr()*all[i][j].getValue() *
                                                                      ActivationFunction(0,true,all[i][j].getSum());
                //std::cout<<"Przed "<<all[i][j].getWeight(z) <<std::endl;
               // std::cout<<"Nowy "<<new_weight<<std::endl;
                all[i][j].setWeight(new_weight,z);
                //std::cout<<"Po  "<<all[i][j] .getWeight(z)<<std::endl;
            }

        }



    }

}*/

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

       // std::cout<<"Wynik mianownika :"<<(exp(2*x) + 2*exp(x)+1) <<" Dla x= "<<x<<std::endl;
        return exp(x)/(exp(2*x) + 2*exp(x)+1);
    }

}

double Net::TanhFunction(bool is_backprop, double sum_of_neuron) {
    return 0;
}

void Net::setExpValue_XOR() {
double first=0;
double second =0;
    for(size_t i = 0 ; i < all[0].size();i++){
        if(  i % 2 == 0){
            first = all[0][i].getValue();
        }else
            second = all[0][i].getValue();
    }

    if ( (first == 0 && second == 0 ) || (first == 1 && second == 1) ){
        exp_val = 0;
    }else{
        exp_val = 1;
    }
      // std::cout<<"First "<<first<<" Second : "<<second<<std::endl;
        std::cout<<"wartosc oczekiwana to : "<<exp_val<<std::endl;


}




