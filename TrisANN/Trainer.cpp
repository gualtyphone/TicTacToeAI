#include "Trainer.h"

Trainer::Trainer()
{
    
}

void Trainer::train(NeuralNetwork* ann_o)
{
    int strategy_o[] =
    {
        #include "strategy_o.h"
    };
    
    int strategy_x[] =
    {
        #include "strategy_x.h"
    };
    
    char currentBoard[10];
    
    for (int row = 0; row < 1000; row++)
    {
        //convert to char grid
        for (int i = 0; i < 9; i++)
        {
            if (strategy_x[row*9 + i] == 0) {
                currentBoard[i+1] = i + '1';
            }
            else if (strategy_x[row*9 + i] == 2) {
                currentBoard[i+1] = 'O';
            }
            else if (strategy_x[row*9 + i] == 1) {
                currentBoard[i+1] = 'X';
            }
        }
        
        //IS FINAL GRID rowX????
        if (strategy_x[row*9+0] == 1 && strategy_x[row*9+1] == 1 && strategy_x[row*9+2] == 1 &&
            strategy_x[row*9+3] == 0 && strategy_x[row*9+4] == 0 && strategy_x[row*9+5] == 0 &&
            strategy_x[row*9+6] == 0 && strategy_x[row*9+7] == 2 && strategy_x[row*9+8] == 2)
        {
            row = 2000;
        }
        
        //Get best answer
        int currentBestSolutionRow = 0;
        for (int rowO = 0; rowO < 1000; rowO++)
        {
            int differences = 0;
            //convert to char grid
            for (int i = 0; i < 9; i++)
            {
                if (strategy_x[row*9 + i] == 1 && strategy_o[rowO*9 +i] != 2) {
                    differences++;
                }
                if (strategy_x[row*9 + i] == 2 && strategy_o[rowO*9 +i] != 1) {
                    differences++;
                }
                if (strategy_x[row*9 + i] == 0 && strategy_o[rowO*9 +i] != 0) {
                    differences++;
                }
            }
            if (differences == 1)
            {
                currentBestSolutionRow = rowO;
            }
            //IS FINAL GRID rowO????
            if (strategy_x[rowO*9+0] == 0 && strategy_x[rowO*9+1] == 0 && strategy_x[rowO*9+2] == 1 &&
                strategy_x[rowO*9+3] == 0 && strategy_x[rowO*9+4] == 1 && strategy_x[rowO*9+5] == 2 &&
                strategy_x[rowO*9+6] == 1 && strategy_x[rowO*9+7] == 2 && strategy_x[rowO*9+8] == 2)
            {
                row = 2000;
            }
        }
        
        
            
        //Get answer from NeuralNet
        int answer = ann_o->guess(currentBoard);
        if (currentBoard[answer] == 'O' || currentBoard[answer] == 'X')
        {
            ann_o->removeFromNode(answer, 1);
        }
        else
        {
            currentBoard[answer] = 'O';
            
            //convert back to int grid
            int guessedGrid[9];
            for (int i = 0; i < 9; i++)
            {
                if (currentBoard[i+1] == i+ '1') {
                    guessedGrid[i] = 0;
                }
                else if (currentBoard[i+1] == 'O') {
                    guessedGrid[i] = 1;
                }
                else if (currentBoard[i+1] == 'X') {
                    guessedGrid[i] = 2;
                }
            }
            
            for (int i = 0; i < 9; i++)
            {
                if (strategy_o[currentBestSolutionRow*9 + i] != guessedGrid[i])
                {
                    if (guessedGrid[i] == 0 && strategy_o[currentBestSolutionRow*9 + i] == 1)
                    {
                        ann_o->addToNode(i, 1);
                    }
                    else if (guessedGrid[i] == 1 && strategy_o[currentBestSolutionRow*9 + i] == 0)
                    {
                        ann_o->removeFromNode(i, 1);
                    }
                }
            }
            ann_o->resetNodes();
        }
    }
}













