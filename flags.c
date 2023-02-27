/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** ls proyect
*/

#include <stdio.h>
#include <dirent.h>
#include "printf/lib/my/include/myprintf.h"
#include "include/my.h"

int my_ls_a(const char *files)
{
    DIR *dir;
    struct dirent *dirp;
    dir = opendir (files);

    if (dir == NULL)
        return 84;
    dirp = readdir(dir);
    while (dirp != NULL) {
        if (dirp->d_type == DT_REG) {
            my_putstr(dirp->d_name);
        }
        if (dirp->d_type == DT_DIR) {
            my_putstr(dirp->d_name);
        }
        my_printf("%c ", ' ');
        dirp = readdir(dir);
    }
    closedir(dir);
    my_printf("\n");
    return (0);
}

int my_ls_r (char const *files)
{
    DIR* dir;
    struct dirent *dirp[10000];
    int index = 0, count = 0;
    dir = opendir(files);
    if (dir == NULL)
        return 84;
    while ((dirp[index] = readdir(dir)) != NULL) {
        if (my_strcmp(dirp[index]->d_name, ".") == 0
            || my_strcmp(dirp[index]->d_name, "..") == 0
            || my_strcmp(dirp[index]->d_name, ".git") == 0)
            continue;
        index = index + 1;
    }
    closedir(dir);
    for (count = index - 1; count >= 0; count--)
        my_printf("%s  ", dirp[count]->d_name);
    my_printf("\n");
    return 0;
}
