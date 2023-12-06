/*
** EPITECH PROJECT, 2023
** my
** File description:
** linked_list
*/

#include "../include/include.h"

node_t *create_node(char *file_name, char *file_path)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return NULL;
    node->next = NULL;
    node->file_name = my_strdup(file_name);
    node->path = file_path;
    return (node);
}

node_t *add_node(node_t *old, char *file_name, char *file_path)
{
    node_t *node = create_node(file_name, file_path);

    if (!node)
        return NULL;
    node->next = old;
    return (node);
}

void print_list(node_t *node)
{
    while (node) {
        my_putstr(node->file_name);
        my_putchar('\n');
        node = node->next;
    }
}
