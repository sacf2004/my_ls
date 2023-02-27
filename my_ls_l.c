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

void print_permissions(mode_t mode)
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

void printing_info (struct group* grp, struct passwd* pwd,
    struct stat statbuf, struct dirent* ent)
{
    char *hour = ctime(&statbuf.st_mtime);
    hour[my_str_count_len(hour) - 9] = '\0';
    print_permissions(statbuf.st_mode);
    my_printf(" %d", statbuf.st_nlink);
    my_printf(" %s", pwd->pw_name);
    my_printf(" %s", grp->gr_name);
    my_printf(" %d", statbuf.st_size);
    start_print_date(hour, 3);
    my_printf(" %s\n", ent->d_name);
}

int my_ls_l (DIR *dir)
{
    struct dirent *dirp;
    struct stat file_stat;
    struct passwd *pwd;
    struct group *grp;
    dir = opendir(".");
    my_printf ("total 84\n");
    if (dir == NULL)
        return 84;
    while ((dirp = readdir(dir)) != NULL) {
        if (my_strcmp(dirp->d_name, ".") == 0 ||
            my_strcmp(dirp->d_name, "..") == 0 ||
            my_strcmp(dirp->d_name, ".git") == 0)
            continue;
        lstat(dirp->d_name, &file_stat);
        pwd = getpwuid(file_stat.st_uid);
        grp = getgrgid(file_stat.st_gid);
        printing_info(grp, pwd, file_stat, dirp);
    } closedir(dir);
    return 0;
}
