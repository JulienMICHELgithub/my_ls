/*
** EPITECH PROJECT, 2023
** include
** File description:
** include
*/

#pragma once

#include "../lib/my/libmy.h"

#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <time.h>
#include <stdbool.h>

#define SUCCESS 0
#define FAILURE 1
#define ERROR 84

typedef struct node_s {
    char *file_name;
    char *path;
    struct node_s *next;
}node_t;

node_t *add_node(node_t *old, char *file_name, char *file_path);
void print_list(node_t *node);

typedef struct flag_s {
    char c;
    int nb;
}flag_t;

int my_ls(node_t *node, int k);
int pre_ls(char *str, int k);

node_t *my_opendir(char *str, int k);
int my_get_flags(const char *str, int *k);
int my_l(char *file_path);
int my_r(node_t *node, int k);
int my_t(node_t *node);
int my_total(node_t *node);
