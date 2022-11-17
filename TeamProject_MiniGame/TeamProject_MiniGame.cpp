#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "        CHOOSE THE GAME" << endl << "------------------------------------" << endl;
	cout << "1. 369 upgrade.ver" << endl << "2. baseball game" << endl << "3. baskin robbins 31 upgrade.ver"
		<< endl << "4. subway game" << endl << "5. rock, scissors, paper game" << endl << "6. lotto game" << endl
		<< "------------------------------------";
}

void upgrade369()
{
	srand(time(0));
	int n1, n2, n3;
	n1 = rand() % 9 + 1;
	n2 = rand() % 9 + 1;
	n3 = rand() % 9 + 1;
}