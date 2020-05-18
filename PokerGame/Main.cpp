#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
//Class 
#include "PokerCard.h"
#include "Poker.h"
#include "toolKit.h"

using namespace std;
toolKit tool(1);

/*
void testDrawCard(int x,int y,string cardNO)
{
	
	tool.gotoxy(x, y);   cout << "***********";
	tool.gotoxy(x, y+1); cout << "*    *    *";
	tool.gotoxy(x, y+2); cout << "*   ***   *";
	tool.gotoxy(x, y+3); cout << "*  *****  *";
	tool.gotoxy(x, y+4); cout << "*  *****  *";
	tool.gotoxy(x, y+5); cout << "*    *    *";
	tool.gotoxy(x, y+6); cout << "*   ***   *";
	tool.gotoxy(x, y+7); cout << "*    "<< cardNO <<"    *";
	tool.gotoxy(x, y+8); cout << "***********";
}
*/

int main()
{
	vector<vector<int>> coordinate = 
	{
		{
		}
	};
	system(" mode con cols=200 lines=50");
	Poker test1;
	PokerCard testCard1(2, 11);

	test1.drawCard(1, 41, test1.card[24]); //player 3
	test1.drawCard(12, 41, test1.card[20]);
	test1.drawCard(23, 41, test1.card[11]);
	test1.drawCard(34, 41, test1.card[18]);
	test1.drawCard(45, 41, test1.card[21]);

	test1.drawCard(76, 41, test1.card[24]); //player 3
	test1.drawCard(87, 41, test1.card[20]);
	test1.drawCard(98, 41, test1.card[11]);
	test1.drawCard(109, 41, test1.card[18]);
	test1.drawCard(120, 41, test1.card[21]);
	
	test1.drawCard(145, 41, test1.card[51]); //player 4
	test1.drawCard(156, 41, test1.card[21]);
	test1.drawCard(167, 41, test1.card[34]);
	test1.drawCard(178, 41, test1.card[44]);
	test1.drawCard(189, 41, test1.card[38]);
	tool.pause();
}