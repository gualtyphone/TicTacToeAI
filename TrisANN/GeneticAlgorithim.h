#pragma once
#define POPULATION 100
#include "NeuralNetwork.h"
#include "utils.h"
#include "Game.h"

class GeneticAlgorithim
{
public:

	void init();
	NeuralNetwork oneGeneration();
	void updateFitness(int p1);
    void updateFitnessTrial(int p1);
	void mutate(int candidateN);

    NeuralNetwork population[POPULATION];
    int fitnesses[POPULATION];
    
private:
	
	bool alive[POPULATION];

	float MaxFitness;
};