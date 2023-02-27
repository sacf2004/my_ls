/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** replace words
*/

#include <stdio.h>
char *my_strcpy (char *dest, char const *src)
{
    int index = 0;
    if (src == NULL && dest == NULL) {
        return NULL;
    }
    while (src[index] != '\0'){
        dest[index] = src[index];
        index = index + 1;
    }
    dest[index] = '\0';
    return (dest);
}
