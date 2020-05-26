#include "Poker.h"
#include "PokerCard.h"
#include "toolKit.h"
#include <iomanip>
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
	default:
		break;
	}
	
}

void Poker::PrintAll()
{
	for(int i = 0 ; i< 52;i++)
		cout << card[i].toString();
}