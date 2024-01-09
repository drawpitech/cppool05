/*
** EPITECH PROJECT, 2024
** ppool05
** File description:
** string
*/

#ifndef PPOOL5_STRING_H
    #define PPOOL5_STRING_H

    #include <stdlib.h>

typedef struct string_s string_t;

struct string_s {
    char *str;
    void (*assign_c)(string_t *this, const char *s);
    void (*assign_s)(string_t *this, const string_t *s);
    void (*append_c)(string_t *this, const char *ap);
    void (*append_s)(string_t *this, const string_t *ap);
    char (*at)(const string_t *this, size_t pos);
    void (*clear)(string_t *this);
    int (*length)(const string_t *this);
    int (*compare_c)(const string_t *this, const char *str);
    int (*compare_s)(const string_t *this, const string_t *str);
};

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);

void assign_c(string_t *this, const char *s);
void assign_s(string_t *this, const string_t *str);

void append_c(string_t *this, const char *ap);
void append_s(string_t *this, const string_t *ap);

char at(const string_t *this, size_t pos);

void clear(string_t *this);

int length(const string_t *this);

int compare_c(const string_t *this, const char *str);
int compare_s(const string_t *this, const string_t *str);

#endif /* PPOOL5_STRING_H */
