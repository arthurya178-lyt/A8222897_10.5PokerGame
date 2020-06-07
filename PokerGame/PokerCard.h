#pragma once
#include <string>
#include<sstream>

using namespace std;
class PokerCard

{
private:
	int _suit, _card;									//���Υd��
public:
	PokerCard();										//�L���e�غc�l
	PokerCard(int suit,int card);						//�]�w���μƦr
	void setCard(int suit, int card);					//�]�w���μƦr
	int getSuit() const;								//���o���
	int getCard() const;								//���o�d��
	string getStringCard() const;						//10 11 12 �� J Q K
	void setSuit(int suit);								//�]�w���
	void setCard(int card);								//�]�w�d��
	string toString() const;							//���o���t�d��
	double convertTo10_5();								//�ন10�I�b���I��
	int pointPlus (const PokerCard &card2) const;		//�ƭȬۥ[
	PokerCard& operator=(const PokerCard &card2);		//���w�B��l����
};

