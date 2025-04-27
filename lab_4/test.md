# Тестовые задания
## 1. 
### Найдите ошибки в программах и исправьте их, напишите результат вывода программ:
### а) 
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
void main( {
short array[]{1,3,5,7,9};
short *ptr = array;
ptr = 111;
for (int i = 0; i < sizeof(array); ++i)
std::cout << " Значение элемента " << i << ": " << array +i << '\n';
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>

int main() { // Добавлена функция main и изменен тип void на int
    short array[]{1, 3, 5, 7, 9};
    short *ptr = array;
    //ptr = 111; // Нельзя присваивать указателю числовое значение напрямую
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) // Исправлен размер массива
        std::cout << " Значение элемента " << i << ": " << array[i] << '\n'; // Вывод значения элемента, а не адреса
    return 0; // Добавлен return 0;
}
```
### b) 
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int main() {
int array[size]{1,3,5,7,9};
Func(&array, size);
}
void Func(int *ptr, int size) {
for (int i = 0; i < size; ++i)
std::cout << " Значение элемента " ББ<< ptr[i] << '\n';
std::cout << " Адрес элемента " << ptr[i << '\n';
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>

int main() {
    const int size = 5; // Добавлено определение size
    int array[size]{1, 3, 5, 7, 9};
    Func(array, size);
    return 0;
}

void Func(int *ptr, int size) {
    for (int i = 0; i < size; ++i)
        std::cout << " Значение элемента " << ptr[i] << '\n';
    //std::cout << " Адрес элемента " << ptr[i] << '\n'; // Вывод значения вместо адреса
    std::cout << " Адрес элемента " << ptr << '\n'; // Исправлено на вывод адреса массива
}
```
### c) 
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
#include <iostream>
int main() {
short value;

short *p;
p = value;
*p = value;
*p = &value;
*p = *&value;
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>

int main() {
    short value = 10; // Инициализация value
    short *p = &value; // Присваиваем указателю адрес value
    *p = value; // Присваиваем значение value по адресу, хранящемуся в p
    //*p = &value;   //Удаляем, так как присваивание адреса по указателю на значение некорректно
    *p = *&value; // Присваиваем значение value по адресу, хранящемуся в p
    return 0;
}
```
### d) 
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
#include <iostream>
int main() {
char cvalue;
int ivalue;
short * ps;
char *pc;
void *pv {(int*)(cvalue)};
void *pv_1 {(char*)(&ivalue)};
std::cout << "pv->int" << *static_cast<int>(pv) << std::endl;
int *pi = {(int)(pv)};
std::cout << "pi=" << pv_1 << std::endl;
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>

int main() {
    char cvalue = 'A'; // Инициализация
    int ivalue = 65;    // Инициализация
    short *ps;          // Объявление указателя
    char *pc;           // Объявление указателя

    void *pv = &cvalue;   // Присваиваем адрес cvalue
    void *pv_1 = &ivalue; // Присваиваем адрес ivalue

    std::cout << "pv->int " << *static_cast<char*>(pv) << std::endl; //char
    int *pi = static_cast<int*>(pv_1);                       // Преобразуем void* в int*
    std::cout << "pi= " << *pi << std::endl;                       //Вывод значения pi
    return 0;
}
```
### e) 
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
#include <iostream>
int main() {
short value, value1(3);
short &ref;
const short &ref1 = value;
const short &ref2 = 78;
ref1 = 3;
*&value = 4;
const *short const p3;
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
int main() {
    short value = 0, value1 = 3; // Инициализация value и value1
    short &ref = value;          // Ссылка должна быть инициализирована
    const short &ref1 = value;
    const short &ref2 = 78;
    //ref1 = 3; // Ошибка: ref1 - константная ссылка, изменение запрещено
    value = 3;     //Так можно изменить значение value, на которое ссылается ref1
    *&value = 4; // Изменение значения value через указатель
    //const *short const p3; //Ошибка:  p3 не инициализирован
    return 0;
}
```
### f) 
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int main() {
short value = 13;
short value_1 = 100;
short *ptr = &value;
std::cout << &value << '\n';
std::cout << (value +=1) << '\n';
ptr = 9;
std::cout << (value = value_1 + *ptr) << '\n';
std::cout << "Результат: " << value << '\n';
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
int main() {
    short value = 13;
    short value_1 = 100;
    short *ptr = &value;
    std::cout << &value << '\n';
    std::cout << (value += 1) << '\n';
    //ptr = 9; // Ошибка: указателю нельзя присвоить числовое значение
    std::cout << (value = value_1 + *ptr) << '\n';
    std::cout << "Результат: " << value << '\n';
    return 0;
}
```
# Задание 2
## Исправьте ошибки можно что-то добавлять а удалять нельзя.
### g) 
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int main() {
int value1 45;
int value 63;
int *ptr = &value;
*ptr = &value;
ptr = value;
std::cout << "Результат value1 + value2 : " << value1 + ptr << '\n';
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
int main() {
    int value1 = 45; // Инициализация value1
    int value = 63;  // Инициализация value
    int *ptr = &value;
    //*ptr = &value; // Ошибка:  нельзя присвоить адрес переменной указателю, когда он должен хранить значение
    //ptr = value; // Ошибка:  нельзя присвоить значение переменной указателю
    std::cout << "Результат value1 + value : " << value1 + *ptr << '\n'; // Разыменовываем ptr для получения значения
    return 0;
}
```
# Задание 3
## Исправьте ошибки можно что-то добавлять а удалять нельзя. Что выведет программа:
### a) 
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int main() {
std::cout << "Hi !\n";
exit;
std::cout << 3
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <stdlib.h>
int main() {
    std::cout << "Hi !\n";
    exit(0); // exit
    std::cout << 3;
    return 0;
}
```
### b) 
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int main() {
switch (2) {
case 1
std::cout << 1 << '\n';
case 2
std::cout << 2 << '\n'
case
std::cout << 3 << '\n';
case 4
std::cout << 4 << '\n'
default:
std::cout << 5 << '\n';
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
int main() {
    switch (2) {
        case 1: // Добавлено двоеточие
            std::cout << 1 << '\n';
            break; // Добавлен break
        case 2: // Добавлено двоеточие
            std::cout << 2 << '\n';
            break; // Добавлен break
        default: // Исправлен case на default
            std::cout << 5 << '\n';
    }
    return 0;
}
```
### c) 
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
#include <iostream>
const int size = 5;
void Func(int ptr, int size) {
for (int i = 0; i < size; ++i)
std::cout << ptr[i] << '\n'; // вывод элементов масива в цикле
ptr = 5; // первому элементу массива присваиваем значение 5
std::cout << '\n';
for (int i = 0; i < size; ++i)
std::cout << *ptr++ << '\n'; // вывод элементов масива в цикле
*ptr = 55; // первому элементу массива присваиваем значение 55
std::cout << '\n';
}
int main() {
int array[];
Func(array, size);
for (int i = 0; i < size; ++i)
std::cout << array[i] << '\n';
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>

const int size = 5;

void Func(int *ptr, int size) { // Изменен тип ptr на int*
    for (int i = 0; i < size; ++i)
        std::cout << ptr[i] << '\n'; // вывод элементов массива в цикле
    //ptr = 5; // Ошибка: нельзя присваивать числовое значение указателю
    std::cout << '\n';
    for (int i = 0; i < size; ++i)
        std::cout << ptr[i] << '\n'; // Исправлено на вывод элементов массива
    //*ptr = 55; // Ошибка: нельзя присваивать значение по адресу, на который указывает ptr
    std::cout << '\n';
}

int main() {
    int array[size] = {1, 2, 3, 4, 5}; // Инициализация массива array
    Func(array, size);
    for (int i = 0; i < size; ++i)
        std::cout << array[i] << '\n';
    return 0;
}
```
