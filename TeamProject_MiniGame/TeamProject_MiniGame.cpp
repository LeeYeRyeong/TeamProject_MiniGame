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
	int num = 1, userNum, endNum, i = 0;
	bool select;
	char user;

	while (i < 3) {
		n[i] = createNum(10);
		if (isRepeat369(n[i])) continue;
		i++;
	}

	cout << "Enter a end number : ";
	cin >> endNum;
	cout << "The key number is " << n[0] << ", " << n[1] << ", " << n[2] << endl;
	cout << "If you choose 0, you starts first, and if you choose 1, the computer starts first, " 
		<< endl << "Choose the number : ";
	cin >> select;

	if (select) {
		while (num <= endNum) {
			if (num == n[0] || num == n[1] || num == n[2]) {
				cout << "*" << endl;
				num++;
			}
			else {
				cout << num++ << endl;
			}
			if (num == n[0] || num == n[1] || num == n[2]) {
				cin >> user;
				if (user != '*') {
					cout << "Game Over!" << endl;
					break;
				}
			}
			else {
				cin >> userNum;
				if (userNum != num) {
					cout << "Game Over!" << endl;
					break;
				}
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
	int select;
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
	"지축","무악재","학여울" },
		{ "진접", "오남", "별내별가람", "당고개", "상계", "노원", "창동", "쌍문", "수유", "미아", "미아사거리", "길음",
	"성신여대입구", "한성대입구", "혜화", "동대문", "동대문역사문화공원", "충무로", "명동", "회현", "서울역",
	"숙대입구", "삼각지", "신용산", "이촌", "동작", "총신대입구(이수)", "사당", "남태령", "선바위", "경마공원",
	"대공원", "과천", "정부과천청사", "인덕원", "평촌", "범계", "금정", "산본", "수리산", "대야미",
	"반월", "상록수", "한대앞", "중앙", "고잔", "초지", "안산", "신길온천", "정왕", "오이도" },
 {"방화", "개화산", "김포공항", "송정", "마곡", "발산", "우장산", "화곡", "까치산", "신정", "목동", "오목교",
	"양평", "영등포구청", "영등포시장", "신길", "여의도", "여의나루", "마포", "공덕", "애오개","충정로","서대문",
 "광화문", "종로3가", "을지로4가","동대문역사문화공원", "청구", "신금호","행당","왕십리","마장","답십리","장한평",
 "군자", "아차산","광나루","천호","강동","길동", "굽은다리", "명일","고덕","상일동","강일","미사","하남풍산","하남시청",
	"하남검단산","둔촌동","올림픽공원", "방이","오금","개롱","거여","마천" },
	 { "응암","공덕","망원","디지털미디어시티","마포구청","합정","석계","새절","월곡","이태원","증산","화랑대","안암",
	"한강진","돌곶이","상수","동묘앞","봉화산","광흥창","신당","대흥","고려대","보문","구산","효창공원앞","상월곡",
	"태릉입구","삼각지","월드컵경기장","녹사평","불광","역촌","청고","약수","창신","독바위","버티고개" },
	{ "가산디지털단지","학동","광명사거리","철산","노원","논현","청담","하계","상봉","사가정","강남구청","신대방사거리",
		"남구로","면목","이수","고속터미널","신중동","내방","중계","군자","상동","수락산","부천시청","건대입구","어린이대공원",
		"마들","숭실대입구","공릉","신풍","중화","천왕","남성","도봉산","상도","먹골","온수","중곡","보라매","장승배기","춘의","굴포천",
		"뚝섬유원지","부평구청","대림","태릉입구","까치울","용마산","반포","산곡","삼산체육관","석남","부천종합운동장","장암"},
	 {"문정","암사","장지","천호","잠실","남한산성입구","단대오거리","강동구청","복정","석촌","가락시장","송파",
		"산성","몽촌토성","수진","신흥","모란","남위례"},
	{"신논현","노량진","여의도","가양","당산","염창","봉은사","고속터미널","국회의사당","마곡나루","등촌","김포공항","언주",
		"양천향교","선정릉","중앙보훈병원","흑석","석촌","선유도","증미","신방화","삼전","삼성중앙","올림픽공원","석촌고분",
		"샛강","송파나루","노들","종합운동장","신목동","사평","신반포","공항시장","구반포","한성백제","개화","동작","둔춘오륜"} }; // 역 이름 추가하기



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