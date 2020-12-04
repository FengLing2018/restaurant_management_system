#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <Windows.h>
#include "tools.h"
#include "fun.h"



extern Dish dishes[10];

Order* head = NULL;
Order* prev = NULL;
Order* current = NULL;

/// <summary>
/// use linklist to order dishes
/// </summary>
void order()
{
	//create a linklist
	//Since the linklist is used in  whole program, function free() is not a must
	current = (Order*)malloc(sizeof(Order));
	if (head == NULL)
		head = current;
	else
		prev->next = current;
	current->next = NULL;

	//get and store information
	int choice = -1;
	int i = 0;
	int sum = 0;
	while (choice = get_choice(10))
	{
		current->dish_id[i++] = choice;
		sum += dishes[choice-1].price;
	}
	prev = current;

	printf("\ntotally %d dollars...\n\n", sum);
	printf("any key to back...");
	_getch();
	

	//record this purchase
	FILE* fp = fopen("record.txt", "a");
	fprintf(fp, "price: %-6d\t%d.%d.%d  %d:%d:%d\n",
		sum, get_time(1), get_time(2), get_time(3), get_time(4), get_time(5), get_time(6));
	fclose(fp);

	
	
}

