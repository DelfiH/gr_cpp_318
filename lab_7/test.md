# Тестовые задания
## Задание 1. 
### Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
std::mutex g_lock;
void threadFunction() {
std::cout << "entered thread " << std::this_thread::get_id() << std::endl;
std::this_thread::sleep_for(std::chrono::seconds(rand()%10));
std::cout << "leaving thread " << std::this_thread::get_id() << std::endl;
g_lock.unlock();
}
int main() {
srand((unsigned int)time(0));
std::thread t1(threadFunction);
std::thread t2(threadFunction);
std::thread t3();
return 0;
}
Программа должна выдавать примерно следующее:
entered thread 1396
leaving thread 1396
entered thread 1397
leaving thread 1397
entered thread 1398
leaving thread 1398
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <ctime>

std::mutex g_lock;

void threadFunction() {
    g_lock.lock(); // Захватываем мьютекс перед выполнением
    std::cout << "entered thread " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(rand() % 10));
    std::cout << "leaving thread " << std::this_thread::get_id() << std::endl;
    g_lock.unlock(); // Освобождаем мьютекс после выполнения
}

int main() {
    srand((unsigned int)time(0));
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);
    std::thread t3(threadFunction); // Здесь нужно передать функцию для потока
    
    t1.join(); // Ожидаем завершения потока t1
    t2.join(); // Ожидаем завершения потока t2
    t3.join(); // Ожидаем завершения потока t3
    
    return 0;
}
```
# Задание 2
## Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
using namespace std;
int main() {
try {
domain_error("Your domain is in error!");
}
(const exception& e) {
cerr << "Caught: " << e.what() << endl;
cerr << "Type: " << typeid(e).name() << endl;
}
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>  // Для ввода/вывода
#include <stdexcept> // Для класса domain_error
#include <typeinfo>  // Для typeid

using namespace std;

int main() {
    try {
        throw domain_error("Your domain is in error!"); // Бросаем исключение типа domain_error
    }
    catch (const exception& e) { // Ловим исключение типа exception (или его производные)
        cerr << "Caught: " << e.what() << endl;   // Выводим сообщение об ошибке
        cerr << "Type: " << typeid(e).name() << endl; // Выводим тип исключения
    }
    
    return 0;
}
```
# Задание 3
## Перенесите рисунок представленный ниже на программный код t задается пользователем в сек: 
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp

```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
import threading
import time

def f():
    """
    Функция, выполняющаяся в отдельном потоке.
    Имитирует работу в течение 7 секунд.
    """
    print("Thread 't' started")
    time.sleep(7)
    print("Thread 't' finished")

if __name__ == "__main__":
    # Запускаем поток 't'
    t = threading.Thread(target=f)
    t.start()

    # Выполняем другие задачи в основном потоке
    print("Main thread: Running some other tasks")
    time.sleep(2)  # Имитация выполнения задач
    print("Main thread: Other tasks finished")

    # Ожидаем завершения потока 't'
    print("Main thread: Waiting for thread 't' to finish")
    t.join()  # Основной поток ждет завершения потока 't'
    print("Main thread: Thread 't' has finished. Continuing main thread.")

    print("Main thread: Program completed.")
```
# Задание 4
## Перенесите рисунок представленный ниже на программный код:
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp

```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
import threading
import time

def task1():
    """Имитация задачи 1, выполняющейся в потоке t1."""
    print("Task 1 started in thread t1")
    time.sleep(10 * c)
    print("Task 1 finished in thread t1")

def task2():
    """Имитация задачи 2, выполняющейся в потоке t2."""
    print("Task 2 started in thread t2")
    time.sleep(1 * c)
    print("Task 2 finished in thread t2")

def task3():
    """Имитация задачи 3, выполняющейся в потоке t3."""
    print("Task 3 started in thread t3")
    time.sleep(3 * c)
    print("Task 3 finished in thread t3")

if __name__ == "__main__":
    c = 1  # Базовая единица времени (можно изменить)

    # Создание и запуск потоков
    t1 = threading.Thread(target=task1)
    t2 = threading.Thread(target=task2)
    t3 = threading.Thread(target=task3)

    t1.start()
    t2.start()
    t3.start()

    # Ожидание завершения потоков t1, t2 и t3
    print("Main thread: Waiting for threads t1, t2, and t3 to finish")
    t1.join()
    t2.join()
    t3.join()
    print("Main thread: All threads have finished. Continuing main thread.")

    print("Main thread: Program completed.")
```
# Задание 5
## Исправьте ошибки в программе.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
void task1(string msg) {
cout << "task1 says: " << msg;
}
int main() {
thread t1(task1);
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <thread>
#include <string>

void task1(std::string msg) {
    std::cout << "task1 says: " << msg << std::endl;
}

int main() {
    std::thread t1(task1, "Hello from thread t1!"); // Передаем аргумент в поток
    t1.join(); // Ожидаем завершения потока t1
    return 0;
}
```
# Задание 6 
## Исправьте ошибки в программе.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
static const int num_threads = 10;
//This function will be called from a thread
void call_from_thread(int tid) {
std::cout << "Launched by thread " << tid << std::endl;
}
int main() {
std::thread t[num_threads];
//Launch a group of threads
for (int i = 0; i < num_threads; ++i) {
t[i] = std::thread();
}
std::cout << "Launched from the main\n";
//Join the threads with the main thread
for (int i = 0; i < ; ++i) {
t[i].join();
}
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <thread>

static const int num_threads = 10;

// Эта функция будет вызываться из потока
void call_from_thread(int tid) {
    std::cout << "Launched by thread " << tid << std::endl;
}

int main() {
    std::thread t[num_threads];

    // Запускаем группу потоков
    for (int i = 0; i < num_threads; ++i) {
        t[i] = std::thread(call_from_thread, i); // Передаем функцию и аргумент при создании потока
    }

    std::cout << "Launched from the main\n";

    // Дожидаемся завершения потоков
    for (int i = 0; i < num_threads; ++i) { // Исправлена ошибка: i < num_threads
        t[i].join();
    }

    return 0; // Добавлен return 0;
}
```
# Задание 7
## Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
constexpr int COUNT_DATA{15};
// a global variable
static int myList[COUNT_DATA];
// a global instance of std::mutex to protect global variable
std::mutex myMutex;
void addToList(int max, int interval) {
// the access to this function is mutually exclusive
std::lock_guard guard(myMutex);

for (int i = 0; i < max; i++) {
if( (i % interval) == 0) myList[i] = i;
}
}
void printList() {
// the access to this function is mutually exclusive
std::lock_guard<> (myMutex);
for (auto itr{0}; itr < COUNT_DATA; ++itr ) {
cout << myList[itr] << ", ";
}
}
int main() {
int max = 100;
std::thread t1(addToList, max);
std::thread t2(addToList, max);
std::thread t3(printList);
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
 #include <iostream>
#include <thread>
#include <mutex>

constexpr int COUNT_DATA{15};
// a global variable
static int myList[COUNT_DATA];
// a global instance of std::mutex to protect global variable
std::mutex myMutex;

void addToList(int max, int interval) {
    // the access to this function is mutually exclusive
    std::lock_guard<std::mutex> guard(myMutex); // Явное указание типа для lock_guard

    for (int i = 0; i < COUNT_DATA; i++) { // Изменено max на COUNT_DATA
        if ((i % interval) == 0) myList[i] = i;
    }
}

void printList() {
    // the access to this function is mutually exclusive
    std::lock_guard<std::mutex> guard(myMutex); // Явное указание типа для lock_guard

    for (auto itr{0}; itr < COUNT_DATA; ++itr) {
        std::cout << myList[itr] << ", ";
    }
    std::cout << std::endl; // Добавлен перевод строки
}

int main() {
    int max = 100;
    int interval1 = 2; // Добавлен параметр interval для addToList
    int interval2 = 3; // Добавлен параметр interval для addToList

    std::thread t1(addToList, max, interval1);
    std::thread t2(addToList, max, interval2);
    std::thread t3(printList);

    t1.join(); // Добавлено ожидание завершения потока t1
    t2.join(); // Добавлено ожидание завершения потока t2
    t3.join(); // Добавлено ожидание завершения потока t3

    return 0; // Добавлен return 0
}
```
# Задание 8
##  Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
// Global mutex to protect shared_data
mutex mtx;
// Shared data variable
int shared_data = 0;
// Function to increment shared_data
void increment_data() {
// Create a unique_lock object, but defer locking the mutex
unique_lock<> (mtx, defer_lock);
// Critical section: safely modify shared_data
shared_data += 2;
}
int main() {
// Create two threads that run the increment_data function
thread t1();
thread t2();
// Wait for both threads to finish
t1.join();
// Output the value of shared_data
cout << "Value of shared variable: " << shared_data;
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// Global mutex to protect shared_data
mutex mtx;
// Shared data variable
int shared_data = 0;

// Function to increment shared_data
void increment_data() {
    // Create a unique_lock object, but defer locking the mutex
    unique_lock<mutex> lck(mtx, defer_lock); // Явное указание типа mutex и создание объекта lck
    lck.lock(); // Блокируем мьютекс

    // Critical section: safely modify shared_data
    shared_data += 2;

    lck.unlock(); // Необязательно: мьютекс будет автоматически разблокирован при выходе из функции
}

int main() {
    // Create two threads that run the increment_data function
    thread t1(increment_data); // Передаем функцию для выполнения в потоке
    thread t2(increment_data); // Передаем функцию для выполнения в потоке

    // Wait for both threads to finish
    t1.join();
    t2.join();

    // Output the value of shared_data
    cout << "Value of shared variable: " << shared_data << endl; // Добавлен endl для переноса строки
    return 0; // Добавлен return 0
}
```
# Задание 9
##  Найдите ошибки в коде, и сделайте чтобы вывод в терминале был: new faild.
### НЕПРАВИЛЬНЫЙ КОД:
``` cpp
std::mutex m;
int a,b;
void f1() {
lock_guard lock(m);
a = 1;
try {
int * ptr = new int[10];
}catch(...) {
cout <<"new faild"<<endl;
}
// still locked
std::this_thread::sleep_for(std::chrono::milliseconds(2000)); //2s
b = 2;
}
void f2() {
lock_guard<> (m);
cout << a <<" : "<<b <<endl;
}
int main() {
std::thread T1(f1);
std::thread T2(f2);
}
```
### ИСПРАВЛЕННЫЙ КОД:
``` cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

std::mutex m;
int a = 0, b = 0; // Инициализируем a и b нулями

void f1() {
    lock_guard<mutex> lock(m); // Явное указание типа mutex
    a = 1;
    try {
        int* ptr = new int[999999999999999999]; // Попытка выделить очень большой объем памяти для вызова исключения
    } catch (const std::bad_alloc& e) { // Ловим исключение std::bad_alloc
        cout << "new faild" << endl;
    }
    // still locked
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // 2s
    b = 2;
}

void f2() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Даем время f1 захватить мьютекс
    lock_guard<mutex> lock(m); // Явное указание типа mutex и создание объекта lock
    cout << a << " : " << b << endl;
}

int main() {
    std::thread T1(f1);
    std::thread T2(f2);

    T1.join();
    T2.join();

    return 0; // Добавлен return 0
}
```
