/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** Function that displays the number given as a parameter
*/
#include <unistd.h>
void my_putchar (char c);
int my_count_nbr(unsigned int nb);
int my_put_nbr (int nb)
{
    if (nb < 0 && nb > -2147483648) {
        my_putchar ('-');
        nb = nb *(-1);
        return (my_put_nbr(nb) + 1);
    }
    if (nb >= 10) {
        my_put_nbr (nb / 10);
    }
    my_putchar ('0' + (nb % 10));
    return (my_count_nbr(nb));
}
