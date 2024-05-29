#include "PageUser.h"

#include <iostream>
#include <stdio.h>
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
		//printf("-------------Page-login-------------\n");
		std::cout << "User:" << std::endl;
		//printf("User:");
		std::cin >> UserName;
		//scanf_s("%s", UserName, (int)sizeof UserName);
		rewind(stdin);			//������뻺����
		std::cout << "Password:" << std::endl;
		printf("Password:");
		std::cin >> UserPassword;
		//scanf_s("%s", UserPassword, (int)sizeof UserPassword);
		rewind(stdin);			//������뻺����

		isLoggedIn = TAV(UserName, UserPassword);
		if (isLoggedIn == true)
		{
			std::cout << "------------------------------------" << std::endl;
			//printf("------------------------------------\n");
			std::cout << "��¼�ɹ�����ת��Page-UserInformationҳ��" << std::endl;
			//printf("��¼�ɹ�����ת��Page-UserInformationҳ��\n");

			Sleep(1000);
			PageUserInformation(UserName, UserPassword, UserCardNum, Amount);
		}
		else
		{
			isLoggedIn = false;
			std::cout << "��¼ʧ�ܣ�����û��������룡" << std::endl;
			//printf("��¼ʧ�ܣ�����û��������룡\n");
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

	printf("--------Page-UserInformation--------\n");
	printf("1.�޸��û���Ϣ\t| 2.�޸��˻���Ϣ\n");
	printf("3.���\t\t| 4.ȡ��\n");
	printf("5.�л�����\t| 6.�˳�\n");
	printf("------------------------------------\n");

	printf("ѡ�����");
	scanf_s("%d", &num);
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
		printf("�˳�...\n");
		Sleep(1000);
		break;
	default:
		printf("��Чѡ������ԡ�\n");
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