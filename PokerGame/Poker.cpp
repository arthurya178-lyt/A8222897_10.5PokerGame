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
void Poker::init(bool checkOut)
{
	if (checkOut)
	{
		drawingCard = 0;
		for(int i = 0 ; i < 6; i++)
			for (int j = 0; j < 5; j++)
			{
				Player_card[i][j] = 52;
			}

		for (int i = 0; i < 6; i++)
			playerLocate[i] = 0;
		printAllPlayer();
		shuffle();
	}
}

void Poker::shuffle()
{
	srand(unsigned int(time(NULL)));
	for (int x = 0; x < (rand() % 6); x++)
		for (int i = 51; i >= 0; i--)
		{
			int chLocate = rand() % 52;
			PokerCard buff = card[i];
			card[i] = card[chLocate];
			card[chLocate] = buff;
		}
}



void Poker::printCard(int coorX, int coorY, const PokerCard &GCard)
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


void Poker::printPlayer(int player)
{
	if (player != 5)
	{
		gotoxy(playerCoor[player][0][0] - 1, playerCoor[player][0][1] - 1);
		cout << "--Player:" << player+1 << " --" << "Player Point:" << setw(4) << fixed << setprecision(1) << countPlayerPoint(player) << "--";
		for (int i = 0; i < 5; i++)
			printCard(playerCoor[player][i][0], playerCoor[player][i][1], card[Player_card[player][i]]);
	}
	else
	{
		gotoxy(playerCoor[player][0][0] - 1, playerCoor[player][0][1] - 1);
		cout << "--Dealer--" << "Player Point:" <<setw(4)<< fixed << setprecision(1) << countPlayerPoint(player) << "--";
		for (int i = 0; i < 5; i++)
			printCard(playerCoor[player][i][0], playerCoor[player][i][1], card[Player_card[player][i]]);
	}
}

void Poker::printAllPlayer()
{
	for (int i = 0; i < 6; i++)
	{
		printPlayer(i);
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

void Poker::drawPoker(int player)
{
	Player_card[player][playerLocate[player]] = drawingCard;
	
	playerLocate[player]++;
	drawingCard++;
}


void Poker::playerDecision(int player)
{
	bool keep = true;
	drawPoker(player);
	printPlayer(player);
	for (int i = 0; i < 4; i++)
	{
				
		bool loopKeep = true;
		do
		{
			char decision;
			gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
			cout << "是否要叫牌(Y/N)) :";
			cin >> decision;
			switch (decision)
			{
			case 'Y':
			case 'y':
				drawPoker(player);
				printPlayer(player);
				keep = true;
				loopKeep = false;
				break;
			case 'N':
			case 'n':
				keep = false;
				loopKeep = false;
				break;
			default:
				gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
				cout << "輸入錯誤,請重新輸入!!   ";
				sleep(3);
				break;
			}
			gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
			cout << "                                                    ";
		} while (loopKeep);
		if (!(keep))
			break;
	}
}