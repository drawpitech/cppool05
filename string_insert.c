/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_insert
*/

#include <string.h>

#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *start = NULL;
    char *end = NULL;

    if (this == NULL || str == NULL || this->str == NULL)
        return;
    start = strndup(this->str, pos);
    end = (pos <= (size_t)this->length(this))
        ? strdup(this->str + pos)
        : strdup("");
    this->assign_c(this, start);
    this->append_c(this, str);
    this->append_c(this, end);
    free(start);
    free(end);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    if (this == NULL || str == NULL || str->str == NULL)
        return;
    this->insert_c(this, pos, str->str);
}
