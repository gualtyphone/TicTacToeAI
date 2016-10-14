#include "GeneticAlgorithim.h"

void GeneticAlgorithim::init()
{
	float startingWeights[WEIGHTSNUMBER];

	for (int i = 0; i < POPULATION; i++)
	{
		for (int j = 0; j < WEIGHTSNUMBER;j++)
		{
			startingWeights[j] =  RandomClamped();
		}
		population[i].init(startingWeights);
		fitnesses[i] = 0;
		alive[i] = true;
	}
}

NeuralNetwork GeneticAlgorithim::oneGeneration()
{
	//select best half candidates
    int tempFitnesses[POPULATION];
    for (int i = 0; i < POPULATION; i++)
    {
       tempFitnesses[i] = fitnesses[i];
    }
    
	int firstFittest = 0;
	int secondFittest = 0;
    int avgFitness = 0;
	int order[POPULATION];
	for (int i = 0; i < POPULATION; i++)
	{
		int fittest = 0;
		int bestFitness = -20000;
		for (int j = 0; j < POPULATION; j++)
		{
			if (tempFitnesses[j] > bestFitness)
			{
				fittest = j;
				bestFitness = tempFitnesses[j];
			}
		}
        avgFitness += fitnesses[i];
		order[i] = fittest;
		if (i == 0)
		{
			firstFittest = fittest;
			MaxFitness = tempFitnesses[fittest];
		}
		if (i == 1)
		{
			secondFittest = fittest;
		}
		tempFitnesses[fittest] = -20000;
	}
    
    avgFitness = avgFitness/POPULATION;
    
    std::cout << "MaxFitness: " << MaxFitness <<", avgFitness: " << avgFitness << std::endl;
    
	for (int i = 0; i < POPULATION; i++)
	{
		if (i > 50)
		{
			alive[order[i]] = false;
		}
	}

	//MATE, MY PRETTIES, MATE!!!!!!!!
    if (MaxFitness < 1)
    {
        MaxFitness = 1;
    }
	for (int i = 0; i < POPULATION; i++)
	{
		if (!(alive[i]))
		{
			int p1, p2;
			do
			{
				do {
					p1 = rand() % POPULATION;
				} while (fitnesses[p1] < rand() % (int) MaxFitness);
			} while (!(alive[p1]));

			do
			{
				do{
					p2 = rand() % POPULATION;
				} while (fitnesses[p2] < rand() % (int) MaxFitness);
			} while (!(alive[p2]));

			int matingPoint = rand() % (WEIGHTSNUMBER);
           // for (int j = 0; j < INPUTNODES + HIDDENNODES*INPUTNODES + OUTPUTNODES * HIDDENNODES + 1; j++)
           // {
           //     population[i].weights[j] = ((population[p1].weights[j]+ population[p2].weights[j]) /2);
           // }
            
			for (int j = 0; j < matingPoint; j++)
			{
				population[i].weights[j] = population[p1].weights[j];
			}

			for (int j = matingPoint; j < WEIGHTSNUMBER; j++)
            {
                population[i].weights[j] = population[p2].weights[j];
			}

			alive[i] = true;
		}
	}
    
    //for (int i = 0; i < POPULATION; i++)
    //{
    //    population[i] = newPopulation[i];
    //}

	//Mutation
	for (int i = 0; i < POPULATION; i++)
	{
		mutate(i);
	}

	//Game game;
	/*int fit1;
	int fit2;
	game.playOneGame(&population[firstFittest], &population[secondFittest],&fit1, &fit2 , true);

	std::cout << "\n" << fit1 << std::endl;
	std::cout << fit2 << std::endl;*/
	return population[firstFittest];
}

void GeneticAlgorithim::updateFitness(int p1)
{
	for (int i = 0; i < POPULATION; i++)
	{
		Game game;
		game.playOneGame(&population[p1], &population[i], &fitnesses[p1], &fitnesses[i], false);

	}
}
void GeneticAlgorithim::updateFitnessTrial(int p1)
{
    float sum = 0;
    for (int i = 0; i < WEIGHTSNUMBER; i++)
    {
        sum += population[p1].weights[i];
    }
    fitnesses[p1] = sum;
}

void GeneticAlgorithim::mutate(int candidateN)
{
	for (int i = 0; i < WEIGHTSNUMBER; i++)
	{
		if (rand() % 100 < 5)
		{
            population[candidateN].weights[i] += RandomClamped();
		}
	}
}