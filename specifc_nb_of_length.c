/*
** EPITECH PROJECT, 2023
** My_ls
** File description:
** Goes and print a specific part of a str
*/

#include "printf/lib/my/include/myprintf.h"

void start_print_date(char *str, int pos)
{
    int len = my_str_count_len(str);
    if (pos >= 0 && pos < len) {
        for (int index = pos; index < len; index++) {
            my_printf("%c", str[index]);
        }
    }else {
        my_printf ("Invalid position\n");
    }
}
