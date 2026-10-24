#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coolstr.h"

coolstr_t* init_coolstr(const char* src) {
    coolstr_t* tmp = malloc(sizeof(coolstr_t));
    size_t tmp_len = strlen(src) + 1;
    if (tmp == NULL)
        return NULL;

    char* tmp_data = (char*) malloc(sizeof(*src) * tmp_len);
    if (tmp_data == NULL) {
        free(tmp);
        return NULL;
    }

    tmp->data = tmp_data;
    strcpy(tmp->data, src); 
    tmp->length = tmp_len - 1;
    tmp->capacity = sizeof(*src) * tmp_len;

    return tmp;
}

int add_coolstr(coolstr_t* dest, const char* src) {
    size_t tmp_len = strlen(src);

    if (dest->capacity < (dest->length + tmp_len + 1) * sizeof(*src)) {
        char* tmp_buf = realloc(dest->data, dest->capacity + sizeof(*src) * tmp_len);
        if (tmp_buf == NULL) {
            fprintf(stderr, "fatal: Failed to allocate memory");
            return 1;
        }
        dest->data = tmp_buf;
        dest->capacity += sizeof(*src) * tmp_len;
    }

    strcat(dest->data, src);
    dest->length = strlen(dest);
    return 0;
}
