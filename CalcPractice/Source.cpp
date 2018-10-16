/*
By Justin Orner | Last updated on: OCT/9/2018 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

//TODO Functions

void fMathCreate(int, int);
string addition(int);

int main()
{
	int maxDigits;

	srand(time(0));

	cout << "What is the maximum number of digits that you want to work with?" << endl;
	cin >> maxDigits;

	//TODO Selector
	fMathCreate(1, maxDigits);

	system("PAUSE");
	return 0;
}

void fMathCreate(int oppType, int digitsMax)
{
	int opp;
	ofstream fout;
	string fileName;

	cout << "Enter File Name: ";
	cin >> fileName;

	fout.open(fileName);

	for (int i = 0; i < 10; i++)	// Creates 10 questions 
	{
		switch (oppType)
		{
		case 1:			// Addition
			fout << addition(digitsMax) << endl;
			break;
		default:		// The opperator type is either random or null
			opp = rand() % 4;
			switch (opp)
			{
			case 0:
				fout << addition(digitsMax) << endl;
			default:
				break;
			}
			break;
		}
	}

	fout.close();
}

string addition(int opLength)
{
	string question;
	int op1 = rand() % static_cast<int>(pow(10, opLength));
	int op2 = rand() % static_cast<int>(pow(10, opLength));

	// Converts values to strings to create a question
	question = to_string(op1) + " + " + to_string(op2) + " = ";
	return question;
}