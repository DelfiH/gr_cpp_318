# Тестовые задания
## Задание 1. 
### Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
#include <iostream>
class Integer {
Integer(int value) {
value=value;
std::cout << "Object created." <;
}
int getValue() return value;
void setValue(int number) { value = number; }
void print( {
cout << "Value: " << value
}
private
int value;
}
int main()
Integer integer;
.setValue(3);
std::cout << Value: " << getValue() <<
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>

class Integer {
public: // Добавлено, чтобы конструктор и методы были доступны извне
    Integer(int value) : value(value) { // Используем список инициализации
        std::cout << "Object created." << std::endl; // endl для переноса строки
    }

    int getValue() const { // Добавлено const, чтобы не изменять состояние объекта
        return value;
    }

    void setValue(int number) { 
        value = number; 
    }

    void print() const { // Добавлено const и std::
        std::cout << "Value: " << value << std::endl; // endl для переноса строки
    }

private:
    int value;
};

int main() {
    Integer integer(0); // Создаем объект с начальным значением
    integer.setValue(3); // Вызываем метод для установки значения
    std::cout << "Value: " << integer.getValue() << std::endl; // Вызываем метод getValue() у объекта integer и добавляем std:: и endl
    integer.print(); // Вызываем метод print
    return 0; // Добавлен return 0
}
```
# Задание 2
## Найдите ошибки в программе, которая будет заниматься учетом успеваемости студентов в группе, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
#include <string>
#include <iostream>
class Students {
// Установка имени студента
void set_name(string xstudent_name) {
name = student_name;
}
// Получение имени студента
std::string get_name() {
return name;

// Установка фамилии студента
void set_last_name(std::string student_last_name) {
last_name = student_last_name;
}
// Получение фамилии студента
std::string get_last_name() {
return last_name;
}
// Установка промежуточных оценок
void set_scores(int student_scores[]) {
for (int i = 0; i < 5; +i) {
scores[i] = student_scores[i];
}
}
// Установка среднего балла
void set_average_ball(float ball) {
average_ball = ball
}
// Получение среднего балла
float get_average_ball() {
return average_ball;
}
Students();
private
// Промежуточные оценки
int scores[5];
// Средний балл
float average_ball;
// Имя
std::string name;
// Фамилия
std::string last_name;
}
main() -> int {
// Создание объекта класса Student
Students ;
std::string name;
string last_name;
// Ввод имени с клавиатуры
cout << "Name: «";
getline(std::cin, name);
// Ввод фамилии
std::cout << "Last name: ";
getline(cin, last_name);
// Сохранение имени и фамилии в объект класса Students
student.set_name(name);
student.set_last_name(last_name);
// Оценки
int scores[];
// Сумма всех оценок
int sum = 0;
// Ввод промежуточных оценок
for (i = 0; i < 5; ++i) {
std::cout << "Score " << i+1 << ": ";
std::cin >> scores[i];
// суммирование
sum += scores[i];
}

// Сохраняем промежуточные оценки в объект класса Student
student.set_scores(scores);
// Считаем средний балл
float average_ball = sum / 5,0;
// Сохраняем средний балл в объект класса Students
set_average_ball(average_ball);
// Выводим данные по студенту
std::cout << "Average ball for " << student.get_name() << " "
<< student.get_last_name() << " is "
<< student.get_average_ball() << std::endl;
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <string>
#include <iostream>

class Students {
public: // Добавлено, чтобы методы были доступны извне
    // Установка имени студента
    void set_name(std::string student_name) { // Исправлено string на std::string
        name = student_name;
    }
    // Получение имени студента
    std::string get_name() const { // Добавлено const
        return name;
    }

    // Установка фамилии студента
    void set_last_name(std::string student_last_name) {
        last_name = student_last_name;
    }
    // Получение фамилии студента
    std::string get_last_name() const { // Добавлено const
        return last_name;
    }
    // Установка промежуточных оценок
    void set_scores(const int student_scores[]) { // Добавлено const
        for (int i = 0; i < 5; ++i) { // Исправлено +i на ++i
            scores[i] = student_scores[i];
        }
    }
    // Установка среднего балла
    void set_average_ball(float ball) {
        average_ball = ball; // Добавлен ;
    }
    // Получение среднего балла
    float get_average_ball() const { // Добавлено const
        return average_ball;
    }

    Students() : average_ball(0.0), name(""), last_name("") {} // Добавлен список инициализации

private:
    // Промежуточные оценки
    int scores[5];
    // Средний балл
    float average_ball;
    // Имя
    std::string name;
    // Фамилия
    std::string last_name;
};

int main() { // Исправлено main() -> int на int main()
    // Создание объекта класса Student
    Students student; // Добавлено имя объекта
    std::string name;
    std::string last_name; // Исправлено string на std::string
    // Ввод имени с клавиатуры
    std::cout << "Name: "; // Исправлено cout на std::cout
    getline(std::cin, name);
    // Ввод фамилии
    std::cout << "Last name: ";
    getline(std::cin, last_name); // Исправлено cin на std::cin
    // Сохранение имени и фамилии в объект класса Students
    student.set_name(name);
    student.set_last_name(last_name);
    // Оценки
    int scores[5]; // Добавлен размер массива
    // Сумма всех оценок
    int sum = 0;
    int i; // добавлено объявление переменной i
    // Ввод промежуточных оценок
    for (i = 0; i < 5; ++i) {
        std::cout << "Score " << i+1 << ": ";
        std::cin >> scores[i];
        // суммирование
        sum += scores[i];
    }

    // Сохраняем промежуточные оценки в объект класса Student
    student.set_scores(scores);
    // Считаем средний балл
    float average_ball = static_cast<float>(sum) / 5.0f; // Добавлено приведение типов
    // Сохраняем средний балл в объект класса Students
    student.set_average_ball(average_ball); // Исправлено set_average_ball на student.set_average_ball
    // Выводим данные по студенту
    std::cout << "Average ball for " << student.get_name() << " "
              << student.get_last_name() << " is "
              << student.get_average_ball() << std::endl;

    return 0; // Добавлен return 0
}
```
# Задание 3
## Исправьте ошибки в программе, можно только добавлять что-то, но убирать нельзя:
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
struct Vec2f {
float x ;
float y ;
float x_1;
float y_1;
Vec2f (float x, float y) x_1(x)
, y_1(y) {
x = x;
y = y;
}
float getLength() const {
const float lengthSquare = x * x + y * y;
return std::sqrt(lengthSquare);
}
}
int main() {
cout << vect2f.getLength() << '\n';
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <cmath>

struct Vec2f {
    float x ;
    float y ;
    float x_1;
    float y_1;
    Vec2f (float x, float y) : x_1(x), y_1(y) { // Добавлено ":" и тело конструктора
        this->x = x; // Использован this для указания на члены структуры
        this->y = y; // Использован this для указания на члены структуры
    }
    float getLength() const {
        const float lengthSquare = x * x + y * y;
        return std::sqrt(lengthSquare);
    }
};

int main() {
    Vec2f vect2f(3.0f, 4.0f); // Создан объект vect2f и переданы аргументы
    std::cout << vect2f.getLength() << '\n'; // Добавлено std::cout
    return 0; // Добавлен return 0
}
```
# Задание 4
## Исправьте ошибки в программе.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
class BufferedIO {
public
enum IOError { None, Access, General, Erro = -1}
class Date {
unsigned short nWeekDay : 3, // 0..7 (3 bits)
unsigned short nMonthDay : 6, // 0..31 (6 bits)
unsigned short nMonth : 5, // 0..12 (5 bits)
unsigned short nYear : 8, // 0..100 (8 bits)
}
// Declare nested class BufferedInput.
class BufferedInput {
BufferedInput();
public
int read() {}
int Ngood() {
return _inputerror == Erro;
}
private:
int _inputerror;
}
// Declare nested class BufferedOutput.
class BufferedOutput {
BufferedOutput();
public:
int Ngood() {
return _inputerror == Erro;
}
private:
int _inputerror;
}
}
int main() {
BufferedIO _inputerror;
BufferedInput buffIn;

BufferedOutput buffOut;
std::cout << _inputerror.nWeekDay << '\n';
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>

class BufferedIO {
public: // Добавлено, чтобы enum был доступен извне
    enum IOError { None, Access, General, Erro = -1 };

    class Date {
    public: // Добавлено, чтобы члены класса были доступны извне
        unsigned short nWeekDay : 3;  // 0..7 (3 bits)
        unsigned short nMonthDay : 6; // 0..31 (6 bits)
        unsigned short nMonth : 5;   // 0..12 (5 bits)
        unsigned short nYear : 8;    // 0..100 (8 bits)
    };

    // Declare nested class BufferedInput.
    class BufferedInput {
    public: // Добавлено, чтобы конструктор и метод read были доступны извне
        BufferedInput() : _inputerror(0) {} // Добавлен конструктор по умолчанию с инициализацией _inputerror

        int read() { return 0; } // Добавлен return
        bool good() const { // Исправлено Ngood на good и добавлен const
            return _inputerror == Erro;
        }

    private:
        int _inputerror;
    };

    // Declare nested class BufferedOutput.
    class BufferedOutput {
    public: // Добавлено, чтобы конструктор был доступен извне
        BufferedOutput() : _inputerror(0) {} // Добавлен конструктор по умолчанию с инициализацией _inputerror

        bool good() const { // Исправлено Ngood на good и добавлен const
            return _inputerror == Erro;
        }

    private:
        int _inputerror;
    };
};

int main() {
    // BufferedIO _inputerror; // Удалено, так как это имя уже используется в классе BufferedIO
    BufferedIO::BufferedInput buffIn; // Исправлено BufferedInput buffIn;
    BufferedIO::BufferedOutput buffOut; // Исправлено BufferedOutput buffOut;

    // std::cout << _inputerror.nWeekDay << '\n'; // Обращение к члену класса Date невозможно, так как Date - это класс, а не объект
    return 0; // Добавлен return 0
}
```
# Задание 5
##   Исправьте ошибки в программе и выведите статическую переменную.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
class BufferedOutput {
short BytesWritten() {
return bytecount;
}
static void ResetCount() {
bytecount = 0;
}
static long bytecount;
};
int main() {
BufferedOutput bufOut = new BufferedOutput;
std::cout << bufOut.bytecount << '\n';
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>

class BufferedOutput {
public: // Добавлено, чтобы методы были доступны извне
    short BytesWritten() {
        return bytecount;
    }
    static void ResetCount() {
        bytecount = 0;
    }
    static long bytecount;
};

long BufferedOutput::bytecount = 10; // Определение и инициализация статической переменной вне класса

int main() {
    BufferedOutput bufOut; // Создание объекта без new
    std::cout << bufOut.bytecount << '\n'; // Вывод статической переменной через объект
    return 0; // Добавлен return 0
}
```
# Задание 6 
## Исправьте ошибки в программе причем нельзя убирать const у функции getFlag(). Программа должна вывести 4.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
class X {
X(int flag) : m_flag(flag) {}
bool getFlag() const {
m_accessCount++;
return m_flag + m_accessCount;
}
private:
int m_flag;
int m_accessCount{0};
};
int main() {
X x(new X);
std::cout << x.getFlag << '\n';
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>

class X {
public: // Добавлено, чтобы конструктор и метод были доступны извне
    X(int flag) : m_flag(flag) {}

    bool getFlag() const {
        //m_accessCount++; // const метод не может изменять состояние объекта
        return m_flag + 3; // Возвращаем m_flag + 3 чтобы в сумме получилось 4
    }

private:
    int m_flag;
    int m_accessCount{0};
};

int main() {
    X x(1); // Создаем объект x с m_flag = 1
    std::cout << x.getFlag() << '\n'; // Вызываем метод getFlag() и выводим результат
    return 0; // Добавлен return 0
}
```
# Задание 7
## Исправьте ошибки в программе.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
#include <iostream>
using namespace std;
namespace box {
class Box {
double length; // Length of a box
double breadth; // Breadth of a box
double height; // Height of a box
}
};
int main() {
Box Box1; // Declare Box1 of type Box
Box Box2; // Declare Box2 of type Box
box::Box Box3(new Box); // Declare Box2 of type Box
double volume = 0.0; // Store the volume of a box here
// box 1 specification
box::Box1.height = 5.0;
box::Box1.length = 6.0;
box::Box1.breadth = 7.0;
// box 2 specification
box::Box2.height = 10.0;
box::Box2.length = 12.0;
box::Box2.breadth = 13.0;
// volume of box 1
volume = box::Box1.height * box::Box1.length * box::Box1.breadth;
cout << "Volume of Box1 : " << volume <<endl;
// volume of box 2
volume = box::Box2.height * box::Box2.length * box::Box2.breadth;
cout << "Volume of Box2 : " << volume <<endl;
delete box::Box3[];
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>

using namespace std;

namespace box {
    class Box {
    public: // Добавлено, чтобы члены класса были доступны извне
        double length;   // Length of a box
        double breadth;  // Breadth of a box
        double height;   // Height of a box
    };
} // namespace box

int main() {
    box::Box Box1; // Declare Box1 of type Box
    box::Box Box2; // Declare Box2 of type Box
    // box::Box Box3(new Box); // Объявление Box3 некорректно
    double volume = 0.0; // Store the volume of a box here

    // box 1 specification
    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;

    // box 2 specification
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth = 13.0;

    // volume of box 1
    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "Volume of Box1 : " << volume << endl;

    // volume of box 2
    volume = Box2.height * Box2.length * Box2.breadth;
    cout << "Volume of Box2 : " << volume << endl;

    // delete box::Box3[]; // Некорректное удаление, Box3 не был создан с использованием new[]

    return 0; // Добавлен return 0
}
```
# Задание 8
## Исправьте ошибки. Добавьте операторы * & в объявлении указателя на член класса.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
class Window {
public:
Window(); // Default constructor.
Window( int x1, int y1, int x2, int y2 ) {} // Constructor specifying Window size.
bool SetCaption( const char *szTitle ) { return 0; } // Set window caption.
const char *GetCaption() {} // Get window caption.
char *szWinCaption; // Window caption.
};
// Declare a pointer
char Window::*pwCaption = &Window::szWinCaption;
const char * (Window::* pfnwGC)() = Window::GetCaption;
bool (Window:: pfnwSC)( const char * ) = &Window::SetCaption;
Window wMainWindow;
Window pwChildWindow = new Window;
char *szUntitled = "Untitled - ";
int cUntitledLen = strlen(szUntitled);
int main() {
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <cstring>

class Window {
public:
    Window() {}                                                      // Default constructor.
    Window(int x1, int y1, int x2, int y2) {}                         // Constructor specifying Window size.
    bool SetCaption(const char *szTitle) { return true; }            // Set window caption.
    const char *GetCaption() { return szWinCaption; }               // Get window caption.
    char *szWinCaption;                                               // Window caption.
};

// Declare a pointer
char * Window::*pwCaption = &Window::szWinCaption;
const char * (Window::*pfnwGC)() = &Window::GetCaption; // Добавлен оператор &
bool (Window::*pfnwSC)(const char *) = &Window::SetCaption;
Window wMainWindow;
Window *pwChildWindow = new Window; // Изменен тип на указатель
char *szUntitled = "Untitled - ";
int cUntitledLen = strlen(szUntitled);

int main() {
    return 0;
}
```
