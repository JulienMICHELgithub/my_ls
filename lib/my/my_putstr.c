/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_putstr
*/

#include "libmy.h"

int my_putstr(char *str)
{
    return (write(1, str, my_strlen(str)));
}
