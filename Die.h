#pragma
#include <iostream>
#include <string>

using namespace std;

class Die
{
private: 
	int sides = 6;
	int currentDieNumber;
public:

	int getSides()
	{
		return sides;
	}
	int rollDie()
	{
		for (int x = 0; x < 10; x++)
		{
			currentDieNumber = rand() % sides + 1;
		}
		currentDieNumber = rand() % sides + 1;
		return currentDieNumber;
		
	}
	int getCurrentDieNumber()
	{
		return currentDieNumber;
	}
};
