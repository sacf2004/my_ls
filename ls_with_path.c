/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** Ls including a path
*/

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "include/my.h"
#include "printf/lib/my/include/myprintf.h"

char my_ls_normal_with_path (int ac, char **av)
{
    DIR *dir = opendir(av[1]);
    struct dirent *dirp[10000];
    int index = 0;
    if (dir == NULL)
        return 84;
    while ((dirp[index] = readdir(dir)) != NULL) {
        if (my_strcmp(dirp[index]->d_name, ".") == 0
            || my_strcmp(dirp[index]->d_name, "..") == 0
            || my_strcmp(dirp[index]->d_name, ".git") == 0)
            continue;
        my_printf(" %s ", dirp[index]->d_name);
        index = index + 1;
    }
    closedir(dir);
    my_printf ("\n");
    return 0;
}
