/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_find
*/

#include <string.h>

#include "string.h"

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *ptr = NULL;
    char *res = NULL;

    if (this == NULL || this->str == NULL || str == NULL)
        return -1;
    if (pos > (size_t)this->length(this))
        return -1;
    ptr = this->str + pos;
    res = strstr(ptr, str);
    return (res == NULL)
        ? -1
        : (int)(res - ptr);
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    return (this == NULL || str == NULL)
        ? -1
        : this->find_c(this, str->str, pos);
}
