#include "task2_a.h"

#include <iostream>

namespace TaskA {

//-----------------------------------------------------------------------------
// Функция для смешивания вектора и списка
//-----------------------------------------------------------------------------
std::vector<int> mix_vector_list(const std::vector<int>& vec, const std::list<int>& lst) {
    // Создаем результирующий вектор, копируя исходный
    std::vector<int> result = vec;
    auto list_iterator = lst.begin();

    // Итерируемся по результирующему вектору
    for (size_t i = 0; i < result.size(); ++i) {
        // Если элемент четный
        if (result[i] % 2 == 0) {
            // Если есть элементы в списке для замены
            if (list_iterator != lst.end()) {
                // Если текущий элемент списка нечетный
                if (*list_iterator % 2 != 0) {
                    // Заменяем четный элемент вектора на нечетный элемент списка
                    result[i] = *list_iterator;
                }
                // Переходим к следующему элементу списка
                ++list_iterator;
            }
        }
    }
    return result;
}

//-----------------------------------------------------------------------------
// Функция для запуска задачи A
//-----------------------------------------------------------------------------
void run_task_a() {
    std::cout << "Вы выбрали: Смешать вектор и список\n";

    // Инициализация данных для задачи A
    std::vector<int> my_vector = {3, 5, 4, 5, 9, 20, 3, 23, 12};
    std::list<int> my_list = {-5, -9, -3, -15, -126, -33, -50};

    std::cout << "my_vector:\n";
    for (int val : my_vector) {
        std::cout << val << " ";
    }
    std::cout << "\nmy_list:\n";
    for (int val : my_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Получаем смешанный вектор
    std::vector<int> mixed_vector = mix_vector_list(my_vector, my_list);

    std::cout << "Смешанный вектор:\n";
    for (int val : mixed_vector) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

}  // namespace TaskA
