#include "NeuralNetwork.h"

void NeuralNetwork::init(float* newWeights)
{
	for (int i = 0; i < WEIGHTSNUMBER; i++)
	{
		weights[i] = newWeights[i];
	
    }

	for (int i = 0; i < INPUTNODES; i++) {
		inputNodes[i].type = "Input";
		inputNodes[i].ID = i;
	}
	for (int i = 0; i < HIDDENNODES1; i++) {
		hiddenNodes1[i].type = "Hidden";
		hiddenNodes1[i].ID = i;
	}
    for (int i = 0; i < HIDDENNODES2; i++) {
        hiddenNodes2[i].type = "Hidden";
        hiddenNodes2[i].ID = i;
    }
    for (int i = 0; i < OUTPUTNODES; i++) {
		outputNodes[i].type = "Output";
		outputNodes[i].ID = i;
	}
}


int NeuralNetwork::guess(char grid[10]) {

	//foreact inputNode
	//add input based on grid state
	for (int input = 0; input < INPUTNODES; input++)
	{
		if (input <= 9)
		{
			if (grid[(input + 1)] == 'X')
			{
				inputNodes[input].addInput(weights[input] * 1);
			}
		}
		else
		{
			if (grid[(input-9 + 1)] == 'O')
			{
				inputNodes[input].addInput(weights[input] * 1);
			}
		}
	}
    
    //foreach inputnode
    for (int input = 0; input < INPUTNODES; input++)
    {
        //foreach hidden node level 1
        for (int hidden = 0; hidden < HIDDENNODES1; hidden++)
        {
            //find weight ( inputnode * HIDDENNODES1 + hiddenNode1)
            //add inputs from inputNodes output
            hiddenNodes1[hidden].addInput(inputNodes[input].output() *
                                          weights[INPUTNODES +
                                                  ((input * HIDDENNODES1) + hidden)]);
        }
    }
    
    //foreach hidden node level 1
    for (int hidden1 = 0; hidden1 < HIDDENNODES1; hidden1++)
    {
        //foreach hidden node level 2
        for (int hidden2 = 0; hidden2 < HIDDENNODES2; hidden2++)
        {
            //find weight ( hidden1 * HIDDENNODES2 + hiddenNode2)
            //add inputs from inputNodes output
            hiddenNodes2[hidden2].addInput(hiddenNodes1[hidden1].output() *
                                           weights[(INPUTNODES+(INPUTNODES*HIDDENNODES1)) +
                                                   ((hidden1 * HIDDENNODES2) + hidden2)]);
        }
    }
    //foreach output node
    for (int hidden2 = 0; hidden2 < HIDDENNODES2; hidden2++)
    {
        //foreach hidden node level 2
        for (int output = 0; output < OUTPUTNODES; output++)
        {
            //find weight ( hidden2 * OUTPUTNODES + output)
            //add inputs from inputNodes output
            outputNodes[output].addInput(hiddenNodes2[hidden2].output() *
                                           weights[(INPUTNODES+(INPUTNODES*HIDDENNODES1)+
                                                    (HIDDENNODES2*HIDDENNODES1)) +
                                                   ((hidden2 * OUTPUTNODES) + output)]);
        }
    }
    //BIAS input
    for (int output = 0;
         output < OUTPUTNODES;
         output++)
    {
        outputNodes[output].addInput (1 * weights[output + (INPUTNODES + (HIDDENNODES1*INPUTNODES) + (HIDDENNODES1 * HIDDENNODES2) + (OUTPUTNODES * HIDDENNODES2))]);
        if (grid[output+1] == 'X' || grid[output+1] == 'O')
        {
            outputNodes[output].addInput(-500);
        }
    }
    

    int highestOutputNode = 0;
    float biggestSoFar = -2000;
    
    for (int output = 0;
         output < OUTPUTNODES;
         output++)
    {
        if ( outputNodes[output].currentValue > biggestSoFar)
        {
            //  result += outputNodes[output].output();
            biggestSoFar = outputNodes[output].currentValue;
            highestOutputNode = output;
        }
    }
    
    return highestOutputNode+1;
}

void NeuralNetwork::resetNodes()
{
    for (int i = 0; i < INPUTNODES; i++) {
        inputNodes[i].currentValue = 0;
    }
    for (int i = 0; i < HIDDENNODES1; i++) {
        hiddenNodes1[i].currentValue = 0;
    }
    for (int i = 0; i < HIDDENNODES2; i++) {
        hiddenNodes2[i].currentValue = 0;
    }
    for (int i = 0; i < OUTPUTNODES; i++) {
        outputNodes[i].currentValue = 0;
    }
}

void NeuralNetwork::addToNode(int node, int level)
{
    if (level == 1)
    {
        for (int i = 0; i < HIDDENNODES2; i ++)
        {
            weights[(INPUTNODES+
                     (INPUTNODES*HIDDENNODES1)+
                     (HIDDENNODES2*HIDDENNODES1))+
                    ((i * OUTPUTNODES) + node)] += 0.5f;
            addToNode(i, 2);
        }
        weights[node + (INPUTNODES + (HIDDENNODES1*INPUTNODES) + (HIDDENNODES1 * HIDDENNODES2) + (OUTPUTNODES * HIDDENNODES2))] += 0.1f;
    }
    else if ( level == 2)
    {
        for (int i = 0; i < HIDDENNODES1; i ++)
        {
            weights[(INPUTNODES+(INPUTNODES*HIDDENNODES1)) +
                    ((i * HIDDENNODES2) + node)] += 0.25f;
            addToNode(i, 3);
        }
    }
    else
    {
        for (int i = 0; i < INPUTNODES; i ++)
        {
            weights[INPUTNODES +
                    ((i * HIDDENNODES1) + node)] += 0.12f;
        }
    }
}

void NeuralNetwork::removeFromNode(int node, int level)
{
    if (level == 1)
    {
        for (int i = 0; i < HIDDENNODES2; i ++)
        {
            weights[(INPUTNODES+
                     (INPUTNODES*HIDDENNODES1)+
                     (HIDDENNODES2*HIDDENNODES1))+
                    ((i * OUTPUTNODES) + node)] -= 0.5f;
            addToNode(i, 2);
        }
        weights[node + (INPUTNODES + (HIDDENNODES1*INPUTNODES) + (HIDDENNODES1 * HIDDENNODES2) + (OUTPUTNODES * HIDDENNODES2))] -= 0.1f;
    }
    else if ( level == 2)
    {
        for (int i = 0; i < HIDDENNODES1; i ++)
        {
            weights[(INPUTNODES+(INPUTNODES*HIDDENNODES1)) +
                    ((i * HIDDENNODES2) + node)] -= 0.25f;
            addToNode(i, 3);
        }
    }
    else
    {
        for (int i = 0; i < INPUTNODES; i ++)
        {
            weights[INPUTNODES +
                    ((i * HIDDENNODES1) + node)] -= 0.12f;
        }
    }

}




