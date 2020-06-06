#include "Poker.h"
#include "PokerCard.h"
#include "toolKit.h"
#include <cstdlib>
#include <ctime> 
#include <iomanip>
#include <vector>
Poker::Poker()
{
	int PokerPlace = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <=13; j++)
		{
			card[PokerPlace].setCard(j);
			card[PokerPlace].setSuit(i+1);
			PokerPlace += 1;
		}
	}
	card[PokerPlace].setCard(0);				//設定覆蓋卡
	card[PokerPlace].setSuit(5);
	shuffle();									//洗牌
}

void Poker::shuffle()
{
	srand(unsigned int(time(NULL)));
	for (int i = 51; i >= 0; i--)
	{
		int chLocate = rand() % 52;
		PokerCard buff = card[i];
		card[i] = card[chLocate];
		card[chLocate] = buff;
	}
}



void Poker::drawCard(int coorX, int coorY, const PokerCard &GCard)
{
	switch (GCard.getSuit())
	{
	case 1:
		gotoxy(coorX, coorY);	  cout << "***********";
		gotoxy(coorX, coorY + 1); cout << "*    *    *";
		gotoxy(coorX, coorY + 2); cout << "*   ***   *";
		gotoxy(coorX, coorY + 3); cout << "*  *****  *";
		gotoxy(coorX, coorY + 4); cout << "*  *****  *";
		gotoxy(coorX, coorY + 5); cout << "*    *    *";
		gotoxy(coorX, coorY + 6); cout << "*   ***   *";
		gotoxy(coorX, coorY + 7); cout << "*   " << setw(3) <<GCard.toString() << "   *";
		gotoxy(coorX, coorY + 8); cout << "***********";
		break;
	case 2:
		gotoxy(coorX, coorY);	  cout << "***********";
		gotoxy(coorX, coorY + 1); cout << "*    *    *";
		gotoxy(coorX, coorY + 2); cout << "*   ***   *";
		gotoxy(coorX, coorY + 3); cout << "*  *****  *";
		gotoxy(coorX, coorY + 4); cout << "*  *****  *";
		gotoxy(coorX, coorY + 5); cout << "*   ***   *";
		gotoxy(coorX, coorY + 6); cout << "*    *    *";
		gotoxy(coorX, coorY + 7); cout << "*   " << setw(3) << GCard.toString() << "   *";
		gotoxy(coorX, coorY + 8); cout << "***********";
		break;
	case 3:
		gotoxy(coorX, coorY);	  cout << "***********";
		gotoxy(coorX, coorY + 1); cout << "*  *   *  *";
		gotoxy(coorX, coorY + 2); cout << "* *** *** *";
		gotoxy(coorX, coorY + 3); cout << "* ******* *";
		gotoxy(coorX, coorY + 4); cout << "*  *****  *";
		gotoxy(coorX, coorY + 5); cout << "*   ***   *";
		gotoxy(coorX, coorY + 6); cout << "*    *    *";
		gotoxy(coorX, coorY + 7); cout << "*   " << setw(3) << GCard.toString() << "   *";
		gotoxy(coorX, coorY + 8); cout << "***********";
		break;
	case 4:
		gotoxy(coorX, coorY);	  cout << "***********";
		gotoxy(coorX, coorY + 1); cout << "*   ***   *";
		gotoxy(coorX, coorY + 2); cout << "*   ***   *";
		gotoxy(coorX, coorY + 3); cout << "* ******* *";
		gotoxy(coorX, coorY + 4); cout << "* ******* *";
		gotoxy(coorX, coorY + 5); cout << "*    *    *";
		gotoxy(coorX, coorY + 6); cout << "*   ***   *";
		gotoxy(coorX, coorY + 7); cout << "*   " << setw(3) << GCard.toString() << "   *";
		gotoxy(coorX, coorY + 8); cout << "***********";
		break;
	case 5:
		gotoxy(coorX, coorY);	  cout << "***********";
		gotoxy(coorX, coorY + 1); cout << "**       **";
		gotoxy(coorX, coorY + 2); cout << "* *     * *";
		gotoxy(coorX, coorY + 3); cout << "*  *   *  *";
		gotoxy(coorX, coorY + 4); cout << "*   ***   *";
		gotoxy(coorX, coorY + 5); cout << "*  *   *  *";
		gotoxy(coorX, coorY + 6); cout << "* *     * *";
		gotoxy(coorX, coorY + 7); cout << "**       **";
		gotoxy(coorX, coorY + 8); cout << "***********";
		break;
		break;
	}
	
}
void Poker::drawOut(int player,int locate,int index)
{
	drawCard(playerCoor[player][locate][0], playerCoor[player][locate][1], card[index]);
}

void Poker::drawPlayerAll(int player)
{
	if (player != 5)
	{
		gotoxy(playerCoor[player][0][0] - 1, playerCoor[player][0][1] - 1);
		cout << "--Player:" << player+1 << " --" << "Player Point:" << fixed << setprecision(1) << countPlayerPoint(player) << "--";
		for (int i = 0; i < 5; i++)
			drawCard(playerCoor[player][i][0], playerCoor[player][i][1], card[Player_card[player][i]]);
	}
	else
	{
		gotoxy(playerCoor[player][0][0] - 1, playerCoor[player][0][1] - 1);
		cout << "--Dealer--" << "Player Point:" << fixed << setprecision(1) << countPlayerPoint(player) << "--";
		for (int i = 0; i < 5; i++)
			drawCard(playerCoor[player][i][0], playerCoor[player][i][1], card[Player_card[player][i]]);
	}
}

double Poker::countPlayerPoint(int player)
{
	double totalPoint = 0;
	for (int i = 0; i < 5;i++)
	{
		int point = card[Player_card[player][i]].getCard();
		if (point >= 11)
		{
			totalPoint += 0.5;
		}
		else
		{
			totalPoint += point;
		}
	}
	return totalPoint;
}