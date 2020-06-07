#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <map>
//Class 
#include "PokerCard.h"
#include "Poker.h"
#include "toolKit.h"

using namespace std;
toolKit tool;

Poker Poker1;
PokerCard testCard1(2, 11);

void controlPanel();
void gameFunction();

int main()
{

	tool.startUpPage();
	string keyCode;
	while (Poker1.allPlayerStatus())
	{
		gameFunction();
		keyCode = Poker1.jump();
		if (keyCode == "admin")
			controlPanel();
		else if (keyCode == "exit")
			break;
	}
}









void gameFunction()
{
	system("mode con cols=190 lines=50");
	Poker1.init(TRUE);
	Poker1.printAllPlayer();
	Poker1.betDown();
	Poker1.throwFirstCard();
	Poker1.allDecision();
	Poker1.pcDecision();
	Poker1.result();
	tool.pause();
	tool.sleep(2);

}

void controlPanel()
{
	while (true)
	{
		tool.terminal_clear();
		int __controlCode = 8;
		string checkStr, checkStr2;
		system("mode con cols=100 lines=50");
		tool.gotoxy(0, 0);
		cout << "�п�ܥ\��" << endl;
		cout << "1.�ɶ��ü�     = " << tool.timeSEED << endl;
		cout << "2.�~�P����     = " << tool.shuffleTIME << endl;
		cout << "3.���a�H��     = " << tool.playerAmount << endl;
		cout << "4.���a��¦�w�X = " << tool.Chips << endl;
		cout << "5.���a�I��     =  1." << tool.playerPoint[0] << " 2." << tool.playerPoint[1] << " 3." << tool.playerPoint[2] << " 4." << tool.playerPoint[3] << " 5." << tool.playerPoint[4] << endl;
		cout << "6.�C�����A��l��" << endl;
		cout << "7.���C����l��" << endl;
		cout << "8.���}�����" << endl << endl;
		cout << "�п�J����s�X:"; cin >> __controlCode;
		switch (__controlCode)
		{
		case 1:
			int newIndex;
			cout << "1.��ʿ�J�s���ɶ��ü� 2.�۰ʲ��ͷs���ɶ��ü�:"; cin >> newIndex;
			switch (newIndex)
			{
			case 1:
				cout << "�п�J�s���ɶ��ü�:"; cin >> tool.timeSEED;
				cout << endl;
				cout << "[�ק粒��]";
				break;
			case 2:
				cout << "�s���ɶ��üƲ��ͤ�..." << endl;
				tool.timeSEED = unsigned int(time(NULL));
				tool.sleep(1.5);
				cout << "[�ק粒��]";
			}
			break;
		case 2:
			cout << "�п�J�s���~�P����:"; cin >> tool.shuffleTIME;
			cout << endl;
			cout << "[�ק粒��]";
			break;
		case 3:
			cout << "�п�J�s�����a�H��:"; cin >> tool.playerAmount;
			cout << endl;
			cout << "[�ק粒��]";
			break;
		case 4:
			cout << "�п�J�s����¦�w�X:"; cin >> tool.Chips; cout << endl;
			cout << "[�ק粒��]";
			break;
		case 5:
			int player;
			cout << "�п�J�n�ק諸���a:"; cin >> player;
			cout << "�п�J�s���I��:"; cin >> tool.playerPoint[player - 1];
			cout << endl;
			cout << "[�ק粒��]";
			break;
		case 6:
			cout << "�нT�{�O�_�n��l��(��JTrue):"; cin >> checkStr; cout << endl;
			if (checkStr == "True")
			{
				Poker1.init(true);
				cout << "[��l�Ƨ���]" << endl;
			}
			else
				cout << "[��l�ƥ��ѡA��J���~]" << endl;
			break;
		case 7:
			cout << "�o�ӫ��O�|�N�C�����m" << endl;
			cout << "[ĵ�i]�нT�{�O�_�n��l��(��JTrue):"; cin >> checkStr; cout << endl;
			cout << "[ĵ�i]�Э��ƽT�{�O�_�n��l��(��JtRUE):"; cin >> checkStr2; cout << endl;
			if (checkStr == "True" && checkStr2 == "tRUE")
			{
				Poker1.init(true);
				tool.toolKitInit();
				cout << "[��l�Ƨ���]" << endl;
			}
			else
				cout << "[��l�ƥ��ѡA��J���~]" << endl;
			break;
		case 8:
			cout << "���b���������..." << endl;
		default:
			break;
		}
		tool.sleep(30);
		tool.terminal_clear();
		if (__controlCode == 8)
			break;
	}

}