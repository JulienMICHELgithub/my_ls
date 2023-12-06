/*
** EPITECH PROJECT, 2023
** my
** File description:
** main.c
*/

#include "../include/include.h"

static void my_put_perm(struct stat *sb)
{
    my_putchar((S_ISDIR(sb->st_mode)) ? 'd' : '-');
    my_putchar((sb->st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar((sb->st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar((sb->st_mode & S_IXUSR) ? 'x' : '-');
    my_putchar((sb->st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar((sb->st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar((sb->st_mode & S_IXGRP) ? 'x' : '-');
    my_putchar((sb->st_mode & S_IROTH) ? 'r' : '-');
    my_putchar((sb->st_mode & S_IWOTH) ? 'w' : '-');
    if (sb->st_mode & S_ISVTX) {
        my_putchar('t');
    } else if (sb->st_mode & S_IXOTH) {
        my_putchar('x');
    } else {
        my_putchar('-');
    }
    my_putchar(' ');
    my_put_nbr((int)sb->st_nlink);
    my_putchar(' ');
}

static int my_put_cred(struct stat *sb)
{
    struct passwd *pw;
    struct group  *gr;

    pw = getpwuid(sb->st_uid);
    my_putstr(pw->pw_name);
    my_putchar(' ');
    gr = getgrgid(sb->st_gid);
    my_putstr(gr->gr_name);
    my_putchar(' ');
    return 0;
}

int my_total(node_t *node)
{
    struct stat sb;
    int tot = 0;

    while (node) {
        if (lstat(node->path, &sb) == -1) {
            return (0);
        }
        tot += sb.st_blocks;
        node = node->next;
    }
    my_putstr("total ");
    my_put_nbr(tot / 2);
    my_putchar('\n');
    return (0);
}

int my_l(char *file_path)
{
    struct stat sb;
    char *test = NULL;

    if (lstat(file_path, &sb) == -1) {
        return (FAILURE);
    }
    my_put_perm(&sb);
    my_put_cred(&sb);
    my_put_nbr((int)sb.st_size);
    my_putchar(' ');
    test = ctime(&sb.st_mtime) + 4;
    test[12] = ' ';
    write(1, test, 13);
    return SUCCESS;
}
