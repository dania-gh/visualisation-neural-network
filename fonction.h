#ifndef FONCTION_H
#define FONCTION_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double sigmoid(double z);
double sigmoid_deriv(double z);
double log_loss(double expected, double predicted);
#endif