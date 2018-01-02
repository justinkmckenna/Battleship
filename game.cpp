//battleship main
//Justin Mckenna
//12/17/2017

#include "battleship.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
	
	srand(time(nullptr));

	//field grid is initialized
	int field[fieldSize][fieldSize];
	initialize(field);

	//enemy is formed and deployed
	Fleet enemy;
	enemy.deployFleet();

	//asks player if they want to see ship locations
	cout << "Welcome to battleship!" << endl
		<< "Would you like to see the status/location of the enemy fleet while you play?(y/n) ";
	char answer;
	cin >> answer;

	//shows ship locations based on player response
	if (answer == 'y') 
		enemy.showShips(field);
	
	//shows player field grid
	cout << "Here is your battlefield! O=miss, X=hit";
	if (answer == 'y')
		cout << ", S=ship";
	cout << endl;
	printField(field);

	//initiates turn counter
	int numTurns = 0;

	//game is ran while ships are all up
	while (enemy.operational()) {
		
		numTurns += 1;
		cout << numTurns << ".";
		
		//player fires a shot at playerShot
		Location playerShot;
		cout << "Enter the coordinates of your shot(eg a1): ";
		playerShot.fire();

		//ship sinks if hit
		if (enemy.isHitNSink(playerShot, field))
			cout << "Hit!" << endl;
		else
			cout << "Miss!" << endl;

		printField(field);//prints field
	}

	cout << endl << "You Win!" << endl;
	
	if (answer == 'n') 
		if (bestScore(numTurns))
			getScore(numTurns);
	if (answer == 'y')
		cout << "Your score is not a best score!(you saw the ship locations)" << endl;
	
	printScore();

}