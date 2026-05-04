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

int vec_shrink(Vector* vec) {
    if (!vec){return -1;}
    if (vec->size == 0) {
        free(vec->data);
        vec->data = NULL;
        vec->capacity = 0;
        return 0;
    }
    if (vec->size * 2 <= vec->capacity) {
        size_t new_capacity = vec->size;
        if (new_capacity < 4) {
            new_capacity = 4;
        }
        void* same_data = realloc(vec->data, new_capacity * vec->element_size);
        if (same_data == NULL) { return -1; }
        vec->data = same_data;
        vec->capacity = new_capacity;
    };
    return 0;
};

void* vec_front(Vector* vec) {
    if (!vec || vec->size == 0) {return NULL;}
    return vec_data(vec);
};

void* vec_back(Vector* vec) {
    if (!vec || vec->size == 0){return NULL;}
    return (char*) vec_data(vec)+(vec->size - 1) * vec->element_size;
};

int vec_insert(Vector* vec, size_t index, const void* element) {
    if (!vec){return -1;}
    if (index > vec->size) {return -1;}
    if (vec->size >= vec->capacity) {
        size_t new_cap = vec->capacity == 0 ? 4 : vec->capacity * 2;
        if (vec_reserve(vec, new_cap) != 0) return -1;
    }
    char* data = (char*) vec->data;
    memmove(data + (index+1)*vec->element_size, data + (index) * vec->element_size,
        (vec->size - index) * vec->element_size);
    vec->size ++;
    memcpy(data+index*vec->element_size, element, vec->element_size);
    return 0;
};

