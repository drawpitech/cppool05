/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_length
*/

#include <string.h>

#include "string.h"

int length(const string_t *this)
{
    return (this == NULL || this->str == NULL)
        ? -1
        : (int)strlen(this->str);
}
