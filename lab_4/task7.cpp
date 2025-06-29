#include "tasks.h"
#include <iostream>
#include <string>
#include <algorithm>

// Type alias для улучшения читаемости
using phase_string = std::string;

// Задание 7: Перестановки строки
void task7() {
    phase_string phases = "UVWN";
    std::cout << "Варианты подключения обмоток для 3х-фазного двигателя UVWN:\n";
    std::size_t count = 0;
    std::sort(phases.begin(), phases.end());
    do {
        std::cout << phases << std::endl;
        count++;
    } while (std::next_permutation(phases.begin(), phases.end()));
    std::cout << "Всего перестановок: " << count << std::endl;
}
