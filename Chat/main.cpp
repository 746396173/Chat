#include "stdafx.h"
#include<iostream>
#include"chat.h"
#include"tools.h"
#include"GreedySnake.h"
#include<Windows.h>
#include<string>
using namespace std;

int main()
{
	SetConsoleTitle("Chat-2017级吉林大学软件工程9班陈鸿超制作");
	string QQ = "QQ";
	string WeiChat = "WeiChat";
	string WeiBo = "WeiBo";
	string Parties = "QQ\\Parties";
	CreateDirectory(QQ.c_str(), NULL);//创建文件夹
	CreateDirectory(WeiChat.c_str(), NULL);
	CreateDirectory(WeiBo.c_str(), NULL);
	CreateDirectory(Parties.c_str(), NULL);
	GetQQ();
	Menu();
	return 0;
}