# Тестовые задания
## Задание 1. 
### Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя.
### Первая таблица:
``` cpp
#include <iostream>
template <typename T1, typename T2>
void mssg(T1 & first, T2 & second, T3 & third){
std::cout << first << std::endl;
std::cout << second << std::endl;
std::cout << third << endl;
}
int main () {
char a('a');
double c(7.89);
mssg<char,int>(a, b, c);
mssg(a, b, c);
}
```
### Вторая таблица:
``` cpp
#include <iostream>

template <typename T1, typename T2, typename T3> // Добавлено typename T3
void mssg(T1 & first, T2 & second, T3 & third){
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << third << std::endl; // Исправлено endl
}

int main () {
    char a('a');
    int b = 5; // Добавлено определение переменной b
    double c(7.89);
    mssg<char, int, double>(a, b, c); // Добавлено double
    mssg(a, b, c);
    return 0;
}
```
# Задание 2
## Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int main( {
int a{4}, b{5};
std::cout << *max(&a, &b) << std::endl; // 5
double numbers[]{3.4, 2.3, 6.1, 4.3};
std::cout << *max(numbers, sizeof(numbers)/sizeof(int)) << std::endl; //6.1
}
template<typename T> const T* max(const T* a, const T* b) {
std::cout << "const T *max(const T* a, const T* b) " << std::endl;
return *a > *b? a : b;
}
template <typename T>
const T* max(const T data[], unsigned size) {
std::cout << "const T* max(const T data[], unsigned size)" << std::endl;
const T* result {}; // если вектор пуст, то возвращается nullptr
for(i{}; i < size; i++) {
// если result не равен nullptr и *result меньше value
if (!result || data[i] > *result)
result = &data[i];
}
return result;
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
 #include <iostream>

template<typename T> const T* max(const T* a, const T* b) {
    std::cout << "const T *max(const T* a, const T* b) " << std::endl;
    return *a > *b ? a : b;
}

template <typename T>
const T* max(const T data[], unsigned size) {
    std::cout << "const T* max(const T data[], unsigned size)" << std::endl;
    const T* result {}; // если вектор пуст, то возвращается nullptr
    for(unsigned i = 0; i < size; i++) { // Добавлено unsigned и инициализация i
        // если result не равен nullptr и *result меньше value
        if (!result || data[i] > *result)
            result = &data[i];
    }
    return result;
}

int main() { // Исправлена опечатка в main
    int a{4}, b{5};
    std::cout << *max(&a, &b) << std::endl; // 5
    double numbers[]{3.4, 2.3, 6.1, 4.3};
    std::cout << *max(numbers, sizeof(numbers)/sizeof(double)) << std::endl; //6.1 // Исправлен расчет размера
    return 0;
}
```
# Задание 3
## Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
struct Point {
Point(double x, double y): x{x}, y{y} {}
double x;
double y;
}
int main() {
std::vector<Point> points{ Point{0, 0}, Point{4, 5}, Point{-5, 7}};
out("points.txt");
if (out.is_open()) {
// записываем все объекты Point в файл
for (const Point& point: points) {
out << point.x << " " << point.y << endl;
}
}
out.close();
std::vector<Point> new_points;
std::ifstream in("points.txt"); // окрываем файл для чтения
if (in.is_open()) {
double x, y;
while (in >> x >> y) {
new_points.push_back(Point{x, y});

}
}
close();
for (const Point& : new_points) {
std::cout << "Point X: " << point.x << "\tY: " << point.y << std::endl;
}
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Point {
    Point(double x, double y): x{x}, y{y} {}
    double x;
    double y;
};

int main() {
    std::vector<Point> points{ Point{0, 0}, Point{4, 5}, Point{-5, 7}};
    std::ofstream out("points.txt"); // Исправлено: добавлен тип std::ofstream
    if (out.is_open()) {
        // записываем все объекты Point в файл
        for (const Point& point: points) {
            out << point.x << " " << point.y << std::endl;
        }
    }
    out.close();

    std::vector<Point> new_points;
    std::ifstream in("points.txt"); // окрываем файл для чтения
    if (in.is_open()) {
        double x, y;
        while (in >> x >> y) {
            new_points.push_back(Point{x, y});
        }
    }
    in.close(); // Исправлено: вызывается для in, а не глобально

    for (const Point& point : new_points) { // Исправлено: добавлено имя переменной point
        std::cout << "Point X: " << point.x << "\tY: " << point.y << std::endl;
    }
    return 0;
}

```
# Задание 4
## Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int main() {
transfer("id1234", "id5678", 2804, 5000);
}
template <typename T, typename K>
void transfer(T fromAccount, T toAccount, K code, int sum) {
std::cout << "From: " << fromAccount << "\nTo: " << toAccount
<< "\nSum: " << sum << "\nCode: " << code << std::endl;
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <string> // Необходимо для использования std::string

template <typename T, typename K>
void transfer(T fromAccount, T toAccount, K code, int sum) {
    std::cout << "From: " << fromAccount << "\nTo: " << toAccount
              << "\nSum: " << sum << "\nCode: " << code << std::endl;
}

int main() {
    transfer(std::string("id1234"), std::string("id5678"), 2804, 5000); // Явное указание типа std::string
    return 0;
}
```
# Задание 5
## Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно
только добавлять что-то, но убирать нельзя.
template <typename T, size_t N> T average(const T (&)[N]);
int main() {
int numbers1[]{1, 2, 3, 4, 5};
std::cout << average(numbers1) << std::endl; // 3
double numbers2[]{1.1, 3.2, 4.3, 5.4, 6.5, 2.6};
std::cout << average(numbers2) << std::endl; // 3.85
template
T result {};
for(unsigned i{}; i < N; i++) {
result += data[i];
}
return result / N;
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>

template <typename T, size_t N>
T average(const T (&data)[N]) { // Реализация функции должна быть здесь
    T result {};
    for(unsigned i{}; i < N; i++) {
        result += data[i];
    }
    return result / N;
}

int main() {
    int numbers1[]{1, 2, 3, 4, 5};
    std::cout << average(numbers1) << std::endl; // 3
    double numbers2[]{1.1, 3.2, 4.3, 5.4, 6.5, 2.6};
    std::cout << average(numbers2) << std::endl; // 3.85
    return 0;
}
```
# Задание 6 
## Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
template < T, V>
class Transaction {
public:
Transaction(T fromAcc, T toAcc, V code, unsigned sum):
fromAccount{fromAcc}, toAccount{toAcc}, code{code}, sum{sum} { }
void print() const
std::cout << "From: " << fromAccount << "\tTo: " << toAccount
<< "\tSum: " << sum << "\tCode: " << code endl;
private:
T fromAccount;
T toAccount;
V code;
unsigned sum;
}
int main() {
Transaction<std::string> transaction1{"id1234", "id5678", 2804, 5000};
transaction1.print();
Transaction transaction2{"id6789", "id9018", 3000, 6000};
transaction2.print();
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
 #include <iostream>
#include <string>

template <typename T, typename V> // Добавлено typename V
class Transaction {
public:
    Transaction(T fromAcc, T toAcc, V code, unsigned sum):
        fromAccount{fromAcc}, toAccount{toAcc}, code{code}, sum{sum} { }
    void print() const { // Добавлены фигурные скобки
        std::cout << "From: " << fromAccount << "\tTo: " << toAccount
                  << "\tSum: " << sum << "\tCode: " << code << std::endl;
    }
private:
    T fromAccount;
    T toAccount;
    V code;
    unsigned sum;
};

int main() {
    Transaction<std::string, int> transaction1{"id1234", "id5678", 2804, 5000}; // Добавлен тип int для V
    transaction1.print();
    Transaction<std::string, int> transaction2{"id6789", "id9018", 3000, 6000}; // Добавлен тип int для V
    transaction2.print();
    return 0;
}
```
