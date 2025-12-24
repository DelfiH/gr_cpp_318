#include "ring_buffer.h"
#include <iostream>
#include <chrono>
#include <thread>

//-----------------------------------------------------------------------------
// Функция для запуска задания с кольцевым буфером
//-----------------------------------------------------------------------------
void run_ring_buffer_task() {
    try {
        RingBuffer<int> rb(5);

        std::cout << "Для выполнения задания с кольцевым буфером, пожалуйста, введите 5 целых чисел через пробел.\n";
        std::cout << "После этого начнется запись в буфер в отдельном потоке. Вы можете вводить числа или 'q' для выхода.\n";

        // Демонстрация ввода
        std::cin >> rb;
        std::cout << "Вы ввели: " << rb << std::endl;

        // Демонстрация работы операторов
        std::cout << "rb[0]: " << rb[0] << std::endl;
        rb += 100;
        std::cout << "rb после += 100: " << rb << std::endl;

        // Демонстрация потока записи
        rb.startWriter();  // Запускаем поток записи

        // Даем время потоку записи поработать
        std::this_thread::sleep_for(std::chrono::seconds(10));
        rb.stopWriter();

        std::cout << "Все элементы буфера: " << rb << std::endl;
        rb.printRange(1, 3);
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}
