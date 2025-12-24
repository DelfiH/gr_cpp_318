#ifndef FILEVECTOR_H
#define FILEVECTOR_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>

template <typename T>
class FileVector {
public:
    class iterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        iterator(FileVector<T>* vec, size_t pos) : vec_(vec), pos_(pos) {}

        reference operator*() const { return vec_->operator[](pos_); } // Используем operator[]
        pointer operator->() const { return &(vec_->operator[](pos_)); }

        iterator& operator++() { ++pos_; return *this; }
        iterator operator++(int) { iterator temp = *this; ++pos_; return temp; }
        iterator& operator--() { --pos_; return --pos_; }
        iterator operator--(int) { iterator temp = *this; --pos_; return temp; }

        iterator operator+(difference_type n) const { return iterator(vec_, pos_ + n); }
        iterator operator-(difference_type n) const { return iterator(vec_, pos_ - n); }
        difference_type operator-(const iterator& other) const { return pos_ - other.pos_; }

        reference operator[](difference_type n) const { return vec_->operator[](pos_ + n); }

        bool operator==(const iterator& other) const { return vec_ == other.vec_ && pos_ == other.pos_; }
        bool operator!=(const iterator& other) const { return !(*this == other); }
        bool operator<(const iterator& other) const { return pos_ < other.pos_; }
        bool operator>(const iterator& other) const { return pos_ > other.pos_; }
        bool operator<=(const iterator& other) const { return pos_ <= other.pos_; }
        bool operator>=(const iterator& other) const { return pos_ >= other.pos_; }

    private:
        FileVector<T>* vec_;
        size_t pos_;

        friend class FileVector<T>; // FileVector имеет доступ к private
    };

    FileVector(const std::string& filename, size_t window_size = 100);
    FileVector(const std::string& filename, size_t initial_size, const T& initial_value, size_t window_size = 100);
    ~FileVector();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void resize(size_t new_size, const T& val = T());
    void push_back(const T& value);
    T pop_back();

    size_t size() const { return file_size; }
    bool empty() const { return file_size == 0; }

    iterator begin() { return iterator(this, 0); }
    iterator end() { return iterator(this, file_size); }

    void seek_window(size_t index);
    void seek_window(iterator it);

    void flush();

private:
    std::string filename;
    std::fstream file;
    std::vector<T> window;
    size_t window_start;
    size_t window_size;
    size_t file_size;
    bool window_dirty;

    void load_window(size_t index);
    void save_window();
    void ensure_file_size(size_t size);
};

// Определение fileVectorMenu здесь
inline void fileVectorMenu() {
    std::cout << "Вы выбрали FileVector.\n";

    std::string filename;
    size_t initial_size;
    int initial_value;  // Для простоты используем int

    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    std::cout << "Введите начальный размер вектора: ";
    std::cin >> initial_size;

    std::cout << "Введите начальное значение для элементов: ";
    std::cin >> initial_value;

    FileVector<int> vec(filename, initial_size, initial_value);

    int choice;
    do {
        std::cout << "\nМеню FileVector:\n";
        std::cout << "1. Доступ к элементу по индексу\n";
        std::cout << "2. Изменить размер вектора\n";
        std::cout << "3. Добавить элемент в конец\n";
        std::cout << "4. Удалить элемент из конца\n";
        std::cout << "5. Вывести размер вектора\n";
        std::cout << "0. Вернуться в главное меню\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                size_t index;
                std::cout << "Введите индекс элемента: ";
                std::cin >> index;
                try {
                    std::cout << "Значение элемента: " << vec[index] << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cerr << "Ошибка: " << e.what() << std::endl;
                }
                break;
            }
            case 2: {
                size_t new_size;
                int new_value;
                std::cout << "Введите новый размер вектора: ";
                std::cin >> new_size;
                std::cout << "Введите значение для новых элементов: ";
                std::cin >> new_value;
                vec.resize(new_size, new_value);
                std::cout << "Размер вектора изменен.\n";
                break;
            }
            case 3: {
                int value;
                std::cout << "Введите значение для добавления: ";
                std::cin >> value;
                vec.push_back(value);
                std::cout << "Элемент добавлен.\n";
                break;
            }
            case 4: {
                try {
                    vec.pop_back();
                    std::cout << "Последний элемент удален.\n";
                } catch (const std::out_of_range& e) {
                    std::cerr << "Ошибка: " << e.what() << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Размер вектора: " << vec.size() << std::endl;
                break;
            }
            case 0:
                std::cout << "Возврат в главное меню.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте еще раз.\n";
        }
    } while (choice != 0);
}

template <typename T>
FileVector<T>::FileVector(const std::string& filename, size_t window_size)
    : filename(filename),
      file(filename, std::ios::binary | std::ios::in | std::ios::out | std::ios::app),
      window_start(0),
      window_size(window_size),
      file_size(0),
      window_dirty(false) {
    if (!file.is_open()) {
        file.clear();
        file.open(filename, std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
        if (!file.is_open()) {
            throw std::runtime_error("Не удалось открыть или создать файл: " + filename);
        }
    } else {
        file.seekg(0, std::ios::end);
        file_size = file.tellg() / sizeof(T);
    }
    window.resize(std::min(window_size, file_size));
}

template <typename T>
FileVector<T>::FileVector(const std::string& filename, size_t initial_size, const T& initial_value, size_t window_size)
    : filename(filename),
      file(filename, std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc),
      window_start(0),
      window_size(window_size),
      file_size(initial_size),
      window_dirty(false) {
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось создать файл: " + filename);
    }
    window.resize(std::min(window_size, file_size));
    resize(initial_size, initial_value);
}

template <typename T>
FileVector<T>::~FileVector() {
    flush();
    file.close();
}

template <typename T>
void FileVector<T>::load_window(size_t index) {
    if (index >= file_size) {
        throw std::out_of_range("Index out of range");
    }

    save_window();

    window_start = index;
    size_t load_size = std::min(window_size, file_size - index);
    window.resize(load_size);

    file.seekg(window_start * sizeof(T), std::ios::beg);
    file.read(reinterpret_cast<char*>(window.data()), load_size * sizeof(T));
    if (file.fail() && !file.eof()) {
        throw std::runtime_error("Ошибка чтения из файла");
    }

    window_dirty = false;
}

template <typename T>
void FileVector<T>::save_window() {
    if (window_dirty) {
        file.seekp(window_start * sizeof(T), std::ios::beg);
        file.write(reinterpret_cast<const char*>(window.data()), window.size() * sizeof(T));
        if (file.fail()) {
            throw std::runtime_error("Ошибка записи в файл");
        }
        window_dirty = false;
    }
}

template <typename T>
void FileVector<T>::ensure_file_size(size_t size) {
    if (file_size < size) {
        resize(size);
    }
}

template <typename T>
T& FileVector<T>::operator[](size_t index) {
    if (index >= file_size) {
        throw std::out_of_range("Index out of range");
    }

    if (index < window_start || index >= window_start + window.size()) {
        load_window(index);
    }

    window_dirty = true;
    return window[index - window_start];
}

template <typename T>
const T& FileVector<T>::operator[](size_t index) const {
    if (index >= file_size) {
        throw std::out_of_range("Index out of range");
    }

    if (index < window_start || index >= window_start + window.size()) {
        load_window(index);
    }

    return window[index - window_start];
}

template <typename T>
void FileVector<T>::resize(size_t new_size, const T& val) {
    flush();

    size_t old_size = file_size;
    file_size = new_size;

    file.seekp(0, std::ios::end);
    if (new_size > old_size) {
        size_t append_size = new_size - old_size;
        for (size_t i = 0; i < append_size; ++i) {
            file.write(reinterpret_cast<const char*>(&val), sizeof(T));
        }
    } else {
        // To truncate the file, we need to close and reopen it
        file.close();
        file.open(filename, std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
        if (!file.is_open()) {
            throw std::runtime_error("Не удалось открыть файл для изменения размера: " + filename);
        }
    }

    window_start = 0;
    window.resize(std::min(window_size, file_size));
}

template <typename T>
void FileVector<T>::flush() {
    save_window();
    file.flush();
}

template <typename T>
void FileVector<T>::push_back(const T& value) {
    resize(file_size + 1);
    (*this)[file_size - 1] = value;
}

template <typename T>
T FileVector<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Vector is empty");
    }
    T value = (*this)[file_size - 1];
    resize(file_size - 1);
    return value;
}

template <typename T>
void FileVector<T>::seek_window(size_t index) {
    if (index >= file_size) {
        throw std::out_of_range("Index out of range");
    }
    load_window(index);
}

template <typename T>
void FileVector<T>::seek_window(typename FileVector<T>::iterator it) {
    seek_window(it.pos_);
}

#endif
