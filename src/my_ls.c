/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls.c
*/

#include "my_all_ls.h"

int check_my_ls(char **argv)
{
    int status = 0;

    if (argv[2] == NULL) {
        status = my_ls_l("./");
    } else {
        status = my_ls_l(argv[2]);
    }
    return (status);
}

int my_ls(char **argv)
{
    int status = 0;

    if (argv[1][0] == '-' && argv[1][1] == 'l') {
        status = check_my_ls(argv);
    } else if (argv[2] == NULL) {
        status = my_ls_basic(argv[1]);
    } else {
        return (1);
    }
    return (status);
}

int my_ls_basic(char *argv)
{
    char const *filepath;
    struct dirent *path = NULL;
    DIR *dir = opendir(argv);

    if (dir == NULL) {
        return (84);
    }
    path = readdir(dir);
    while (path != NULL) {
        if (path->d_name[0] != '.') {
            my_putstr(path->d_name);
            my_putchar('\n');
        }
        path = readdir(dir);
    }
    closedir(dir);
    return (0);
}