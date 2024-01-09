/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_empty
*/

#include "string.h"

int empty(const string_t *this)
{
    return (this == NULL || this->str == NULL || this->str[0] == '\0');
}
