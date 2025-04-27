# Тестовые задания
## Задание 1. 
### Найдите ошибку в потере данных, измените код чтобы не было потери данных: 
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
#include<iostream>
int main() {
float a=3.14;
char *pj;
pj = (char*)&a;
std::cout << *pj << '\n';
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
int main() {
  float a = 3.14;
  float *pj; // Используем указатель на float
  pj = &a;
  std::cout << *pj << '\n'; // Выводим значение, на которое указывает указатель
}
```
# Задание 2
## Исправьте ошибки в программе и реализуйте вывод значение и адрес объекта a через указатели pj и pk:
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
int main(){
int a=10, *pj;
void *pk;
pj = pk = &a;
pj++;
k++;
std::cout << pk << '\n';
std::cout << pj << '\n'
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
int main(){
  int a = 10, *pj;
  void *pk;
  pj = &a;
  pk = &a; // Присваиваем pk адрес переменной a
  std::cout << "Адрес pk: " << pk << '\n'; // Выводим адрес, хранящийся в pk
  std::cout << "Значение *pk: " << *(int*)pk << '\n'; // Выводим значение по адресу pk, приводя void* к int*

  pj++; // Увеличиваем указатель pj на размер int (4 байта)
  std::cout << "Адрес pj: " << pj << '\n'; // Выводим адрес, хранящийся в pj
  std::cout << "Значение *pj: " << *pj << '\n'; // Выводим значение по адресу pj
}
```
# Задание 3
## Помогите другу разработчику доработайте или исправьте код, который сделал:
## Номер телефона, например (212) 767-8900, можно условно разделить на три части: 
## код города (212), номер телефонной станции (767) и номер абонента (8900).
## Разработана программа с использованием двух структур phone, позволяющую раздельно хранить эти три
## части телефонного номера. Инициализацию одной из них производится самостоятельно, а
## значения для другой запрашивается с клавиатуры. Затем выводится содержимое обеих
## переменных на экран. Результат работы программы должен выглядеть так:
## Введите код города, номер станции и номер абонента: 415 555 1212
## Мой номер: (212) 767-8900
## Ваш номер: (415) 555-1212 
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
#include <iostream>
using namespace std;
struct phone{
int kod ;
int nom ;
int mom_abon ;
};
struct new_phone{
int kod1;
int nom1;
int mom_abon1;
};
int main() {
setlocale (LC_ALL, "rus" );
phone object;
new_phone new_object;
wcout << L"Введите код города, номер станции и номер абонента: ";
int mas_all[11];
cin >> mas_all[11];
int mas_a[2];
mas_a[0] = mas_all[0];
mas_a[1] = mas_all[1];
mas_a[2] = mas_all[2];
new_object.kod1 = mas_a[2];
int mas_b[2];
mas_b[0] = mas_all[4];

mas_b[1] = mas_all[5];
mas_b[2] = mas_all[6];
new_object.nom1 = mas_b[2];
int mas_c[3];
mas_c[0] = mas_all[8];
mas_c[1] = mas_all[9];
mas_c[2] = mas_all[10];
mas_c[3] = mas_all[11];
new_object.mom_abon1= mas_b[2];
object.kod = 123;
object.nom = 456;
object.mom_abon = 7890;
wcout << L"Мой номер телефона : " << object.kod << " " << object.nom << " " << object.mom_abon << endl;
wcout << L"Ваш номер : " << new_object.kod1 << " " << new_object.nom1 << " " << new_object.mom_abon1 << endl;
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <string> // Для работы со строками
#include <sstream> // Для преобразования строки в числа
#include <locale>   // Для работы с локалью
using namespace std;

struct phone {
  int kod;
  int nom;
  int mom_abon;
};

struct new_phone {
  int kod1;
  int nom1;
  int mom_abon1;
};

int main() {
  setlocale(LC_ALL, "rus");

  phone object = {212, 767, 8900}; // Инициализация первой структуры
  new_phone new_object;

  wcout << L"Введите код города, номер станции и номер абонента (XXX YYY ZZZZ): ";
  int kod, nom, abon;
  cin >> kod >> nom >> abon;

  new_object.kod1 = kod;
  new_object.nom1 = nom;
  new_object.mom_abon1 = abon;

  wcout << L"Мой номер: (" << object.kod << ") " << object.nom << "-" << object.mom_abon << endl;
  wcout << L"Ваш номер: (" << new_object.kod1 << ") " << new_object.nom1 << "-" << new_object.mom_abon1 << endl;

  return 0;
}
```
# Задание 4
## Найдите 2е ошибки и измените код чтобы он был рабочим:
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
#include <iostream>
using namespace std;
int main() {
setlocale (LC_ALL, "rus" );
const int n = 5;
const int m = 10;
int *a;
int *b;
a = new int*[n];
b = new int*[n];
for (int i = 0; i < n; i++) {
a[i] = new int[m];
b[i] = new int[m];
cout << &a[i][0] << endl;
cout << &b[i][0] << endl;
}
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
using namespace std;

int main() {
  setlocale(LC_ALL, "rus");
  const int n = 5;
  const int m = 10;

  int **a = new int*[n]; // Выделяем память под n указателей на int
  int **b = new int*[n]; // Выделяем память под n указателей на int

  for (int i = 0; i < n; i++) {
    a[i] = new int[m]; // Для каждого указателя выделяем память под m элементов int
    b[i] = new int[m]; // Для каждого указателя выделяем память под m элементов int
    cout << "Адрес a[" << i << "][0]: " << &a[i][0] << endl;
    cout << "Адрес b[" << i << "][0]: " << &b[i][0] << endl;
  }

  // Не забываем освободить выделенную память после использования!
  for (int i = 0; i < n; i++) {
    delete[] a[i];
    delete[] b[i];
  }
  delete[] a;
  delete[] b;

  return 0;
}
```
# Задание 5
## Найдите ошибки и измените код чтобы он был рабочим и выведите все строки заданные разными способами:
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
#include <iostream>
using namespace std;
int main() {
char s[] = "char s[]: text";
char* ps = "char* ps: text";
std::string str = "std::string str: text";
s = "another text";
str = "std::string str: another text";
char *s_1 = "char *s_1: text";
const char *s_2 = "const char *s_2: text";
wcout << "Вывод строк : "
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main() {
  setlocale(LC_ALL, "rus");

  char s[] = "char s[]: text"; // Создаем массив символов, инициализированный строковым литералом
  char* ps = "char* ps: text";  // Указатель на строковый литерал (неизменяемый)
  std::string str = "std::string str: text"; // Строка std::string

  // s = "another text"; // Ошибка: нельзя присвоить строковый литерал массиву напрямую, нужно копировать
  strcpy(s, "another text");   // Используем strcpy для копирования строки в массив s
  str = "std::string str: another text"; // std::string можно изменять напрямую

  char *s_1 = s;              // Указатель на первый элемент массива s
  const char *s_2 = ps;       // Указатель на константную строку

  wcout << L"Вывод строк: " << endl;
  wcout << L"s (массив): " << s << endl;         // Вывод массива s
  wcout << L"ps (указатель): " << ps << endl;    // Вывод строки через указатель ps
  wcout << L"str (std::string): " << str.c_str() << endl; // Вывод std::string (используем c_str() для получения C-style строки)
  wcout << L"s_1 (указатель на s): " << s_1 << endl;   // Вывод через указатель s_1
  wcout << L"s_2 (const указатель): " << s_2 << endl;   // Вывод через константный указатель s_2
}
```
# Задание 6 
## Исправьте чтобы был следующий вывод, причем нельзя использовать при выводе строку s
## а использовать s1-s4 (изменить код программы где вопросы примерно так s1 = s.substr(0, 3)):
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
Кто вы по профессии? : Я инженер-программист!
int main() {
wstring s = "I'am an developer";
wstring
s1 = s.substr(????),
s2 = s.substr(????),
s3 = s.substr(?),
s4 = s.substr(????);
wcout << "Why is you? : " << s1 s2+s3+s4 << '\n';
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main() {
  setlocale(LC_ALL, "rus");
  wstring s = L"I'am an developer";
  wstring
    s1 = s.substr(5, 3),    // "an "
    s2 = s.substr(8, 9),   // "developer"
    s3 = s.substr(4, 1),    // " "
    s4 = s.substr(0, 5);    // "I'am "

  wcout << L"Who is you? : " << s4 + s1 + s3 + s2 << '\n';
}
```
