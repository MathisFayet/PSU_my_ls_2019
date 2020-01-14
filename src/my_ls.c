/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls.c
*/

#include "my_all_ls.h"

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int my_ls(char *argv)
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
}
