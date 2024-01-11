/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string_split
*/

#include <stdbool.h>
#include <string.h>

#include "string.h"

static
size_t count_words(const char *str, char separator)
{
    size_t count = 0;

    if (str == NULL || *str == '\0')
        return 0;
    while (true) {
        str = strchr(str, separator);
        count += 1;
        if (str == NULL || !*str)
            break;
        str += 1;
    }
    return count;
}

char **split_c(const string_t *this, char separator)
{
    char **array = NULL;
    char *ptr = NULL;
    char *end = NULL;
    size_t count = 0;

    if (this == NULL || this->str == NULL)
        return NULL;
    count = count_words(this->str, separator);
    array = calloc(count + 1, sizeof(char *));
    ptr = this->str;
    for (size_t i = 0; i < count; i++) {
        end = strchr(ptr, separator);
        if (end == NULL || !*end) {
            array[i] = strdup(ptr);
            break;
        }
        array[i] = strndup(ptr, end - ptr);
        ptr = end + 1;
    }
    return array;
}

string_t **split_s(const string_t *this, char separator)
{
    char **sarray = NULL;
    string_t **array = NULL;

    if (this == NULL || this->str == NULL)
        return NULL;
    array = calloc(
        (count_words(this->str, separator) + 1), sizeof(string_t *));
    sarray = split_c(this, separator);
    if (sarray == NULL)
        return NULL;
    for (size_t i = 0; sarray[i] != NULL; i++) {
        array[i] = malloc(sizeof(string_t));
        string_init(array[i], sarray[i]);
        free(sarray[i]);
    }
    free(sarray);
    return array;
}
