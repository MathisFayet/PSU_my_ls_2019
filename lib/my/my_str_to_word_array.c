/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** LIBRAIRIE
*/

#include <stdlib.h>

int length(char *str)
{
    int first = 0;
    int count  = 0;

    while (str[first] != '\0') {
        if (str[first] == ' ')
            count += 1;
        first += 1;
    }
    return (count + 2);
}

char **my_malloc(char **str, int length, int len)
{
    int index = 0;

    while (index < length) {
        str[index] = malloc(sizeof(char) * len);
        index += 1;
    }
    return (str);
}

int length_my_str(char *str)
{
    int index = 0;

    while (str[index] != '\0') {
        index += 1;
    }
    return (index);
}

char **copy_my_str(char *str, char **dest)
{
    int index = 0;
    int x = 0;
    int y = 0;

    while (str[index] != '\0') {
        if (str[index] == ':') {
            dest[x][y] = '\0';
            x += 1;
            y = 0;
            index += 1;
        }
        dest[x][y] = str[index];
        y += 1;
        index += 1;
    }
    dest[x + 1] = NULL;
    return (dest);
}

char **my_str_to_word_array(char *str)
{
    int index = 0;
    int result = length(str);
    char **dest = malloc(sizeof(char *) * result);
    int len = length_my_str(str);

    dest = my_malloc(dest, result, len);
    dest = copy_my_str(str, dest);
    return (dest);
}
