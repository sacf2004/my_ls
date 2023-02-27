/*
** EPITECH PROJECT, 2022
** flag_list
** File description:
** ...
*/
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/myprintf.h"

void myput_nb (va_list *list)
{
    my_put_nbr(va_arg(*list, int));
}

int myput_percent (va_list *list)
{
    my_putchar('%');
    return (1);
}

void myput_octal (va_list *list)
{
    decimal_to_octal(va_arg(*list, unsigned int));
}

void myput_str (va_list *list)
{
    my_putstr(va_arg(*list, char*));
}

char myput_char (va_list *list)
{
    my_putchar(va_arg(*list, int));
    return (1);
}
