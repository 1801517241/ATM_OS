#include"PageUser.h"

#include <iostream>

int main()
{
	User user = { 1,"admin","123456","12345678912345678",5000};

	//½øÈëµÇÂ¼Ò³Ãæ
	PageLogin(user.name, user.password, user.CardNum, &user.amount);

	return 0;
}