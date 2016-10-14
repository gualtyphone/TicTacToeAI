#pragma once
#include <string>
#include <math.h>

class Neuron
{
public:
	Neuron();

	void addInput(float input);
	float output();
    float currentValue;

	std::string type;
	int ID;

private:
	float threshold;
};

