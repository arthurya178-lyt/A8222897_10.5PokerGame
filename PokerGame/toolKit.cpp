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
	gotoxy(18, 15);cout  << "                     �w��C�� \"10�I�b\"";
	gotoxy(18, 16); cout << "    �C������:A,2,3,4,5,6,7,8,9,10�@���O���@�ܤQ�I�CJ,Q,K���b�I"     ;
	gotoxy(18, 17); cout << "   ���a�i�H�@���[�P�A���Y�W�L�Q�I�b�A�Y�u�z�P�v(Busted)�A���a�߽�"  ;
	gotoxy(18, 18); cout << "     ���a�խY�� �@��10�[�@��J,Q��K���Q�I�b�A���a�߽�2�����`"       ;
	gotoxy(18, 19); cout << " �Y�G���a�@�����i�P�Ӥ����u�z�P�v�A�١u�L�����v�A���a�߽�3�����`" ;
	gotoxy(18, 20); cout << "        �Y�G���a�@�����i�P�ӫo�w�u�z�P�v�A���a�߽�2�����`"        ;
	gotoxy(18, 21); cout << "              �Y���a�P���a�I�ƬۦP�A�h���a�ӡA���a�߽�"             ;
	gotoxy(18, 30); cout << "                       [[[[[�]�w]]]]]";
	error1:
	gotoxy(18, 31); cout << "                  [���a�H��](�w�]1�H,�ܦh���H) :"; getline(cin,chPA);
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
			gotoxy(18, 31); cout << "                  [��J���~,�г]�Ʀr�p�󵥩�5,�j��0]           ";
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
	gotoxy(18, 32); cout << "                       [��l�w�X](�w�]5000):"; getline(cin,chChips);
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
			gotoxy(18, 32); cout << "                  [��J���~,�г]�Ʀr�j��0,�p��20��]            ";
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
	gotoxy(18, 34); cout << "                       [�] �w �� ��]";
	gotoxy(18, 38); cout << "                       [��ENTER�}�l�C��]";
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
			cout << "��J���~�A�Э��s��J!!";
			cin.clear();
			cin.sync();
			cin >> garbage;
			sleep(3);
		}
	}
	data = check;
	return check;
}