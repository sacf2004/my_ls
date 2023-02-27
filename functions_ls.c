/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** ls proyect
*/

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "printf/lib/my/include/myprintf.h"
#include "include/my.h"
#include "include/struct.h"

void my_ls_d (void)
{
    my_printf(".\n");
}

int my_ls_normal (char const *files)
{
    DIR* dir;
    struct dirent *dirp[10000];
    int index = 0;
    dir = opendir(files);
    if (dir == NULL)
        return 84;
    while ((dirp[index] = readdir(dir)) != NULL) {
        if (my_strcmp(dirp[index]->d_name, ".") == 0
            || my_strcmp(dirp[index]->d_name, "..") == 0
            || my_strcmp(dirp[index]->d_name, ".git") == 0)
            continue;
        my_printf("%s  ", dirp[index]->d_name);
        index = index + 1;
    }
    closedir(dir);
    my_printf("\n");
    return 0;
}

int flags_help (int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-a") == 0)
        my_ls_a(".");
    if (ac == 2 && my_strcmp(av[1], "-R") == 0)
        my_ls_r_may(".");
    if (ac == 3 && my_strcmp(av[1], "-R") == 0)
        my_ls_r_may_with_path(ac, av);
    if (ac == 2 && my_strcmp(av[1], "-l") == 0) {
        DIR *dir;
        my_ls_l(dir);
    }
    if (ac == 3 && my_strcmp(av[1], "-l") == 0){
        DIR *dir;
        if (my_ls_l_with_path(ac, av) == 84)
            return 84;
    }
    if (ac == 2) {
        if (my_ls_normal_with_path(ac, av) == 84)
            return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 1)
        my_ls_normal(".");
    if (ac == 2 && my_strcmp(av[1], "-d") == 0)
        my_ls_d();
    if (ac == 2 && my_strcmp(av[1], "-r") == 0)
        my_ls_r(".");
    if (flags_help(ac, av) == 84)
        return 84;
    return (0);
}
