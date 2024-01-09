/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** tests
*/

#include <criterion/criterion.h>

#include "string.h"

Test(append_c, normal)
{
    string_t s;

    string_init(&s, "Hello") ;
    s.append_c(&s, " World");
    cr_assert_str_eq(s.str, "Hello World");
    string_destroy(&s);
}

Test(append_c, two_strings)
{
    string_t s;

    string_init(&s, "Hello") ;
    s.append_c(&s, " World");
    s.append_c(&s, "!");
    cr_assert_str_eq(s.str, "Hello World!");
    string_destroy(&s);
}

Test(append_c, empty_string)
{
    string_t s;

    string_init(&s, "HE") ;
    s.append_c(&s, "");
    cr_assert_str_eq(s.str, "HE");
    string_destroy(&s);
}

Test(append_s, normal)
{
    string_t s1;
    string_t s2;

    string_init(&s1, "Hello") ;
    string_init(&s2, " World");
    s1.append_s(&s1, &s2);
    cr_assert_str_eq(s1.str, "Hello World");
    string_destroy(&s1);
    string_destroy(&s2);
}
