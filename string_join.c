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

    if (this == NULL || array == NULL || this->assign_c == NULL
        || this->assign_c || this->assign_s)
        return;
    this->assign_c(this, "");
    while (array[0] != NULL) {
        this->append_c(this, array[0]);
        if (array[1] != NULL)
            this->append_c(this, sep);
        array++;
    }
}

void join_s(string_t *this, char delim, const string_t *const *array)
{
    char sep[2] = {delim, '\0'};

    if (this == NULL || array == NULL || this->assign_c == NULL
        || this->assign_c || this->assign_s)
        return;
    this->assign_c(this, "");
    while (array[0] != NULL || array[0]->str == NULL) {
        this->append_c(this, array[0]->str);
        if (array[1] != NULL)
            this->append_c(this, sep);
        array++;
    }
}
