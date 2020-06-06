#include "PokerCard.h"
#include <iostream>
using namespace std;
PokerCard::PokerCard()
{

}
PokerCard::PokerCard(int suit, int card)
{
	_suit = suit;
	_card = card;
}
void PokerCard::setCard(int suit, int card)
{
	_suit = suit;
	_card = card;
}
int PokerCard::getSuit() const
{
	return _suit;
}
int PokerCard::getCard() const
{
	return _card;
}
string PokerCard::getStringCard() const
{
	string stringCard;
	switch (_card)
	{
	case 11:
		stringCard = "J";
		break;
	case 12:
		stringCard = "Q";
		break;
	case 13:
		stringCard = "K";
		break;
	default:
		stringCard = to_string(_card);
		break;
	}
	return stringCard;
}

void PokerCard::setSuit(int suit)
{
	_suit = suit;
}
void PokerCard::setCard(int card)
{
	_card = card;
}
string PokerCard::toString() const
{
	stringstream ss;
	string SCard = getStringCard();
	switch (_suit)
	{
	case 1:
		ss << (char)'\6';
		ss << SCard;
		break;
	case 2:
		ss << (char)'\3';
		ss << SCard;
		break;
	case 3:
		ss << (char)'\4';
		ss << SCard;
		break;
	case 4:
		ss << (char)'\5';
		ss << SCard;
		break;

	}
	return ss.str();
	
}
int PokerCard::pointPlus(const PokerCard &card2) const
{
	return _card + card2.getCard();
}

PokerCard& PokerCard::operator=(const PokerCard &card2)
{
	this->_card = card2.getCard();
	this->_suit = card2.getSuit();

	return *this;
}