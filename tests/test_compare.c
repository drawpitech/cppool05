/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** tests
*/

#include <criterion/criterion.h>

#include "string.h"

Test(compare_c, same)
{
    string_t s;

    string_init(&s, "Hello world");
    cr_assert_eq(s.compare_c(&s, "Hello world"), 0);
    string_destroy(&s);
}

Test(compare_c, different)
{
    string_t s;

    string_init(&s, "Hello world");
    cr_assert(s.compare_c(&s, "Hello") > 0);
    string_destroy(&s);
}

Test(compare_s, same)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello world");
    string_init(&s2, "Hello world");
    cr_assert_eq(s.compare_s(&s, &s2), 0);
    string_destroy(&s);
    string_destroy(&s2);
}

Test(compare_s, different)
{
    string_t s;
    string_t s2;

    string_init(&s, "Hello world");
    string_init(&s2, "Hello");
    cr_assert(s.compare_s(&s, &s2) > 0);
    string_destroy(&s);
    string_destroy(&s2);
}
