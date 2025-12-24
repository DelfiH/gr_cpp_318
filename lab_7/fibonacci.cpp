#include "fibonacci.h"
#include <iostream> // Для std::cerr

//-----------------------------------------------------------------------------
// Метод для запуска вычисления чисел Фибоначчи
//-----------------------------------------------------------------------------
void FibonacciCalculator::calculate() {
  // Обработка тривиальных случаев n = 0 и n = 1
  if (n_ == 0) {
    result_ = 0;
    std::cout << "Fibonacci(" << n_ << ") = " << result_ << std::endl;
    return;
  }

  if (n_ == 1) {
    result_ = 1;
    std::cout << "Fibonacci(" << n_ << ") = " << result_ << std::endl;
    return;
  }

  // Инициализация первых двух чисел Фибоначчи
  fibonacci_results_[0] = 0;
  fibonacci_results_[1] = 1;

  // Создание и запуск потоков
  for (int i = 0; i < num_threads_; ++i) {
    threads_.emplace_back(&FibonacciCalculator::fibonacci_thread, this, i);
  }

  // Ожидание завершения всех потоков
  for (auto& thread : threads_) {
    thread.join();
  }

  result_ = fibonacci_results_[n_];
  std::cout << "Fibonacci(" << n_ << ") = " << result_ << std::endl;
}

//-----------------------------------------------------------------------------
// Метод, выполняемый каждым потоком для вычисления чисел Фибоначчи
//-----------------------------------------------------------------------------
void FibonacciCalculator::fibonacci_thread(int thread_id) {
  while (true) {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [this, thread_id] {
      return current_iteration_ > n_ || (current_iteration_ <= n_ && current_iteration_ % num_threads_ == thread_id);
    });

    if (current_iteration_ > n_) {
      break; // Все вычисления завершены
    }

    int current = current_iteration_;
    current_iteration_++;

    lock.unlock();
    cv_.notify_all();

    try {
      if (current == 9) {
        throw std::runtime_error("Нельзя вычислять 9-е число Фибоначчи!");
      }

      if (current > 1) {
        fibonacci_results_[current] = fibonacci_results_[current - 1] + fibonacci_results_[current - 2];
      }
    } catch (const std::exception& e) {
      std::cerr << "Ошибка при вычислении Fibonacci(" << current << "): " << e.what() << std::endl;
      // Обработка ошибки: например, можно установить флаг ошибки и выйти из потока
      // Или, если возможно, продолжить вычисления для других значений
      break; // Выходим из потока при возникновении ошибки
    }
  }
}
