#pragma once

#include "Function.h"

#ifndef __PAGEUSER_H__
#define __PAGEUSER_H__

void PageLogin(char* UserName, char* UserPassword, char* UserCardNum, double* Amount);					//µ«¬º“≥√Ê(UserName ”√ªß,UserPassword √‹¬Î,UserCardNum ø®∫≈,Amount ”‡∂Ó)
void PageUserInformation(char* UserName, char* UserPassword, char* UserCardNum, double* Amount);		//≤Àµ•“≥√Ê(UserName ”√ªß,UserPassword √‹¬Î,UserCardNum ø®∫≈,Amount ”‡∂Ó)

bool TAV(char* UserName, char* UserPassword);		//’À∫≈—È÷§

#endif // !__PAGEUSER_H__

typedef struct User
{
	int id;
	char name[11];
	char password[11];
	char CardNum[18];
	double amount;
}User;