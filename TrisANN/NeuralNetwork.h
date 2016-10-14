#pragma once

#define INPUTNODES 18
#define HIDDENNODES1 18
#define HIDDENNODES2 18
#define OUTPUTNODES 9
#define WEIGHTSNUMBER INPUTNODES + (HIDDENNODES1*INPUTNODES) + (HIDDENNODES1 * HIDDENNODES2) + (OUTPUTNODES * HIDDENNODES2)+ OUTPUTNODES

#include <random>
#include <time.h>
#include <cmath> 
#include "Neuron.h"

class NeuralNetwork
{
public:

	int guess(char grid[10]);
	void init(float* newWeights);
	float weights[WEIGHTSNUMBER];
    void resetNodes();
    void addToNode(int node, int level);
    void removeFromNode(int node, int level);
    
    
	int gridState[10];
	Neuron inputNodes[INPUTNODES];
	Neuron hiddenNodes1[HIDDENNODES1];
    Neuron hiddenNodes2[HIDDENNODES2];
	Neuron outputNodes[OUTPUTNODES];
    
private:


};