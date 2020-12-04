#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tools.h"
#include "fun.h"

extern Table tables[10];

/// <summary>
/// make tables.state from occupied to free
/// </summary>
void check_out()
{
	show_table_menu();
	printf("Please selecct a table you want: ");
	int choice = get_choice(10);

	if (tables[choice-1].state == 1) {
		tables[choice - 1].state = 0;
		FILE* fp = fopen("table.txt", "w");
		for (int i = 0; i < 10; i++) {
			fprintf(fp, "%d %d\n", tables[i].capacity, tables[i].state);
		}
		fclose(fp);

		printf("accepted!\n");
		printf("any key to back...");
		_getch();

	}
	else {
		puts("This table is NOT occupied!");
		printf("any key to back...");
		_getch();
	}
	return;
	
}