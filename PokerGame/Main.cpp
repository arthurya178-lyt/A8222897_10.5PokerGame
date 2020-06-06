#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
//Class 
#include "PokerCard.h"
#include "Poker.h"
#include "toolKit.h"

using namespace std;
toolKit tool;

int playerPoint[5] = { 0,0,0,0,0 };
Poker Poker1;
PokerCard testCard1(2, 11);

int main()
{
	system("mode con cols=190 lines=50");
	
	Poker1.printAllPlayer();
	tool.sleep(3);
	Poker1.allDecision();
	Poker1.playerDecision(5);
	
	
	tool.pause();
}