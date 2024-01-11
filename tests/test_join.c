/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** tests
*/

#include <criterion/criterion.h>

#include "string.h"

static
void free_char_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

static
void free_string_array(string_t **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        string_destroy(array[i]);
        free(array[i]);
    }
    free(array);
}

Test(join_c, normal)
{
    string_t s;
    string_t cmp;
    char **array = NULL;

    string_init(&s, "Hello World") ;
    string_init(&cmp, "");
    array = s.split_c(&s, ' ');
    cr_assert_not_null(array);
    cmp.join_c(&cmp, ' ', (const char *const *)array);
    cr_assert_str_eq(cmp.str, "Hello World");
    free_char_array(array);
    string_destroy(&s);
    string_destroy(&cmp);
}

Test(join_c, empty)
{
    string_t s;
    string_t cmp;
    char **array = NULL;

    string_init(&s, "") ;
    string_init(&cmp, "");
    array = s.split_c(&s, ' ');
    cr_assert_not_null(array);
    cmp.join_c(&cmp, ' ', (const char *const *)array);
    cr_assert_str_eq(cmp.str, "");
    free_char_array(array);
    string_destroy(&s);
    string_destroy(&cmp);
}

Test(join_c, long) 
{
    string_t s;
    string_t cmp;
    char **array = NULL;

    string_init(&s, "Hello World, I'm a long string");
    string_init(&cmp, "");
    array = s.split_c(&s, ' ');
    cr_assert_not_null(array);
    cmp.join_c(&cmp, ' ', (const char *const *)array);
    cr_assert_str_eq(cmp.str, "Hello World, I'm a long string");
    free_char_array(array);
    string_destroy(&s);
    string_destroy(&cmp);
}

Test(join_s, normal)
{
    string_t s;
    string_t **array = NULL;
    string_t cmp;

    string_init(&s, "Hello World") ;
    string_init(&cmp, "");
    array = s.split_s(&s, ' ');
    cr_assert_not_null(array);
    cmp.join_s(&cmp, ' ', (const string_t *const *)array);
    cr_assert_str_eq(cmp.str, "Hello World");
    free_string_array(array);
    string_destroy(&s);
    string_destroy(&cmp);
}
