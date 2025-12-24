#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iostream>
#include <thread>
#include <vector>
#include <stdexcept>
#include <mutex>
#include <condition_variable>

//-----------------------------------------------------------------------------
// Класс для вычисления чисел Фибоначчи с использованием многопоточности
//-----------------------------------------------------------------------------
class FibonacciCalculator {
public:
  // Конструктор класса
  FibonacciCalculator(int n) : n_(n), result_(0), current_iteration_(0) {
    num_threads_ = std::thread::hardware_concurrency();
    if (num_threads_ == 0) {
      num_threads_ = 4; // Минимальное количество потоков ??
    }
    fibonacci_results_.resize(n_ + 1, 0);
  }

  // Деструктор класса
  ~FibonacciCalculator() {}

  // Метод для запуска вычислений
  void calculate();

private:
  int n_; // Количество чисел Фибоначчи для вычисления
  int num_threads_; // Количество используемых потоков
  std::vector<std::thread> threads_; // Вектор потоков
  std::vector<long long> fibonacci_results_; // Вектор для хранения результатов
  long long result_; // Итоговый результат
  int current_iteration_; // Текущая итерация
  std::mutex mutex_; // Мьютекс для синхронизации потоков
  std::condition_variable cv_; // Условная переменная для синхронизации потоков

  // Метод, выполняемый каждым потоком
  void fibonacci_thread(int thread_id);
};

#endif // FIBONACCI_H
