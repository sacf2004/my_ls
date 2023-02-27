/*
** EPITECH PROJECT, 2023
** My_ls
** File description:
** Flag -l
*/

#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include "printf/lib/my/include/myprintf.h"
#include "include/my.h"

void print_permission(mode_t mode)
{
    my_printf( (S_ISDIR(mode)) ? "d" : "-");
    my_printf( (mode & S_IRUSR) ? "r" : "-");
    my_printf( (mode & S_IWUSR) ? "w" : "-");
    my_printf( (mode & S_IXUSR) ? "x" : "-");
    my_printf( (mode & S_IRGRP) ? "r" : "-");
    my_printf( (mode & S_IWGRP) ? "w" : "-");
    my_printf( (mode & S_IXGRP) ? "x" : "-");
    my_printf( (mode & S_IROTH) ? "r" : "-");
    my_printf( (mode & S_IWOTH) ? "w" : "-");
    my_printf( (mode & S_IXOTH) ? "x" : "-");
    my_printf(".");
}

void print_info (const char *path, struct dirent *dirp)
{
    struct stat file_stat;
    struct group* grp;
    struct passwd* pwd;
    char full_path[2000];
    my_strcpy(full_path, path);
    my_strcat(full_path, "/");
    my_strcat(full_path, dirp->d_name);
    lstat(full_path, &file_stat);
    pwd = getpwuid(file_stat.st_uid);
    grp = getgrgid(file_stat.st_gid);
    char *hour = ctime(&file_stat.st_mtime);
    hour[my_str_count_len(hour) - 9] = '\0';
    print_permission(file_stat.st_mode);
    my_printf(" %d", file_stat.st_nlink);
    my_printf(" %s", pwd->pw_name);
    my_printf(" %s", grp->gr_name);
    my_printf(" %d", file_stat.st_size);
    start_print_date(hour, 3);
    my_printf(" %s\n", dirp->d_name);
}

int my_ls_l_with_path (int ac, char **av)
{
    DIR *dir = opendir(av[2]);
    if (dir == NULL)
        return 84;
    struct dirent *dirp;
    my_printf ("total 84\n");
    while ((dirp = readdir(dir))) {
        if (my_strcmp(dirp->d_name, ".") == 0 ||
            my_strcmp(dirp->d_name, "..") == 0 ||
            my_strcmp(dirp->d_name, ".git") == 0)
            continue;
        print_info(av[2], dirp);
    }
    closedir(dir);
    return 0;
}
