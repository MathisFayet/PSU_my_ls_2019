/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** LIBRAIRIE
*/

void my_putchar(char c);

int my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}