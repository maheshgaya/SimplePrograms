/*
* author: Mahesh Gaya
* date: 01/27/2015
* description: simple comparator program
*/

#include <iostream>
using namespace std;

int main()
{
	int a = 0, b = 0; //variables
	//Prompt the user to enter two numbers and save them to a and b
	cout << "Enter a number: ";
	cin >> a;
	cout << "Enter another number:";
	cin >> b;
	
	//compare the number
	if (a>b)
	{
		cout << "The first number is greater than the second number." << endl;
	}
	else if (a==b)
	{
		cout << "Both numbers are equal." << endl;
	}
	else
	{
		cout << "The second number is greater than the first number." << endl;
	}
	return 0;
}
