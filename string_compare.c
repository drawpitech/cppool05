/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_compare
*/

#include <string.h>

#include "string.h"

int compare_c(const string_t *this, const char *str)
{
    if (this == NULL || this->str == NULL || str == NULL)
        return -1;
    return strcmp(this->str, str);
}

int compare_s(const string_t *this, const string_t *str)
{
    if (this == NULL || str == NULL || this->compare_c)
        return -1;
    return this->compare_c(this, str->str);
}
