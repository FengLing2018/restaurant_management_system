//
// fun.h
//
//
// The header for dish, table, order.
//

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#define MAXDISHNUM 10

//Function prototype
void greeting();
void log_in();
void show_main_menu();
void show_table_menu();
bool select_table();
void show_dish_menu();
void check_out();
void order();
void show_records();
void show_favourate();



typedef struct order {
	int table_id;					
	int dish_id[MAXDISHNUM];	//many dish id in ONE ORDER
	struct Order* next;
}Order;

typedef struct table {
	int id;					
	int capacity;					
	int state;					// 0.free 1.occupied 2.reserved 3.damaged				
}Table;

typedef struct dish {
	int id;		
	char name[15];				
	int price;			
	int popularity;
}Dish;





