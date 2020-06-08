#include "toolKit.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
int toolKit::shuffleTIME = 0 ;
int toolKit::timeSEED = unsigned int(time(NULL));
int toolKit::playerAmount = 1;
int toolKit::Chips = 5000;
int toolKit::playerPoint[5] = { 0,0,0,0,0 };
int toolKit::playerBet[5] = { 0,0,0,0,0 };
bool toolKit::gameStatus[5] = { true,true,true,true,true };

toolKit::toolKit()
{
	
}
void toolKit::toolKitInit()
{
	for (int i = 0; i < playerAmount; i++)
	{
		playerPoint[i] = Chips;
	}
}

string toolKit::startUpPage()
{
	string chPA, chChips;
	system("mode con cols=100 lines=50");
	gotoxy(18, 15);cout  << "                     歡迎遊玩 \"10點半\"";
	gotoxy(18, 16); cout << "    遊戲說明:A,2,3,4,5,6,7,8,9,10　分別為一至十點。J,Q,K為半點"     ;
	gotoxy(18, 17); cout << "   閒家可以一路加牌，但若超過十點半，即「爆牌」(Busted)，閒家立賠"  ;
	gotoxy(18, 18); cout << "     閒家倘若為 一隻10加一隻J,Q或K成十點半，莊家立賠2倍原賭注"       ;
	gotoxy(18, 19); cout << " 若果閒家共有五張牌而仍未「爆牌」，稱「過五關」，莊家立賠3倍原賭注" ;
	gotoxy(18, 20); cout << "        若果閒家共有五張牌而卻已「爆牌」，閒家立賠2倍原賭注"        ;
	gotoxy(18, 21); cout << "              若莊家與閒家點數相同，則莊家勝，閒家立賠"             ;
	gotoxy(18, 30); cout << "                       [[[[[設定]]]]]";
	error1:
	gotoxy(18, 31); cout << "                  [玩家人數](預設1人,至多五人) :"; getline(cin,chPA);
	if (chPA != "")
	{
		stringstream ss;
		ss.clear();
		int buff;
		ss << chPA;
		ss >> buff;
		if (buff > 5 || buff <= 0)
		{
			gotoxy(18, 31); cout << "                                                               ";
			gotoxy(18, 31); cout << "                  [輸入錯誤,請設數字小於等於5,大於0]           ";
			sleep(3);
			gotoxy(18, 31); cout << "                                                               ";
			goto error1;
		}
		else
		{
			playerAmount = buff;
		}
	}
	error2:
	gotoxy(18, 32); cout << "                       [初始籌碼](預設5000):"; getline(cin,chChips);
	if (chChips != "")
	{
		stringstream ss;
		ss.clear();
		int buff;
		ss << chChips;
		ss >> buff;
		if (buff <= 0 || buff > 2000000000)
		{
			gotoxy(18, 32); cout << "                                                               "; 
			gotoxy(18, 32); cout << "                  [輸入錯誤,請設數字大於0,小於20億]            ";
			sleep(3);
			gotoxy(18, 32); cout << "                                                               ";
			goto error2;
		}
		else
		{
			Chips = buff;
		}
	}
	
	toolKitInit();
	gotoxy(18, 34); cout << "                       [設 定 完 成]";
	gotoxy(18, 38); cout << "                       [按ENTER開始遊戲]";
	return pause();
}
string toolKit::pause()
{
	string dummy;
	getline(cin, dummy);
	return dummy;
}

void toolKit::sleep(double timeS)
{
	unsigned int timeMs = int(timeS * 1000);
	Sleep((int)timeMs);
}

void toolKit::gotoxy(double x, double y) // allows to move inside the terminal using coordinates 
{	// the type is double, so objects can move less than 1 unit 
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = (short)x; // start from 0
	dwPos.Y = (short)y; // start from 0
	SetConsoleCursorPosition(hCon, dwPos);
}

void toolKit::terminal_clear()
{
	system("cls");
}

int toolKit::BetterRead(int &data, string inputS, int locateX, int locateY)
{
	int check;
	while (true)
	{
		
		gotoxy(locateX, locateY);
		cout << "                                       ";
		gotoxy(locateX, locateY);
		cout << inputS;
		cin >> check;
		if (!(cin.fail()))
		{
			break;
		}
		else
		{
			string garbage;
			gotoxy(locateX, locateY);
			cout << "                                       ";
			gotoxy(locateX, locateY);
			cout << "輸入錯誤，請重新輸入!!";
			cin.clear();
			cin.sync();
			cin >> garbage;
			sleep(3);
		}
	}
	data = check;
	return check;
}