/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "string.h"

Test(print, normal, .init=cr_redirect_stdout)
{
    string_t s;

    setbuf(stdout, NULL);
    string_init(&s, "Hello world");
    s.print(&s);
    cr_assert_stdout_eq_str("Hello world");
    string_destroy(&s);
}
