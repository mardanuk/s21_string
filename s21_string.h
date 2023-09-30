#ifndef S21_STRING_H_
#define S21_STRING_H_

#define S21_NULL ((void *)0)

typedef unsigned long int s21_size_t;

void *s21_memchr(const void *, int, s21_size_t);

int s21_memcmp(const void *, const void *, s21_size_t);

void *s21_memcpy(void *, const void *, s21_size_t);

void *s21_memset(void *, int, s21_size_t);

char *s21_strncat(char *, const char *, s21_size_t);

char *s21_strchr(const char *, int);

int s21_strncmp(const char *, const char *, s21_size_t);

char *s21_strncpy(char *, const char *, s21_size_t);

s21_size_t s21_strcspn(const char *, const char *);

char *s21_strerror(int);

s21_size_t s21_strlen(const char *);

char *s21_strpbrk(const char *, const char *);

char *s21_strrchr(const char *, int);

char *s21_strstr(const char *, const char *);

char *s21_strtok(char *, const char *);

int s21_sscanf(const char *, const char *, ...);

int s21_sprintf(char *, const char *, ...);

void *s21_to_upper(const char *);

void *s21_to_lower(const char *);

void *s21_insert(const char *, const char *, s21_size_t);

void *s21_trim(const char *, const char *);

long double s21_atof(const char *);

long long s21_strtol(const char *, char **, int);

char *s21_itoa(long int, char *, int);

char *s21_ftoa(long double, char *, int);

#endif