/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** printf function
*/
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "include/myprintf.h"
#include "include/struct.h"

int myput_nb (va_list *list);
int myput_percent (va_list *list);
int myput_octal (va_list *list);
int myput_str (va_list *list);
int myput_char (va_list *list);
int myhexadecimalmay (va_list *list);
int myputnbrpositive (va_list *list);
int myhexadecimalmin(va_list *list);

int flags(int index, const char *format, va_list *list)
{
    my_printf_t solutions[9] = {
        {'d', &myput_nb},
        {'%', &myput_percent},
        {'o', &myput_octal},
        {'s', &myput_str},
        {'c', &myput_char},
        {'X', &myhexadecimalmay},
        {'u', &myputnbrpositive},
        {'i', &myput_nb},
        {'x', &myhexadecimalmin}
    };
    for (int count = 0; count < 9; count++){
        if (solutions[count].character == format[index + 1]){
            return (solutions[count].pt(list));
        }
    }
    index++;
    return (0);
}

int my_printf(const char* format, ...)
{
    int index = 0;
    int n = 0;
    int length = 0;
    va_list list;
    va_start(list, format);
    while (format[index] != '\0') {
        if (format[index] == '%') {
            length = length + flags(index, format, &list);
            index = index + 1;
        }else {
            my_putchar(format[index]);
            n = n + 1;
        }
        index = index + 1;
    }
    length = length + n;
    return (length);
}
