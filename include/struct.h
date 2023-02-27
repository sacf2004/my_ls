/*
** EPITECH PROJECT, 2022
** structures
** File description:
** Create the struct
*/
#ifndef _LS_H
    #define _LS_H
    #include <stdarg.h>
    #include <sys/stat.h>
    #include <stdio.h>
    #include <time.h>

typedef struct arguments_s {
    int argc;
    char *argv[];
} arguments_t;

typedef struct info_files_s {
    struct dirent *sd;
    struct stat sb;
    struct group *grp;
    struct passwd *pwd;
} info_files_t;
#endif
