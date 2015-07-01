/*
* Author: Mahesh Gaya
* Date: 02/01/2015
* Description: a program that allows user to enter student grades with their names and save the whole thing to a file.
* Functionality: Enter a name, Enter a grade, Type "done" to exit
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//variables
	ofstream studentFile;
	int gradeNum; //gradeNum is a number
	char grade;
	string name;

	studentFile.open("students.txt"); //opens students.txt file
	
	//title for the file
	studentFile << "Grades for Computer Science " << endl;	

	do
	{
		//ask the user to enter a student name
		cout << "Enter the student name: ";
		getline(cin, name);
		
		//done for exiting the loop
		if (name == "done")
		{
			break;
		}

		do
		{
			//enter the result for computer science exams
			cout << "Enter grade: ";
			cin >> gradeNum;
		}
		while (!(gradeNum >= 0 && gradeNum <= 100));		
		//convert to A(90-100), B(80-89), C(70-79) or F(<=69)
		if (gradeNum >= 90 && gradeNum <=100)
		{
			grade = 'A';
		}
		else if (gradeNum >= 80 && gradeNum <=89)
		{
			grade = 'B';
		}
		else if (gradeNum >= 70 && gradeNum <=79)
		{
			grade = 'C';
		}
		else
		{
			grade = 'F';
		}
		//constantly save to the file
		studentFile << name << '\t' << gradeNum << '\t' << grade << endl;
		
		cin.ignore(1,'\n'); //grabs garbage
	}
	while (!(name == "done"));
	
	studentFile.close(); //closes file
	
	cout << "--> Done! Writing to students.txt" << endl;
	return 0;
}
