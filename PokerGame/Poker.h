#pragma once
#include "PokerCard.h"
#include "toolKit.h"
#include <vector>
#include<map>
class Poker : toolKit
{
private:
	
	int playerLocate[6] = {0,0,0,0,0,0};								//���b�o�P���P��(INDEX = ���a�s��)
	int drawingCard = 0;												//���b������d��
	void printCard(int coorX, int coorY, const PokerCard &Card);		//�L�X��i�d��
public:
	int playerStatus[6] = { -5,-5,-5,-5,-5,-5 };						//���a��d���A
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
	void pcDecision();									//�q�����a��d
	int JudgePc();										//���a���_(return = 1(�Q�I�b) 0(���z) -1 (�z�I))
	int playerDecision(int player);						//���a�[�P���(return=3(�L����)2(��i�Q�I�b)1(�Q�I�b),0(���z),-1(�z�I)-2(�L�����z))
	void allDecision();									//�������a�[�P���
	int JudgePlayer(int player);						//�˴����a�O�_���(return=2(�L����)1(�ӧQ),0(����),-1(����))
	void throwFirstCard();								//���������a�o�Ĥ@�i�d
	void betDown();										//�Ҧ����a�U�`
	void result();										//����ӭt
	bool allPlayerStatus();								//�˴��O�_�٦����a���~��
	template<typename T,typename U>
	int mapLowAmount(int number, map<T, U> &map2);
};

