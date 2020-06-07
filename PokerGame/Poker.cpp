#include "Poker.h"
#include "PokerCard.h"
#include "toolKit.h"
#include <cstdlib>
#include <ctime> 
#include <iomanip>
#include <vector>
#include <map>
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
		for (int i = 0; i < 5; i++)
			playerBet[i] = 0;
		printAllPlayer();
		shuffle();
	}
}

void Poker::shuffle()
{
	timeSEED = unsigned int(time(NULL));
	srand(timeSEED);
	shuffleTIME = (rand() % 6);
	for (int x = 0; x < shuffleTIME; x++)
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
		cout << "--閒家:" << player + 1 << " --" << "點數 :" << setw(4) << fixed << setprecision(1) << countPlayerPoint(player) << "--";cout << "持有籌碼:" << playerPoint[player] <<"--下注金額:" << playerBet[player] <<"-----";
		for (int i = 0; i < 5; i++)
			printCard(playerCoor[player][i][0], playerCoor[player][i][1], card[Player_card[player][i]]);
	}
	else
	{
		gotoxy(playerCoor[player][0][0] - 1, playerCoor[player][0][1] - 1);
		cout << "--莊家--" << "點數 :" << setw(4) << fixed << setprecision(1) << countPlayerPoint(player) << "--";
		for (int i = 0; i < 5; i++)
			printCard(playerCoor[player][i][0], playerCoor[player][i][1], card[Player_card[player][i]]);
	}
}

void Poker::printAllPlayer()
{
	for (int i = 0; i < playerAmount; i++)
	{
		if(gameStatus[i])
			printPlayer(i);
	}
	printPlayer(5);
}

double Poker::countPlayerPoint(int player)
{
	double totalPoint = 0;
	for (int i = 0; i < 5; i++)
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

int Poker::JudgePc()
{
	const int player = 5;
	if (countPlayerPoint(player) == 10.5)
	{
		gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
		cout << "--- 十點半 --- 點數: " << setw(4) << fixed << setprecision(1) << countPlayerPoint(player) << "---";
		return 1;
	}
	else if (countPlayerPoint(player) < 10.5)
	{
		gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
		cout << "--- 未爆 --- 點數: " << setw(4) << fixed << setprecision(1) << countPlayerPoint(player) << "---";
		return 0;
	}
	else
	{
		gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
		cout << "--- 爆點 --- 點數:" << setw(4) << fixed << setprecision(1) << countPlayerPoint(player) << "---";
		return -1;
	}
}

int Poker::playerDecision(const int player)
{
	int status = 0;
	if (gameStatus[player] || player == 5)
	{
		bool keep = true;
		for (int i = 0; i < 4; i++)
		{

			bool loopKeep = true;
			do
			{
				char decision;
				gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
				cout << "                                                               ";
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
			{
				status = 0;
				gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
				cout << "--- 未爆 --- 點數: " << setw(4) << fixed << setprecision(1) << countPlayerPoint(player) << "---";
				break;
			}
			else if (i == 3 && countPlayerPoint(player) > 10.5)
			{
				status = -2;
				gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
				cout << "--- 過五關 爆點--- 點數: " << setw(4) << fixed << setprecision(1) << countPlayerPoint(player) << "---";
				break;
			}
			else if (countPlayerPoint(player) > 10.5)
			{
				status = -1;
				gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
				cout << "已超過10點半，您已爆點了!!!";
				sleep(3);
				gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
				cout << "--- 爆點 --- 點數:" << setw(4) << fixed << setprecision(1) << countPlayerPoint(player) << "---";
				break;
			}
			else if (countPlayerPoint(player) == 10.5 && i == 0)
			{
				status = 2;
				gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
				cout << "--- 兩張十點半 --- 點數: " << setw(4) << fixed << setprecision(1) << countPlayerPoint(player) << "---";
				break;
			}
			else if (countPlayerPoint(player) == 10.5)
			{
				status = 1;
				gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
				cout << "--- 十點半 --- 點數: " << setw(4) << fixed << setprecision(1) << countPlayerPoint(player) << "---";
				break;
			}
			else if (i == 3)
			{
				status = 3;
				gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
				cout << "--- 過五關 --- 點數: " << setw(4) << fixed << setprecision(1) << countPlayerPoint(player) << "---";
				break;
			}
		}
	}
	return status;
}

void Poker::pcDecision()														//莊家選卡    (心累區)
{
	srand(timeSEED);
	while (rand() % 10)
		rand();
	drawPoker(5);
	while(true)
	{
		bool keep = true;
		map<double, int> arrayOfCard = { {0.5,12}, {1,4},{2,4},{3,4},{4,4},{5,4},{6,4},{7,4},{8,4},{9,4},{10,4} };
		for (int i = 0; i < drawingCard; i++)
		{
			arrayOfCard[card[i].convertTo10_5()]--;
		}
		double existCard = 52 - drawingCard;
		double needPoint = 10.5 - countPlayerPoint(5);
		double needAmount = mapLowAmount(needPoint, arrayOfCard);
		int targetProbability = int(needAmount / existCard * 1000.0);
		int random = rand() % 1000;
		for (int i = 0; i < playerAmount; i++)
		{
			if (countPlayerPoint(i) <= countPlayerPoint(5))
				keep = false;
		}
		if(random <= targetProbability && keep)
		{
			drawPoker(5);
			printPlayer(5);
		}
		else
		{
			break;
		}
	};
	printPlayer(5);
	JudgePc();
	sleep(3);
}

void Poker::allDecision()
{
	for(int i = 0 ;i < playerAmount;i++)
		playerStatus[i] = playerDecision(i);
	//playerStatus[5] = playerDecision(5);                   //人工DECISION 判斷  手動輸入
}

int Poker::JudgePlayer(int player)
{
	if (playerStatus[player] == 3)													//過五關3倍
	{
		return 3;
	}
	else if (playerStatus[player] == 2)												//10.5兩倍
	{
		return 2;
	}
	else if (playerStatus[player] == -2)											//過五關爆牌賠2倍
	{
		return -1;
	}
	else if ((playerStatus[player] >= 0 && countPlayerPoint(player) > countPlayerPoint(5)) || (countPlayerPoint(5) > 10.5 && playerStatus[player] >= 0))//贏牌原賭注賠償
	{
		return 1;
	}
	else if (playerStatus[player] <= 0 && countPlayerPoint(player) <= countPlayerPoint(5))//平手及輸牌 莊家勝
	{
		return 0;
	}
	return 0;
}

void Poker::throwFirstCard()
{
	for (int i = 0; i < playerAmount; i++)
		drawPoker(i);
	printAllPlayer();
}
void Poker::betDown()
{
	for (int player = 0; player < playerAmount; player++)
	{
		if (playerPoint[player] > 0)
		{
			stringstream ss;
			int check;
			string buff;
			while (true)
			{
				check = 0;
				buff = "";
				ss.clear();
				gameStatus[player] = true;
				gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
				cout << "玩家" << player + 1 << "請下注  剩餘籌碼: " << playerPoint[player] << " 金額: "; getline(cin, buff);
				ss << buff;
				ss >> check;
				if (check > playerPoint[player])
				{
					gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
					cout << "                                                               ";
					gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
					cout << "您的籌碼不足，請重新下注!!";
					sleep(3);
					gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
					cout << "                                                               ";
				}
				else if (check <= 0)
				{
					gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
					cout << "                                                               ";
					gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
					cout << "籌碼不可小於等於0，請重新下注!!";
					sleep(3);
					gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
					cout << "                                                               ";
				}
				else
				{
					gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
					cout << "                                                               ";
					playerBet[player] = check;
					printPlayer(player);
					break;
				}
			}
		}
		else
		{
			gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
			cout << "                                                               ";
			gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
			cout << "您的籌碼不足，無法下注!!";
			gameStatus[player] = false;
			sleep(3);
			gotoxy(playerCoor[player][0][0], playerCoor[player][0][1] + 9);
			cout << "                                                               ";
		}
	}
}

void Poker::result()
{
	for (int player = 0; player < playerAmount; player++)
	{
		if (gameStatus[player])
		{
			switch (JudgePlayer(player))
			{
			case -1:
				playerPoint[player] -= playerBet[player] * 2;
				break;
			case 0:
				playerPoint[player] -= playerBet[player];
				break;
			case 1:
				playerPoint[player] += playerBet[player];
				break;
			case 2:
				playerPoint[player] += playerBet[player] * 2;
				break;
			case 3:
				playerPoint[player] += playerBet[player] * 3;
				break;
			}
		}
	}
	printAllPlayer();
}

bool Poker::allPlayerStatus()
{
	for (int i = 0; i < playerAmount; i++)
	{
		if (playerPoint[i] > 0)
			return true;
	}
		return false;
}

template<typename T, typename U>
int Poker::mapLowAmount(int number, map<T, U> &map2)
{
	int amount = 0;
	double list[11] = { 0.5,1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 11; i++)
	{
		if (list[i] < number)
			amount += map2[list[i]];
	}
	return amount;
}