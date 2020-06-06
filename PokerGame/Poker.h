#pragma once
#include "PokerCard.h"
#include "toolKit.h"
#include <vector>

class Poker : toolKit
{
private:
	int playerLocate[6] = {0,0,0,0,0,0};								//正在發牌的牌位(INDEX = 玩家編號)
	int drawingCard = 0;												//正在抽取的卡號
	void printCard(int coorX, int coorY, const PokerCard &Card);		//印出單張卡片
public:
	int playerStatus[6] = { 0,0,0,0,0,0 };								//玩家抽卡狀態
	vector<vector<int>> Player_card =									//玩家持有的卡牌(52是卡背(0))
	{
		{52,52,52,52,52},
		{52,52,52,52,52},
		{52,52,52,52,52},
		{52,52,52,52,52},
		{52,52,52,52,52},
		{52,52,52,52,52},
	};
	void init(bool checkOut = FALSE);					//撲克牌初始化(確認重置)
	PokerCard card[53];									//定義一副撲克牌
	Poker();											//撲克牌初始化定義(1~13,4個花色,52是卡背(0))
	void shuffle();										//洗牌
	void printPlayer(int player);						//印出一位玩家的 (玩家ID)
	void printAllPlayer();								//印出所有玩家的卡
	double countPlayerPoint(int player);				//計算單個玩家目前點數
	void drawPoker(int player);							//為某位玩家抽卡
	int playerDecision(int player);						//玩家加牌選擇(return=2(過五關)1(十點半),0(未爆),-1(爆點))
	void allDecision();									//全部玩家加牌選擇
	int JudgePlayer(int player);						//檢測玩家是否獲勝(return=2(過五關)1(勝利),0(平局),-1(失敗))
};

