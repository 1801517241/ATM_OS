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
	printf("当前信息：\n");
	printf("  用户名：%s | 密码：%s\n", UserName, UserPassword);
	printf("------------------------------------\n");

	printf("选择业务(修改用户名/密码/返回）：");
	scanf_s("%d", &num);
	rewind(stdin);			//清除输入缓存区
	switch (num)
	{
	case 1:
		printf("当前用户名：");
		scanf_s("%s", &name, (int)sizeof name);
		rewind(stdin);			//清除输入缓存区
		if (strcmp(name, UserName) != 0)
		{
			printf("当前用户名(错误)：");
			scanf_s("%s", &name, (int)sizeof name);
			rewind(stdin);			//清除输入缓存区
			while (strcmp(name, UserName) != 0)
			{
				printf("当前用户名(错误)：");
				scanf_s("%s", &name, (int)sizeof name);
				rewind(stdin);			//清除输入缓存区

			}
			printf("修改用户名：");
			scanf_s("%s", UserName, (int)sizeof UserName);
			rewind(stdin);			//清除输入缓存区
			PageSetUser(UserName, UserPassword);
			break;
		}
		else
		{
			printf("修改用户名：");
			scanf_s("%s", UserName, (int)sizeof UserName);
			rewind(stdin);			//清除输入缓存区
			PageSetUser(UserName, UserPassword);
		}
		break;
	case 2:
		printf("当前密码：");
		scanf_s("%s", &Password, (int)sizeof Password);
		rewind(stdin);			//清除输入缓存区
		if (strcmp(Password, UserPassword) != 0)
		{
			while (strcmp(Password, UserPassword) != 0)
			{
				printf("当前密码(错误)：");
				scanf_s("%s", &Password, (int)sizeof Password);
				rewind(stdin);			//清除输入缓存区			
			}
			printf("修改密码：");
			scanf_s("%s", UserPassword, (int)sizeof UserPassword);
			rewind(stdin);			//清除输入缓存区
			PageSetUser(UserName, UserPassword);
			break;
		}
		else
		{
			printf("修改密码：");
			scanf_s("%s", UserPassword, (int)sizeof UserPassword);
			rewind(stdin);			//清除输入缓存区
			PageSetUser(UserName, UserPassword);
		}
		break;
	case 3:
		printf("返回Page-UserInformation！\n");
		Sleep(1000);
		break;
	default:
		printf("输入错误值!");
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

	printf("\n当前金额￥%.2f\n", *Amount);

	printf("\n请确认当前业务(存款/退出)：");
	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		printf("请输入存款额度：");
		scanf_s("%lf", &money);
		rewind(stdin);			//清除输入缓存区

		*Amount += money;

		PageDeposit(Amount);
		break;
	case 2:
		printf("返回Page-UserInformation！\n");
		Sleep(1000);
		break;
	default:
		printf("输入错误值!");
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

	printf("\n当前金额￥%.2f\n", *Amount);

	printf("\n请确认当前业务(取款/退出)：");
	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		printf("请输入取款额度：");
		scanf_s("%lf", &money);
		rewind(stdin);			//清除输入缓存区
		if (money <= *Amount)
			*Amount -= money;
		else
			printf("余额不足!");
		Sleep(1000);
		PageWithdrawal(Amount);
		break;
	case 2:
		printf("返回Page-UserInformation！\n");
		Sleep(1000);
		break;
	default:
		printf("输入错误值!");
		Sleep(1000);
		PageWithdrawal(Amount);
		break;
	}
}