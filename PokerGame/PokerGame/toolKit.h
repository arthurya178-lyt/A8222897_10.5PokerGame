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
	toolKit();
	toolKit(int);
	void pause();
	void sleep(double );
	void terminal_clear();
	void gotoxy(double, double);
	template <typename T>
	void drawGame(T* , int, int );
	void drawCard(int ,int );
};

#endif // !toolKit_h