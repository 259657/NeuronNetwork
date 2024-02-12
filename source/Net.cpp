//
// Created by PRO on 04.02.2024.
//

#include "../include/Net.h"

//xor 00;11 = 0
Net::Net(int input, int hidden, int output) : input(input),hidden(hidden),output(output) {
        int sum = std::max( input, hidden );
        sum = std::max(sum,output);

        learning_rate = 0.035;

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
Net::Net(int input_neurons, int hidden_layer, int hidden_neurons, int output_neurons):input(input_neurons),hidden(hidden_neurons),output(output_neurons) {

    all.resize(2+hidden_layer);

    learning_rate = 0.0315;
    total_error = 0.0;

    all[0].resize(input_neurons);
    for(size_t i = 1 ; i < all.size()-1;i++){
        all[i].resize(hidden_neurons);

    }
    all.back().resize(output_neurons);

    for(size_t i = 0 ; i < all.size();i++){
        initNeuronsInLayer(all[i].size(),i);
    }
    setExpValue_XOR();
}
void Net::initNeuronsInLayer(size_t number_of_neurons,size_t which_layer) {

    for(size_t i = 0 ; i < number_of_neurons; i++){
        if(which_layer == 0){
            all[which_layer][i]= Neuron(0);
        }else{
            all[which_layer][i]= Neuron(1);
        }


    }
    if(which_layer != all.size()-1){
        initWeight(all[which_layer],all[which_layer+1]);
    }

}



void Net::Print_layer(int number) {
    std::cout<<"Warstwa : "<<number<<std::endl;
for(size_t i = 0 ; i < all[number].size();i++ )
    {
    std::cout<<"Wartosc Neurona: "<<all[number][i].getValue()<<std::endl;
    std::cout<<"Wagi :"<<std::endl;
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
            all[i][j].setText();
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
//    for(size_t i = 0 ; i < all.back().size();i++){
//    all.back()[i].setText();
//    }
      // std::cout<<"First "<<first<<" Second : "<<second<<std::endl;
       // std::cout<<"wartosc oczekiwana to : "<<exp_val<<std::endl;


}

void Net::Print_Answer() {

    for(const auto & i : all.back()){
        std::cout<<"Wartosc obliczona "<<i.getValue()<<" Total err "<<getTot_err()<<std::endl;
    }

}

void Net::Print_all_layer() {

    for(size_t i = 0 ; i < all.size();i++){
        Print_layer(i);
    }

}

void Net::setIntAndOutValue() {
    double first,second;
    first = ( std::rand() % 2);
    second = ( std::rand() % 2);
   // std::cout<<first<<" "<<second<<std::endl;



      //  all[0][0].setValue(wektorPar[losowyIndeks].first);
      //  all[0][1].setValue(wektorPar[losowyIndeks].second);
        all[0][0].setValue(first);
        all[0][1].setValue(second);
        all[0][0].setText();
        all[0][1].setText();
      //  std::cout<<"Zmienione wartosci na wejsciu "<<all[0][0].getValue()<<" "<<all[0][1].getValue()<<" ";
        setExpValue_XOR();


   // ( std::rand() % 2)


}

void Net::TestNet(int first,int second) {

    all[0][0].setValue(first);
    all[0][1].setValue(second);
    setExpValue_XOR();
    ForwardNetwork();
    BackNetwork();
    Print_Answer();


}





