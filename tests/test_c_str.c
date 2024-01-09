/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** tests
*/

#include <criterion/criterion.h>

#include "string.h"

Test(c_str, return_c_str)
{
    const char *ptr;
    string_t s;

    string_init(&s, "Hello world");
    ptr = s.c_str(&s);
    cr_assert_str_eq(ptr, "Hello world");
    cr_assert_eq(ptr, s.str);
    string_destroy(&s);
}

Test(c_str, empty_string)
{
    const char *ptr;
    string_t s;

    string_init(&s, "");
    ptr = s.c_str(&s);
    cr_assert_str_eq(ptr, "");
    cr_assert_eq(ptr, s.str);
    string_destroy(&s);
}
