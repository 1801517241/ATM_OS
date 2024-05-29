#pragma once

#ifndef __FUNCTION_H__
#define __FUNCTION_H__

void PageSetUser(char* UserName, char* UserPassword);		//修改用户信息
void PageSetCarNum(char* UserName, char* UserPassword);		//修改账户信息
void PageDeposit(double* Amount);		//存款
void PageWithdrawal(double* Amount);	//取款

#endif // !__FUNCTION_CPP__