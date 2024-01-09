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
    *this = (string_t){
        .str = strdup(s),
        .assign_c = &assign_c, .assign_s = &assign_s, .append_c = &append_c,
        .append_s = &append_s, .at = &at, .clear = &clear, .length = &length,
        .compare_c = &compare_c, .compare_s = &compare_s, .copy = &copy,
        .c_str = &c_str, .empty = &empty, .find_c = &find_c, .find_s = &find_s,
        .insert_c = &insert_c, .insert_s = &insert_s, .to_int = &to_int,
        .split_c = &split_c, .split_s = &split_s, .print = &print,
        .join_c = &join_c, .join_s = &join_s,
    };
}

void string_destroy(string_t *this)
{
    if (this == NULL || this->str == NULL)
        return;
    free(this->str);
    *this = (string_t){ 0 };
}
