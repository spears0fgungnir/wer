#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coolstr.h"

coolstr_t* init_coolstr(const char* src) {
    coolstr_t* tmp = malloc(sizeof(coolstr_t));
    if (tmp == NULL)
        return NULL;

    char* tmp_data = (char*) malloc(sizeof(*src));
    if (tmp_data == NULL) {
        free(tmp);
        return NULL;
    }

    tmp->data = tmp_data;
    strcpy(tmp->data, src);
    size_t tmp_len = strlen(src);
    tmp->length = tmp_len;
    tmp->capacity = sizeof(*src);

    return tmp;
}

int add_coolstr(coolstr_t* dest, const char* src) {
    size_t tmp_len = strlen(src);

    if (dest->capacity < dest->length + tmp_len + 1) {
        char* tmp_buf = realloc(dest->data, dest->capacity + sizeof(*src));
        if (tmp_buf == NULL) {
            fprintf(stderr, "fatal: Failed to allocate memory");
            return 1;
        }
        dest->data = tmp_buf;
        dest->capacity += sizeof(*src);
    }

    strcat(dest, src);
    dest->length = strlen(dest);
    return 0;
}
