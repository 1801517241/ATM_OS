#include "Function.h"

#include <iostream>
#include <Windows.h>

#ifdef _WIN32
#include <Windows.h>
#define CLEAR_SCREEN "cls"
#define SLEEP(x) Sleep(x)
#else
#include <unistd.h>
#define CLEAR_SCREEN "clear"
#define SLEEP(x) sleep(x)
#endif

/// <summary>
/// 
/// </summary>
/// <param name="UserName">�û���</param>
/// <param name="UserPassword">����</param>
void PageSetUser(char* UserName, char* UserPassword)
{
	system(CLEAR_SCREEN);

	int num = 0;
	char name[11] = { 0 };
	char Password[11] = { 0 };

	std::cout << "------------Page-SetUser------------\n";
	std::cout << "��ǰ��Ϣ��\n";
	std::cout << "  �û�����" << UserName << " | ���룺" << UserPassword << std::endl;
	std::cout << "------------------------------------\n";

	std::cout << "ѡ��ҵ��(�޸��û���/����/���أ���";
	std::cin >> num;
	rewind(stdin);			//������뻺����
	switch (num)
	{
	case 1:
		std::cout << "��ǰ�û�����";
		std::cin >> name;
		rewind(stdin);			//������뻺����
		if (strcmp(name, UserName) != 0)
		{
			std::cout << "��ǰ�û���(����)��";
			std::cin >> name;
			rewind(stdin);			//������뻺����
			while (strcmp(name, UserName) != 0)
			{
				std::cout << "��ǰ�û���(����)��";
				std::cin >> name;
				rewind(stdin);			//������뻺����

			}
			std::cout << "�޸��û�����";
			std::cin >> UserName;
			rewind(stdin);			//������뻺����
			PageSetUser(UserName, UserPassword);
			break;
		}
		else
		{
			std::cout << "�޸��û�����";
			std::cin >> UserName;
			rewind(stdin);			//������뻺����
			PageSetUser(UserName, UserPassword);
		}
		break;
	case 2:
		std::cout << "��ǰ���룺";
		std::cin >> Password;
		rewind(stdin);			//������뻺����
		if (strcmp(Password, UserPassword) != 0)
		{
			while (strcmp(Password, UserPassword) != 0)
			{
				std::cout << "��ǰ���루���󣩣�";
				std::cin >> Password;
				rewind(stdin);			//������뻺����	
			}
			std::cout << "��ǰ���루���󣩣�";
			std::cin >> UserPassword;
			rewind(stdin);			//������뻺����	
			PageSetUser(UserName, UserPassword);
			break;
		}
		else
		{
			std::cout << "��ǰ���루���󣩣�";
			std::cin >> UserPassword;
			rewind(stdin);			//������뻺����	
			PageSetUser(UserName, UserPassword);
		}
		break;
	case 3:
		std::cout << "����Page-UserInformation��\n";
		Sleep(1000);
		break;
	default:
		std::cout << "�������ֵ!";
		Sleep(1000);
		PageSetUser(UserName, UserPassword);
		break;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="UserName"></param>
/// <param name="UserPassword"></param>
void PageSetCarNum(char* UserName, char* UserPassword)
{
	system(CLEAR_SCREEN);

	std::cout << "-----------Page-SetCarNum-----------\n";
}

/// <summary>
/// 
/// </summary>
/// <param name="Amount"></param>
void PageDeposit(double* Amount)
{
	system(CLEAR_SCREEN);

	int num;
	double money = 0;

	std::cout << "------------Page-Deposit------------\n";

	std::cout << "\n��ǰ���" << Amount << std::endl;

	std::cout << "\n��ȷ�ϵ�ǰҵ��(���/�˳�)��";
	std::cin >> num;

	switch (num)
	{
	case 1:
		std::cout << "���������ȣ�";
		std::cin >> money;
		rewind(stdin);			//������뻺����

		*Amount += money;

		PageDeposit(Amount);
		break;
	case 2:
		std::cout << "����Page-UserInformation��\n";
		Sleep(1000);
		break;
	default:
		std::cout << "�������ֵ!";
		Sleep(1000);
		PageDeposit(Amount);
		break;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="Amount"></param>
void PageWithdrawal(double* Amount)
{
	system(CLEAR_SCREEN);

	int num;
	double money = 0;

	std::cout << "-----------Page-Withdrawal-----------\n";

	std::cout << "\n��ǰ��%.2f\n";

	std::cout << "\n��ȷ�ϵ�ǰҵ��(ȡ��/�˳�)��";
	std::cin >> num;

	switch (num)
	{
	case 1:
		std::cout << "������ȡ���ȣ�";
		std::cin >> money;
		rewind(stdin);			//������뻺����
		if (money <= *Amount)
			*Amount -= money;
		else
			std::cout << "����!";
		Sleep(1000);
		PageWithdrawal(Amount);
		break;
	case 2:
		std::cout << "����Page-UserInformation��\n";
		Sleep(1000);
		break;
	default:
		std::cout << "�������ֵ!";
		Sleep(1000);
		PageWithdrawal(Amount);
		break;
	}
}