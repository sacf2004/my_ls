/*
** EPITECH PROJECT, 2022
** change_base
** File description:
** change the base
*/
#include <stdio.h>

int my_put_nbr (int nb);
void my_putchar (char c);
int my_count_nbr(int nb);
int my_str_count_len (char const *str);
int decimal_to_binary(int nb)
{
    int binary[32];
    int index = 0;
    int count = 0;
    if (nb == 0) {
        my_put_nbr(0);
        return (0);
    }

    while (nb > 0) {
        binary[index] = nb % 2;
        nb = nb / 2;
        index = index + 1;
    }
    count = index - 1;
    while (count >= 0) {
        my_put_nbr(binary[count]);
        count = count - 1;
    }
    return (my_count_nbr(nb));
}

int decimal_to_octal(unsigned int nb)
{
    int binary[32];
    int index = 0;
    int count = 0;
    if (nb == 0) {
        my_put_nbr(0);
        return (0);
    }
    while (nb > 0) {
        binary[index] = nb % 8;
        nb = nb / 8;
        index = index + 1;
    }
    count = index - 1;
    while (count >= 0) {
        my_put_nbr(binary[count]);
        count = count - 1;
    }
    return (index + count + 1);
}

int decimal_to_hexadecimal_may(unsigned int nb)
{
    int operation, index = 0; int temp = 0; int binary[100];
    if (nb == 0) {
        my_put_nbr(0);
        return (0);
    } while (nb > 0) {
        operation = nb % 16;
        if (operation < 10) {
            binary[index] = '0' + operation;
        }else {
            binary[index] = 'A' + (operation - 10);
        }
        nb = nb / 16;
        index = index + 1;
        temp = index;
    } while (index--) {
        my_putchar(binary[index]);
    }
    return (temp + index + 1);
}

int decimal_to_hexadecimal_min(unsigned int nb)
{
    int operation, index = 0; int temp = 0; int binary[100];
    if (nb == 0) {
        my_put_nbr(0);
        return (0);
    } while (nb > 0) {
        operation = nb % 16;
        if (operation < 10) {
            binary[index] = '0' + operation;
        }else {
            binary[index] = 'a' + (operation - 10);
        }
        nb = nb / 16;
        index = index + 1;
        temp = index;
    } while (index--) {
        my_putchar(binary[index]);
    }
    return (temp + index + 1);
}
