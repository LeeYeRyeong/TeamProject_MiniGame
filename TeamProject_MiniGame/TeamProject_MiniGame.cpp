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
	int count = createNum(5) + 1;
	int number = 0, i = 0, guessNum;
	int temp[10];

	while (i < count) {
		temp[i] = createNum(10);
		if (isRepeat369(temp[i]) || (i == 0 && temp[i] == 0)) continue;
		number = number * 10 + createNum(10);
		i++;
	}

	cout << "The number of digits of secret numbers is " << count << endl;

	while (true) {
		cout << "Enter the guess number : ";
		cin >> guessNum;
		if (guessNum == number) {
			cout << "Correct! You found the exact one!" << endl << "The answer is " << number << endl;
			return;
		}
		else {
			int strikeCount = strike(number, guessNum, count);
			int ballCount = ball(number, guessNum, count);
			cout << strikeCount << " strike" << " " << ballCount << " ball" << " "
				<< (count - strikeCount - ballCount > 0 ? count - strikeCount - ballCount : 0) << " out" << endl;
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
	string station[10][1000] = { 
		{ "서울역","영등포","용산","부천","종각","수원","역곡","송내","부평","금정"
   "가산디지털단지","종로3가","회기","안양","종로5가","개봉","청량리","시청","주안","의정부"
   "구로","노량진","제기동","독산","동암","병점","석계","성균관대","동인천","신설동",
   "평택","대방","회룡","오류동","금천구청","동대문","소사","제물포","오산","동묘앞",
   "방학","도봉산","석수","남영","중동","의왕","명학","부개","신이문","광운대",
   "양주","망월사","외대앞","군포","화서","관악","온수","백운","신길","서정리",
   "가능","지행","구일","월계","도봉","천안","당정","간석","두정","덕정",
   "녹양","송탄","녹천","신도림","도화","온양온천","성환","오산대","소요산",
   "인천","동두천중앙","평택지제","도원","광명","아산","세류","덕계","세마","동두천",
   "쌍용","보산","신창","진위","서동탄","봉명","배방","직산","탕정" },
	{ "강남","잠실","신림","구로디지털단지","홍대입구","신도림","선릉","삼성","역삼","서울대입구",
	   "사당","건대입구","을지로입구","성수","교대","신촌","합정","강변","낙성대","신대방",
	   "대림","봉천","구의","영등포구청","뚝섬","잠실새내","문래","시청","서초","을지로3가",
	   "당산","방배","왕십리","신당","상왕십리","잠실나루","동대문역사문화공원","이대","을지로4가","신정네거리",
	   "아현","충정로","종합운동장","한양대","양천구청","신설동","용답","용두","신답","도림천" },
	{ "고속터미널","양재","연신내","압구정","신사","남부터미널","구파발","안국","경복궁","불광",
	"수서","홍제","녹번","약수","매봉","대치","교대","종로3가","을지로3가","옥수",
	   "일원","대청","가락시장","동대입구","금호","오금","도곡","잠원",
	"지축","무악재","학여울" } }; // 역 이름 추가하기
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