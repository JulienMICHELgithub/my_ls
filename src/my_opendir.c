/*
** EPITECH PROJECT, 2023
** my
** File description:
** my_opendir.c
*/

#include "../include/include.h"

char *get_file_path(char *file_name, char *folder_path)
{
    int len = my_strlen(folder_path);
    char *cpy = NULL;
    int i = 0;

    if (folder_path[len - 1] == '/') {
        cpy = my_concat(folder_path, file_name);
        return (cpy);
    }
    len += my_strlen(file_name);
    cpy = malloc(sizeof(char) * len + 2);
    for (int j = 0; folder_path[j]; ++j) {
        cpy[j] = folder_path[j];
        ++i;
    }
    cpy[i] = '/';
    ++i;
    my_strcpy(&cpy[i], file_name);
    return (cpy);
}

node_t *my_opendir(char *str, int k)
{
    DIR *dir;
    node_t *first = NULL;
    struct dirent *entity;

    dir = opendir(str);
    if (!dir)
        return NULL;
    if (k & 8)
        return add_node(NULL, str, str);
    entity = readdir(dir);
    while (entity) {
        if (entity->d_name[0] != '.' || k & 1)
            first = add_node(first, entity->d_name,
                get_file_path(entity->d_name, str));
        entity = readdir(dir);
    }
    closedir(dir);
    return first;
}
