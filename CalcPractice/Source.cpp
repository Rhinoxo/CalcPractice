/*
By Justin Orner | Last updated on: OCT/9/2018 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

//TODO Functions

int addition(int opLength, bool create)
{
	int op1 = rand() % static_cast<int>(pow(10, opLength));
	int op2 = rand() % static_cast<int>(pow(10, opLength));
	cout << op1 << endl;
	cout << op2 << endl;
	return op1 + op2;
}

int main()
{
	srand(time(0));

	//TODO Selector
	cout << addition(3,0) << endl;

	system("PAUSE");
	return 0;
}