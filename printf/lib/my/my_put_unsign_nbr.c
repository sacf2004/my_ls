/*
** EPITECH PROJECT, 2022
** my_put_unsign_nbr
** File description:
** ...
*/
#include <unistd.h>
void my_putchar (char c);

int my_count_nbr(int nb);
int my_put_nbr_positive (unsigned int nb)
{
    if (nb >= 10) {
        my_put_nbr_positive (nb / 10);
    }
    my_putchar ('0' + (nb % 10));
    return (my_count_nbr(nb));
}
