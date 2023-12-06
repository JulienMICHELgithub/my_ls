/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_strcpy
*/

#include "libmy.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i]) {
        ++i;
    }
    return i;
}
