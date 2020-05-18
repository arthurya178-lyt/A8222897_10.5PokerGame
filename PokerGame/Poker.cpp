#include "Poker.h"
#include "PokerCard.h"
#include "toolKit.h"
#include <vector>
Poker::Poker()
{
	int PokerPlace = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			card[PokerPlace].setCard(Number[i][j]);
			card[PokerPlace].setSuit(i+1);
			PokerPlace += 1;
		}
	}
}
void Poker::drawCard(int coorX, int coorY, const PokerCard &GCard)
{
	gotoxy(coorX, coorY);	  cout << "***********";
	gotoxy(coorX, coorY + 1); cout << "*    *    *";
	gotoxy(coorX, coorY + 2); cout << "*   ***   *";
	gotoxy(coorX, coorY + 3); cout << "*  *****  *";
	gotoxy(coorX, coorY + 4); cout << "*  *****  *";
	gotoxy(coorX, coorY + 5); cout << "*    *    *";
	gotoxy(coorX, coorY + 6); cout << "*   ***   *";
	gotoxy(coorX, coorY + 7); cout << "*    " << GCard.getStringCard() << "    *";
	gotoxy(coorX, coorY + 8); cout << "***********";
}

void Poker::PrintAll()
{
	for(int i = 0 ; i< 52;i++)
		cout << card[i].toString();
}