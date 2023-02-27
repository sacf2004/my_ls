/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** flag -R with path
*/

#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "printf/lib/my/include/myprintf.h"
#include "include/my.h"

char read_al_files (DIR *dir, struct dirent **dirp, char *all_path)
{
    int index = 0;
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

char read_al_folders (DIR *dir, struct dirent *dirp[10000],
    char *all_path, const char *path)
{
    struct stat file_stat;
    int index = 0;
    while ((dirp[index] = readdir(dir)) != NULL) {
        my_strcpy(all_path, path);
        my_strcat(all_path, "/");
        my_strcat(all_path, dirp[index]->d_name);
        if (my_strcmp(dirp[index]->d_name, ".") == 0 ||
            my_strcmp(dirp[index]->d_name, "..") == 0 ||
            my_strcmp(dirp[index]->d_name, ".git") == 0)
            continue;
        if (stat(all_path, &file_stat) == -1)
            return 84;
        if (S_ISDIR(file_stat.st_mode)) {
            my_printf("\n%s:\n", all_path);
            my_ls_r_may_help(all_path);
        }
    }
    return 0;
}

char my_ls_r_may_help (const char *path)
{
    DIR *dir;
    struct dirent *dirp[10000];
    struct stat file_stat;
    char *all_path;
    size_t path_length;
    dir = opendir(path);
    if (dir == NULL)
        return 84;
    path_length = my_str_count_len(path) + 300;
    all_path = malloc(path_length);
    if (all_path == NULL)
        return 84;
    read_al_files(dir, dirp, all_path);
    dir = opendir(path);
    read_al_folders (dir, dirp, all_path, path);
    free(all_path);
    closedir(dir);
    return 0;
}
