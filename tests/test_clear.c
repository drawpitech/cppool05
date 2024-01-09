/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** tests
*/

#include <criterion/criterion.h>

#include "string.h"

Test(clear, clear_string)
{
    string_t s;

    string_init(&s, "Hello world");
    s.clear(&s);
    cr_assert_str_empty(s.str);
    string_destroy(&s);
}

Test(clear, empty_string)
{
    string_t s;

    string_init(&s, "");
    s.clear(&s);
    cr_assert_str_empty(s.str);
    string_destroy(&s);
}
