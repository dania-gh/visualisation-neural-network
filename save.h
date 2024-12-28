#ifndef SAVE_H
#define SAVE_H
#include <stdio.h>
#include "initialisation.h"

void save_weight_bias(Parameters* params, const char* fichier_poids, const char* fichier_bias);

#endif