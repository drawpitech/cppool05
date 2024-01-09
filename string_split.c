/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_split
*/

#include <string.h>

#include "string.h"

char **split_c(const string_t *this, char separator)
{
    size_t size = 0;
    char **array = NULL;
    char *ptr;
    char sep[] = {separator, '\0'};

    if (this == NULL || this->str == NULL)
        return NULL;
    ptr = strdup(this->str);
    array = malloc(sizeof(char *));
    while (*ptr) {
        array = reallocarray(array, size + 2, sizeof(char *));
        array[size] = ptr;
        strsep(&ptr, sep);
        size += 1;
    }
    array[size] = NULL;
    return array;
}

string_t **split_s(const string_t *this, char separator)
{
    char **array = NULL;
    string_t **result = NULL;
    size_t size = 0;
    string_t *ptr;

    if (this == NULL || this->str == NULL)
        return NULL;
    array = split_c(this, separator);
    array = malloc(sizeof(char *));
    while (*array) {
        array = reallocarray(array, size + 2, sizeof(char *));
        ptr = malloc(sizeof(string_t));
        string_init(ptr, array[size]);
        free(array[size]);
        result[size] = ptr;
        size += 1;
    }
    array[size] = NULL;
    free(array);
    return result;
}
