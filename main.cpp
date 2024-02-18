#include "DataFrame.h"
#include "LinearRegression.h"
#include <iostream>

using namespace std;

void normalize_data(DataFrame& df) {
    // Implement normalization logic here
}

int main() {
    DataFrame df;
    df.read_csv("/Users/ChrisPowell/Downloads/archive/train.csv");

    normalize_data(df);

    LinearRegression model;
    model.fit(df);

    DataFrame testDf;
    testDf.read_csv("/Users/ChrisPowell/Downloads/archive/test.csv");
    // Consider normalizing test data similarly to training data

    vector<double> predictions = model.predict(testDf);

    for (double pred : predictions) {
        cout << "Prediction: " << pred << endl;
    }

    return 0;
}
