#pragma once

#include <iostream>
#include "NeuralNetwork.h"

class Game
{
public:

	void playOneGame(NeuralNetwork *player1, NeuralNetwork *player2, int *fit1, int *fit2 ,bool showGame);
	int playOneGame(NeuralNetwork *player1, bool something);
    int playOneGame(NeuralNetwork *player1);
    
	int checkwin(char* square);
	void drawBoard(char* square);

private:
	

};

