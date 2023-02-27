/*
** EPITECH PROJECT, 2022
** my_count_nbr
** File description:
** ...
*/
#include <unistd.h>
#include <stdio.h>

int my_count_nbr(unsigned int nb)
{
    int index = 0;
    if (nb < 0) {
        index = index + 1;
    }
    while (nb != 0) {
        nb = nb / 10;
        index = index + 1;
    }
    return (index);
}
