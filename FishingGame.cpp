#include <iostream>
#include <string>
#include "Die.h"
using namespace std;


class FishingGame: public Die
{
private:
	int score;
public:
	FishingGame()
	{
		score = 0;
	}
	string options[6] = { "Golden Boot", "Nothing", "Salmon", "Dollar Tree Tuna",
		"Nemo", "Where is my Diet Dr. Kelp!" };
	int scoring[6] = { 5,-2,3,1,-1, 2 };
	string c = "";

	void compare()
	{
		for (int x = 1; x <= 6; x++)
		{
			if (x == getCurrentDieNumber())
			{
				c = options[x-1];
			}
		}
	}
	void CalculateScore()
	{
		for (int x = 0; x < 6; x++)
		{
			if (c == options[x])
			{
				score += scoring[x];
			}
		}
	}
	int getScore()
	{
		return score;
	}
	void getFeedback()
	{
		for (int x = 0; x < 6; x++)
		{
			if (c == options[x])
			{
				cout << "\nLooks like you caught a " << c << ".\t Your new score is: " << score;
			}
		}
	}
};

int main()
{
	char answer;
	FishingGame game;
	cout << "\nWelcome to the Fishing Game!";

	//Initial
	cout << "\nWould you like to play? Y/N";
	cin >> answer;

	//Menu
	cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
	cout << "\n\t\tPOTENTIAL PRIZES";
	cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
	cout << "\nITEM\t\t\tPRIZE";
	for (int x = 0; x < 6; x++)
	{
		cout << "\n" << x + 1 << ". " << "'" << game.options[x] << "'";
		cout << " = " << game.scoring[x] << " Points.";
	}
	cout << "\n\nSTART:";
	//Loop
	
	while (answer == 'Y')
	{
		game.rollDie();

		game.compare();
		game.CalculateScore();
		game.getScore();
		game.getFeedback();
		
		cout << "\nWould you like to play again? Y/N";
		cin >> answer;
	}

	cout << "\nYour TOTAL SCORE IS: \t" << game.getScore();


}
