#ifndef toolKit_h

#define toolKit_h

#include <iostream>
#include <stdio.h>
#include <ctime>
#include <Windows.h>
#include <map>
using namespace std;

class toolKit
{
public:
	static int timeSEED;
	static int shuffleTIME;
	static int playerAmount,Chips;
	static int playerPoint[5];
	static int playerBet[5];
	static bool gameStatus[5];
	int playerCoor[6][5][2] = 
	{
		{{1,1},{12, 1},{23, 1},{34, 1},{45, 1}},
		{{1,28},{12, 28},{23, 28},{34, 28},{45, 28}},
		{{68, 35},{79, 35},{90, 35},{101, 35},{112, 35}} ,
		{{135, 28},{146, 28},{157, 28},{168, 28},{179, 28}},
		{{135, 1},{146, 1},{157, 1},{168, 1},{179, 1}},
		{ {68, 15},{79, 15},{90, 15},{101, 15},{112, 15}} 
	};
	toolKit();
	void toolKitInit();								//初始化
	void startUpPage();								//起動介面
	void pause();									//暫停
	void sleep(double );							//休眠(單位 秒)
	void terminal_clear();							//清除CMD
	void gotoxy(double, double);					//游標前往指定座標
	//Map tool

};

#endif // !toolKit_h