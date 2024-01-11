/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_join
*/

#include "string.h"

void join_c(string_t *this, char delim, const char *const *array)
{
    char sep[2] = {delim, '\0'};

    if (this == NULL || array == NULL)
        return;
    this->assign_c(this, "");
    for (; array[0] != NULL; array++) {
        this->append_c(this, array[0]);
        if (array[1] != NULL)
            this->append_c(this, sep);
    }
}

void join_s(string_t *this, char delim, const string_t *const *array)
{
    char sep[2] = {delim, '\0'};

    if (this == NULL || array == NULL)
        return;
    this->assign_c(this, "");
    for (; array[0] != NULL && array[0]->str != NULL; array++) {
        this->append_s(this, array[0]);
        if (array[1] != NULL)
            this->append_c(this, sep);
    }
}
