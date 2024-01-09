/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** tests
*/

#include <criterion/criterion.h>

#include "string.h"

Test(length, length_string)
{
    string_t s;

    string_init(&s, "Hello world");
    cr_assert_eq(s.length(&s), 11);
    string_destroy(&s);
}

Test(length, empty_string)
{
    string_t s;

    string_init(&s, "");
    cr_assert_eq(s.length(&s), 0);
    string_destroy(&s);
}

Test(length, append)
{
    string_t s;

    string_init(&s, "Hello");
    s.append_c(&s, " world");
    cr_assert_eq(s.length(&s), 11);
    string_destroy(&s);
}
