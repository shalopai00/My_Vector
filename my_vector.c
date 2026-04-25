#include "my_vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t vec_capacity(const Vector* vec) {
    return vec->capacity;
}
size_t vec_size(const Vector* vec) {
    return vec->size;
};
void* vec_data(const Vector* vec) {
    return vec->data;
};

Vector* vec_new(size_t element_size) {
    Vector* vec = (Vector*) malloc(sizeof(Vector));   //Vector* vec = malloc(sizeof(Vector)); ??
    if (!vec) return NULL;
    vec->capacity =0;
    vec->size = 0;
    vec->data = NULL;
    vec->element_size = element_size;
    return vec;
};

void vec_free(Vector *vec) {
    free(vec->data);
    free(vec);
};

int vec_push(Vector* vec, const void* element) {
    if (vec->size >= vec->capacity) {
        size_t new_capacity = vec->capacity == 0 ? 4 : vec->capacity * 2;
        void *new_data = realloc(vec->data, new_capacity * vec->element_size);
        if (new_data == NULL) { return -1;}
        vec->data = new_data;
        vec->capacity = new_capacity;
    }
    char* dest = (char *) vec->data + vec->size * vec->element_size;
    memcpy(dest, element, vec->element_size);
    vec->size++;
    return 0;
};

int vec_pop(Vector* vec) {
    if (!vec || vec->size == 0) return -1;
    vec->size--;
    return 0;
};

void* vec_at(Vector* vec, size_t index) {
    if (!vec || index>vec->size){return NULL;}
    return (char*) vec->data + index * vec->element_size;
};

bool vec_empty(Vector* vec) {     // const Vector *vec ??
    if (!vec || vec->size == 0) {return true;} else {return false;}
};

int vec_reserve(Vector* vec, size_t capacity) {
    if (!vec || vec->capacity>capacity){return -1;}
    size_t new_capacity = capacity;
    void *same_data = realloc(vec->data, new_capacity * vec->element_size);
    if (same_data == NULL) { return -1; }
    vec->data = same_data;
    vec->capacity = new_capacity;
    return 0;
};

void vec_clear(Vector* vec) {
    if (!vec || vec->size == 0){return;}
    vec->size = 0;
};


