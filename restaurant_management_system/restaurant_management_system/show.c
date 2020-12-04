//
// show.c
//
//
// The function for showing information.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tools.h"
#include "fun.h"
#include <Windows.h>
#include <conio.h>

extern Dish dishes[10];
extern Table tables[10];

/// <summary>
/// print greeing message
/// </summary>
void greeting()
{

	printf("******************************************************\n");
	printf("*                                                    *\n");
	printf("*                                                    *\n");
	printf("*      Welcome to restaurant management system!      *\n");
	printf("*                                                    *\n");
	printf("*                                                    *\n");
	printf("*                   Please login in                  *\n");
	printf("*                                                    *\n");
	printf("*                                                    *\n");
	printf("*                                                    *\n");
	printf("*                                                    *\n");
	printf("*                                                    *\n");
	printf("******************************************************\n");
	printf("any key to continue...");
	_getch();

}

/// <summary>
/// print main menu
/// </summary>
void show_main_menu() 
{
	system("cls");
	printf("******************************************************\n");
	printf("*                                                    *\n");
	printf("*         Please select the function you want        *\n");
	printf("*                                                    *\n");
	printf("*         1.order                                    *\n");
	printf("*         2.check out                                *\n");
	printf("*         3.purchase records                         *\n");
	printf("*         4.customer evaluation                      *\n");
	printf("*                                                    *\n");
	printf("*         0.exit                                     *\n");
	printf("*                                                    *\n");
	printf("*                                                    *\n");
	printf("******************************************************\n");


}


/// <summary>
/// print dish menu
/// </summary>
void show_dish_menu()
{
	

	FILE* fp = fopen("dish.txt", "r");
	for (int i = 0; i < 10; i++) {
		fscanf(fp, "%s%d", dishes[i].name, &dishes[i].price);
	}
	fclose(fp);

	system("cls");
	printf("******************************************************\n");
	printf("*    Please select the dishes you want (0 to end)    *\n");
	for (int i = 0; i < 10; i++)
		printf("*         %-2d.%-15s     %4d                *\n", i+1, dishes[i].name, dishes[i].price);
	printf("******************************************************\n");


}

/// <summary>
/// print tables ane their states
/// </summary>
void show_table_menu()
{
	char state_str[10];
	FILE* fp = fopen("table.txt", "r");
	for (int i = 0; i < 10; i++) {
		fscanf(fp, "%d%d", &tables[i].capacity, &tables[i].state);
		tables[i].id = i + 1;
	}
	fclose(fp);

	
	system("cls");
	printf("******************************************************\n");
	printf("*    Please select one table  you want (0 to end)    *\n");
	for (int i = 0; i < 10; i++) {	
		switch (tables[i].state) 
		{
		case 0:
			strcpy(state_str, "free");
			break;
		case 1:
			strcpy(state_str, "occupied");
			break;
		case 2:
			strcpy(state_str, "reserved");
			break;
		case 3:
			strcpy(state_str, "damaged");
			break;
		}
		printf("*        ID: %2d  CAPACITY: %2d  STATE: %-8s       *\n",tables[i].id, tables[i].capacity, state_str);
	}
	printf("******************************************************\n");
}

/// <summary>
/// print the last ten purchase records
/// </summary>
void show_records()
{
	system("cls");
	char temp[50];
	int total = 0;
	FILE* fp = fopen("record.txt", "r");
	while (fgets(temp, 45, fp)) {
		puts(temp);
		total++;
	}
	fclose(fp);
	printf("----------- 10 recently -----------\n\n");
	printf("any key to back...");
	_getch();
}

/// <summary>
/// print customers' preference for dishes
/// </summary>
void show_favourate()
{
	FILE* fp;

	fp = fopen("favourate.txt", "r");
	for (int i = 0; i < 10; i++) {
		
		fscanf(fp, "%d", &dishes[i].popularity);
	}
	fclose(fp);

	fp = fopen("dish.txt", "r");
	for (int i = 0; i < 10; i++) {
		fscanf(fp, "%s%d", dishes[i].name, &dishes[i].price);
	}
	fclose(fp);
	system("cls");
	printf("******************************************************\n");
	printf("*           The popularity of all dishes             *\n");
	for (int i = 0; i < 10; i++)
		printf("*         %-2d.%-15s     %4d                *\n", 
			    i + 1, dishes[i].name, dishes[i].popularity);
	printf("******************************************************\n");
	printf("any key to back...");
	_getch();
}