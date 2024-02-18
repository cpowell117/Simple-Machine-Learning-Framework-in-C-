#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include "Model.h"
#include <vector>
#include <numeric> // For std::inner_product
#include <cmath>    // For pow, sqrt, etc.

using namespace std;

class LinearRegression : public Model {
private:
    vector<double> theta; // Model parameters/coefficients

    // Helper function to compute the cost (Mean Squared Error)
    double computeCost(const vector<vector<double>>& X, const vector<double>& y) {
        size_t m = y.size();
        double totalError = 0.0;
        for (size_t i = 0; i < m; i++) {
            double prediction = inner_product(X[i].begin(), X[i].end(), theta.begin(), 0.0);
            double error = prediction - y[i];
            totalError += pow(error, 2);
        }
        return totalError / (2 * m);
    }

public:
    LinearRegression() {}

    // Fit the linear regression model to the data
    void fit(const DataFrame& data) override {
        size_t m = data.data.size(); // Number of training examples
        size_t n = data.data[0].size() - 1; // Number of features (-1 because last column is the target variable)

        // Initialize theta with zeros (n+1 for intercept term)
        theta = vector<double>(n + 1, 0);

        // Learning rate and number of iterations for gradient descent
        double alpha = 0.01;
        int iterations = 1000;

        // Separate features (X) and target variable (y)
        vector<vector<double>> X(m, vector<double>(n + 1, 1.0)); // +1 for intercept term, initialized to 1
        vector<double> y(m);
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                X[i][j + 1] = data.data[i][j]; // +1 to skip intercept term
            }
            y[i] = data.data[i][n]; // Last column is the target variable
        }

        // Gradient descent
        for (int it = 0; it < iterations; ++it) {
            vector<double> predictions(m);
            for (size_t i = 0; i < m; i++) {
                predictions[i] = inner_product(X[i].begin(), X[i].end(), theta.begin(), 0.0);
            }

            for (size_t j = 0; j < theta.size(); j++) {
                double sumErrors = 0;
                for (size_t i = 0; i < m; i++) {
                    sumErrors += (predictions[i] - y[i]) * X[i][j];
                }
                theta[j] = theta[j] - alpha * (1.0 / m) * sumErrors;
            }

            // Optional: Print the cost every 100 iterations (or adjust as needed)
            if (it % 100 == 0) {
                cout << "Iteration " << it << " Cost: " << computeCost(X, y) << endl;
            }
        }
    }

    // Predict the target variable for a new dataset
    vector<double> predict(const DataFrame& data) override {
        size_t m = data.data.size();
        size_t n = data.data[0].size();
        vector<double> predictions(m);

        for (size_t i = 0; i < m; i++) {
            vector<double> xi(n + 1, 1.0); // Initialize with intercept term
            for (size_t j = 0; j < n; j++) {
                xi[j + 1] = data.data[i][j];
            }
            predictions[i] = inner_product(xi.begin(), xi.end(), theta.begin(), 0.0);
        }
        return predictions;
    }
};

#endif // LINEARREGRESSION_H
