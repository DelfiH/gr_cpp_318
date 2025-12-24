#include "task3.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

namespace Task3 {

//-----------------------------------------------------------------------------
// Функция для преобразования единиц измерения
//-----------------------------------------------------------------------------
void UnitsConverter::convert(double value, int from_unit,
                             const std::vector<int>& to_units) const {
  // Преобразуем введенное значение в байты
  double bytes = to_bytes(value, from_unit);

  // Выводим результаты преобразования с использованием stringstream
  std::stringstream ss;
  ss << std::fixed << std::setprecision(2);

  ss << "Результаты преобразования:\n";
  for (int unit : to_units) {
    switch (unit) {
      case 1:
        ss << "  Гбайт: " << to_gbyte(bytes) << " Гбайт\n";
        break;
      case 2:
        ss << "  Мбайт: " << to_mbyte(bytes) << " Мбайт\n";
        break;
      case 3:
        ss << "  Кбайт: " << to_kbyte(bytes) << " Кбайт\n";
        break;
      case 4:
        ss << "  Байт: " << bytes << " Байт\n";
        break;
      case 5:
        ss << "  МиБ: " << to_mib(bytes) << " МиБ\n";
        break;
      default:
        ss << "  Неподдерживаемая единица: " << unit << "\n";
        break;
    }
  }

  std::cout << ss.str();
}

//-----------------------------------------------------------------------------
// Функция для преобразования в байты
//-----------------------------------------------------------------------------
double UnitsConverter::to_bytes(double value, int from_unit) const {
  switch (from_unit) {
    case 1:  // Gbyte
      return value * kGbyteToByte;
    case 2:  // Mbyte
      return value * kMbyteToByte;
    case 3:  // Kbyte
      return value * kKbyteToByte;
    case 4:  // byte
      return value;
    case 5:  // MiB
      return value * kMibToByte;
    default:
      std::cout << "Ошибка: Неподдерживаемая единица измерения: " << from_unit
                << std::endl;
      return 0.0;
  }
}

//-----------------------------------------------------------------------------
// Функция для запуска задачи 3
//-----------------------------------------------------------------------------
void run_task_3() {
  UnitsConverter converter;
  double value;
  int from_unit;
  std::vector<int> to_units;
  int unit_choice;

  std::cout << "Вы выбрали: Преобразование единиц информации\n";
  std::cout << "Введите значение: ";
  std::cin >> value;

  std::cout << "Выберите единицу измерения:\n";
  std::cout << "1. Gbyte\n";
  std::cout << "2. Mbyte\n";
  std::cout << "3. Kbyte\n";
  std::cout << "4. byte\n";
  std::cout << "5. MiB\n";
  std::cout << "Ваш выбор: ";
  std::cin >> from_unit;

  // Сразу преобразуем во все доступные единицы
  to_units = {1, 2, 3, 4, 5};
  converter.convert(value, from_unit, to_units);
}

}  // namespace Task3
