/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string
*/

#ifndef PPOOL5_STRING_H
    #define PPOOL5_STRING_H

typedef struct string_s string_t;

struct string_s {
    char *str;
    void (*assign_c)(string_t *this, const char *s);
    void (*assign_s)(string_t *this, const string_t *s);
};

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void assign_c(string_t *this, const char *s);
void assign_s(string_t *this, const string_t *str);

#endif /* PPOOL5_STRING_H */
