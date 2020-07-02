/*
By Justin Orner | Last updated on: JUN/20/20 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <conio.h>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

//TODO Functions
/*
TODO Interactive
	TODO Answer Checking
*/

void fMathCreate(int, int);
string addition(int);
string subtraction(int);
string multiplication(int);
string division(int);
int mainMenu(int&, int&);
void selectMath(int, int, int);
void checkWKST();
void checkAnswer(double, int, double, char);
string createQ(int, int);
void interactive(int, int);

int main()
{
	int choice = -1;
	int opptype, digitMax;

	srand(time(0));
	
	do {
		choice = mainMenu(opptype, digitMax);
		selectMath(choice, opptype, digitMax);
	} while (choice != 4);

	system("PAUSE");
	return 0;
}

int mainMenu(int &opptype, int &digitMax)
{
	int choice1;//, opptype, digitMax;

	// Displays main menu
	cout << "What would you like to do?" << endl;
	cout << "\t 1. Interactive Solving" << endl;
	cout << "\t 2. Create A Practice Worksheet" << endl;
	cout << "\t 3. Check Practice Worksheet" << endl;
	cout << "\t 4. Quit" << endl;

	cin >> choice1;

	// check if quit
	if (choice1 == 4)
	{
		exit(0);
	}
	if (choice1 == 2 || choice1 == 1)
	{
		// Display opperation choices
		cout << "What opperation would you like to practice?" << endl;
		cout << "\t 1. Addition" << endl;
		cout << "\t 2. subtraction" << endl;
		cout << "\t 3. Multiplication" << endl;
		cout << "\t 4. Division" << endl;
		cout << "\t 5. Random Mix" << endl;

		cin >> opptype;

		// Get max digits
		cout << "What is the maximum number of digits that you want to work with?" << endl;
		cin >> digitMax;
	}

	return choice1;
}

void selectMath(int createType, int opptype, int maxDigits)
{
	switch (createType)
	{
	case 1:
		// Interactive play
		interactive(opptype, maxDigits);
		break;
	case 2:
		fMathCreate(opptype, maxDigits);
		break;
	case 3:
		checkWKST();
		break;
	default:
		break;
	}
}

void fMathCreate(int oppType, int digitsMax)
{
	ofstream fout;
	string fileName;

	cout << "Enter File Name: ";
	cin >> fileName;

	fout.open(fileName);

	for (int i = 0; i < 10; i++)	// Creates 10 questions 
	{
		fout << createQ(oppType, digitsMax) << endl;
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

string subtraction(int opLength)
{
	string question;
	int op1 = rand() % static_cast<int>(pow(10, opLength));
	int op2 = rand() % static_cast<int>(pow(10, opLength));

	// Converts values to strings to create a question
	question = to_string(op1) + " - " + to_string(op2) + " = ";
	return question;
}

string multiplication(int opLength)
{
	string question;
	int op1 = rand() % static_cast<int>(pow(10, opLength));
	int op2 = rand() % static_cast<int>(pow(10, opLength));

	// Converts values to strings to create a question
	question = to_string(op1) + " * " + to_string(op2) + " = ";
	return question;
}

string division(int opLength)
{
	string question;
	int op1 = rand() % static_cast<int>(pow(10, opLength));
	int op2 = rand() % static_cast<int>(pow(10, opLength));

	// Converts values to strings to create a question
	question = to_string(op1) + " / " + to_string(op2) + " = ";
	return question;
}

void checkWKST()
{
	char opp, equi;
	int valOne, valTwo;
	double valRes, resTrue;
	ifstream fin;
	string fname;

	cout << "Enter File Name: " << endl;
	cin >> fname;

	fin.open(fname);

	for (int i = 0; i < 10; i++)
	{
		if (!fin)
		{
			cout << "Could not open file" << endl;
		}
		else
		{
			fin >> valOne >> opp >> valTwo >> equi >> valRes;
			cout << valOne << " " << opp << " " << valTwo << " "
				<< equi << " " << valRes << endl;
		}

		checkAnswer(valOne, valTwo, valRes, opp);
	}
	
	fin.close();
}

void checkAnswer(double valOne, int valTwo, double valRes, char opp)
{
	double resTrue;

	// looks at the opperator and computes
	if (opp == '+')
	{
		resTrue = valOne + valTwo;
	}
	else if (opp == '-')
	{
		resTrue = valOne - valTwo;
	}
	else if (opp == '*')
	{
		resTrue = valOne * valTwo;
	}
	else if (opp == '/')
	{
		resTrue = valOne / valTwo;
	}
	else
	{
		cout << "Invaled Opperator" << endl;
		resTrue = 0;
	}

	resTrue = round(resTrue * 1000) / 1000;

	// Prints the two values to compare and then compares the inputed result to the calculated result
	cout << valRes << " = " << resTrue << endl;
	if (valRes == resTrue)
	{
		cout << "Correct!";
	}
	else
	{
		cout << "Wrong!";
	}

	cout << endl;
}

string createQ(int oppType, int digitsMax)
{
	int opp;
	string q;

	switch (oppType)
	{
	case 1:			// Addition
		q = addition(digitsMax);
		break;
	case 2:			// Subtraction
		q = subtraction(digitsMax);
		break;
	case 3:			// Multiplication
		q = multiplication(digitsMax);
		break;
	case 4:			// Division
		q = division(digitsMax);
		break;
	default:		// The opperator type is either random or null
		opp = rand() % 4;
		switch (opp)
		{
		case 0:
			q = addition(digitsMax);
			break;
		case 1:
			q = subtraction(digitsMax);
			break;
		case 2:
			q = multiplication(digitsMax);
			break;
		case 3:
			q = division(digitsMax);
			break;
		default:
			break;
		}
		break;
	}
	return q;
}

void interactive(int opptype, int digitmax)
{
	double answer;
	char delim = ' ';
	int idx1 = 0, idx2;
	string question, q1, q2, opp;

	question = createQ(opptype, digitmax);

	cout << question;
	cin >> answer;

	for (int i = 0; i < 3; i++)
	{
		idx2 = question.find(delim, idx1);
		switch (i) 
		{
		case(0):
			q1 = question.substr(idx1,idx2);
			break;
		case(1):
			opp = question.substr(idx1,idx2);
			break;
		case(2):
			q2 = question.substr(idx1, idx2);
			break;
		default:
			break;
		}
		idx1 = idx2 + 1;

	}

	//DEBUG
	cout << " q1 " << q1 << " q2 " << q2 << " opp " << opp << endl;
	
	checkAnswer(stod(q1), stoi(q2), answer, opp[0]);
}