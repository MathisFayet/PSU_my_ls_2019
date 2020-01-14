/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** LIBRAIRIE
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);

    return (nb * my_compute_power_rec(nb, p - 1));
}

int main(void)
{
    int i = 0;
    char const *str;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}