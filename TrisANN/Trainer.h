#pragma once

#include <stdio.h>
#include "NeuralNetwork.h"

class Trainer
{
public:
    Trainer();
    void train(NeuralNetwork* ann_o);
};