/*
** EPITECH PROJECT, 2022
** my_pointer_address
** File description:
** ...
*/
int *my_pointer_adress(int c)
{
    int index = 0;
    int *p = &c;
    while (*p != '\0') {
        index = index + 1;
    }
    return (p);
}
