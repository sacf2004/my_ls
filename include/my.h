/*
** EPITECH PROJECT, 2023
** My_ls
** File description:
** All functions used
*/

#ifndef _LS_H
    #define _LS_H
    #include <dirent.h>

int my_strcmp (char const *s1, char const *s2);

char *my_strcat (char *dest, char const *src);

int my_ls_l (DIR *dir);

int my_ls_r (char const *files);

int my_ls_a(const char *files);

void start_print_date(char *str, int pos);

char my_ls_normal_with_path (int ac, char **av);

char my_ls_r_may (char const *files);

char my_ls_r_may_with_path(int ac, char **av);

int my_ls_l_with_path (int ac, char **av);

char my_ls_r_may_help (const char *path);

#endif
