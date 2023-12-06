/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_putstr
*/

#include "libmy.h"

int my_puterror(char *str)
{
    return (write(2, str, my_strlen(str)));
}
