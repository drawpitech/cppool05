/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string
*/

#ifndef PPOOL5_STRING_H
    #define PPOOL5_STRING_H

typedef struct {
    char *str;
} string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);

#endif /* PPOOL5_STRING_H */
