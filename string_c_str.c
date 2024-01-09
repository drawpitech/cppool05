/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_c_str
*/

#include "string.h"

const char *c_str(const string_t *this)
{
    return (this == NULL || this->str == NULL)
        ? NULL
        : this->str;
}
