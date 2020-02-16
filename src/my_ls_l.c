/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_ls_l
*/

#include "my_all_ls.h"

char *create_new_path(char *argv, char *path)
{
    char *copy = malloc(sizeof(char) * (my_strlen(argv) + my_strlen(path)));

    copy = my_strcpy(copy, argv);
    copy = my_strcat(copy, path);
    return (copy);
}

int print_total(char *argv)
{
    struct stat info_file;
    DIR *dir = opendir(argv);
    struct dirent *path = readdir(dir);
    int counter = 0;
    char *str = NULL;

    if (argv[my_strlen(argv) - 1] != '/')
        my_strcat(argv, "/");
    while (path != NULL) {
        if (path->d_name[0] != '.') {
            str = create_new_path(argv, path->d_name);
            stat(str, &info_file);
            counter += info_file.st_blocks;
        }
        path = readdir(dir);
    }
    my_putstr("total ");
    my_put_nbr(counter / 2);
    my_putchar('\n');
    closedir(dir);
    free(str);
    return (0);
}

int print_ls_l(struct stat info_file, struct passwd *name_user,
                struct group *name_group)
{
    gettype(info_file);
    getlaw(info_file);
    my_put_nbr(info_file.st_nlink);
    my_putchar(' ');
    name_user = getpwuid(info_file.st_uid);
    name_group = getgrgid(info_file.st_gid);
    my_putstr(name_user->pw_name);
    my_putchar(' ');
    my_putstr(name_group->gr_name);
    my_putchar(' ');
    my_put_nbr(info_file.st_size);
    my_putchar(' ');
    write(1, &ctime(&info_file.st_mtime)[4], 12);
    my_putchar(' ');
    return (0);
}

int my_ls_l(char *argv)
{
    struct stat info_file;
    struct passwd *name_user = NULL;
    struct group *name_group = NULL;
    DIR *dir = opendir(argv);
    struct dirent *path = NULL;
    char *str = NULL;

    if (dir == NULL)
        return (1);
    path = readdir(dir);
    print_total(argv);
    while (path != NULL) {
        if (path->d_name[0] != '.') {
            str = create_new_path(argv, path->d_name);
            stat(str, &info_file);
            print_ls_l(info_file, name_user, name_group);
            my_putstr(path->d_name);
            my_putchar('\n');
        }
        path = readdir(dir);
    }
}