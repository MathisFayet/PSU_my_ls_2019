/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** ls_l_back
*/

#include "my_all_ls.h"

int gettype(struct stat info_file)
{
    if (S_ISREG(info_file.st_mode))
        my_putchar('-');
    if (S_ISDIR(info_file.st_mode))
        my_putchar('d');
    if (S_ISCHR(info_file.st_mode))
        my_putchar('c');
    if (S_ISBLK(info_file.st_mode))
        my_putchar('b');
    if (S_ISFIFO(info_file.st_mode))
        my_putchar('f');
    if (S_ISSOCK(info_file.st_mode))
        my_putchar('s');
    return (0);
}

int getlaw(struct stat info_file)
{
    my_putchar((info_file.st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar((info_file.st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar((info_file.st_mode & S_IXUSR) ? 'x' : '-');
    my_putchar((info_file.st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar((info_file.st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar((info_file.st_mode & S_IXGRP) ? 'x' : '-');
    my_putchar((info_file.st_mode & S_IROTH) ? 'r' : '-');
    my_putchar((info_file.st_mode & S_IWOTH) ? 'w' : '-');
    my_putchar((info_file.st_mode & S_IXOTH) ? 'x' : '-');
    my_putchar('.');
    my_putchar(' ');
    return (0);
}