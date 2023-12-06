/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_t.c
*/

#include "../include/include.h"

void my_swap(node_t *n1, node_t *n2)
{
    char *path = NULL;
    char *file_name = NULL;

    path = n1->path;
    file_name = n1->file_name;
    n1->path = n2->path;
    n1->file_name = n2->file_name;
    n2->path = path;
    n2->file_name = file_name;
}

int my_t(node_t *node)
{
    struct stat sb1;
    struct stat sb2;
    node_t *current = node;

    while (current->next) {
        if (lstat(current->path, &sb1) == -1
            || lstat(current->next->path, &sb2) == -1) {
            return (FAILURE);
        }
        if (sb1.st_mtime < sb2.st_mtime) {
            my_swap(current, current->next);
            current = node;
        } else {
            current = current->next;
        }
    }
    return (SUCCESS);
}
