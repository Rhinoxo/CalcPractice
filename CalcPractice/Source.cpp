/*
By Justin Orner | Last updated on: OCT/9/2018 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//TODO Functions
int addition(int opLength, bool create)
{
	int op1 = rand() % 10 ^ opLength;
	int op2 = rand() % 10 ^ opLength;
	cout << op1 << endl;
	cout << op2 << endl;
	return op1 + op2;
};

int main()
{
	srand(83);

	//TODO Selector
	cout << addition(5,0) << endl;

	system("PAUSE");
	return 0;
}