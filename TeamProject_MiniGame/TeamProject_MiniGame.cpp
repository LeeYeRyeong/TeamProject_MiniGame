#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <windows.h>
using namespace std;

void upgrade369();
void baseballGame();
void upgradeBR31();
void subway();
bool isRepeat369(const int&);
int createNum(int);
int numCount(int);
int strike(int, int, int);
int ball(int, int, int);

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
		else if (select == 3) upgradeBR31();
		else if (select == 4) subway();
		else continue;

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

// 메세지 부분만 수정하면 됨.
void baseballGame()
{
	int number = createNum(1000);
	int guessNum;
	cout << "The number of digits of secret numbers is " << numCount(number) << endl;

	while (true) {
		cout << "Enter the guess number : ";
		cin >> guessNum;
		if (guessNum == number) {
			cout << "Correct! You found the exact one!" << endl << "The answer is " << number << endl;
			break;
		}
		else {
			int strikeCount = strike(number, guessNum, numCount(number));
			int ballCount = ball(number, guessNum, numCount(number));
			cout << strikeCount << " strike" << " " << ballCount << " ball" << " "
				<< (numCount(number) - strikeCount - ballCount > 0 ? numCount(number) - strikeCount - ballCount : 0) << " out" << endl;
			continue;
		}
	}
}

void upgradeBR31()
{
	int number = createNum(50 - 31) + 32;
	cout << "the end number is " << number << endl;

	// 알고리즘을 사용자도 이길 수 있게 구성할지 or 사용자가 절대 이길 수 없게 구성할지
}

void subway()
{
	string station[10][1000] = {}; // 역 이름 추가하기
}

inline int createNum(int n)
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

int strike(int number, int guessNum, int n)
{
	int strike = 0;
	int NUM[5] = {}, GUESS[5] = {};

	for (int i = 0; i < n; i++) {
		NUM[n - i - 1] = number % 10;
		GUESS[n - i - 1] = guessNum % 10;
		number /= 10;
		guessNum /= 10;
	}

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (NUM[i] == GUESS[j] && i == j)
				strike++;

	return strike;
}

int ball(int number, int guessNum, int n)
{
	int ball = 0;
	int NUM[5] = {}, GUESS[5] = {};

	for (int i = 0; i < n; i++) {
		NUM[n - i - 1] = number % 10;
		GUESS[n - i - 1] = guessNum % 10;
		number /= 10;
		guessNum /= 10;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (NUM[i] == GUESS[j] && i != j) ball++;

	return ball;
}