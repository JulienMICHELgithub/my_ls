/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_put_nbr
*/

#include "libmy.h"

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return 0;
    }
    if (nb >= 0 && nb <= 9)
        my_putchar('0' + nb);
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar('0' + (nb % 10));
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb *= -1);
    }
    return 0;
}
