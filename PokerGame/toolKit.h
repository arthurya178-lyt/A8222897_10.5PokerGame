#ifndef toolKit_h

#define toolKit_h

#include <iostream>
#include <stdio.h>
#include <ctime>
#include <Windows.h>
using namespace std;

class toolKit
{
public:
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
	toolKit(int);
	void pause();
	void sleep(double );
	void terminal_clear();
	void gotoxy(double, double);
	template <typename T>
	void drawGame(T* , int, int );
	//void drawCard(int);
};

#endif // !toolKit_h