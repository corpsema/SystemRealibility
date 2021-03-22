#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

const int RandomNumberMin = 0, RandomNumberMax = 1;

bool isComponentWorking (double reliabilityOfC1, int numberOfSimulations); 
bool isParallelWorking (double reliablieyOfC2, double reliablieyOfC3, int numberOfSimulations);


int main ()
{

	double reliabilityOfC1, reliabilityOfC2, reliabilityOfC3, ReliabilityForParallel, reliabilityOfSystem;
	int numberOfSimulations;
	bool inName = true;
	cout << "the system is made of 3 components the 1st is a" << endl;
	cout<< "series while 2 and 3 are in parallel." << endl;
	
	cout << "what is the number of simulations? ";
	cin >> numberOfSimulations;

	cout << "what is the reliability of the component one? ";
	cin >> reliabilityOfC1;

	if (isComponentWorking (reliabilityOfC1, numberOfSimulations))
	{
		cout << "the simulation states component 1 is working for that number of simulations." << endl;
	}
	else
	{
		cout << "the simulation states component 1 is not working, for that number of simulations." << endl;
	}
	
	cout << "component 2 and 3 are in a parallel system and will be tested together." << endl;
	cout << "what is the reliability of the component two? ";
	cin >> reliabilityOfC2;
	cout << "what is the reliability of the component three? ";
	cin >> reliabilityOfC3;

	if (isParallelWorking (reliabilityOfC2, reliabilityOfC3, numberOfSimulations))
	{
		cout << "the simulation states the parellel system is working, for that number of simulations" << endl;
	}
	else
	{
		cout << "the simulation states the parellel system is working, for that number of simulations" << endl;
	}
	
	ReliabilityForParallel = 1 - ( (1-reliabilityOfC2)*(1-reliabilityOfC3) );
	reliabilityOfSystem = (ReliabilityForParallel*reliabilityOfC1);
	cout << "the reliability of the system is" << reliabilityOfSystem << endl;
	
}


bool isComponentWorking (double reliabilityOfC1, int numberOfSimulations)
{
	double randomSimulate;
	for (int counter = 0; counter <= numberOfSimulations; counter++)
	{
		randomSimulate = (RandomNumberMin + rand()) % (RandomNumberMax-RandomNumberMin+1);
		if(randomSimulate < reliabilityOfC1)
		return true;
		else
		return false;
	}
	
}

bool isParallelWorking (double reliablieyOfC2, double reliablieyOfC3, int numberOfSimulations)
{
	double randomSimulate;
	double reliabilityOfC = 1 - ( (1-reliablieyOfC2)*(1-reliablieyOfC3)); 
	for (int counter = 0; counter <= numberOfSimulations; counter++)
	{
		randomSimulate = (RandomNumberMin + rand()) % (RandomNumberMax-RandomNumberMin+1);
		if( randomSimulate < reliabilityOfC)
		return true;
		else
		return false;
	}
	
}
