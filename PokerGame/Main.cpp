#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <map>
//Class 
#include "PokerCard.h"
#include "Poker.h"
#include "toolKit.h"

using namespace std;
toolKit tool;

Poker Poker1;
PokerCard testCard1(2, 11);

void controlPanel();
void gameFunction();

int main()
{

	tool.startUpPage();
	string keyCode;
	while (Poker1.allPlayerStatus())
	{
		gameFunction();
		keyCode = Poker1.jump();
		if (keyCode == "admin")
			controlPanel();
		else if (keyCode == "exit")
			break;
	}
}









void gameFunction()
{
	system("mode con cols=190 lines=50");
	Poker1.init(TRUE);
	Poker1.printAllPlayer();
	Poker1.betDown();
	Poker1.throwFirstCard();
	Poker1.allDecision();
	Poker1.pcDecision();
	Poker1.result();
	tool.pause();
	tool.sleep(2);

}

void controlPanel()
{
	while (true)
	{
		tool.terminal_clear();
		int __controlCode = 8;
		string checkStr, checkStr2;
		system("mode con cols=100 lines=50");
		tool.gotoxy(0, 0);
		cout << "請選擇功能" << endl;
		cout << "1.時間亂數     = " << tool.timeSEED << endl;
		cout << "2.洗牌次數     = " << tool.shuffleTIME << endl;
		cout << "3.玩家人數     = " << tool.playerAmount << endl;
		cout << "4.玩家基礎籌碼 = " << tool.Chips << endl;
		cout << "5.玩家點數     =  1." << tool.playerPoint[0] << " 2." << tool.playerPoint[1] << " 3." << tool.playerPoint[2] << " 4." << tool.playerPoint[3] << " 5." << tool.playerPoint[4] << endl;
		cout << "6.遊玩狀態初始化" << endl;
		cout << "7.全遊戲初始化" << endl;
		cout << "8.離開控制介面" << endl << endl;
		cout << "請輸入控制編碼:"; cin >> __controlCode;
		switch (__controlCode)
		{
		case 1:
			int newIndex;
			cout << "1.手動輸入新的時間亂數 2.自動產生新的時間亂數:"; cin >> newIndex;
			switch (newIndex)
			{
			case 1:
				cout << "請輸入新的時間亂數:"; cin >> tool.timeSEED;
				cout << endl;
				cout << "[修改完成]";
				break;
			case 2:
				cout << "新的時間亂數產生中..." << endl;
				tool.timeSEED = unsigned int(time(NULL));
				tool.sleep(1.5);
				cout << "[修改完成]";
			}
			break;
		case 2:
			cout << "請輸入新的洗牌次數:"; cin >> tool.shuffleTIME;
			cout << endl;
			cout << "[修改完成]";
			break;
		case 3:
			cout << "請輸入新的玩家人數:"; cin >> tool.playerAmount;
			cout << endl;
			cout << "[修改完成]";
			break;
		case 4:
			cout << "請輸入新的基礎籌碼:"; cin >> tool.Chips; cout << endl;
			cout << "[修改完成]";
			break;
		case 5:
			int player;
			cout << "請輸入要修改的玩家:"; cin >> player;
			cout << "請輸入新的點數:"; cin >> tool.playerPoint[player - 1];
			cout << endl;
			cout << "[修改完成]";
			break;
		case 6:
			cout << "請確認是否要初始化(輸入True):"; cin >> checkStr; cout << endl;
			if (checkStr == "True")
			{
				Poker1.init(true);
				cout << "[初始化完成]" << endl;
			}
			else
				cout << "[初始化失敗，輸入錯誤]" << endl;
			break;
		case 7:
			cout << "這個指令會將遊戲重置" << endl;
			cout << "[警告]請確認是否要初始化(輸入True):"; cin >> checkStr; cout << endl;
			cout << "[警告]請重複確認是否要初始化(輸入tRUE):"; cin >> checkStr2; cout << endl;
			if (checkStr == "True" && checkStr2 == "tRUE")
			{
				Poker1.init(true);
				tool.toolKitInit();
				cout << "[初始化完成]" << endl;
			}
			else
				cout << "[初始化失敗，輸入錯誤]" << endl;
			break;
		case 8:
			cout << "正在關閉控制介面..." << endl;
		default:
			break;
		}
		tool.sleep(30);
		tool.terminal_clear();
		if (__controlCode == 8)
			break;
	}

}