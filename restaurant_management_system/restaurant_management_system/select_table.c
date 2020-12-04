#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tools.h"
#include "fun.h"

void update_file();
extern Table tables[10];

/// <summary>
/// select a table
/// </summary>
/// <returns>is successfully selected the table</returns>
bool select_table()
{
	char state_str[10];
	printf("Please select a table you want: ");
	int choice = get_choice(10);
	
	//function get_choice() can not exclude the popularity of 0
	if (!choice)
		return false;

	int index = choice - 1;
	if (!tables[index].state) {
		tables[index].state = 1;
		printf("accepted!\n");
		update_file();
		return true;
	}
	else {
		switch (tables[index].state)
		{
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
		printf("This table is %s!\n", state_str);
		Sleep(1000);
		return false;
	}
	
	
}

/// <summary>
/// update the lastest table-info to "table.txt" 
/// </summary>
static void update_file()
{
	FILE* fp = fopen("table.txt", "w");
	for (int i = 0; i < 10; i++) {
		fprintf(fp, "%d %d\n", tables[i].capacity, tables[i].state);
	}
	fclose(fp);
}