#include "fonction.h"

double sigmoid(double z)
{
    return 1.0/(1.0 + exp(-z));
}