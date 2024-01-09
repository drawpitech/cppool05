/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** tests
*/

#include <criterion/criterion.h>

#include "string.h"

Test(assign_c, normal)
{
    string_t s;

    string_init(&s, "") ;
    s.assign_c(&s, "Hello World");
    cr_assert_str_eq(s.str, "Hello World");
    string_destroy(&s);
}

Test(assign_c, two_calls)
{
    string_t s;

    string_init(&s, "") ;
    s.assign_c(&s, "Hello World");
    s.assign_c(&s, "bob");
    cr_assert_str_eq(s.str, "bob");
    string_destroy(&s);
}

Test(assign_s, normal)
{
    string_t s1;
    string_t s2;

    string_init(&s1, "") ;
    string_init(&s2, "Hello World") ;
    s1.assign_s(&s1, &s2);
    cr_assert_str_eq(s1.str, "Hello World");
    string_destroy(&s1);
    string_destroy(&s2);
}
