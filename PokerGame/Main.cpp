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


Poker test1;
PokerCard testCard1(2, 11);

int main()
{
	system("mode con cols=190 lines=50");
	
	test1.drawPlayerAll(0);
	test1.drawPlayerAll(1);
	test1.drawPlayerAll(2);
	test1.drawPlayerAll(3);
	test1.drawPlayerAll(4);
	test1.drawPlayerAll(5);

	tool.sleep(10);
	test1.drawPlayerAll(3);
	test1.drawPlayerAll(4);
	test1.drawOut(5, 4, 13);
	tool.pause();
}