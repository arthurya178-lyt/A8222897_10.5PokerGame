#pragma once
#include "PokerCard.h"
#include "toolKit.h"
#include <vector>

class Poker : toolKit
{
private:
	vector<vector<int>> Player_card =
	{
		{1,2,3,4,5},
		{4,5,6,7,8},
		{9,10,11,12,13},
		{14,15,16,17,18},
		{19,20,21,22,23},
		{24,25,26,17,52},
	};
	void drawCard(int coorX, int coorY, const PokerCard &Card);
public:
	PokerCard card[53];
	Poker();
	void shuffle();										//洗牌
	void drawOut(int player, int locate,int index);     //印出單張牌 (玩家ID,牌位置,牌號)
	void drawPlayerAll(int player);						//印出一位玩家的 (玩家ID)
	double countPlayerPoint(int player);				//計算單個玩家目前點數
};

