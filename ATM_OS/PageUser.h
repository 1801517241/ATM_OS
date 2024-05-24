#pragma once

#include "Function.h"

#ifndef __PAGEUSER_H__
#define __PAGEUSER_H__

void PageLogin(char* UserName, char* UserPassword, char* UserCardNum, double* Amount);		//µÇÂ¼Ò³Ãæ(UserName ÓÃ»§ UserPassword ÃÜÂë)
void PageUserInformation(char* UserName, char* UserPassword, char* UserCardNum, double* Amount);

bool TAV(char* UserName, char* UserPassword);

#endif // !__PAGEUSER_H__

typedef struct User
{
	int id;
	char name[11];
	char password[11];
	char CardNum[18];
	double amount;
}User;