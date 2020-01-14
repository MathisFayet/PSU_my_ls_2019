/*
** EPITECH PROJECT, 2020
** Main.c
** File description:
** Epitech Project
*/

#include "my_all_ls.h"

int main(int argc, char **argv)
{
    struct my_ls;
    if (argc == 2) {
        my_ls(argv[1]);
    } else if (argc == 1)
        my_ls("./");
    return (0);
}