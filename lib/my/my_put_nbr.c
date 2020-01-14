/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** LIBRAIRIE
*/

void my_putchar(char);

int taller(int pdr)
{
    int i = 0;

    while (pdr != 0) {
        pdr = pdr / 10;
        i++;
    }
    return (i);
}

int counter(int x, int y)
{
    int count = y;
    int sell = 1;

    while (x > sell) {
        y = y * count;
        sell++;
    }
    return (y);
}

int activate(int tall, int modulo)
{
    while (tall > 0) {
        my_putchar(modulo * 10 / counter(tall, 10) + '0');
        if (tall != 0)
            modulo = modulo % counter(tall - 1, 10);
        tall--;
    }
    return (modulo);
}

int my_put_nbr(int nb)
{
    int modulo = nb;
    int tall = taller(nb);

    if (nb < 0) {
        modulo = nb * (-1);
        tall = taller(modulo);
        my_putchar('-');
    }
    return (modulo);
}
