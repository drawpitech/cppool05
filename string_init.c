/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** init
*/

#include <stdlib.h>
#include <string.h>

#include "string.h"

void string_init(string_t *this, const char *s)
{
    if (this == NULL || s == NULL)
        return;
    *this = (string_t){ 0 };
    this->str = strdup(s);
    this->assign_c = &assign_c;
    this->assign_s = &assign_s;
    this->append_c = &append_c;
    this->append_s = &append_s;
    this->at = &at;
    this->clear = &clear;
    this->length = &length;
    this->compare_c = &compare_c;
    this->compare_s = &compare_s;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
}

void string_destroy(string_t *this)
{
    if (this == NULL || this->str == NULL)
        return;
    free(this->str);
    *this = (string_t){ 0 };
}
