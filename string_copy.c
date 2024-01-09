/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_copy
*/

#include <string.h>
#include <sys/param.h>

#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t len;

    if (this == NULL || this->str == NULL || s == NULL)
        return 0;
    len = strlen(this->str) + 1;
    if (pos > len)
        return 0;
    n = MIN(len - pos, n);
    strncpy(s, this->str + pos, n);
    return n;
}
