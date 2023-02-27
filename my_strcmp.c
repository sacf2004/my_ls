/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** Reproduce the behavior of the strcmp function.
*/

#include "printf/lib/my/include/myprintf.h"

int my_strcmp (char const *s1, char const *s2)
{
    int index = 0;
    int length1 = my_str_count_len(s1);
    int length2 = my_str_count_len(s2);
    if (length1 != length2) {
        return (1);
    }
    while (s1[index] != '\0') {
        if (s1[index] != s2[index]) {
            return 1;
        }
        index = index +1;
    }
    return 0;
}
