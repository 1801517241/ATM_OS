#pragma once

#ifndef __FUNCTION_H__
#define __FUNCTION_H__

void PageSetUser(char* UserName, char* UserPassword);		//�޸��û���Ϣ
void PageSetCarNum(char* UserName, char* UserPassword);		//�޸��˻���Ϣ
void PageDeposit(double* Amount);		//���
void PageWithdrawal(double* Amount);	//ȡ��

#endif // !__FUNCTION_CPP__