#include "perceptron.h"
#include <iostream>

int main() {
    Perceptron perceptron(2);

    std::vector<double> custom_weights = {0.5, -0.5};
    perceptron.set_weights(custom_weights);

    std::vector<double> input = {1, 0.5};
    double output = perceptron.run(input);

    std::cout << "Perceptron output: " << output << std::endl;
    return 0;
}