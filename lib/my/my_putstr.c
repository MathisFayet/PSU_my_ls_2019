/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** LIBRAIRIE
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char *str)
{
    int i = 0;
    
    if (str != NULL) {
        while (str[i] != '\0') {
            my_putchar(str[i]);
            i = i + 1;
        }
    }
    return (0);
}
