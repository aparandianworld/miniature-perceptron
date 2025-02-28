#include "perceptron.h"

#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

double random_weight() {
    return ((double) rand() / RAND_MAX) * 2 - 1;
}

Perceptron::Perceptron(size_t inputs, double bias) : bias(bias) {
    static bool seed_initialized = false;
    if (!seed_initialized) {
        srand(static_cast<unsigned int>(time(0)));
        seed_initialized = true;
    }

    weights.resize(inputs);
    std::generate(weights.begin(), weights.end(), random_weight);
}

double Perceptron::run(const std::vector<double>& x) const {
    if (x.size() != weights.size()) {
        std::cerr << "Error: Input size does not match perceptron weight size!" << std::endl;
        return 0.0;
    }

    double sum = bias;
    for (size_t i = 0; i < x.size(); i++) {
        sum += x[i] * weights[i];
    }
    return sigmoid(sum);
}

void Perceptron::set_weights(const std::vector<double>& init_weights) {
    if (init_weights.size() != weights.size()) {
        std::cerr << "Error: init_weights size does not match perceptron weight size!" << std::endl;
        return;
    }
    weights = init_weights;
}

double Perceptron::sigmoid(double x) const {
    return 1 / (1 + exp(-x));
}
