#ifndef MODEL_H
#define MODEL_H

#include "DataFrame.h"

using namespace std;

class Model {
public:
    virtual void fit(const DataFrame& data) = 0;
    virtual vector<double> predict(const DataFrame& data) = 0;
};

#endif
