#ifndef MY_VECTOR_LIBRARY_H
#define MY_VECTOR_LIBRARY_H
#include <stdbool.h>
#include <stddef.h>

typedef struct{
    void* data;
    size_t size;
    size_t capacity;
    size_t element_size;
} Vector;

//геттеры
size_t vec_capacity(const Vector* vec);
size_t vec_size(const Vector* vec);
void* vec_data(const Vector* vec);
//*

Vector* vec_new(size_t capacity);
void vec_free(Vector* vec);
int vec_push(Vector* vec, const void* element);
int vec_pop(Vector* vec);
void* vec_at(Vector* vec, size_t index);
bool vec_empty(Vector* vec);
int vec_reserve(Vector* vec, size_t capacity);

#endif // MY_VECTOR_LIBRARY_H