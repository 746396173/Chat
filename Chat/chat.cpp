#include<iostream>
#include"chat.h"
#include<time.h>
#include "stdafx.h"
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
using namespace std;

QQ_CHC::QQ_CHC()
{
	for (int i = 0; i<1000000; i++) //��ǿQQ�����������
	{
		srand(time(0));
	}
	int p = rand()*rand();
	char temp[128];
	itoa(p , temp , 10);
	QQID = string(temp);
	/*QQID = rand()*rand();*/
	cout << "���QQ��Ϊ:" << QQID <<endl;
	cout << "�������������" << endl;
	cin >> QQPassWord;
	ApplyDate.ShowDate();
	Qage = 0;
	cout << "���������QQ����:" << endl;
	cin >> QQName;
	cout << "�����������ڵ�ʡ��" << endl;
	cin >> QQProvince;
	cout << "������ĸ���ǩ��" << endl;
	cin >> QQAutograph;
	cout << "QQ������ɹ�" << endl;
	cout << "���QQ��Ϊ:" << QQID << endl;
	cout << "���QQ����Ϊ:" << QQPassWord << endl;
	cout << "�����Ʊ����ʺź�����" << endl;

}

QQ_CHC::QQ_CHC(string qqid, int qage, string qqpw, string qqname, string qqpv, string ag)
{
	QQID = qqid;
	Qage = qage;
	QQPassWord = qqpw;
	QQName = qqname;
	QQProvince = qqpv;
	QQAutograph = ag;
	FriendsNumber = 0;
	PartyNumbers = 0;
}

QQFriends_CHC::QQFriends_CHC(string name, string id)
{
	FriendName = name;
	ID = id;
}

QQParties_CHC::QQParties_CHC(string id, string name, string userid)
{
	PartyID = id;
	PartyName = name;
	CreatUserID = userid;
}