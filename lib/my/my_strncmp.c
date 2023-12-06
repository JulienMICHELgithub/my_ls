/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_put_nbr
*/

#include "libmy.h"

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (s1[i] && s2[i] && i < n) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        ++i;
    }
    return (0);
}
