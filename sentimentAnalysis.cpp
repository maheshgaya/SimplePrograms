//author: Mahesh Gaya
//description: a program counting number of good words and bad words
//proposed points (out of 10): 10 
/*
pseudocode
	search for next data (can be string, integer, or double)
	check with the words(good words and bad words)
	temp list:	{good words: amazing, good, great, love,  lmao, yay
				bad words: boring/bored, terrible, shit, problem}
	report results
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>		
		
using namespace std;



int main()
{
	ifstream inputFile;
	ofstream outputFile;

	string filename, infilename;
	cout << "Enter the file name: ";
	getline(cin, filename);
	//open file
	inputFile.open(filename.c_str());
	cout << "Enter the input file: ";
	getline(cin, infilename);
	outputFile.open(infilename); 

	//check for inputfile opening error
	if(inputFile.fail())
	{
		cout << "err: cannot open file"<< endl;
		exit(0);
	}

	const int rows =8, cols =2;
	int arrayTrack[rows][cols] = {0};


	string nextStr;
	int score = 0;
	//read file until end of file
	do
	{
		//read next data
		inputFile >> nextStr;
		//convert to lowercase if string starts with an alphabet(a-z)(A-Z)
		if ((nextStr[0] >= char(65) && nextStr[0] <= char(90)) || (nextStr[0] >= char(97) && nextStr[0] <= char(122)))
		{
			transform(nextStr.begin(), nextStr.end(), nextStr.begin(), ::tolower);
			//cout << "convert:"; //testing for lowercase
		}
		//cout << nextStr << endl; //testing data input

		//I tried to keep the words separate in case I would want to do other 
		//calculations on them.
		//count good words: amazing, good, great, love,  lmao, yay
		if (nextStr == "amazing")
		{
			arrayTrack[0][0]++;
		}
		if (nextStr == "good")
		{
			arrayTrack[1][0]++;
		}
		if (nextStr == "great")
		{
			arrayTrack[2][0]++;
		}
		if (nextStr == "love")
		{
			arrayTrack[3][0]++;
		}
		if (nextStr == "lmao")
		{
			arrayTrack[4][0]++;
		}
		if (nextStr == "yay")
		{
			arrayTrack[5][0]++;
		}


		//count bad words: boring/bored(counting them as one), problem, shit, terrible
		if (nextStr == "boring" || nextStr == "bored")
		{
			arrayTrack[0][1]++;
		}
		if (nextStr == "problem")
		{
			arrayTrack[1][1]++;
		}
		if (nextStr == "shit" )
		{
			arrayTrack[2][1]++;
		}
		if (nextStr == "terrible" )
		{
			arrayTrack[3][1]++;
		}


	} while (!inputFile.eof());

	int sumGood = 0, sumBad = 0;

	//calculate total number of good words and bad words
	for (int i = 0; i<rows; i++)
	{
		sumGood += arrayTrack[i][0];
	}

	for (int j = 0; j<rows; j++)
	{
		sumBad += arrayTrack[j][1];
	}
	
	score = sumGood - sumBad;	
	
	//output results to console
	/*cout << "amazing: " << arrayTrack[0][0] << endl;
	cout << "good: " << arrayTrack[1][0] << endl;
	cout << "great: " << arrayTrack[2][0] << endl;
	cout << "love: " << arrayTrack[3][0] << endl;
	cout << "lmao: " << arrayTrack[4][0] << endl;
	cout << "yay: " << arrayTrack[5][0] << endl;
	cout << "boring/bored: " << arrayTrack[0][1] << endl;
	cout << "problem: " << arrayTrack[1][1] << endl;
	cout << "shit: " << arrayTrack[2][1] << endl;
	cout << "terrible: " << arrayTrack[3][1] << endl;*/

	cout << "Number of positive words: " << sumGood << endl;
	cout << "Number of negative words: " << sumBad << endl;
	cout << "Posivity of the tweets: " << score << endl;

	//output results to file
	outputFile << "amazing: " << arrayTrack[0][0] << endl;
	outputFile << "good: " << arrayTrack[1][0] << endl;
	outputFile << "great: " << arrayTrack[2][0] << endl;
	outputFile << "love: " << arrayTrack[3][0] << endl;
	outputFile << "lmao: " << arrayTrack[4][0] << endl;
	outputFile << "yay: " << arrayTrack[5][0] << endl;
	outputFile << "boring/bored: " << arrayTrack[0][1] << endl;
	outputFile << "problem: " << arrayTrack[1][1] << endl;
	outputFile << "shit: " << arrayTrack[2][1] << endl;
	outputFile << "terrible: " << arrayTrack[3][1] << endl;
	outputFile << "---------------------------------" << endl;
	outputFile << "Number of positive words: " << sumGood << endl;
	outputFile << "Number of negative words: " << sumBad << endl;
	outputFile << "Posivity of the tweets: " << score << endl;

	cout << "--> Done! Results output to tweetAnalysis.txt" << endl;

	//close file
	inputFile.close();
	outputFile.close();
	return 0;
}

