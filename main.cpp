/*
    Author: Tilo Klarenbeek
    Date: 30.06.2017
    Github: https://github.com/Tilo-K
*/
#include <iostream>

#define correct 0.621371

using namespace std;


// The Main part of the Program
class Perceptron {
    public:
        double weight;

        // Guessing based on the current weight
        double guess(double input){
            return input * weight;
        }
        Perceptron(double w){
            weight = w;
        }

        // To train the Perceptron
        void train(double input, double expected){
            double result = input * weight;
            if(result != expected){
                double error = result - expected;
                // 0.000001 = Learning Rate
                weight -= error*0.000001;
            }
        }
};

int main()
{
    // Initializing the Perceptron and set the default weight to 0.5
    Perceptron perc(0.5);

    cout << "Training..." << endl;

    for(double i = 0; i <= 100000; i++){
        perc.train(i, i*correct);
    }

    while (true){
        cout << "n: ";
        double n = 0;
        cin >> n;
        cout << perc.guess(n) << endl;
        cout << "Should be: " << n*correct << endl;

    }
    return 0;
}


