/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** tests
*/

#include <criterion/criterion.h>

#include "string.h"

Test(empty, empty_string)
{
    string_t s;

    string_init(&s, "");
    cr_assert_eq(s.empty(&s), 1);
    string_destroy(&s);
}

Test(empty, not_empty_string)
{
    string_t s;

    string_init(&s, "Hello world");
    cr_assert_eq(s.empty(&s), 0);
    string_destroy(&s);
}
