#include "PageUser.h"

#include <iostream>
#include <string>
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
/// <param name="UserCardNum">����</param>
/// <param name="Amount">���</param>
void PageLogin(char* UserName, char* UserPassword, char* UserCardNum, double* Amount)
{
	bool isLoggedIn = false;
	while (isLoggedIn != true)
	{
		std::cout << "-------------Page-login-------------" << std::endl;
		std::cout << "User:";
		std::cin >> UserName;
		rewind(stdin);			//������뻺����
		std::cout << "Password:";
		std::cin >> UserPassword;
		rewind(stdin);			//������뻺����

		isLoggedIn = TAV(UserName, UserPassword);
		if (isLoggedIn == true)
		{
			std::cout << "------------------------------------" << std::endl;
			std::cout << "��¼�ɹ�����ת��Page-UserInformationҳ��" << std::endl;

			Sleep(1000);
			PageUserInformation(UserName, UserPassword, UserCardNum, Amount);
		}
		else
		{
			isLoggedIn = false;
			std::cout << "��¼ʧ�ܣ�����û��������룡" << std::endl;
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="UserName">�û���</param>
/// <param name="UserPassword">����</param>
/// <param name="UserCardNum">����</param>
/// <param name="Amount">���</param>
void PageUserInformation(char* UserName, char* UserPassword, char* UserCardNum, double* Amount)
{
	int num = 6;

	system(CLEAR_SCREEN);

	std::cout << "--------Page-UserInformation--------\n";
	std::cout << "1.�޸��û���Ϣ\t| 2.�޸��˻���Ϣ\n";
	std::cout << "3.���\t\t| 4.ȡ��\n";
	std::cout << "5.�л�����\t| 6.�˳�\n";
	std::cout << "------------------------------------\n";

	std::cout << "ѡ�����";
	std::cin >> num;
	rewind(stdin);			//������뻺����
	switch (num)
	{
	case 1:
		PageSetUser(UserName, UserPassword);
		PageUserInformation(UserName, UserPassword, UserCardNum, Amount);
		break;
	case 2:
		PageSetCarNum(UserName, UserPassword);
		PageUserInformation(UserName, UserPassword, UserCardNum, Amount);
		break;
	case 3:
		PageDeposit(Amount);
		PageUserInformation(UserName, UserPassword, UserCardNum, Amount);
		break;
	case 4:
		PageWithdrawal(Amount);
		PageUserInformation(UserName, UserPassword, UserCardNum, Amount);
		break;
	case 5:
		// ʵ�������л�����
	case 6:
		std::cout << "�˳�...\n";
		Sleep(1000);
		break;
	default:
		std::cout << "��Чѡ������ԡ�\n";
		Sleep(1000);
		PageUserInformation(UserName, UserPassword, UserCardNum, Amount);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="UserName">�û���</param>
/// <param name="UserPassword">����</param>
/// <returns>1 ��ȷ��2 ����</returns>
bool TAV(char* UserName, char* UserPassword)
{
	return(strcmp(UserName, "admin") == 0 && strcmp(UserPassword, "123456") == 0);
}