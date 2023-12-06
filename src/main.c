/*
** EPITECH PROJECT, 2023
** my
** File description:
** main.c
*/

#include "../include/include.h"

static void reverse_list(node_t **head)
{
    node_t *prev = NULL;
    node_t *current = *head;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int my_ls(node_t *node, int k)
{
    if (k & 2)
        my_total(node);
    for (node_t *tmp = node; tmp; tmp = tmp->next) {
        if (k & 2)
            my_l(tmp->path);
        my_putstr(tmp->file_name);
        my_putchar('\n');
    }
    if (k & 32 && !(k & 8)) {
        my_r(node, k);
    }
    return (SUCCESS);
}

int pre_ls(char *str, int k)
{
    static bool b = false;
    node_t *node = my_opendir(str, k);

    if (!node)
        return (SUCCESS);
    if (k & 32 && !(k & 8)) {
        if (!b) {
            b = true;
        } else {
            my_putchar('\n');
        }
        my_putstr(str);
        my_putstr(":\n");
    }
    if (k & 4)
        my_t(node);
    if (k & 16)
        reverse_list(&node);
    my_ls(node, k);
    return (SUCCESS);
}

int my_init(char **av, node_t **node, int *k)
{
    int rvalue = SUCCESS;
    DIR *dir = NULL;

    for (int i = 1; av[i]; ++i) {
        if (av[i][0] == '-' && av[i][1]) {
            my_get_flags(av[i], k);
            continue;
        }
        dir = opendir(av[i]);
        if (!dir) {
            my_puterror("ls: cannot access '");
            my_puterror(av[i]);
            my_puterror("': No such file or directory\n");
            rvalue = ERROR;
        } else {
            node[0] = add_node(node[0], av[i], NULL);
            closedir(dir);
        }
    }
    return (rvalue);
}

int main(int ac, char *av[])
{
    int k = 0;
    node_t *node = NULL;
    int rvalue = 0;

    if (ac == 1) {
        node = my_opendir(".", k);
        print_list(node);
        return (SUCCESS);
    }
    rvalue = my_init(av, &node, &k);
    if (!node && !rvalue) {
        pre_ls(".", k);
        return (rvalue);
    }
    for (int i = 1; av[i]; ++i) {
        pre_ls(av[i], k);
    }
    return (rvalue);
}
