/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** Write a function that concatenates two strings.
*/

#include <stddef.h>

char *my_strcat (char *dest, char const *src)
{
    int dest_len = 0;
    int src_len = 0;
    if (src == NULL && dest == NULL)
        return NULL;
    while (dest[dest_len] != '\0') {
        dest_len = dest_len + 1;
    }
    while (src[src_len] != '\0') {
        dest[dest_len] = src[src_len];
        dest_len = dest_len + 1;
        src_len = src_len + 1;
    }
    dest[dest_len] = '\0';
    return (dest);
}
