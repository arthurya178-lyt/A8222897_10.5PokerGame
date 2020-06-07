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

int playerPoint[5] = { 0,0,0,0,0 };
Poker Poker1;
PokerCard testCard1(2, 11);

void controlPanel()
{
	system("mode con cols=100 lines=50");
	tool.gotoxy(0, 0);
	cout << "1.�ɶ��ü�     = " << tool.timeSEED << endl;
	cout << "2.�~�P����     = " << tool.shuffleTIME << endl;
	cout << "3.���a�H��     = " << tool.playerAmount << endl;
	cout << "4.���a��¦�w�X = " << tool.Chips << endl;
	cout << "5.���a�I��     =  1." << tool.playerPoint[0] << " 2." << tool.playerPoint[1] << " 3." << tool.playerPoint[2] << " 4." << tool.playerPoint[3] << " 5." << tool.playerPoint[4];
	cout << 
}
void gameFunction()
{
	system("mode con cols=190 lines=50");
	while (Poker1.allPlayerStatus())
	{

		Poker1.printAllPlayer();
		Poker1.betDown();
		Poker1.throwFirstCard();
		Poker1.allDecision();
		Poker1.pcDecision();
		Poker1.result();
		tool.pause();
		tool.sleep(5);
		Poker1.init(TRUE);
	}
	
}

int main()
{

	tool.startUpPage();
	gameFunction();
	
	
}