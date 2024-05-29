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
/// <param name="UserName">用户名</param>
/// <param name="UserPassword">密码</param>
void PageSetUser(char* UserName, char* UserPassword)
{
	system(CLEAR_SCREEN);

	int num = 0;
	char name[11] = { 0 };
	char Password[11] = { 0 };

	std::cout << "------------Page-SetUser------------\n";
	std::cout << "当前信息：\n";
	std::cout << "  用户名：" << UserName << " | 密码：" << UserPassword << std::endl;
	std::cout << "------------------------------------\n";

	std::cout << "选择业务(修改用户名/密码/返回）：";
	std::cin >> num;
	rewind(stdin);			//清除输入缓存区
	switch (num)
	{
	case 1:
		std::cout << "当前用户名：";
		std::cin >> name;
		rewind(stdin);			//清除输入缓存区
		if (strcmp(name, UserName) != 0)
		{
			std::cout << "当前用户名(错误)：";
			std::cin >> name;
			rewind(stdin);			//清除输入缓存区
			while (strcmp(name, UserName) != 0)
			{
				std::cout << "当前用户名(错误)：";
				std::cin >> name;
				rewind(stdin);			//清除输入缓存区

			}
			std::cout << "修改用户名：";
			std::cin >> UserName;
			rewind(stdin);			//清除输入缓存区
			PageSetUser(UserName, UserPassword);
			break;
		}
		else
		{
			std::cout << "修改用户名：";
			std::cin >> UserName;
			rewind(stdin);			//清除输入缓存区
			PageSetUser(UserName, UserPassword);
		}
		break;
	case 2:
		std::cout << "当前密码：";
		std::cin >> Password;
		rewind(stdin);			//清除输入缓存区
		if (strcmp(Password, UserPassword) != 0)
		{
			while (strcmp(Password, UserPassword) != 0)
			{
				std::cout << "当前密码（错误）：";
				std::cin >> Password;
				rewind(stdin);			//清除输入缓存区	
			}
			std::cout << "当前密码（错误）：";
			std::cin >> UserPassword;
			rewind(stdin);			//清除输入缓存区	
			PageSetUser(UserName, UserPassword);
			break;
		}
		else
		{
			std::cout << "当前密码（错误）：";
			std::cin >> UserPassword;
			rewind(stdin);			//清除输入缓存区	
			PageSetUser(UserName, UserPassword);
		}
		break;
	case 3:
		std::cout << "返回Page-UserInformation！\n";
		Sleep(1000);
		break;
	default:
		std::cout << "输入错误值!";
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

	std::cout << "\n当前金额" << Amount << std::endl;

	std::cout << "\n请确认当前业务(存款/退出)：";
	std::cin >> num;

	switch (num)
	{
	case 1:
		std::cout << "请输入存款额度：";
		std::cin >> money;
		rewind(stdin);			//清除输入缓存区

		*Amount += money;

		PageDeposit(Amount);
		break;
	case 2:
		std::cout << "返回Page-UserInformation！\n";
		Sleep(1000);
		break;
	default:
		std::cout << "输入错误值!";
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

	std::cout << "\n当前金额￥%.2f\n";

	std::cout << "\n请确认当前业务(取款/退出)：";
	std::cin >> num;

	switch (num)
	{
	case 1:
		std::cout << "请输入取款额度：";
		std::cin >> money;
		rewind(stdin);			//清除输入缓存区
		if (money <= *Amount)
			*Amount -= money;
		else
			std::cout << "余额不足!";
		Sleep(1000);
		PageWithdrawal(Amount);
		break;
	case 2:
		std::cout << "返回Page-UserInformation！\n";
		Sleep(1000);
		break;
	default:
		std::cout << "输入错误值!";
		Sleep(1000);
		PageWithdrawal(Amount);
		break;
	}
}