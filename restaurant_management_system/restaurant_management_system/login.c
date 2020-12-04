//
// login.c
//
//
// The function for logging in.
// 
//
// The initial account number and password are both "test"
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include "tools.h"

/// <summary>
/// user log in
/// </summary>
void log_in()
{
	while (true)
	{
		char right_account[] = "test";
		char right_password[] = "test";

		char account[20];
		char password[20];

		system("cls");
		printf("Please input your account: ");
		s_gets(account, 15);
		printf("Please input your password: ");
		s_gets(password, 15);

		if (strcmp(right_account, account)){
			printf("account does not exist!");
			Sleep(1000);
			continue;
		}

		if (strcmp(right_password, password)){
			printf("Wrong password!\n");
			printf("any key to retry...");
			_getch();
			continue;
		}

		printf("Accepted!\n");
		printf("any key to continue...");
		_getch();
		break;
			

	}
	
}