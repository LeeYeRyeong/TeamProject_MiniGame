#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

void upgrade369();
void baseballGame();
bool isRepeat369(const int&);
int createNum();

int main()
{
	srand(time(0));
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
	int n[3] = {};
	int num = 1, endNum, userNum, i = 0;
	bool select;

	while (i < 3) {
		n[i] = createNum();
		if (isRepeat369(n[i])) continue;
		i++;
	}

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

int createNum()
{
	return rand() % 10;
}

bool isRepeat369(const int &num1) 
{
	static int list[10] = {};
	list[num1]++;
	if (list[num1] > 1) return true;

	return false;
}