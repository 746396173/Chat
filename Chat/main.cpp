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
	SetConsoleTitle("Chat-2017�����ִ�ѧ�������9��º賬����");
	string QQ = "QQ";
	string WeiChat = "WeiChat";
	string WeiBo = "WeiBo";
	string Parties = "QQ\\Parties";
	CreateDirectory(QQ.c_str(), NULL);//�����ļ���
	CreateDirectory(WeiChat.c_str(), NULL);
	CreateDirectory(WeiBo.c_str(), NULL);
	CreateDirectory(Parties.c_str(), NULL);
	GetQQ();
	Menu();
	return 0;
}