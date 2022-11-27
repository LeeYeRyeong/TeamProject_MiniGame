#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

void upgrade369();
void baseballGame();
bool isRepeat369(const int&);
int createNum(int);
int numCount(int);

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
		else if (select == 2) baseballGame();

	} while (select == 0); 
}

// 369게임 기호 어떤걸할지.... 함수를 새로 만들지 관련해서
// 이부분 구현 끝나면 끝
void upgrade369()
{
	int n[3] = {};
	int num = 1, endNum, userNum, i = 0;
	bool select;

	while (i < 3) {
		n[i] = createNum(10);
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
			cout << num++ << endl;
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

// 메세지 올바르게 고치기
void baseballGame()
{
	int number = createNum(1000);
	int guessNum;
	cout << "secret number count is " << numCount(number) << endl;

	while (true) {
		cout << "Enter the guess number : ";
		cin >> guessNum;
		if (guessNum == number) {
			cout << "You Win!" << endl;
			break;
		}
		else {
			continue;
		}
	}
}

int createNum(int n)
{
	return rand() % n;
}

int numCount(int number)
{
	int count = 0;
	while (number > 0) {
		number /= 10;
		count++;
	}
	return count;
}

bool isRepeat369(const int &num1) 
{
	static int list[10] = {};
	list[num1]++;
	if (list[num1] > 1) return true;

	return false;
}