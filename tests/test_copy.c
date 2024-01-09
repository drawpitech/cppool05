/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** tests
*/

#include <criterion/criterion.h>

#include "string.h"

Test(copy, full_string)
{
    char buf[12] = {0};
    string_t s;
    size_t res;

    string_init(&s, "Hello World");
    res = s.copy(&s, buf, 12, 0);
    cr_assert_str_eq(buf, "Hello World");
    cr_assert_eq(res, 12);
}

Test(copy, empty_string)
{
    char buf[12] = {0};
    string_t s;
    size_t res;

    string_init(&s, "");
    res = s.copy(&s, buf, 12, 0);
    cr_assert_str_empty(buf);
    cr_assert_eq(res, 1);
}

Test(copy, empty_string_v2)
{
    char buf[12] = {0};
    string_t s;
    size_t res;

    string_init(&s, "");
    res = s.copy(&s, buf, 0, 0);
    cr_assert_str_empty(buf);
    cr_assert_eq(res, 0);
}

Test(copy, partial_string)
{
    char buf[12] = {0};
    string_t s;
    size_t res;

    string_init(&s, "Hello World");
    res = s.copy(&s, buf, 5, 0);
    cr_assert_str_eq(buf, "Hello");
    cr_assert_eq(res, 5);
}

Test(copy, partial_string_with_offset)
{
    char buf[12] = {0};
    string_t s;
    size_t res;

    string_init(&s, "Hello World");
    res = s.copy(&s, buf, 5, 6);
    cr_assert_str_eq(buf, "World");
    cr_assert_eq(res, 5);
}
