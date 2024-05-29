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
		std::cout << "User:";
		std::cin >> UserName;
		rewind(stdin);			//清除输入缓存区
		std::cout << "Password:";
		std::cin >> UserPassword;
		rewind(stdin);			//清除输入缓存区

		isLoggedIn = TAV(UserName, UserPassword);
		if (isLoggedIn == true)
		{
			std::cout << "------------------------------------" << std::endl;
			std::cout << "登录成功！跳转至Page-UserInformation页面" << std::endl;

			Sleep(1000);
			PageUserInformation(UserName, UserPassword, UserCardNum, Amount);
		}
		else
		{
			isLoggedIn = false;
			std::cout << "登录失败，检查用户名或密码！" << std::endl;
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

	std::cout << "--------Page-UserInformation--------\n";
	std::cout << "1.修改用户信息\t| 2.修改账户信息\n";
	std::cout << "3.存款\t\t| 4.取款\n";
	std::cout << "5.切换语言\t| 6.退出\n";
	std::cout << "------------------------------------\n";

	std::cout << "选择服务：";
	std::cin >> num;
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
		std::cout << "退出...\n";
		Sleep(1000);
		break;
	default:
		std::cout << "无效选项！请重试。\n";
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