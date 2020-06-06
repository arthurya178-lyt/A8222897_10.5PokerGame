#pragma once
#include "PokerCard.h"
#include "toolKit.h"
#include <vector>

class Poker : toolKit
{
private:
	int playerLocate[6] = {0,0,0,0,0,0};								//���b�o�P���P��(INDEX = ���a�s��)
	int drawingCard = 0;												//���b������d��
	void printCard(int coorX, int coorY, const PokerCard &Card);		//�L�X��i�d��
public:
	int playerStatus[6] = { 0,0,0,0,0,0 };								//���a��d���A
	vector<vector<int>> Player_card =									//���a�������d�P(52�O�d�I(0))
	{
		{52,52,52,52,52},
		{52,52,52,52,52},
		{52,52,52,52,52},
		{52,52,52,52,52},
		{52,52,52,52,52},
		{52,52,52,52,52},
	};
	void init(bool checkOut = FALSE);					//���J�P��l��(�T�{���m)
	PokerCard card[53];									//�w�q�@�Ƽ��J�P
	Poker();											//���J�P��l�Ʃw�q(1~13,4�Ӫ��,52�O�d�I(0))
	void shuffle();										//�~�P
	void printPlayer(int player);						//�L�X�@�쪱�a�� (���aID)
	void printAllPlayer();								//�L�X�Ҧ����a���d
	double countPlayerPoint(int player);				//�p���Ӫ��a�ثe�I��
	void drawPoker(int player);							//���Y�쪱�a��d
	int playerDecision(int player);
	void allDecision();
};

