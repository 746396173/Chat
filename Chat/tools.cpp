#include<iostream>
#include"tools.h"
#include"chat.h"
#include<conio.h>
#include "stdafx.h"
#include "Initsock.h"
#include<fstream>
CInitSock initSock; // ��ʼ��Winsock��
using namespace std;
vector<QQ_CHC*>QQ;
string QQid;

void SaveQQ()
{
	ofstream file;
	file.open("QQ.txt",ios::app);
	auto iter = QQ.begin();
	int i = 0;
	for (i = 0; i < size(QQ); i++)
	{

	}
		file << QQ[i-1]->QQID << endl;
		file << QQ[i-1]->Qage << endl;
		file << QQ[i-1]->QQPassWord << endl;
		file << QQ[i-1]->QQName << endl;
		file << QQ[i-1]->QQProvince << endl;
		file << QQ[i-1]->QQAutograph << endl;
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
		if (QQ[i]->QQID == ::QQid)
		{
			Myqq = i;
		}
	}
	for (n = 0; n < size(QQ[Myqq]->FriendList); n++)
	{
	}
	file << QQ[Myqq]->FriendList[n - 1]->FriendName << endl;
	file << QQ[Myqq]->FriendList[n - 1]->ID << endl;
	file << " " << endl;
	file.close();
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
		if (QQ[i]->QQID == ::QQid)
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
		QQ[Myqq]->FriendList.emplace_back(new QQFriends_CHC(name, id));
	}

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
		cout << "QQ��:"<<qq[i]->QQID << endl;
		cout << "Q��:"<<qq[i]->Qage << endl;
		cout << "QQ����:"<<qq[i]->QQPassWord << endl;
		cout << "QQ����:"<<qq[i]->QQName << endl;
		cout << "���ڵ���:"<<qq[i]->QQProvince << endl;
		cout << "����ǩ��:"<<qq[i]->QQAutograph << endl;
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
		if (QQ[i]->QQID == ID)
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
		if (QQ[i]->QQID == ID && QQ[i]->QQPassWord == PassWord)
		{
			cout << "��½�ɹ�" << endl;
			cout << "���������ʼʹ��QQ" << endl;
			_getch();
			QQMenu();
			break;
		}
		else if (QQ[i]->QQID == ID && QQ[i]->QQPassWord != PassWord)
		{
			cout << "�����������" << endl;
			cout << "��������������" << endl;
			cin >> PassWord;
			if (QQ[i]->QQPassWord == PassWord)
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
	int select;
	cout << "��ӭʹ��QQ" << endl;
	cout << "���QQ��Ϊ:" << QQid << endl;
	cout << "��ѡ��ʹ�õĹ���" << endl;
	cout << "1.��������������" << endl;
	cout << "2.���QQ����" << endl;
	cout << "3,�鿴QQ����" << endl;
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
		if (QQ[i]->QQID == id)
		{
			flag = true;
			name = QQ[i]->QQName;
			cout << "��Ӻ��ѳɹ�" << endl;
		}
	}
	if(flag == false)
		{
			cout << "��QQ��û��ע�ᣬ���������������QQ��" << endl;
			_getch();
			AddFriend();
		}
	
	if (flag)
	{
		for (int i = 0; i < size(QQ); i++)
		{
			if (QQ[i]->QQID == ::QQid)
			{
				Myqq = i;
			}
		}
		QQ[Myqq]->FriendList.emplace_back(new QQFriends_CHC(name , id));
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
		if (QQ[i]->QQID == ::QQid)
		{
			Myqq = i;
		}
	}
	cout << "����" << QQ[Myqq]->FriendsNumber << "������" <<endl;
	for (int i = 0; i < QQ[Myqq]->FriendsNumber; i++)
	{
		cout << "��" << i + 1 << "λ����" << endl;
		cout << "����:"<<QQ[Myqq]->FriendList[i]->FriendName << endl;
		cout << "QQ:"<<QQ[Myqq]->FriendList[i]->ID << endl;
		cout << endl;
	}
	cout << "�����������QQ��ҳ" << endl;
	_getch();
	QQMenu();
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