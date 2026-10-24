#pragma once 
#include <stddef.h>

typedef struct CoolStr {
    char* data;
    size_t length;
    size_t capacity;
} coolstr_t;

coolstr_t* init_coolstr(coolstr_t* dest, const char* src);

int add_coolstr(coolstr_t* dest, const char* data);


