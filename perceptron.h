#pragma once

#include <vector>

class Perceptron {
    public:
        std::vector<double> weights;
        double bias;

        Perceptron(size_t inputs, double bias = 1.0);

        double run(const std::vector<double>& x) const;

        void set_weights(const std::vector<double>& init_weights);

        double sigmoid(double x) const;
};