/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_concat
*/

#include "libmy.h"

char *my_concat(char *s1, char *s2)
{
    int len = my_strlen(s1) + my_strlen(s2);
    char *str = malloc(sizeof(char) * len + 1);
    int k = 0;

    str[len] = '\0';
    for (int i = 0; s1[i]; ++i) {
        str[k] = s1[i];
        ++k;
    }
    for (int i = 0; s2[i]; ++i) {
        str[k] = s2[i];
        ++k;
    }
    return (str);
}
