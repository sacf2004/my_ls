/*
** EPITECH PROJECT, 2022
** flag_list2
** File description:
** ...
*/
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/myprintf.h"

void myhexadecimalmay (va_list *list)
{
    decimal_to_hexadecimal_may(va_arg(*list, unsigned int));
}

void myputnbrpositive (va_list *list)
{
    my_put_nbr_positive(va_arg(*list, unsigned int));
}

void myhexadecimalmin (va_list *list)
{
    decimal_to_hexadecimal_min(va_arg(*list, unsigned int));
}
