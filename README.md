# my_vector

Dynamic array (vector) in C with automatic memory expansion.

## About

`my_vector` is a lightweight library for working with dynamic arrays in C.
It provides a convenient API for storing data of any type with automatic
memory management.

### Features

- Automatic memory expansion (doubling when full)
- Stores any data type via `void*`
- Minimal overhead
- Simple and intuitive API
- Static library for linking
- Safe memory handling

## Quick Start

### Example Usage

```c
#include <my_vector.h>
#include <stdio.h>

int main() {
    // Create a vector for integers
    Vector* numbers = vec_new(sizeof(int));
    
    // Add elements
    for (int i = 1; i <= 10; i++) {
        vec_push(numbers, &i);
    }
    
    // Access elements
    int* data = (int*)vec_data(numbers);
    for (size_t i = 0; i < vec_size(numbers); i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    // Free memory
    vec_free(numbers);
    return 0;
}`
```
## API

| Function | Description |
|----------|-------------|
| `vec_new(element_size)` | Create a new empty vector |
| `vec_free(vec)` | Free vector and its internal memory |
| `vec_push(vec, element)` | Append element to the end (auto-resize) |
| `vec_pop(vec)` | Remove last element (does not shrink capacity) |
| `vec_size(vec)` | Return number of elements |
| `vec_capacity(vec)` | Return current allocated capacity |
| `vec_data(vec)` | Get raw pointer to internal array |
| `vec_empty(vec)` | Check if vector is empty |
| `vec_at(vec, index)` | Safe access: returns pointer or NULL |
| `vec_front(vec)` | Get pointer to first element (or NULL) |
| `vec_back(vec)` | Get pointer to last element (or NULL) |
| `vec_reserve(vec, cap)` | Ensure capacity at least `cap` |
| `vec_shrink(vec)` | Reduce capacity by half when size ≤ capacity/2 (min 4) |
| `vec_clear(vec)` | Remove all elements, keep allocated memory |
| `vec_insert(vec, index, element)` | Insert element at `index` (shifts right) |
| `vec_push_front(vec, element)` | Insert element at beginning (shifts right, O(n)) |
| `vec_erase(vec, index)` | Remove element at `index` (shifts left, O(n)) |
| `vec_swap(a, b)` | Swap contents of two vectors (O(1)) |
| `vec_foreach(vec, callback)` | Call function on every element ||



## Installation

### Quick Installation

```bash
git clone https://github.com/your-username/my_vector.git
cd my_vector

make
sudo make install
```
### Manual Installation (without Makefile)
```bash
gcc -c my_vector.c -o my_vector.o
ar rcs libmy_vector.a my_vector.o
sudo cp my_vector.h /usr/local/include/
sudo cp libmy_vector.a /usr/local/lib/
```

## Uninstallation
```bash
sudo rm /usr/local/include/my_vector.h
sudo rm /usr/local/lib/libmy_vector.a
```
