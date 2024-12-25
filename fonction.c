#include "fonction.h"

double sigmoid(double z)
{
    return 1.0/(1.0 + exp(-z));
}

double sigmoid_deriv(double z)
{
    return z*(1.0 -z);
}

double log_loss(double expected, double predicted) 
{
    const double epsilon = 1e-15;
    predicted = fmax(fmin(predicted ,1-epsilon), epsilon);
    return -(expected * log(predicted)+(1-expected)*log(1- predicted));
}