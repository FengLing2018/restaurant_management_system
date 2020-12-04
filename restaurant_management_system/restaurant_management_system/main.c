/**================================================
*                Author : 陈锦绥
*                    ID : 20206961
*                 Email : ischenjinsui@163.com
*            CreateTime : 2020.12.2
*                   IDE : VisualStudio
*      Operating System : Windows X64
* =================================================
* Running on other operating systems may cause unexpected errors!
*/

#include "fun.h"
#include "tools.h"

Dish dishes[10];
Table tables[10];

int main()
{	
	system("mode con cols=54 lines=24"); // set size of console
	greeting();	
	log_in();
	
	while (true)
	{
		show_main_menu();

		// get the user's order AND run the functions seperately
		switch (get_choice(4)) 
		{
		case 1:
			while (true) {
				show_table_menu();
				bool is_select = select_table();
				if (!is_select)
					continue;
				show_dish_menu();
				order();
				break;
			}					
			break;
		case 2:
			check_out();
			break;
		case 3:
			show_records();
			break;
		case 4:
			show_favourate();
			break;
		case 0:
			return 0;
		}
	}
}