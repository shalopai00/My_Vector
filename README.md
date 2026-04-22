# my_vector

Динамический массив (вектор) на языке C с автоматическим расширением памяти.

## О проекте

`my_vector` — это легковесная библиотека для работы с динамическими массивами в C.
Она предоставляет удобный API для хранения данных любого типа с автоматическим
управлением памятью.

### Особенности

- Автоматическое расширение памяти (удвоение при заполнении)
- Хранение данных любого типа через `void*`
- Минимальные накладные расходы
- Простой и интуитивно понятный API
- Статическая библиотека для линковки
- Безопасная работа с памятью

## Быстрый старт

### Пример использования

```c
#include <my_vector.h>
#include <stdio.h>

int main() {
    // Создание вектора для целых чисел
    Vector* numbers = vec_new(sizeof(int));
    
    // Добавление элементов
    for (int i = 1; i <= 10; i++) {
        vec_push(numbers, &i);
    }
    
    // Доступ к элементам
    int* data = (int*)vec_data(numbers);
    for (size_t i = 0; i < vec_size(numbers); i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    // Очистка памяти
    vec_free(numbers);
    return 0;
}
```

## Установка

### Быстрая установка

```bash
git clone https://github.com/ваш-username/my_vector.git
cd my_vector

make
sudo make install
```
### Ручная установка (без Makefile)
```bash
gcc -c my_vector.c -o my_vector.o
ar rcs libmy_vector.a my_vector.o
sudo cp my_vector.h /usr/local/include/
sudo cp libmy_vector.a /usr/local/lib/
```

## Удаление
```bash
sudo rm /usr/local/include/my_vector.h
sudo rm /usr/local/lib/libmy_vector.a
```