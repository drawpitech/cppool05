/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** tests
*/

#include <criterion/criterion.h>

#include "string.h"

Test(find_c, find_string)
{
    int offset;
    string_t s;

    string_init(&s, "Hello world");
    offset = s.find_c(&s, "world", 0);
    cr_assert_eq(offset, 6);
    string_destroy(&s);
}

Test(find_c, empty_string)
{
    int offset;
    string_t s;

    string_init(&s, "");
    offset = s.find_c(&s, "world", 0);
    cr_assert_eq(offset, -1);
    string_destroy(&s);
}

Test(find_c, not_found)
{
    int offset;
    string_t s;

    string_init(&s, "Hello world");
    offset = s.find_c(&s, "world", 7);
    cr_assert_eq(offset, -1);
    string_destroy(&s);
}

Test(find_c, start)
{
    int offset;
    string_t s;

    string_init(&s, "Hello world");
    offset = s.find_c(&s, "Hell", 0);
    cr_assert_eq(offset, 0);
    string_destroy(&s);
}
