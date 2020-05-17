#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
//Class 
#include "toolKit.h"
#include "PokerCard.h"

using namespace std;
toolKit tool(1);
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


int main()
{
	system(" mode con cols=200 lines=50");
	const int displayDimension1 = 50, displayDimension2 = 200;
	vector<vector<char>> display(displayDimension1,vector<char>(displayDimension2));
	for (int i = 0; i < displayDimension1; i++)
		display[i].push_back('*');
	PokerCard testCard1(2, 11);
	cout << testCard1.toString();
	tool.sleep(3);
	testDrawCard(129, 41, "K");
	testDrawCard(68, 41, "K");
	testDrawCard(19, 41, "K");

	tool.pause();
}