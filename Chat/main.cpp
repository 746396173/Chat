#include "stdafx.h"
#include<iostream>
#include"chat.h"
#include"tools.h"
#include"GreedySnake.h"
#include<Windows.h>
#include<string>
using namespace std;
//extern QQTools_CHC QQtools;
extern QQTools_CHC QQtools;

int main()
{
	SetConsoleTitle("Chat-2017�����ִ�ѧ�������9��º賬����");
	SetWindowSize(41, 32);
	string QQ = "QQ";
	string WeiChat = "WeiChat";
	string WeiBo = "WeiBo";
	string Parties = "QQ\\Parties";
	CreateDirectory(QQ.c_str(), NULL);//�����ļ���
	CreateDirectory(WeiChat.c_str(), NULL);
	CreateDirectory(WeiBo.c_str(), NULL);
	CreateDirectory(Parties.c_str(), NULL);
	/*GetQQ();
	Menu();*/
	QQtools.GetQQ();
	QQtools.Menu();
	return 0;
}