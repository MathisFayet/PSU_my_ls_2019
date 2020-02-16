/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_ls_t
*/

#include "my_all_ls.h"

char *my_strdup(char const *str)
{
    int index = 0;
    char *src = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (src == NULL)
        return (NULL);
    while (str[index] != '\0') {
        src[index] = str[index];
        index += 1;
    }
    src[index] = '\0';
    return (src);
}

char **rotate_element(char **tab_data, int first, int second)
{
    char *stock = NULL;

    my_strdup(tab_data[first]);
    tab_data[first] = tab_data[second];
    tab_data[second] = stock;
    free(stock);
    return (tab_data);
}

char **cmp_data(char **tab_data, char *argv)
{
    int y = 0;
    char *first = NULL;
    char *second = NULL;
    struct stat *info_file;
    int stock = 0;

    while (tab_data[y] != NULL) {
        first = create_new_path(argv, tab_data[y]);
        second = create_new_path(argv, tab_data[y + 1]);
        stat(first, &info_file);
        stock = info_file->st_mtime;
        stat(second, &info_file);
        if (stock > info_file->st_mtime) {
            rotate_element(tab_data, y, y + 1);
            y = 0;
        } else {
        y += 1;
        }
    }
}

int my_ls_t(char *argv)
{
    struct stat info_file;
    DIR *dir = opendir(argv);
    struct dirent *path = readdir(dir);
    char *str = NULL;
    char *stock_data = NULL;
    char **tab_data = NULL;

    print_total(argv);
    while (path != NULL) {
        if (path->d_name[0] != '.') {
            str = create_new_path(argv, path->d_name);
            stat(str, &info_file);
            stock_data = my_strcat(stock_data, path->d_name);
            stock_data = my_strcat(stock_data, ' ');
        }
        path = readdir(dir);
    }
    tab_data = my_str_to_word_array(stock_data);
    tab_data = cmp_data(tab_data, argv);
}