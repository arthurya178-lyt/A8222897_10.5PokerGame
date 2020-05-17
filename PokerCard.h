#pragma once
#include <string>
#include<sstream>

using namespace std;
class PokerCard
{
private:
	int _suit, _card;
public:
	PokerCard(int suit,int card);
	void setCard(int suit, int card);
	int getSuit() const;
	int getCard() const;
	string getStringCard() const;
	void setSuit(int suit);
	void setCard(int card);
	string toString() const;
	int pointPlus (const PokerCard &card2) const;
};

