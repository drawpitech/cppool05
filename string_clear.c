/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_clear
*/

#include "string.h"

void clear(string_t *this)
{
    if (this == NULL)
        return;
    this->assign_c(this, "");
}
