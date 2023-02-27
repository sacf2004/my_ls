/*
** EPITECH PROJECT, 2022
** struct
** File description:
** ...
*/
#ifndef _STRUCT_H
    #define _STRUCT_H
    #include <stdarg.h>

typedef struct my_printf_t {
    char character;
    int (*pt)(va_list *);
} my_printf_t;
#endif
