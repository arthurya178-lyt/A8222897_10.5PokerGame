#pragma once
#include "PokerCard.h"
#include "toolKit.h"
#include <vector>

class Poker : toolKit
{
private:
	vector<vector<int>> Number = 
	{
		{1,2,3,4,5,6,7,8,9,10,11,12,13},
		{1,2,3,4,5,6,7,8,9,10,11,12,13},
		{1,2,3,4,5,6,7,8,9,10,11,12,13},
		{1,2,3,4,5,6,7,8,9,10,11,12,13},
	};
	
public:
	PokerCard card[52];
	Poker();
	void drawCard(int coorX, int coorY, const PokerCard &Card);
	void PrintAll();
};

