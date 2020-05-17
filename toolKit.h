#pragma once

#include <iostream>
#include <stdio.h>
#include <ctime>
#include <Windows.h>
using namespace std;

class toolKit
{
public:
	toolKit(int);
	static void pause();
	static void sleep(double timeS);
	static void terminal_clear();
	static void gotoxy(double x, double y);
	template <typename T>
	static void drawGame(T *Array, int vector1, int vector2);
	static void drawCard(int coordinateX,int coordinateY);
};

toolKit::toolKit(int i = 0)
{
	
}
void toolKit::pause()
{
	string dummy;
	cin >> dummy;
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
	dwPos.X = x; // start from 0
	dwPos.Y = y; // start from 0
	SetConsoleCursorPosition(hCon, dwPos);
}

void toolKit::terminal_clear()
{
	system("cls");
}

template <typename T>
void toolKit::drawGame(T *Array, int vector1, int vector2)
{
	for (int i = 0; i < vector1; i++)
	{
		for (int j = 0; j < vector2; j++)
		{
			gotoxy(j,i); printf("%c", Array[i][j]);
		}
	}

}

void toolKit::drawCard(int coordinateX, int coordinateY)
{
}


/*
template <typename T>
void toolKit::drawGame(T *Array, int vector1, int vector2)
{
	for (int i = 0; i < vector1; i++)
	{
		for (int j = 0; j < vector2; j++)
		{
			printf("%c", Array[i][j]);
		}
		printf("\n");
	}
}
*/