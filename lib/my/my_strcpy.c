/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}
