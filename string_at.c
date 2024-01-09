/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_at
*/

#include "string.h"

char at(const string_t *this, size_t pos)
{
    char *ptr = NULL;

    if (this == NULL || this->str == NULL)
        return -1;
    ptr = this->str;
    for (; pos; pos--) {
        if (*ptr == '\0')
            return -1;
        ptr++;
    }
    return *ptr;
}
