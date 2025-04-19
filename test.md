# Тестовые задания
## 1. 
### Что выводят программы, если есть ошибки исправьте их:
### а) 
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int return 5(){
return 5
}
int return8(){
return;
}
int main( {
std::cout << return5() + return8() << ;
return 0
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
int return5() { // Исправлено название функции
  return 5;
}
int return8() {
  return 8; // Добавлено возвращаемое значение
}
int main() { // Добавлены скобки к main
  std::cout << return5() + return8() << std::endl; // Добавлен std::endl и точка с запятой
  return 0;
}
```
## b)
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int return() {
return 5;
int return()
{
int k ;
k{3};
return k;
}
}
int main(){
std::cout << return() <<
std::cout << return() <<
}
```

### ИСПРАВЛЕННЫЙ КОД:
``` cpp
int return5() { // Исправлено название первой функции
  return 5;
}
int return3() // Исправлено название второй функции
{
  int k = 3; // Исправлено присваивание значения переменной k
  return k;
}
int main() {
  std::cout << return5() << std::endl; // Исправлено название функции и добавлен std::endl
  std::cout << return3() << std::endl; // Исправлено название функции и добавлен std::endl
}
```

## c)
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
void prints
()
{
std::cout << 'O_o' << ;
}
int main ()
{
std::cout << prints() <<
return 0;
}
```

### ИСПРАВЛЕННЫЙ КОД:
``` cpp
void prints() {
  std::cout << "O_o"; // Исправлено на строку
}
int main() {
  prints(); // Исправлен вызов функции
  std::cout << std::endl; // Добавлен перенос строки
  return 0;
}
```

## d)
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int getNumbers()
{
return 6;
return;
}
int main()
{
std::cout << getNumbers(
std::cout << getNumbers)
std::cout << getNumbers
return 0;
}
```

### ИСПРАВЛЕННЫЙ КОД:
``` cpp
int getNumbers() {
  return 6;
}
int main() {
  std::cout << getNumbers() << std::endl; // Добавлены скобки и std::endl
  std::cout << getNumbers() << std::endl; // Добавлены скобки и std::endl
  std::cout << getNumbers() << std::endl; // Добавлены скобки и std::endl
  return 0;
}
```
## e)
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int main()
{
std::cout << multiply(7, 8)

return 0;
}
void multiply(int a)
{
return a * b
}
int main() {
int x;
std::cin >> x;
constexpr y(x);
std::cout << y << std::endl;
return 0;
}
```

### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream> // Добавлен include для iostream

int multiply(int a, int b) { // Добавлено объявление функции и второй аргумент
  return a * b;
}

int main() {
  std::cout << multiply(7, 8) << std::endl; // Добавлен std::endl
  return 0;
}
```
## f)
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
#define VALUE
int main() {
#if (VALUE == 0)
std::cout << VALUE <<"\n";
#elif (VALUE == 1)
std::cout << VALUE <<"\n";
#
elif
std::cout << VALUE <<"\n";
}
```

### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream> // Добавлен include для iostream

#define VALUE 2 // Добавлено определение VALUE

int main() {
#if (VALUE == 0)
  std::cout << VALUE << "\n";
#elif (VALUE == 1)
  std::cout << VALUE << "\n";
#else
  std::cout << VALUE << "\n";
#endif
}
```
## g)
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
namespace Mix {
enum class Fruits {
LEMON,
APPLE
}
enum class Colors {
RED,
BLACK
}
};
int main() {
Fruits fruit = Fruits::LEMON;
std::cout << "MIX\n";
return 1;
}
```

### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream> // Добавлен include для iostream

namespace Mix {
enum class Fruits {
  LEMON,
  APPLE
};
enum class Colors {
  RED,
  BLACK
};
} // namespace Mix
int main() {
  Mix::Fruits fruit = Mix::Fruits::LEMON; // Добавлено пространство имен
  std::cout << "MIX\n";
  return 1;
}
```
## h)
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
namespace DoMath
{
int subtract(int x, int y)
{
return x , y;
}
namespace DoMath
{
int add(int x, int y)
{
return x | y;
}
}
}
auto main()
{
std::cout << DoMath::add(5, 4) << '\n';

std::cout << ::subtract(5, 4) << '\n';
return 0;
}
```

### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream> // Добавлен include для iostream

namespace DoMath {
int subtract(int x, int y) {
  return x - y; // Исправлено на вычитание
}
int add(int x, int y) {
  return x + y; // Исправлено на сложение
}
} // namespace DoMath

int main() {
  std::cout << DoMath::add(5, 4) << '\n';
  std::cout << DoMath::subtract(5, 4) << '\n'; // Исправлен вызов subtract
  return 0;
}
```
# 2.
## Чтобы программа cкомпилировалась нужно что-то добавить, нельзя удалять или
комментировать программный код:
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int tmp 1;
int main() {
tmp 3;
std::cout << "Чтобы программа скомпилилась нужно что-то добавить а нельзя удалять
здесь пустые строки или
комментировать
<< std::endl;
return;
int getNumbers( {
int tmp = 1;
return;
}
Вывод приложения должен быть:
Глобальная переменная tmp: 1
Локальная переменная tmp: 3
zzz ":)" Чтобы программа скомпилилась нужно что-то добавить а нельзя удалять
здесь пустые строки или
комментировать!
```

### ПРАВИЛЬНЫЙ КОД:
``` cpp
#include <iostream> // Необходимо подключить iostream

int tmp = 1; // Объявление глобальной переменной

int main() {
  int tmp = 3; // Объявление локальной переменной
  std::cout << "Глобальная переменная tmp: " << ::tmp << std::endl; // Вывод глобальной переменной
  std::cout << "Локальная переменная tmp: " << tmp << std::endl;     // Вывод локальной переменной
  std::cout << "zzz \":)\" Чтобы программа скомпилилась нужно что-то добавить а нельзя удалять здесь пустые строки или\nкомментировать!" << std::endl;
  return 0;
}
```
