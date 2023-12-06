/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_strcpy
*/

#include "libmy.h"

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *cpy = malloc(sizeof(char) * len + 1);

    cpy[len] = '\0';
    for (int i = 0; str[i]; ++i) {
        cpy[i] = str[i];
    }
    return (cpy);
}
