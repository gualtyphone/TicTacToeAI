#include "Game.h"

using namespace std;

void Game::playOneGame(NeuralNetwork *player1, NeuralNetwork *player2, int *fit1, int *fit2, bool showGame = false)
{
    int moves = 0;
	int player = 1, i, choice;
	char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };
	char mark;
	do
	{
        
		if(showGame)
			drawBoard(square);
		player = (player % 2) ? 1 : 2;

		if (player == 1) {
			choice = player1->guess(square);
            player1->resetNodes();
            moves++;
		}
		else
		{
			choice = player2->guess(square);
            player2->resetNodes();
            moves++;
		}

		mark = (player == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')
		{
			square[1] = mark;
			if (player == 1) {
				*fit1+= 1;
			}
			else
			{
				*fit2+= 1;
			}
		}
		else if (choice == 2 && square[2] == '2')
		{
			square[2] = mark;
			if (player == 1) {
				*fit1+= 1;
			}
			else
			{
				*fit2+= 1;
			}
		}
		else if (choice == 3 && square[3] == '3')
		{
			square[3] = mark;
			if (player == 1) {
				*fit1+= 1;
			}
			else
			{
				*fit2+= 1;
			}
		}
		else if (choice == 4 && square[4] == '4')
		{
			square[4] = mark;
			if (player == 1) {
				*fit1+= 1;
			}
			else
			{
				*fit2+= 1;
			}
		}
		else if (choice == 5 && square[5] == '5')
		{
			square[5] = mark;
			if (player == 1) {
				*fit1+= 1;
			}
			else
			{
				*fit2+= 1;
			}
		}
		else if (choice == 6 && square[6] == '6')
		{
			square[6] = mark;
			if (player == 1) {
				*fit1+= 1;
			}
			else
			{
				*fit2+= 1;
			}
		}
		else if (choice == 7 && square[7] == '7')
		{
			square[7] = mark;
			if (player == 1) {
				*fit1+= 1;
			}
			else
			{
				*fit2+= 1;
			}
		}
		else if (choice == 8 && square[8] == '8')
		{
			square[8] = mark;
			if (player == 1) {
				*fit1+= 1;
			}
			else
			{
				*fit2+= 1;
			}
		}
		else if (choice == 9 && square[9] == '9')
		{
			square[9] = mark;
			if (player == 1) {
				*fit1+= 1;
			}
			else
			{
				*fit2+= 1;
			}
		}
		else
		{
			//cout << "Invalid move ";
			if (player == 1) {
				//*fit1 -= 2;
                //cout << moves;
				return;
			}
			else
			{
				//*fit2 -= 2;
                //cout << moves;
				return;
			}
			//player--;
			//cin.ignore();
			//cin.get();
		}
		i = checkwin(square);

		player++;
	} while (i == -1);

	if(showGame)
		drawBoard(square);


	if (i == 1)
	{
		player--;
		if (player == 1)
		{
			*fit1 += 100;
            //cout << "somebody WON" << endl;
		}
		else if (player == 2)
		{
			*fit2 += 100;
            //cout << "somebody WON" << endl;
		}
	}
    else if ( i == 0)
    {
        *fit1 += 75;
        *fit2 += 75;
    }
    //cout << moves;
	return;
}



int Game::playOneGame(NeuralNetwork *player1)
{
	int player = 1, i, choice;
	char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };
	char mark;
	do
	{
		drawBoard(square);
		player = (player % 2) ? 1 : 2;

		cout << "Player " << player << ", enter a number:  ";
		//cin >> choice;
		if (player == 1) {
			choice = player1->guess(square);
            player1->resetNodes();
		}
		else
		{
			cin >> choice;
		}

		mark = (player == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')

			square[1] = mark;
		else if (choice == 2 && square[2] == '2')

			square[2] = mark;
		else if (choice == 3 && square[3] == '3')

			square[3] = mark;
		else if (choice == 4 && square[4] == '4')

			square[4] = mark;
		else if (choice == 5 && square[5] == '5')

			square[5] = mark;
		else if (choice == 6 && square[6] == '6')

			square[6] = mark;
		else if (choice == 7 && square[7] == '7')

			square[7] = mark;
		else if (choice == 8 && square[8] == '8')

			square[8] = mark;
		else if (choice == 9 && square[9] == '9')

			square[9] = mark;
		else
		{
			cout << "Invalid move ";
			if (player == 1) {
				return -1;
			}
			else
			{
                
			}
			player--;
			cin.ignore();
			cin.get();
		}

		i = checkwin(square);

		player++;
	} while (i == -1);
	drawBoard(square);
	if (i == 1)
		return --player;
	else
		return 0;

	return 0;
}


int Game::playOneGame(NeuralNetwork *player1, bool something)
{
    int player = 1, i, choice;
    char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };
    char mark;
    do
    {
        drawBoard(square);
        player = (player % 2) ? 1 : 2;
        
        cout << "Player " << player << ", enter a number:  ";
        //cin >> choice;
        if (player == 2) {
            choice = player1->guess(square);
            player1->resetNodes();
        }
        else
        {
            cin >> choice;
        }
        
        mark = (player == 1) ? 'X' : 'O';
        
        if (choice == 1 && square[1] == '1')
            
            square[1] = mark;
        else if (choice == 2 && square[2] == '2')
            
            square[2] = mark;
        else if (choice == 3 && square[3] == '3')
            
            square[3] = mark;
        else if (choice == 4 && square[4] == '4')
            
            square[4] = mark;
        else if (choice == 5 && square[5] == '5')
            
            square[5] = mark;
        else if (choice == 6 && square[6] == '6')
            
            square[6] = mark;
        else if (choice == 7 && square[7] == '7')
            
            square[7] = mark;
        else if (choice == 8 && square[8] == '8')
            
            square[8] = mark;
        else if (choice == 9 && square[9] == '9')
            
            square[9] = mark;
        else
        {
            cout << "Invalid move ";
            if (player == 2) {
                return -1;
            }
            else
            {
                
            }
            player--;
            cin.ignore();
            cin.get();
        }
        
        i = checkwin(square);
        
        player++;
    } while (i == -1);
    drawBoard(square);
    if (i == 1)
        return --player;
    else
        return 0;
    
    return 0;
}

/*********************************************
 
 FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
**********************************************/

int Game::checkwin(char* square)
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
		&& square[4] != '4' && square[5] != '5' && square[6] != '6'
		&& square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void Game::drawBoard(char* square)
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}

/*******************************************************************
END OF PROJECT
********************************************************************/