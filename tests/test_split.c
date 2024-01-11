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

Test(split_c, normal)
{
    string_t s;
    char **array = NULL;

    string_init(&s, "Hello World") ;
    array = s.split_c(&s, ' ');
    cr_assert_not_null(array);
    cr_assert_str_eq(array[0], "Hello");
    cr_assert_str_eq(array[1], "World");
    cr_assert_null(array[2]);
    free_char_array(array);
    string_destroy(&s);
}

Test(split_c, empty)
{
    string_t s;
    char **array = NULL;

    string_init(&s, "") ;
    array = s.split_c(&s, ' ');
    cr_assert_not_null(array);
    cr_assert_str_eq(array[0], "");
    cr_assert_null(array[1]);
    free_char_array(array);
    string_destroy(&s);
}

Test(split_c, long) 
{
    string_t s;
    char **array = NULL;

    string_init(&s, "Hello World, I'm a long string");
    array = s.split_c(&s, ' ');
    cr_assert_not_null(array);
    cr_assert_str_eq(array[0], "Hello");
    cr_assert_str_eq(array[1], "World,");
    cr_assert_str_eq(array[2], "I'm");
    cr_assert_str_eq(array[3], "a");
    cr_assert_str_eq(array[4], "long");
    cr_assert_str_eq(array[5], "string");
    cr_assert_null(array[6]);
    free_char_array(array);
    string_destroy(&s);
}

Test(split_s, normal)
{
    string_t s;
    string_t **array = NULL;
    string_t cmp;

    string_init(&s, "Hello World") ;
    array = s.split_s(&s, ' ');
    cr_assert_not_null(array);
    string_init(&cmp, "Hello");
    cr_assert_str_eq(array[0]->str, cmp.str);
    cmp.assign_c(&cmp, "World");
    cr_assert_str_eq(array[1]->str, cmp.str);
    cr_assert_null(array[2]);
    free_string_array(array);
    string_destroy(&s);
    string_destroy(&cmp);
}
