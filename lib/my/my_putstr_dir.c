/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_putstr_dir
*/

#include "libmy.h"

void my_putstr_dir(char *str)
{
    write(1, str, my_strlen(str));
}
