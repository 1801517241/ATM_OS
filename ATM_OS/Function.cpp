#include "Function.h"

#include <stdio.h>
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
/// <param name="UserName"></param>
/// <param name="UserPassword"></param>
void PageSetUser(char* UserName, char* UserPassword)
{
	system(CLEAR_SCREEN);

	int num = 0;
	char name[11] = { 0 };
	char Password[11] = { 0 };

	printf("------------Page-SetUser------------\n");
	printf("��ǰ��Ϣ��\n");
	printf("  �û�����%s | ���룺%s\n", UserName, UserPassword);
	printf("------------------------------------\n");

	printf("ѡ��ҵ��(�޸��û���/����/���أ���");
	scanf_s("%d", &num);
	rewind(stdin);			//������뻺����
	switch (num)
	{
	case 1:
		printf("��ǰ�û�����");
		scanf_s("%s", &name, (int)sizeof name);
		rewind(stdin);			//������뻺����
		if (strcmp(name, UserName) != 0)
		{
			printf("��ǰ�û���(����)��");
			scanf_s("%s", &name, (int)sizeof name);
			rewind(stdin);			//������뻺����
			while (strcmp(name, UserName) != 0)
			{
				printf("��ǰ�û���(����)��");
				scanf_s("%s", &name, (int)sizeof name);
				rewind(stdin);			//������뻺����

			}
			printf("�޸��û�����");
			scanf_s("%s", UserName, (int)sizeof UserName);
			rewind(stdin);			//������뻺����
			PageSetUser(UserName, UserPassword);
			break;
		}
		else
		{
			printf("�޸��û�����");
			scanf_s("%s", UserName, (int)sizeof UserName);
			rewind(stdin);			//������뻺����
			PageSetUser(UserName, UserPassword);
		}
		break;
	case 2:
		printf("��ǰ���룺");
		scanf_s("%s", &Password, (int)sizeof Password);
		rewind(stdin);			//������뻺����
		if (strcmp(Password, UserPassword) != 0)
		{
			while (strcmp(Password, UserPassword) != 0)
			{
				printf("��ǰ����(����)��");
				scanf_s("%s", &Password, (int)sizeof Password);
				rewind(stdin);			//������뻺����			
			}
			printf("�޸����룺");
			scanf_s("%s", UserPassword, (int)sizeof UserPassword);
			rewind(stdin);			//������뻺����
			PageSetUser(UserName, UserPassword);
			break;
		}
		else
		{
			printf("�޸����룺");
			scanf_s("%s", UserPassword, (int)sizeof UserPassword);
			rewind(stdin);			//������뻺����
			PageSetUser(UserName, UserPassword);
		}
		break;
	case 3:
		printf("����Page-UserInformation��\n");
		Sleep(1000);
		break;
	default:
		printf("�������ֵ!");
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

	printf("-----------Page-SetCarNum-----------\n");
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

	printf("------------Page-Deposit------------\n");

	printf("\n��ǰ��%.2f\n", *Amount);

	printf("\n��ȷ�ϵ�ǰҵ��(���/�˳�)��");
	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		printf("���������ȣ�");
		scanf_s("%lf", &money);
		rewind(stdin);			//������뻺����

		*Amount += money;

		PageDeposit(Amount);
		break;
	case 2:
		printf("����Page-UserInformation��\n");
		Sleep(1000);
		break;
	default:
		printf("�������ֵ!");
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

	printf("-----------Page-Withdrawal-----------\n");

	printf("\n��ǰ��%.2f\n", *Amount);

	printf("\n��ȷ�ϵ�ǰҵ��(ȡ��/�˳�)��");
	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		printf("������ȡ���ȣ�");
		scanf_s("%lf", &money);
		rewind(stdin);			//������뻺����
		if (money <= *Amount)
			*Amount -= money;
		else
			printf("����!");
		Sleep(1000);
		PageWithdrawal(Amount);
		break;
	case 2:
		printf("����Page-UserInformation��\n");
		Sleep(1000);
		break;
	default:
		printf("�������ֵ!");
		Sleep(1000);
		PageWithdrawal(Amount);
		break;
	}
}