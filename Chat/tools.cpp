#include<iostream>
#include"tools.h"
#include"chat.h"
#include<conio.h>
#include "stdafx.h"
#include "Initsock.h"
#include<fstream>
#include<io.h>
#include"GreedySnake.h"
#include<list>
#include <cstring>
CInitSock initSock; // ��ʼ��Winsock��
using namespace std;
vector<QQ_CHC*>QQ;
string QQid; //��½��QQ��
string QQparty;//������Ⱥ��;
string PartyMember; //�����Ⱥ��QQ��

void SaveQQ()
{
	ofstream file;
	file.open("QQ.txt",ios::app);
	auto iter = QQ.begin();
	int i = 0;
	for (i = 0; i < size(QQ); i++)
	{

	}
		file << QQ[i-1]->ReturnQQID() << endl;
		file << QQ[i-1]->ReturnQage() << endl;
		file << QQ[i-1]->ReturnQQPassWord() << endl;
		file << QQ[i-1]->ReturnQQName() << endl;
		file << QQ[i-1]->ReturnQQProvince() << endl;
		file << QQ[i-1]->ReturnQQAutograph() << endl;
		file << " "<<endl;
	file.close();
}

void SaveFriends()
{
	int i = 0, Myqq, n;
	ofstream file;
	string qq = ::QQid;
	string txt = ".txt";
	string filename = qq + txt;
	file.open(filename, ios::app);
	for (i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	for (n = 0; n < size(QQ[Myqq]->ReturnFriendList()); n++)
	{
	}
	file << QQ[Myqq]->ReturnFriendList()[n - 1]->ReturnFriendName() << endl;
	file << QQ[Myqq]->ReturnFriendList()[n - 1]->ReturnID() << endl;
	file << " " << endl;
	file.close();
}

void GetQQ()
{
	int qage;
	string qqid;
	string qqpw, qqname, qqpv, qqag;
	ifstream file;
	int line = 0;
	char c;
	file.open("QQ.txt");
	while (file.get(c))
	{
		if (c == ' ')
		{
			line++;
		}
	}
	file.close();
	file.open("QQ.txt");
	for (int i = 0; i < line; i++)
	{
		file >> qqid;
		file >> qage;
		file >> qqpw;
		file >> qqname;
		file >> qqpv;
		file >> qqag;
		//QQ_CHC qq(qqid, qage, qqpw, qqname, qqpv,qqag);
		QQ.emplace_back(new QQ_CHC(qqid, qage, qqpw, qqname, qqpv, qqag));
	}
}

void ShowQQ()
{
	vector<QQ_CHC*>qq;
	int  qage;
	string qqid;
	string qqpw, qqname, qqpv, qqag;
	ifstream file;
	int line = 0;
	char c;

	file.open("QQ.txt");
	while (file.get(c))
	{
		if (c == ' ')
		{
			line++;
		}
	}
	file.close();
	file.open("QQ.txt");
	for (int i = 0; i < line; i++)
	{
		file >> qqid;
		file >> qage;
		file >> qqpw;
		file >> qqname;
		file >> qqpv;
		file >> qqag;
		//QQ_CHC qq(qqid, qage, qqpw, qqname, qqpv,qqag);
		qq.emplace_back(new QQ_CHC(qqid, qage, qqpw, qqname, qqpv, qqag));
	}
	for (int i = 0; i < line; i++)
	{
		cout << "QQ��:"<<qq[i]->ReturnQQID() << endl;
		cout << "Q��:"<<qq[i]->ReturnQage() << endl;
		cout << "QQ����:"<<qq[i]->ReturnQQPassWord() << endl;
		cout << "QQ����:"<<qq[i]->ReturnQQName() << endl;
		cout << "���ڵ���:"<<qq[i]->ReturnQQProvince() << endl;
		cout << "����ǩ��:"<<qq[i]->ReturnQQAutograph() << endl;
		cout << endl;

	}
	/*vector<int>qqid;
	for (int i = 0; i < 2; i++)
	{
		int qq;
		file >> qq;
		qqid.emplace_back(qq);
	}
	file.close();
	cout << qqid[0] << endl;;
	cout << qqid[1];*/
	/*int num = file.gcount();
	int i = 0;
	for (string s; file >> s;)
	{
		QQ[i].push_back(s);
	}
	for (int i = 0; i < file.gcount(); i++)
	{
		file.read((char *)&QQ[i], sizeof(QQ_CHC));
	}*/

	//for (int i = 0; i < size(QQ); i++)
	//{
	//	cout << QQ[i]->QQID << endl;
	//}
	file.close();
}

void Menu()
{
	system("CLS");
	SetColor(6);
	GetQQ();
	int select;

	cout << "��ѡ���½/ע����ʺ�" << endl;
	cout << "1.QQ" << endl;
	cout << "2.΢��" << endl;
	cout << "3.΢��" << endl;

	cin >> select;

	switch (select)
	{
	case 1:
		{
		cout << "��ѡ�����蹦��" << endl;
		cout << "1.��½QQ" << endl;
		cout << "2.ע��QQ" << endl;
		cout << "3.�鿴������QQ��" << endl;
			int ch;
			cin >> ch;
			switch (ch)
			{
			case 1:

				LoginQQ();
				break;

			case 2:

				ApplyQQ();
				break;

			case 3:
				ShowQQ();
				break;

			default:
				{
				cout << "�������" << endl;
				cout << "��������������˵�" << endl;
				getch();
				Menu();
				}
			}
			cout << "��������������˵�" << endl;
			getch();
			Menu();
			break;
		}
	default:
		{
		cout << "�������" << endl;
		cout << "��������������˵�" << endl;
		_getch();
		Menu();
		break;
		}
	}
}

void ApplyQQ() 
{
	system("CLS");
	QQ.emplace_back(new QQ_CHC());
	SaveQQ();
}

void LoginQQ()
{
	string ID;
	bool flag = false;
	string PassWord;
	//vector<QQ_CHC*>::iterator iter = QQ.begin();
	cout << "������Ҫ��½��QQ:" << endl;
	cin >> ID;
	::QQid = ID;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ID)
		{
			flag = true;
		}
	}
	if (flag != true)
	{
		cout << "û�и�QQ�ţ���������" << endl;
		cout << "��������������˵�" << endl;
		_getch();
		Menu();
	}
	cout << "�������QQ������" << endl;
	cin >> PassWord;
	for (int i = 0 ; i < size(QQ) ; i++)
	{
		if (QQ[i]->ReturnQQID() == ID && QQ[i]->ReturnQQPassWord() == PassWord)
		{
			cout << "��½�ɹ�" << endl;
			cout << "���������ʼʹ��QQ" << endl;
			_getch();
			QQMenu();
			break;
		}
		else if (QQ[i]->ReturnQQID() == ID && QQ[i]->ReturnQQPassWord() != PassWord)
		{
			cout << "�����������" << endl;
			cout << "��������������" << endl;
			cin >> PassWord;
			if (QQ[i]->ReturnQQPassWord() == PassWord)
			{
				cout << "��½�ɹ�" << endl;
				cout << "���������ʼʹ��QQ" << endl;
				getch();
				QQMenu();
				break;
			}
			else
			{
				cout << "�����������" << endl;
				cout << "��������������" << endl;
				cin >> PassWord;
			}
			break;
		}
		/*else
		{
			cout << "û�и�QQ�ţ���������" << endl;
			cout << "��������������˵�" << endl;
			_getch();
			Menu();
			break;
		}*/
			
	}
}

void QQMenu()
{
	system("CLS");
	SetColor(6);
	int select;
	cout << "��ӭʹ��QQ" << endl;
	cout << "���QQ��Ϊ:" << QQid << endl;
	cout << "��ѡ��ʹ�õĹ���" << endl;
	cout << "1.��������������" << endl;
	cout << "2.���QQ����" << endl;
	cout << "3,�鿴QQ����" << endl;
	cout << "4.����QQȺ" << endl;
	cout << "5.����QQȺ" << endl;
	cout << "6.�鿴�Լ�����QQȺ" << endl;
	cout << "7.����QQȺ" << endl;
	cout << "9.С��Ϸ" << endl;
	cout << "0.�������˵�" << endl;
	cin >> select;
	switch (select)
	{
	case 1:

		Client();
		break;

	case 2:

		AddFriend();
		break;

	case 3:
		ShowFriends();
		break;

	case 4:
		CreatQQparty();
		break;

	case 5:
		AddPartyMember();
		break;

	case 6:
		ShowQQParty();
		break;

	case 7:
		AgreeMember();
		break;

	case 9:
		PlayGame();
		break;

	case 0:
		Menu();
		break;

	default:
		cout << "�������,�����������QQ��ҳ" << endl;
		_getch();
		QQMenu();
		break;

	}
	_getch();
}

void AddFriend()
{
	system("CLS");
	int Myqq;
	string id;
	string name;
	bool flag = false;
	cout << "��������Ӻ��ѵ�QQ��" << endl;
	cin >> id;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == id)
		{
			flag = true;
			name = QQ[i]->ReturnQQName();
			cout << "��Ӻ��ѳɹ�" << endl;
		}
	}
	if(flag == false)
		{
			cout << "��QQ��û��ע�ᣬ���������������QQ��" << endl;
			cout << "1.��������QQ����Ӻ���" << endl;
			cout << "2.����QQ��ҳ" << endl;
			int select;
			cin >> select;
			switch (select)
			{
			case 1:
				AddFriend();
				break;

			case 2:
				QQMenu();
				break;

			default:
				cout << "�������,�����������QQ��ҳ" << endl;
				_getch();
				QQMenu();
				break;
			}
			
		}
	
	if (flag)
	{
		for (int i = 0; i < size(QQ); i++)
		{
			if (QQ[i]->ReturnQQID() == ::QQid)
			{
				Myqq = i;
			}
		}
		QQ[Myqq]->ReturnFriendList().emplace_back(new QQFriends_CHC(name , id));
		QQ[Myqq]->FriendsNumber++;
	}
	SaveFriends();
	cout << "�����������QQ��ҳ" << endl;
	_getch();
	QQMenu();
}

void ShowFriends()
{
	system("CLS");
	GetFriends();
	int Myqq;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	cout << "����" << QQ[Myqq]->ReturnFriendsNumber() << "������" << endl;
	for (int i = 0; i < QQ[Myqq]->ReturnFriendsNumber(); i++)
	{
		cout << "��" << i + 1 << "λ����" << endl;
		cout << "����:" << QQ[Myqq]->ReturnFriendList()[i]->ReturnFriendName() << endl;
		cout << "QQ:" << QQ[Myqq]->ReturnFriendList()[i]->ReturnID() << endl;
		cout << endl;
	}
	cout << "�����������QQ��ҳ" << endl;
	_getch();
	QQMenu();
}

void GetFriends()
{
	ifstream file;
	string qq = ::QQid;
	string txt = ".txt";
	string filename = qq + txt;
	string id;
	string name;
	char c;
	int line = 0;
	int Myqq;
	file.open(filename, ios::app);
	while (file.get(c))
	{
		if (c == ' ')
		{
			line++;
		}
	}
	file.close();
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	QQ[Myqq]->FriendsNumber = line;
	file.open(filename, ios::app);
	for (int i = 0; i < line; i++)
	{
		file >> id;
		file >> name;
		QQ[Myqq]->ReturnFriendList().emplace_back(new QQFriends_CHC(name, id));
	}

	file.close();
}

void CreatQQparty()
{
	int Myqq;
	system("CLS");
	cout << "���������봴����Ⱥ��" << endl;
	string ID;
	cin >> ID;
	::QQparty = ID;
	cout << "������Ⱥ����" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	QQ[Myqq]->ReturnPartyList().emplace_back(new QQParties_CHC(ID, name, ::QQid));
	QQ[Myqq]->PartyNumbers++;
	SaveQQParty();


	//ÿ��QQ�����Լ���Ⱥ�б�
	fstream FILE;
	string qq;
	qq = ::QQid;
	string txt1 = "PartyList.txt";
	string FILEName = qq + txt1;
	FILE.open(FILEName, ios::app);
	FILE << ID << endl;

	cout << "�����������QQ��ҳ" << endl;
	_getch();
	QQMenu();
}

void AddQQParty()
{
	system("CLS");
	int Myqq;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	cout << "��������������Ⱥ" << endl;
	string partyid;
	::PartyMember = partyid;
	cin >> partyid;
	string txt = ".txt";
	string filename = partyid + txt;
	ofstream file;
	ifstream check;
	check.open(filename,ios::in);
	if (!check)
	{
		int select;
		cout << "��QQȺ��û�д���������������򷵻�QQ��ҳ" << endl;
		cout << "1.��������QQȺ��" << endl;
		cout << "2.����QQ��ҳ" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			AddQQParty();
			break;
		
		case 2:
			QQMenu();
			break;

		default:
			cout << "�������,�����������QQ��ҳ" << endl;
			_getch();
			QQMenu();
			break;

		}
		
	}
	check.close();
	file.open(filename, ios::app);
	file << QQ[Myqq]->ReturnQQID() << endl;
	file << QQ[Myqq]->ReturnQQName() << endl;
	file << endl;
	file.close();

	AddPartyMember();

	cout << "�����������QQ��ҳ" << endl;
	_getch();
	QQMenu();
}

void SaveQQParty() //ÿ����һ��Ⱥ�㽫��Ⱥ�����һ��.txt�ļ�
{
	system("CLS");
	int i = 0, Myqq, n;
	string ID;
	ID = QQparty;
	string txt = ".txt";
	string PartyID = ID + txt;
	fstream file;
	file.open(PartyID, ios::app);
	for (i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	for (n = 0; n < size(QQ[Myqq]->ReturnPartyList()); n++)
	{
	}
	file << QQ[Myqq]->ReturnPartyList()[n - 1]->ReturnPartyID() << endl;
	file << QQ[Myqq]->ReturnPartyList()[n - 1]->ReturnPartyName() << endl;
	file << QQ[Myqq]->ReturnPartyList()[n - 1]->ReturnCreatUserID() << endl;
	file << "��" << endl;
	file.close();

}

void GetQQParty() //���ļ���ȡ��QQ��Ⱥ�������浽������
{
	int Myqq, line = 0;
	char c;
	string txt1 = "PartyList.txt";

	string txt = ".txt";

	ifstream listfile;

	ifstream partyfile;

	string qq = ::QQid;

	vector<string>party;

	string temp;

	string filename = qq + txt1;

	listfile.open(filename);

	while (listfile.get(c))
	{
		string x;
		x = c;
		temp += x;

		if (c == '\n')
		{
			line++;
			temp.pop_back();
			party.emplace_back(temp);
			temp.clear();
		}
	}
	listfile.close();


	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	QQ[Myqq]->ChangePartyNumbers(line);

	for (int i = 0; i < size(party); i++)
	{
		temp = party[i];
		filename = temp + txt;
		partyfile.open(filename);
		string id;
		string name;
		string userid;
		partyfile >> id;
		partyfile >> name;
		partyfile >> userid;
		partyfile.close();
		QQ[Myqq]->ReturnPartyList().emplace_back(new QQParties_CHC(id , name , userid));
	}

}

void ShowQQParty()
{
	system("CLS");
	GetQQParty();
	int Myqq;
	for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}
	cout << "�㹲��" << QQ[Myqq]->ReturnPartyNumbers() << "��Ⱥ" << endl;
	for (int i = 0; i < QQ[Myqq]->ReturnPartyNumbers(); i++)
	{
		cout << "��" << QQ[Myqq]->ReturnPartyNumbers() << "��Ⱥ" << endl;
		cout << "Ⱥ��:" << QQ[Myqq]->ReturnPartyList()[i]->ReturnPartyID() << endl;
		cout << "Ⱥ����:" << QQ[Myqq]->ReturnPartyList()[i]->ReturnPartyName() << endl;
		cout << "Ⱥ��:" << QQ[Myqq]->ReturnPartyList()[i]->ReturnCreatUserID() << endl;
		cout << endl;
	}
	cout << "�����������QQ��ҳ" << endl;
	_getch();
	QQMenu();
}

void AddPartyMember()
{
	system("CLS");
	cout << "��������������Ⱥ" << endl;
	string partyid;
	cin >> partyid;
	::PartyMember = partyid;
	string id;
	int Myqq;
	id = ::PartyMember;
	string txt = ".txt";
	string filename = id + txt;
	ofstream ofile;
	ofile.open(filename,ios::app);
	ofile << "^" <<::QQid  << endl;
	/*for (int i = 0; i < size(QQ); i++)
	{
		if (QQ[i]->ReturnQQID() == ::QQid)
		{
			Myqq = i;
		}
	}*/
	ofile.close();
	cout << "������Ⱥ�ɹ�,��ȴ�Ⱥ��ͬ��" << endl;
	cout << "�����������QQ��ҳ" << endl;
	_getch();
	QQMenu();
}

void AgreeMember()//Ⱥ���鿴����
{
	cout << "������Ҫ�����Ⱥ��" << endl;
	char c;
	int line = 0;
	string id;
	string txt = ".txt";
	cin >> id;
	string filename = id + txt;
	ifstream infile;
	infile.open(filename,ios::in);
	if (!infile)
	{
		cout << "û�д�Ⱥ,����������򷵻�QQ��ҳ" << endl;
		cout << "��������" << endl;
		cout << "����QQ��ҳ" << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			AgreeMember();
			break;

		case 2:
			QQMenu();
			break;
		}
	}
	infile.close();
	fstream outfile;
	outfile.open(filename);

	string temp;
	while (outfile.get(c))
	{
		if (c == '\n')
		{
			line++;
			continue;
		}
		if (line == 2) //��ȡȺ��QQ��
		{
			temp.push_back(c);
		}
		
	}
	/*temp.pop_back(); *///ɾ��ĩβ\n

	if (temp != ::QQid)
	{
		cout << "�㲻�Ǹ�Ⱥ��Ⱥ��,�޷������Ⱥ" << endl;
		cout << "�����������QQ��ҳ" << endl;
		_getch();
		_getch();
		QQMenu();
	}

	outfile.close();
	temp.clear();

	
	line = 0;
	outfile.open(filename);
	

	while (outfile.get(c))
	{
		if (c == '^')
		{
			line++;
			continue;
		}
		if (line == 1) //��ȡ������Ⱥ����QQ��
		{
			temp.push_back(c);
			//temp.clear();//�����
			line++;
		}
		else if (line == 2)
		{
			temp.push_back(c);
		}

	}
		//}
		outfile.close();
		temp.pop_back();
		cout << "���Ƿ�ͬ��" << temp << "��Ⱥ?" << endl;
		cout << "1.ͬ��" << endl;
		cout << "2.�ܾ�" << endl;
		int select;
		cin >> select;

		vector<char> content;

		auto iter = content.begin();
		auto iter1 = temp.begin();
		int m = 0;

		string msg;
		/*char ch1[1000];*/

		int n = 0;
		/*int words = 0;*/
		switch (select)
		{
		case 1:
			outfile.open(filename, ios::in | ios::out);

			char ch;
			while (!outfile.eof())
			{

				char ch[1000];

				outfile.getline(ch,1000);
				for (int i = 0; i < strlen(ch); i++)
				{
					msg.push_back(ch[i]);//��ȡ�ļ�����
				}
				
				
				msg.push_back('\n');
				//cout << msg << endl;

			}

			

			for (int i = 0; i < size(msg); i++)//��δ������ɾ��
			{
				if (msg[i] == '^')
				{
					/*			content[i];*/
								//content.erase(content.begin() + i);
					msg.erase(msg.begin() + i);
				}
			}
			/*size(temp);*/
			/*cout << msg;*/
			

			outfile.close();

			outfile.open(filename, ios::out, ios::trunc); //���ԭ���ļ�����
			
			outfile << msg;

			cout << "ȷ������ɹ�" << endl;

			outfile.close();

			break;

		default:
			cout << "���Ѿܾ�������" << endl;
			outfile.open(filename, ios::in, ios::out);

			while (outfile.get(c))
			{
				content.emplace_back(c);
			}
			outfile.close();

			for (int i = 0; i < size(content); i++)
			{
				if (content[i] == '��')
				{

					n = i;

					while (1)
					{
						content.erase(content.begin() + n); //ɾ��������QQ

						n++;

						if (content[n] == '\n')
						{
							content.erase(content.begin() + n);
							break;
						}


					}

					break;
				}
			}

			outfile.open(filename, ios::out, ios::trunc);//���ԭ������

			for (int i = 0; i < size(content); i++)
			{
				outfile << content[i];//��ɾ��������QQ����ļ��������������ļ���
			}
			outfile.close();

			cout << "�����������QQ��ҳ" << endl;
			_getch();
			QQMenu();
			break;
		}

	
}

void Client()//���������
{
	system("CLS");
	// �����׽���
	cout << "��#������QQ��ҳ" << endl;
	SOCKET s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		printf(" ����ʧ�� socket() \n");
		exit(0);
	}

	// Ҳ�������������bind������һ�����ص�ַ
	// ����ϵͳ�����Զ�����

	// ��дԶ�̵�ַ��Ϣ
	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(4567);
	// ע�⣬����Ҫ��д����������TCPServer�������ڻ�����IP��ַ
	// �����ļ����û��������ֱ��ʹ��127.0.0.1����
	servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	if (::connect(s, (sockaddr*)&servAddr, sizeof(servAddr)) == -1)
	{
		printf(" �������������ʧ��connect() \n");
		cout << "�����������QQ��ҳ" << endl;
		_getch();
		QQMenu();
	}

	char buff[256];
	char szText[256];
	cout << "��½�������ɹ�" << endl;
	while (TRUE)
	{
		//�ӷ������˽�������
		int nRecv = ::recv(s, buff, 256, 0);
		if (nRecv > 0)
		{
			buff[nRecv] = '\0';
			printf("���ԶԷ�����Ϣ��%s\n", buff);
		}

		// ��������˷�������
		cout << "�뷢����Ϣ:" << endl;
		cin >> szText;
		if (szText[0] == '#')
		{
			QQMenu();
		}
		szText[255] = '\0';
		::send(s, szText, strlen(szText), 0);

		cout << "��ȴ��Է��ظ�" << endl;
	}

	// �ر��׽���
	::closesocket(s);
}

void PlayGame()
{
	Controller c;//����һ��Controller��

	c.Game();//������Ϸѭ��

	_getch();

}

string UTF8ToGB(const char* str)
{
	string result;
	WCHAR *strSrc;
	LPSTR szRes;

	//�����ʱ�����Ĵ�С
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//�����ʱ�����Ĵ�С
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}
