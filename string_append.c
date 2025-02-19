/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_assign
*/

#include <stdlib.h>
#include <string.h>

#include "string.h"

void append_c(string_t *this, const char *ap)
{
    char *ptr = NULL;

    if (this == NULL || ap == NULL)
        return;
    ptr = malloc((strlen(this->str) + strlen(ap) + 1) * sizeof(char));
    if (ptr == NULL)
        return;
    strcpy(ptr, this->str);
    strcat(ptr, ap);
    this->assign_c(this, ptr);
    free(ptr);
}

void append_s(string_t *this, const string_t *ap)
{
    if (this == NULL || ap == NULL)
        return;
    this->append_c(this, ap->str);
}
