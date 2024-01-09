/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_assign
*/

#include "string.h"

void assign_c(string_t *this, const char *s)
{
    string_destroy(this);
    string_init(this, s);
}

void assign_s(string_t *this, const string_t *str)
{
    assign_c(this, str->str);
}
