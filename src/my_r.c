/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_r.c
*/

#include "../include/include.h"

int my_r(node_t *node, int k)
{
    while (node) {
        if (my_strncmp(node->file_name, ".", 2) != 0
            && my_strncmp(node->file_name, "..", 3) != 0)
            pre_ls(node->path, k);
        node = node->next;
    }
    return (SUCCESS);
}
