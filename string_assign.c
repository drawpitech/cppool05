/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_assign
*/

#include <stdio.h>
#include <stdlib.h>

#include "string.h"

void assign_c(string_t *this, const char *s)
{
    if (this == NULL || s == NULL)
        return;
    string_destroy(this);
    string_init(this, s);
}

void assign_s(string_t *this, const string_t *str)
{
    if (this == NULL || str == NULL || this->assign_c == NULL)
        return;
    this->assign_c(this, str->str);
}
