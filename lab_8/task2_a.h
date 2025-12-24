#ifndef TASK2_A_H
#define TASK2_A_H

#include <list>
#include <vector>
#include <iostream>

namespace TaskA {

    // Функция для смешивания вектора и списка
    std::vector<int> mix_vector_list(const std::vector<int>& vec, const std::list<int>& lst);

    // Функция для запуска задания A
    void run_task_a();

}  // namespace TaskA

#endif  // TASK2_A_H
