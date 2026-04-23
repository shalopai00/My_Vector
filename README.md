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
## Installation

### Quick Installation

```bash
git clone https://github.com/ваш-username/my_vector.git
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