#pragma once
#ifndef CHAT_H
#define CHAT_H
#include<string>
#include<vector>
#include<iostream>
#include"Date.h"
using namespace std;
class Date;
class QQFriends_CHC;
class QQParties_CHC;
class Tencent_CHC;

class Tencent_CHC //�ʺŻ���
{

public:

	virtual int ReturnAge(){return Age;}

	virtual int ReturnFriendNumber(){return FriendNumber;}

	virtual int ReturnPartyNumber() { return PartyNumber; }

	virtual string ReturnID() { return ID; }

	virtual string  ReturnPassWord(){return PassWord;}

	virtual string  ReturnName(){return Name;}

	virtual string  ReturnArea(){return Area;}

	virtual string  ReturnAutograph(){return Autograph;}

	virtual void ChangePartyNumbers(int num){PartyNumber = num;}

	virtual void ChangeFriendsNumber(int num){FriendNumber = num;}

protected:

	int Age; //ע������

	int FriendNumber; //��������

	int PartyNumber; //Ⱥ����

	string ID;  //�ʺ�
	
	string Name;  //�û�����

	string PassWord; //�û�����

	string Area;//�û����ڵ���

	string Autograph;//�û�����ǩ��

	Date ApplyDate;//�û�ע������

private:

};


class QQ_CHC : public Tencent_CHC
{

public:

	QQ_CHC();

	QQ_CHC(string qqid, int qage, string qqpw, string qqname,string qqpv, string ag);

	~QQ_CHC();

	vector<QQFriends_CHC*>& ReturnFriendList(){return FriendList;}

	vector<QQParties_CHC*>& ReturnPartyList(){return PartyList;}


	//string ReturnID()
	//{
	//	return ID;
	//}

	//int ReturnAge()
	//{
	//	return Age;
	//}

	//int ReturnFriendNumber()
	//{
	//	return FriendNumber;
	//}

	//string  ReturnPassWord()
	//{
	//	return PassWord;
	//}

	//string  ReturnName()
	//{
	//	return Name;
	//}

	//string  ReturnArea()
	//{
	//	return Area;
	//}

	//string  ReturnAutograph()
	//{
	//	return Autograph;
	//}

	/*int ReturnPartyNumber()
	{
		return PartyNumber;
	}

	void ChangePartyNumbers(int num)
	{
		PartyNumber = num;
	}

	void ChangeFriendsNumber(int num)
	{
		FriendNumber = num;
	}*/

private:

	//int Age;

	//int FriendNumber;

	//int PartyNumber;

	//string ID;

	//string PassWord;//

	//string Name;

	//string Area;

	//string Autograph;

	//Date ApplyDate;

	vector<QQFriends_CHC*> FriendList;

	vector<QQParties_CHC*> PartyList;

};

class QQFriends_CHC : public Tencent_CHC
{

public:

	friend class QQ_CHC;

	QQFriends_CHC(string name ,string id);

	string ReturnFriendName(){return FriendName;}

	string ReturnID(){return ID;}


private:
	
	string FriendName;

	string ID;

};


class QQParties_CHC
{

public:

	friend class QQ_CHC;

	string ReturnPartyID(){return PartyID;}

	string ReturnPartyName(){return PartyName;}

	string ReturnCreatUserID(){return CreatUserID;}

	QQParties_CHC(string id , string name ,string userid);

	vector<string> &ReturnPartyMembers() { return PartyMembrs; }

private:
	
	string PartyID;

	string PartyName;

	string CreatUserID;

	vector<string> PartyMembrs;

};

#endif