#pragma once
#include <string>
#include<sstream>

using namespace std;
class PokerCard

{
private:
	int _suit, _card;									//花色及卡號
public:
	PokerCard();										//無內容建構子
	PokerCard(int suit,int card);						//設定花色及數字
	void setCard(int suit, int card);					//設定花色及數字
	int getSuit() const;								//取得花色
	int getCard() const;								//取得卡號
	string getStringCard() const;						//10 11 12 轉 J Q K
	void setSuit(int suit);								//設定花色
	void setCard(int card);								//設定卡號
	string toString() const;							//取得花色配卡號
	double convertTo10_5();								//轉成10點半的點數
	int pointPlus (const PokerCard &card2) const;		//數值相加
	PokerCard& operator=(const PokerCard &card2);		//指定運算子重載
};

