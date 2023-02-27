/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** ...
*/
#include <stdio.h>
#include <unistd.h>
void my_putchar (char c);
int my_strlen (char const *str);

void change(char *str1, char *str2)
{
    char undefined = 0;
    undefined = *str1;
    *str1 = *str2;
    *str2 = undefined;
}

void my_revstr(char *str, int length)
{
    int character = 0;
    int final = length - 1;
    while (character < final) {
        change(&str[character], &str[final]);
        character = character + 1;
        final = final - 1;
    }
}
