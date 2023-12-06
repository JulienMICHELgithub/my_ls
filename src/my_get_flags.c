/*
** EPITECH PROJECT, 2023
** my
** File description:
** main.c
*/

#include "../include/include.h"

static flag_t flags [] = {
    {'a', 1},
    {'l', 2},
    {'t', 4},
    {'d', 8},
    {'r', 16},
    {'R', 32},
    {0}
};

int my_get_flags(const char *str, int *k)
{
    int i = 1;

    for (int j = 0; flags[j].c;) {
        if (!str[i])
            return 0;
        if (flags[j].c == str[i]) {
            *k += (*k & flags[j].nb) ? 0 : flags[j].nb;
            ++i;
            j = 0;
            continue;
        }
        ++j;
        if (!flags[j].c) {
            my_putstr("my_error_gestion");
            return (ERROR);
        }
    }
    return 0;
}
