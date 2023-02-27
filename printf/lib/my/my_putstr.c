/*
** EPITECH PROJECT, 2022
** task02
** File description:
** putchar pero para string
*/
#include <unistd.h>
int my_str_count_len (char const *str);
int my_putstr(char const *str )
{
    int index = 0;
    while (str [index] != '\0'){
        index = index +1;
    }
    write(1, str, index);
    return (my_str_count_len(str));
}
