#ifndef MY_VECTOR_LIBRARY_H
#define MY_VECTOR_LIBRARY_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Dynamic array (vector) structure.
 *
 * Holds a pointer to data, current size, capacity, and element size.
 */
typedef struct {
    void* data;          /**< Pointer to the array of elements */
    size_t size;         /**< Number of elements currently stored */
    size_t capacity;     /**< Total allocated capacity (number of elements) */
    size_t element_size; /**< Size of a single element in bytes */
} Vector;

/**
 * @brief Get the capacity of the vector.
 *
 * @param vec Pointer to the vector
 * @return Current capacity
 */
size_t vec_capacity(const Vector* vec);

/**
 * @brief Get the number of elements in the vector.
 *
 * @param vec Pointer to the vector
 * @return Current size
 */
size_t vec_size(const Vector* vec);

/**
 * @brief Get a pointer to the internal data array.
 *
 * @param vec Pointer to the vector
 * @return Pointer to the data (can be used as an array)
 */
void* vec_data(const Vector* vec);

/**
 * @brief Create a new empty vector.
 *
 * Allocates memory for the Vector structure. Initial data = NULL, size = 0, capacity = 0.
 *
 * @param element_size Size of a single element in bytes (e.g., sizeof(int))
 * @return Pointer to the new vector, or NULL on allocation failure
 */
Vector* vec_new(size_t element_size);

/**
 * @brief Destroy the vector and free all allocated memory.
 *
 * @param vec Pointer to the vector (can be NULL)
 */
void vec_free(Vector* vec);

/**
 * @brief Append an element to the end of the vector.
 *
 * Automatically resizes (doubles capacity) if needed.
 *
 * @param vec Pointer to the vector
 * @param element Pointer to the element to add
 * @return 0 on success, -1 on error (out of memory)
 */
int vec_push(Vector* vec, const void* element);

/**
 * @brief Remove the last element from the vector.
 *
 * Does not free memory; capacity remains unchanged.
 *
 * @param vec Pointer to the vector
 * @return 0 on success, -1 if the vector is empty or vec is NULL
 */
int vec_pop(Vector* vec);

/**
 * @brief Access an element by index with bounds checking.
 *
 * @param vec Pointer to the vector
 * @param index Element index (0‑based, must be < size)
 * @return Pointer to the element, or NULL if index out of bounds or vec is NULL
 */
void* vec_at(Vector* vec, size_t index);

/**
 * @brief Check if the vector is empty.
 *
 * @param vec Pointer to the vector
 * @return true if the vector is empty or vec is NULL, false otherwise
 */
bool vec_empty(const Vector* vec);

/**
 * @brief Reserve memory for at least `capacity` elements.
 *
 * Only increases capacity; never shrinks.
 *
 * @param vec Pointer to the vector
 * @param capacity New capacity
 * @return 0 on success, -1 on error (out of memory or vec is NULL)
 */
int vec_reserve(Vector* vec, size_t capacity);

/**
 * @brief Clear all elements from the vector (fast).
 *
 * Sets size = 0, but does not free memory. O(1) operation.
 *
 * @param vec Pointer to the vector
 */
void vec_clear(Vector* vec);

/**
 * @brief Shrink the vector's capacity if possible.
 *
 * Reduces capacity by half (but not below 4) if size * 2 <= capacity.
 *
 * @param vec Pointer to the vector
 * @return 0 on success, -1 on error (or vec is NULL)
 */
int vec_shrink(Vector* vec);

/**
 * @brief Get a pointer to the first element.
 *
 * @param vec Pointer to the vector
 * @return Pointer to the first element, or NULL if the vector is empty or vec is NULL
 */
void* vec_front(Vector* vec);

/**
 * @brief Get a pointer to the last element.
 *
 * @param vec Pointer to the vector
 * @return Pointer to the last element, or NULL if the vector is empty or vec is NULL
 */
void* vec_back(Vector* vec);

/**
 * @brief Insert an element at an arbitrary position.
 *
 * Shifts elements to the right. Resizes if needed.
 *
 * @param vec Pointer to the vector
 * @param index Position to insert (0 … size)
 * @param element Pointer to the element to insert
 * @return 0 on success, -1 on error (invalid index, out of memory, or vec is NULL)
 */
int vec_insert(Vector* vec, size_t index, const void* element);

/**
 * @brief Insert an element at the beginning of the vector.
 *
 * Equivalent to vec_insert(vec, 0, element). O(n) complexity.
 *
 * @param vec Pointer to the vector
 * @param element Pointer to the element to insert
 * @return 0 on success, -1 on error
 */
int vec_push_front(Vector* vec, const void* element);

/**
 * @brief Remove an element by index.
 *
 * Shifts elements to the left. Does not free memory.
 *
 * @param vec Pointer to the vector
 * @param index Index of the element to remove
 * @return 0 on success, -1 on error (invalid index or vec is NULL)
 */
int vec_erase(Vector* vec, size_t index);

/**
 * @brief Swap the contents of two vectors.
 *
 * Exchanges all fields (data, size, capacity, element_size) in O(1).
 *
 * @param a First vector
 * @param b Second vector
 */
void vec_swap(Vector* a, Vector* b);

/**
 * @brief Apply a callback function to every element of the vector.
 *
 * The callback receives a pointer to the element.
 *
 * @param vec Pointer to the vector
 * @param callback Function pointer: void callback(void* element)
 */
void for_each(Vector* vec, void (*callback)(void* element));

#endif // MY_VECTOR_LIBRARY_H
