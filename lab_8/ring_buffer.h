#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

template <typename T>
class RingBuffer {
 private:
  T* buffer_;
  size_t capacity_;
  size_t size_;
  size_t head_;
  bool is_writing_;
  std::thread writer_thread_;
  std::mutex mutex_;
  std::condition_variable cv_;

 public:
  // Запрещаем неявное преобразование и конструктор копирования
  explicit RingBuffer(size_t capacity) :
      capacity_(capacity), size_(0), head_(0), is_writing_(false), buffer_(nullptr) {
    buffer_ = new T[capacity_];
    if (!buffer_) {
      throw std::bad_alloc();
    }
  }

  RingBuffer(const RingBuffer&) = delete;
  RingBuffer& operator=(const RingBuffer&) = delete;

  ~RingBuffer() {
    stopWriter();
    if (buffer_) {
      delete[] buffer_;
    }
  }

  // Оператор доступа к элементу по индексу
  T& operator[](size_t index) {
    if (index >= capacity_) {
      throw std::out_of_range("Index out of range");
    }
    return buffer_[index];
  }

  // Префиксный инкремент (++)
  RingBuffer& operator++() {
    std::lock_guard<std::mutex> lock(mutex_);
    head_ = (head_ + 1) % capacity_;
    return *this;
  }

  // Постфиксный инкремент (++)
  RingBuffer operator++(int) {
    RingBuffer temp = *this;
    ++(*this);
    return temp;
  }

  // Оператор записи (+)
  RingBuffer& operator+=(const T& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    buffer_[head_] = value;
    head_ = (head_ + 1) % capacity_;
    if (size_ < capacity_) {
      size_++;
    }
    return *this;
  }

  // Оператор вывода в ostream
  friend std::ostream& operator<<(std::ostream& os, const RingBuffer& rb) {
    for (size_t i = 0; i < rb.size_; ++i) {
      os << rb.buffer_[(rb.head_ + i) % rb.capacity_] << " ";
    }
    return os;
  }

  // Оператор ввода из istream
  friend std::istream& operator>>(std::istream& is, RingBuffer& rb) {
    std::lock_guard<std::mutex> lock(rb.mutex_);
    for (size_t i = 0; i < rb.capacity_; ++i) {
      is >> rb.buffer_[i];
    }
    rb.size_ = rb.capacity_;
    return is;
  }

  // Функция для запуска потока записи
  void startWriter() {
    is_writing_ = true;
    writer_thread_ = std::thread([this] { writerFunction(); });
  }

  // Функция для остановки потока записи
  void stopWriter() {
    if (writer_thread_.joinable()) {
      {
        std::lock_guard<std::mutex> lock(mutex_);
        is_writing_ = false;
      }
      cv_.notify_one();
      writer_thread_.join();
    }
  }

  // Функция потока записи
  void writerFunction() {
    while (is_writing_) {
      std::unique_lock<std::mutex> lock(mutex_);
      cv_.wait(lock, [this] { return !is_writing_; });
      if (!is_writing_) break;

      T value;
      std::cout << "Введите значение для записи в буфер (или 'q' для выхода): ";
      std::cin >> value;

      if (std::cin.fail()) {
        std::cin.clear();
        std::string input;
        std::cin >> input;
        if (input == "q") {
          is_writing_ = false;
          break;
        } else {
          std::cout << "Некорректный ввод. Пожалуйста, введите число или 'q'.\n";
          continue;
        }
      }

      buffer_[head_] = value;
      head_ = (head_ + 1) % capacity_;
      if (size_ < capacity_) {
        size_++;
      }

      std::cout << "Записано: " << value << std::endl;
    }
    std::cout << "Поток записи завершен.\n";
  }

  // Вывод элементов в заданном диапазоне
  void printRange(size_t start, size_t end) const {
    if (start >= capacity_ || end >= capacity_ || start > end) {
      throw std::out_of_range("Invalid range");
    }
    for (size_t i = start; i <= end; ++i) {
      std::cout << buffer_[i] << " ";
    }
  }
};

void run_ring_buffer_task();

#endif  // RING_BUFFER_H
