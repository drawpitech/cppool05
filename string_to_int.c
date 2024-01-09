/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_to_int
*/

#include "string.h"

int to_int(const string_t *this)
{
    return (this == NULL || this->str == NULL)
        ? 0
        : atoi(this->str);
}
