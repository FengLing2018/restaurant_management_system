//
// tools.h
//
//
// Some practical tools.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


/// <summary>
/// a safe "gets()"
/// </summary>
/// <param name="st">address</param>
/// <param name="n">Limited number of characters</param>
/// <returns>address</returns>
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');    // find '\n'
		if (find)                   // if address is not NULL
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;           // deal with the remaining character
	}
	return ret_val;
}


/// <summary>
/// A tool to get input (get the number from 0 to max index, including both sides)
/// </summary>
/// <param name="max_index">max index</param>
/// <returns>the choice</returns>
int get_choice(int max_index)
{

    int choice = -1;
    while (true)
    {
        scanf_s("%d", &choice);
        while (getchar() != '\n')
            continue;
        if (choice >= 0 && choice <= max_index)
            return choice;
        else
        {
            printf("There's a mistake, Please input again: ___\b\b");
            return get_choice(max_index);
        }

    }

}

/// <summary>
/// return (1.year 2.month 3.day 4.hour 5.minute 6.second)
/// </summary>
/// <param name="choice">the data number</param>
/// <returns>the data</returns>
int get_time(int choice)
{
	time_t timep;

	struct tm* p;

	time(&timep);

	p = gmtime(&timep);

	switch (choice)
	{
	case 1:
		return 1900 + p->tm_year;
	case 2:
		return 1 + p->tm_mon;
	case 3:
		return p->tm_mday;
	case 4:
		return 8 + p->tm_hour;
	case 5:
		return p->tm_min;
	case 6:
		return p->tm_sec;

	}


}