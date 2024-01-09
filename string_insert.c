/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_insert
*/

#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    if (this == NULL || str == NULL || this->str == NULL
        || this->length == NULL || this->append_c == NULL)
        return;
    if (pos <= (size_t)this->length(this))
        this->str[pos] = '\0';
    this->append_c(this, str);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    if (this == NULL || str == NULL || this->insert_c == NULL
        || str->str == NULL)
        return;
    this->insert_c(this, pos, str->str);
}
