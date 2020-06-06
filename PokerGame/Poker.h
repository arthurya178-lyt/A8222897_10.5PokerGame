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
	void shuffle();										//�~�P
	void drawOut(int player, int locate,int index);     //�L�X��i�P (���aID,�P��m,�P��)
	void drawPlayerAll(int player);						//�L�X�@�쪱�a�� (���aID)
	double countPlayerPoint(int player);				//�p���Ӫ��a�ثe�I��
};

