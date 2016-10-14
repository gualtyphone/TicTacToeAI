#include "GeneticAlgorithim.h"
#include "NeuralNetwork.h"
#include "Trainer.h"
#include "utils.h"

#define GENERATIONS 1000

using namespace std;

void updateFitnesses(GeneticAlgorithim *x, GeneticAlgorithim *o);
void updateFitnesses(GeneticAlgorithim *x, NeuralNetwork *o);

int main()
{
    srand(time(NULL));
	GeneticAlgorithim algorX;
    GeneticAlgorithim algorO;

    //NeuralNetwork perfectNeuralO;
    
	algorX.init();
    algorO.init();
    
    Trainer trainer;
//    
//    for (int i = 0; i < GENERATIONS; i ++)
//    {
//        trainer.train(&perfectNeuralO);
//        
//    }
    
//    for (int i = 0; i < GENERATIONS; i++)
//    {
//        updateFitnesses(&algorX, &perfectNeuralO);
//        algorX.oneGeneration();
//        cout << "generation " << i << endl;
//    }
    
	for (int i = 0; i < GENERATIONS; i++)
	{
        updateFitnesses(&algorX, &algorO);
        algorX.oneGeneration();
        algorO.oneGeneration();
        cout << "generation " << i << endl;
	}
	
	NeuralNetwork player1;
    NeuralNetwork player2;
    updateFitnesses(&algorX, &algorO);
    player1 = algorX.oneGeneration();
    player2 = algorO.oneGeneration();
    
    float sum = 0;
    for (int i = 0; i < WEIGHTSNUMBER + 1; i++)
    {
        sum += player1.weights[i];
    }
    //cout << sum << endl;
    
	bool quit = false;
    Game game;
	while (quit != true)
	{
		game.playOneGame(&player1);

		char quitQuestion;
		cout << "\nPress q to exit, anything else to play again" << endl;
		cin >> quitQuestion;
		if (quitQuestion == 'q')
		{
			quit = true;
		}
	}

    quit = false;
    while (quit != true)
    {
        game.playOneGame(&player2, false);
        
        char quitQuestion;
        cout << "\nPress q to exit, anything else to play again" << endl;
        cin >> quitQuestion;
        if (quitQuestion == 'q')
        {
            quit = true;
        }
    }
}

void updateFitnesses(GeneticAlgorithim *x, GeneticAlgorithim *o)
{
    for (int i = 0; i < POPULATION; i++)
    {
        x->fitnesses[i] = 0;
        o->fitnesses[i] = 0;
    }
    
    Game game;
    for (int i = 0; i < POPULATION; i++)
    {
        for (int j = 0; j < POPULATION; j++)
        {
            game.playOneGame(&x->population[i], &o->population[j], &x->fitnesses[i], &o->fitnesses[j], false);
        }
    }
}

void updateFitnesses(GeneticAlgorithim *x, NeuralNetwork *o)
{
    for (int i = 0; i < POPULATION; i++)
    {
        x->fitnesses[i] = 0;
    }
    
    Game game;
    for (int i = 0; i < POPULATION; i++)
    {
        int* void1 = new int[POPULATION];
        game.playOneGame(&x->population[i], o, &x->fitnesses[i], void1, false);
    }
}