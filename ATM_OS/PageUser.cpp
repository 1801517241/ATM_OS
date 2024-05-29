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
/// <param name="UserName">用户名</param>
/// <param name="UserPassword">密码</param>
/// <param name="UserCardNum">卡号</param>
/// <param name="Amount">余额</param>
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
		rewind(stdin);			//清除输入缓存区
		std::cout << "Password:" << std::endl;
		printf("Password:");
		std::cin >> UserPassword;
		//scanf_s("%s", UserPassword, (int)sizeof UserPassword);
		rewind(stdin);			//清除输入缓存区

		isLoggedIn = TAV(UserName, UserPassword);
		if (isLoggedIn == true)
		{
			std::cout << "------------------------------------" << std::endl;
			//printf("------------------------------------\n");
			std::cout << "登录成功！跳转至Page-UserInformation页面" << std::endl;
			//printf("登录成功！跳转至Page-UserInformation页面\n");

			Sleep(1000);
			PageUserInformation(UserName, UserPassword, UserCardNum, Amount);
		}
		else
		{
			isLoggedIn = false;
			std::cout << "登录失败，检查用户名或密码！" << std::endl;
			//printf("登录失败，检查用户名或密码！\n");
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="UserName">用户名</param>
/// <param name="UserPassword">密码</param>
/// <param name="UserCardNum">卡号</param>
/// <param name="Amount">余额</param>
void PageUserInformation(char* UserName, char* UserPassword, char* UserCardNum, double* Amount)
{
	int num = 6;

	system(CLEAR_SCREEN);

	printf("--------Page-UserInformation--------\n");
	printf("1.修改用户信息\t| 2.修改账户信息\n");
	printf("3.存款\t\t| 4.取款\n");
	printf("5.切换语言\t| 6.退出\n");
	printf("------------------------------------\n");

	printf("选择服务：");
	scanf_s("%d", &num);
	rewind(stdin);			//清除输入缓存区
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
		// 实现语言切换功能
	case 6:
		printf("退出...\n");
		Sleep(1000);
		break;
	default:
		printf("无效选项！请重试。\n");
		Sleep(1000);
		PageUserInformation(UserName, UserPassword, UserCardNum, Amount);
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="UserName">用户名</param>
/// <param name="UserPassword">密码</param>
/// <returns>1 正确、2 错误</returns>
bool TAV(char* UserName, char* UserPassword)
{
	return(strcmp(UserName, "admin") == 0 && strcmp(UserPassword, "123456") == 0);
}