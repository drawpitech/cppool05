/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** tests
*/

#include <criterion/criterion.h>

#include "string.h"

Test(string_at, should_return_char_at_index)
{
    string_t s;

    string_init(&s, "Hello World");
    cr_assert_eq(at(&s, 0), 'H');
    cr_assert_eq(at(&s, 1), 'e');
    cr_assert_eq(at(&s, 2), 'l');
    cr_assert_eq(at(&s, 3), 'l');
    cr_assert_eq(at(&s, 4), 'o');
    cr_assert_eq(at(&s, 5), ' ');
    cr_assert_eq(at(&s, 6), 'W');
    cr_assert_eq(at(&s, 7), 'o');
    cr_assert_eq(at(&s, 8), 'r');
    cr_assert_eq(at(&s, 9), 'l');
    cr_assert_eq(at(&s, 10), 'd');
    string_destroy(&s);
}

Test(string_at, should_return_minus_one)
{
    string_t s;

    string_init(&s, "Hello World");
    cr_assert_eq(at(&s, 15), -1);
    cr_assert_eq(at(&s, 1500), -1);
    string_destroy(&s);
}
