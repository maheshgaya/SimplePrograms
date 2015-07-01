/* authors: Mahesh Gaya
* date: February 16, 2015
* description (PP4): a guessing game that consists of 3 different types of guessing strategies:
	1. simple guessing game: user just guesses a number until the right one is guessed
	2. guess with hints: user is given hints
	3. evil guessing game: make use of a boolean array that keeps track of guessed numbers; outputs the one that is not guessed
*/

#include <cstdlib> //needed for rand on some machines
#include <iostream>

using namespace std;

/*
 * simpleGuessGame
 * input: size: the number of numbers to guess
 * plays a simple guessing game until the answer is guessed correctly
 */
void simpleGuessGame(int size)
{
	int guess = rand() % size; //guess a number between 0 to size
	int ans = 0;	//initialize ans; ans stands for answer	
	
	//welcome message	
	cout << "Welcome to Simple Guess Game!" << endl;
	cout << "I'm thinking of a number between 0 to " << size-1 << endl;	
	
	//allow the user to guess a number until he finds the correct answer
	do
	{
		cout << "Guess a number between 0 and " << size-1 << endl; //give info to the user
		cout << "Enter a guess: "; //prompt user
		cin >> ans;
		if (ans != guess)
		{
			cout << "Nope! That's not it." << endl;
		}
	}
	while (ans!=guess);

	//if the answer is correct then print the message
	if (ans == guess)
	{	
		cout << "YES! You guessed it correctly." << endl;
	}
}

/*
 * guessGameWithHints
 * input: size: the number of numbers to guess
 * plays a simple guessing game until the answer is guessed correctly
 * gives the user hints if they are too high or too low
 */
void guessGameWithHints(int size)
{
	int guess = rand() % size; //random guess: a number between 0 to size
	int ans = 0;//initialize ans; ans stands for answer
	//cout << guess << endl; //test for guessing
	
	//welcome message	
	cout << "Welcome to Guess Game With Hints!" << endl;
	cout << "I'm thinking of a number between 0 to " << size-1 << endl;

	//allow the user to input a number until he finds the right answer. But this time give the user a hint.
	do
	{
		cout << "Guess a number between 0 and " << size-1 << endl; //give info to the user
		cout << "Enter a guess: "; //prompt user
		cin >> ans;
		if (ans > guess)
		{	
			cout << "Nope! That's not it. Your input is too high." << endl;	
		}
		else if (ans < guess)
		{
			cout << "Nope! That's not it. Your input is too low." << endl;
		}
	}
	while (ans!=guess);

	//if the answer is correct then print the message
	if (ans == guess)
	{	
		cout << "YES! You guessed it correctly." << endl;
	}	

}

/*
 * evilGuessGame
 * input: bool* array: array of boolean values
 * input: size: the number of numbers to guess
 * lures user into thinking this is a simple guessing game
 * gives users size-1 guesses 
 * computer always wins by revealing the answer was the ONE selection not chosen
 * does not assume array has been initialized
 */
void evilGuessGame(bool* array, int size)
{
	
	int ans = 0;//initialize ans; ans stands for answer
	int maxGuesses = size-1; //number of times the user can guess that random number
	array = new bool[size]; //dynamic allocation
	//initialization of array	
	for (int j = 0; j < size; j++)
	{
		*(array+j) = false;
	}
	//welcome message	
	cout << "Welcome to Evil Guess Game!" << endl;
	cout << "I'm thinking of a number between 0 to " << size-1 << endl;

	//allow the user to guess size-1 times
	for (int count = 0; count < maxGuesses; count++)
	{ 
		//cout << "count: " << count << endl; //test
		cout << "Guess a number between 0 and " << size-1 << endl; //give info to the user
		cout << "You have "<< maxGuesses-count << " remaining guesses." << endl;
		cout << "Enter a guess: "; //prompt user
		cin >> ans;	
		
		*(array+ans)=true; //change value of the array slot of the user input to true	
		cout << "Nope! That's not it." << endl; //sorry message
		
	}
	
	int guess = 0;
	for (int i = 0; i < size; i++)
	{
		//cout << "Entering checking loop" << endl; //test
		if (*(array+i) == false)
		{
			guess = i; //check which slot is false
		}
	}
	cout << "Sorry! The answer was actually " << guess << "\nBetter luck next time... (heh heh heh)."<< endl; //output that false slot
	delete[] array;
}


int main()
{
	//declare varibles
	int answer = 0;
	int inputNumber = 0;

	//get user response for which game to play
	srand(time(NULL)); //random seed value
	do
	{
		cout << "Which game do you want to play?" <<endl;
		cout << "   1: simple guessing game" <<endl;
		cout << "   2: guessing game with hints"<<endl;
		cout << "   3: evil guessing game" <<endl;
		cout << " choice? ";

		cin >> answer;
	}while (answer <1 || answer>3);


	cout << "How many numbers to choose from?" <<endl;
	cin >> inputNumber;

	//call appropriate guessing game
	switch (answer)
	{
		case 1:
			simpleGuessGame(inputNumber);
			break;
		case 2:
			guessGameWithHints(inputNumber);
			break;
		case 3:
			bool *arr = new bool[inputNumber];
			evilGuessGame(arr, inputNumber);
			break;
	}
	

	return 0;
}
