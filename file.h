#pragma once
#include <stddef.h>
#include "coolstr.h"

typedef struct File {
    coolstr_t* name;
    coolstr_t* path;
    struct File* next;
} file_t;

file_t* init_file(coolstr_t* name, coolstr_t* path);
