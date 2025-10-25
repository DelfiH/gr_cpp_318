# Тестовые задания
## Задание 1. 
### Заполните таблицы 1 и 2, систематизирующие информацию о классах STL. Не стесняйтесь занимать место на страницах; убедитесь, что подробно прочитали вопросы в левом столбце. Информация о классе pair приведена в качестве образца.
### Первая таблица:
``` cpp
## Сравнение контейнеров в C++

| Название класса             | Пара (pair)                        | Массив (array)                   | Вектор (vector)                                  | Список (list)                                  |
| :-------------------------- | :--------------------------------- | :------------------------------- | :----------------------------------------------- | :--------------------------------------------- |
| Какую библиотеку подключить | `<utility>`                        | `<array>`                        | `<vector>`                                       | `<list>`                                       |
| Синтаксис инициализации     | `std::pair<std::string, std::string> myName("Ivan", "Ivanov");` | `std::array<int, 5> myArray = {1, 2, 3, 4, 5};` | `std::vector<int> myVector = {1, 2, 3};` или `std::vector<int> myVector(5);` | `std::list<int> myList = {1, 2, 3};`         |
| Как получить доступ к элементу | `.first`, `.second`                | `myArray[index]`, `myArray.at(index)` | `myVector[index]`, `myVector.at(index)`, итераторы | Итераторы                                      |
| Добавить элементы?          | Нет                              | Нет                              | `push_back()`, `insert()`                         | `push_back()`, `push_front()`, `insert()`       |
| Удалить элементы?           | Нет                              | Нет                              | `pop_back()`, `erase()`                          | `pop_back()`, `pop_front()`, `erase()`         |
| Количество элементов?       | Всегда два                       | `myArray.size()`                 | `myVector.size()`                                | `myList.size()`                                |
| Автоматическая сортировка?  | Нет                              | Нет                              | Нет                                              | Нет                                              |
| Дубликаты?                | Всегда может                     | Да                               | Да                                               | Да                                               |
| Специфичные функции         | `std::make_pair(value, value)`    |                                  |                                                  |                                                  |
```
### Вторая таблица:
``` cpp
| Название класса               | Односвязный список (forward\_list) | Дек (deque)                      | Словарь (map/multimap)                         | Набор (set/multiset)                             |
| :---------------------------- | :--------------------------------- | :------------------------------- | :--------------------------------------------- | :----------------------------------------------- |
| Какую библиотеку подключить   | `<forward_list>`                   | `<deque>`                        | `<map>`                                        | `<set>`                                          |
| Синтаксис инициализации       | `std::forward_list<int> myList = {1, 2, 3};` | `std::deque<int> myDeque = {1, 2, 3};` | `std::map<std::string, int> myMap = {{"one", 1}, {"two", 2}};` | `std::set<int> mySet = {1, 2, 3};`             |
| Как получить доступ к элементу | Итераторы                          | `myDeque[index]`, `myDeque.at(index)`, итераторы | `myMap[key]`, итераторы                         | Итераторы                                        |
| Добавить элементы?            | `push_front()`, `insert_after()`   | `push_back()`, `push_front()`, `insert()` | `insert()`                                     | `insert()`                                       |
| Удалить элементы?             | `pop_front()`, `erase_after()`    | `pop_back()`, `pop_front()`, `erase()` | `erase()`                                      | `erase()`                                        |
| Количество элементов?         | `myList.size()`                    | `myDeque.size()`                 | `myMap.size()`                                 | `mySet.size()`                                   |
| Автоматическая сортировка?    | Нет                              | Нет                              | В `map` ключи отсортированы                   | В `set` элементы отсортированы                 |
| Дубликаты?                  | Да                               | Да                               | В `map` ключи уникальны                      | В `set` элементы уникальны                    |
| Специфичные функции           |                                  |                                  |                                                |                                                  |

```
# Задание 2
## Разместите адреса (заполните адресное пространство)(заполните следующую таблицу), для примера представленного ниже:
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp

```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <vector>
#include <array>
const int CONSTT{3};
int g_val{4};
int g_val1;
int main () {
    int v = 3;
    std::vector<int> vk;
    vk.push_back(1);
    vk.push_back(2);
    vk.push_back(3);
    std::array<int,3> ak;
    std::cout << "\n1 vector is at " << &vk;       // Heap
    std::cout << "\n2 vector.front() is at " << &vk.front(); // Heap
    std::cout << "\n3 vector is at " << &vk;       // Heap
    std::cout << "\n4 array.front() is at " << &ak.front(); // Stack
    std::cout << "\n5 v is at " << &v;         // Stack
    std::cout << "\n6 malloc(8) is at " << malloc(8);   // Heap
    std::cout << "\n7 g_val is at " << &g_val;     // Data
    std::cout << "\n8 g_val1 is at " << &g_val1;    // BSS
    std::cout << "\n9 CONSTT is at " << &CONSTT;    // Text
    std::cout << "\n10 Text is at " << reinterpret_cast<void*>(main) << "\n"; // Text
}

| Область памяти | Переменные                                      |
|-----------------|-------------------------------------------------|
| Stack           | `ak`, `v`                                   |
| Heap            | `vk`, `malloc(8)`                              |
| BSS             | `g_val1`                                      |
| Data            | `g_val`                                       |
| Text (Code)     | `CONSTT`, `main`                                |

```
# Задание 3
## Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
class Dollars {
private:
int m_dollars;
public:
Dollars(int dollars) { m_dollars = dollars; }
// выполняем Dollars + Dollars через дружественную функцию
friend Dollars operator+(const Dollars &d1, const Dollars &d2);
// выполняем Dollars - Dollars через дружественную функцию
Dollars operator-(const Dollars &d1, const Dollars &d2);
Dollars operator*(const Dollars &d1, const Dollars &d2);
Dollars operator/(const Dollars &d1, const Dollars &d2);
int getDollars() const { return m_dollars; }
}
// Примечание: Эта функция не является методом класса!
Dollars +(const Dollars &d1, const Dollars &d2) {
// используем конструктор Dollars и operator+(int, int)
// мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
return Dollars(d1.m_dollars + d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator-(const Dollars &d1, const Dollars &d2) {
// используем конструктор Dollars и operator-(int, int)
// мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
return Dollars(d1.m_dollars - d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator*(const Dollars &d1, const Dollars &d2) {
// используем конструктор Dollars и operator*(int, int)
// мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
return Dollars(d1.m_dollars * d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars /(const Dollars &d1, const Dollars &d2) {
// используем конструктор Dollars и operator/(int, int)
// мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
return Dollars(d1.m_dollars / d2.m_dollars);
}
int main() {
Dollars dollars1();
Dollars dollars2();
std::cout << "+: " << (dollars1 + dollars2).getDollars() << " dollars." << std::endl;
std::cout << "-: " << (dollars1 - dollars2).getDollars() << " dollars." << std::endl;
std::cout << "*: " << (dollars1 * dollars2).getDollars() << " dollars." << std::endl;

std::cout << "/: " << (dollars1 / dollars2).getDollars() << " dollars." << std::endl;
std::cout << "/: " << (dollars1 + 3).getDollars() << " dollars." << std::endl;
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>

class Dollars {
private:
    int m_dollars;
public:
    Dollars(int dollars = 0) : m_dollars(dollars) { } // Добавлен default argument и инициализация m_dollars
    // выполняем Dollars + Dollars через дружественную функцию
    friend Dollars operator+(const Dollars &d1, const Dollars &d2);
    // выполняем Dollars - Dollars через дружественную функцию
    Dollars operator-(const Dollars &d1, const Dollars &d2);
    Dollars operator*(const Dollars &d1, const Dollars &d2);
    Dollars operator/(const Dollars &d1, const Dollars &d2);
    int getDollars() const { return m_dollars; }
};
// Примечание: Эта функция не является методом класса!
Dollars operator+(const Dollars &d1, const Dollars &d2) {
    // используем конструктор Dollars и operator+(int, int)
    // мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
    return Dollars(d1.m_dollars + d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator-(const Dollars &d1, const Dollars &d2) {
    // используем конструктор Dollars и operator-(int, int)
    // мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
    return Dollars(d1.m_dollars - d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator*(const Dollars &d1, const Dollars &d2) {
    // используем конструктор Dollars и operator*(int, int)
    // мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
    return Dollars(d1.m_dollars * d2.m_dollars);
}
// Примечание: Эта функция не является методом класса!
Dollars operator/(const Dollars &d1, const Dollars &d2) {
    // используем конструктор Dollars и operator/(int, int)
    // мы имеем доступ к закрытому члену m_dollars, поскольку эта функция является дружественной классу Dollars
    return Dollars(d1.m_dollars / d2.m_dollars);
}

Dollars operator+(const Dollars &d, int num) {
    return Dollars(d.m_dollars + num);
}

int main() {
    Dollars dollars1(10);  // Вызываем конструктор с параметром
    Dollars dollars2(5);   // Вызываем конструктор с параметром
    std::cout << "+: " << (dollars1 + dollars2).getDollars() << " dollars." << std::endl;
    std::cout << "-: " << (dollars1 - dollars2).getDollars() << " dollars." << std::endl;
    std::cout << "*: " << (dollars1 * dollars2).getDollars() << " dollars." << std::endl;
    std::cout << "/: " << (dollars1 / dollars2).getDollars() << " dollars." << std::endl;
    std::cout << "+ int: " << (dollars1 + 3).getDollars() << " dollars." << std::endl;

    return 0;
}
```
# Задание 4
## Сделайте код программы рабочим, причем элементы массива выводим с использованием цикла foreach.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
#include <iostream>
int sumArray(int array) {
int result = 0;
for (const auto &number : array)
result += number;
return result;
}
int main() {
int array[7] = { 10, 8, 6, 5, 4, 3, 1 };
std::cout << sumArray(array);
return 0;
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <numeric> // для std::accumulate

int sumArray(const int array[], int size) {
    int result = 0;
    for (int i = 0; i < size; ++i) {
        result += array[i];
    }
    return result;
}

int main() {
    int array[7] = { 10, 8, 6, 5, 4, 3, 1 };
    int sum = sumArray(array, sizeof(array) / sizeof(array[0]));
    std::cout << sum << std::endl;
    return 0;
}
```
# Задание 5
## Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
void (*pfunc)();
void print(int i) {
std::cout << i << " ";
}
int main() {
int data[]{1,2,3,4,5};
int len = sizeof(data)/sizeof(data[0]);
std::for_each(data, data+len, pfunc);
return 0;
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <algorithm>

void print(int i) {
    std::cout << i << " ";
}

int main() {
    int data[]{1, 2, 3, 4, 5};
    int len = sizeof(data) / sizeof(data[0]);
    void (*pfunc)(int) = print; // Инициализация указателя на функцию
    std::for_each(data, data + len, pfunc);
    return 0;
}
```
# Задание 6 
## Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
class Number {
private:
int m_number;
Number(int number=0): m_number(number) {}
Number& operator++();
Number& operator--();
Number operator++(int);
Number operator--(int);
friend std::ostream& operator<< (std::ostream &out, const Number &n);
}
Number ::operator++() {
++m_number;
return *this;
}
Number operator--(){
--m_number;

return *this;
}
Number Number::operator++(int){
Number temp(m_number);
++(*this);
return temp;
}
Number Number::operator--(int){
Number temp(m_number);
--(*this);
return temp;
}
std::ostream& operator<< (std::ostream &out, const Number &d){
out << d.m_number << "\n";
return out;
}
int main(){
Number number(6);
std::cout << ++number;
std::cout << number++;
std::cout << number;
std::cout << --number;
std::cout << number--;
std::cout << number;
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>

class Number {
private:
    int m_number;

public:
    Number(int number = 0) : m_number(number) {}

    Number& operator++();
    Number& operator--();
    Number operator++(int);
    Number operator--(int);

    friend std::ostream& operator<< (std::ostream &out, const Number &n);
};

Number& Number::operator++() {
    ++m_number;
    return *this;
}

Number& Number::operator--(){  // Fixed: Added return type "&"
    --m_number;
    return *this;
}

Number Number::operator++(int){
    Number temp(m_number);
    ++(*this);
    return temp;
}

Number Number::operator--(int){
    Number temp(m_number);
    --(*this);
    return temp;
}

std::ostream& operator<< (std::ostream &out, const Number &n){
    out << n.m_number << "\n";
    return out;
}

int main(){
    Number number(6);
    std::cout << ++number;
    std::cout << number++;
    std::cout << number;
    std::cout << --number;
    std::cout << number--;
    std::cout << number;
    return 0;
}
```
# Задание 7
## Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int main() {
std::vector<int> numbers = { 1, 2, 3, 4, 5 };
for (int n : numbers)
std::cout << n << "\t";
std::cout << std::endl;
for (auto iter = begin(); iter != end(); iter++) {
std::cout << *iter << "\t";
}
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    for (int n : numbers)
        std::cout << n << "\t";
    std::cout << std::endl;
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
        std::cout << *iter << "\t";
    }
    std::cout << std::endl;
    return 0;
}
```
# Задание 8
##  Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int main() {
std::list<int> li;
for (int nCount = 0; nCount < 5; ++nCount)
li.push_back(nCount);
std::list<int>::iter it;
it = min_element(li.begin(), li.end());
std::cout << "min: " << it << ' ';
it = max_element(li.begin(), li.end());
std::cout << "max: " << it << ' ';
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <list>
#include <algorithm>

int main() {
    std::list<int> li;
    for (int nCount = 0; nCount < 5; ++nCount)
        li.push_back(nCount);
    std::list<int>::iterator it; // Changed iter to iterator
    it = std::min_element(li.begin(), li.end());
    std::cout << "min: " << *it << ' '; // Dereference the iterator
    it = std::max_element(li.begin(), li.end());
    std::cout << "max: " << *it << ' '; // Dereference the iterator
    return 0;
}
```
