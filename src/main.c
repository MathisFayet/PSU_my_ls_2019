/*
** EPITECH PROJECT, 2020
** Main.c
** File description:
** Epitech Project
*/

#include "my_all_ls.h"

int main(int argc, char **argv)
{
    int status = 0;

    if (argc == 2 || argc == 3) {
        status = my_ls(argv);
    } else if (argc == 1) {
        status = my_ls_basic("./");
    }
    return (status);
}