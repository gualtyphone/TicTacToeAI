#include "Neuron.h"



Neuron::Neuron()
{
	currentValue = 0;
	threshold = 0;
}

void Neuron::addInput(float input)
{
	currentValue += input;
}

float Neuron::output()
{
    float out = 1 - 1/exp(1*currentValue);
    return out;
}