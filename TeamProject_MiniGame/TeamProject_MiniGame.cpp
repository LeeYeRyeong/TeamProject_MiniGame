#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void upgrade369();
void baseballGame();
bool isRepeat(int, int, int);

int main()
{
	int select;
	do {
		cout << "        CHOOSE THE GAME" << endl << "------------------------------------" << endl;
		cout << "0. the end" << endl << "1. 369 upgrade.ver" << endl << "2. baseball game" << endl 
			<< "3. baskin robbins 31 upgrade.ver" << endl << "4. subway game" << endl << "5. rock, scissors, paper game"
			<< endl << "6. lotto game" << endl << "------------------------------------" << endl;
		cout << "Enter a number : ";
		cin >> select;
		if (select == 1) upgrade369();

	} while (select == 0); 
}

void upgrade369()
{
	int n1, n2, n3, num = 1, endNum, userNum;
	bool select;
	srand(time(0));
	n1 = rand() % 9 + 1;
	n2 = rand() % 9 + 1;
	n3 = rand() % 9 + 1;

	cout << "Enter a end number : ";
	cin >> endNum;
	cout << "If you choose 0, you starts first, and if you choose 1, the computer starts first, " 
		<< endl << "Choose the number : ";
	cin >> select;

	if (select) {
		while (num <= endNum) {
			cout << num++ << " ";
			cin >> userNum;
			if (userNum != num) {
				cout << "Game Over!" << endl;
				break;
			}
			num++;
		}
	}
	else {
		while (num <= endNum) {
			cin >> userNum;
			if (userNum != num) {
				cout << "Game Over!" << endl;
				break;
			}
			cout << ++num << " ";
			num++;
		}
	}
}

void baseballGame()
{
	int number;
	cout << "Enter a number : ";
	cin >> number;
}

bool isRepeat(int num1, int num2, int num3) 
{
	return true;
}