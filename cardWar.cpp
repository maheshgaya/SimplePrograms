/*
* author: Mahesh Gaya
* date: 02/23/15
* description (PP5): war of cards
*/

/*
	pseudocode:
		ask user if he wants to play
		if yes then game is ON
		if cards of each player are different, then BATTLE
		else if cards of each player are the same, then WAR, show next cards in each decks
*/

#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

//rank for cards
enum Rank {TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

//structure for cards
struct Card
{
	//card structure, e.g. 5H, TC
	Rank rank;
	char suit;
}; 

//structure for score
struct Score
{
	//keep scores
	int computer;
	int player;
};

//function prototypes
void swap(Card*, Card*);
void shuffle(Card*);
string displayCard(Card*);
void game(Card*, int*, Score*);
void keepScore(Card*, Card*, Score*);
void displayArray(Card* );


//all the functions

/**swap
* swap elements of deck array
*/
void swap(Card *x, Card *y)
{ 
	//swap the array using pointers
	Card temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


/** shuffle
* input: a pointer to an array of Cards
* the contents of the array should be rearranged as in a 
* permutation of the original array
* assume that there 52 elements in the array
*/

void shuffle(Card *arr)
{
	//cout << "Shuffle function" << endl;//test
	
	//generate a random number and switch element at i with that of the random number
	for(int i=0; i<52; i++)
	{
		int random = rand()%52; //generate a random number
		swap(*(arr+i),*(arr+random));
	}

}

/** displayCard
* input: a pointer to a Card
* output: a string that consists of 2 characters:
* the card rank, followed by the suit
* for example,
* ten of clubs = "TC"
* queen of Hearts = "QH"
* 2 of diamonds = "2D"
* ace of spades = "AS"
*/

string displayCard(Card *c)
{
	string result = "xx"; // allocate space for a 2-character string
	char container[1];
	sprintf(container, "%d", c->rank);
	if (c->rank == TEN)
	{
		//output T for TEN
		container[0] = 'T';
	}
	else if (c->rank == JACK)
	{
		//output J for JACK
		container[0] = 'J';
	}
	else if (c->rank == QUEEN)
	{
		//output Q for QUEEN
		container[0] = 'Q';
	}
	else if (c->rank == KING)
	{
		//output K for KING
		container[0] = 'K';
	}
	else if (c->rank == ACE)
	{
		//output A for ACE
		container[0] = 'A';
	}
	//result
	result[0] = container[0];
	result[1] = c->suit;
	
	return result;
}

/**keepScore
* input: pointer to first deck(split deck array), pointer to second deck(split deck array), score
* purpose: calculate score and store it
*/
void keepScore(Card* fDeck, Card* sDeck, Score* gameScore, int* index, Card* shufDeck)//shufDeck means shuffled deck
{
	//score +2 if wins
	//score -1 if loses (negative marking)
	//game if draws
	
	if ((fDeck->rank) > (sDeck->rank))
	{
		cout << "It's a battle" << endl;
		gameScore->computer += 2;
		gameScore->player--;
	}
	else if ((fDeck->rank) < (sDeck->rank))
	{
		cout << "It's a battle" << endl;
		gameScore->player += 2;
		gameScore->computer--;
	}
	else if ((fDeck->rank) == (sDeck->rank))
	{
		cout << "It's a WAR!" << endl;
		(*index)++; //increment pointer index
		game(shufDeck, index, gameScore); //rematch
		
	}
	
}

/**game
* input: pointer to deck array, count from main(index), score
* purpose: this is where the actual game starts
*/

void game(Card* shDeck, int* index, Score* gScore) //shDeck means shuffled deck
{
	//cout << "game function" << endl;//test
	int i = *index;
	cout << "----------------------" << endl;
	cout << "Computer got " << displayCard(&shDeck[i]) << endl; //first deck
	cout << "You got " << displayCard(&shDeck[i+26]) << endl; //second deck
	keepScore(&shDeck[i], &shDeck[i+26], gScore, index, shDeck); //keep track of score
}

/**displayArray
* input: pointer array of deck
* purpose: display the whole array
*/
void displayArray(Card* arr)
{
	for (int j=0; j<52; j++)
	{
		cout << j << " " << displayCard(&arr[j]) << endl;
	}
}

/*main function*/
int main()
{
	srand(time(NULL)); //random seed value
	Card deck[52]; //deck of Cards
	char key;
	
	//welcoming message
	cout << "Welcome to War of Cards" << endl;
	//fill up the Cards with all of the values
	string suits = "SHDC";
	int i=0;
	for(int r=TWO; r<=ACE; r++)
	{
		for (int s=0; s<4; s++)
		{
			deck[i].suit = suits[s];
			deck[i].rank = (Rank) r;
			i++;
		}	
	
	}

	//shuffle elements of the deck
	shuffle(deck);

	//display all of the cards (optional)
	//displayArray(deck); //test

	//play a game of war
	cout << "Would you like to play? Press y to play" << endl;
	cin >> key;
	
	int count = 0; //initialize count
	
	//initialize both scores to zero
	Score score;
	score.computer = 0;
	score.player = 0; 

	//if key is yes or 'y' or 'Y'
	while (key == 'y' || key =='Y')
	{
		//cout << "key" << endl; //test
		game(deck, &count, &score); //play game, first deck and second deck
		
		//print scores
		cout << "----------------------" << endl;
		cout << "Computer score: " << score.computer << endl;
		cout << "Your score: " << score.player << endl;
		cout << "----------------------" << endl;		
			
		count++; //increment count
		if (count == 26)
		{
			shuffle(deck); //shuffle deck when deck is over
			//displayArray(deck); //test
			count = 0; //reinitialize count
		}
		
		//final score is 100
		if (score.computer >= 100 || score.player >= 100)
		{	
			break; //break of while loop and print results
		}
		//ask again if the player wants to play more
		cout << "Would you like to play? Press y to play" << endl;
		cin >> key;
		
	}
	
	//when done, print results
	cout << "Computer got a score of " << score.computer << endl;
	cout << "You got a score of " << score.player << endl;
	if (score.computer > score.player)
	{
		cout << "Oops! Computer WON! You LOST!" << endl;
	}
	else if (score.computer < score.player)
	{
		cout << "Great! You WON! Computer LOST!" << endl;
	}
	else if (score.computer == score.player)
	{
		cout << "Kinda nice! It's a tie!" << endl;
	}


	return 0;
}
