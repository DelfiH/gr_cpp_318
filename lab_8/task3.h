#define TASK3_H

#include <iostream>
#include <string>
#include <vector>

namespace Task3 {

// Класс для преобразования единиц информации
class UnitsConverter {
 public:
  // Конструктор по умолчанию
  UnitsConverter() = default;

  // Функция для преобразования единиц информации
  void convert(double value, int from_unit,
               const std::vector<int>& to_units) const;

 private:
  // Константы для преобразования
  static constexpr double kGbyteToByte = 1000000000.0;  // 1 Гбайт = 10^9 байт
  static constexpr double kMbyteToByte = 1000000.0;     // 1 Мбайт = 10^6 байт
  static constexpr double kKbyteToByte = 1000.0;        // 1 Кбайт = 10^3 байт
  static constexpr double kMibToByte = 1048576.0;       // 1 МиБ = 2^20 байт

  // Вспомогательные функции для преобразования в разные единицы
  double to_gbyte(double bytes) const { return bytes / kGbyteToByte; }
  double to_mbyte(double bytes) const { return bytes / kMbyteToByte; }
  double to_kbyte(double bytes) const { return bytes / kKbyteToByte; }
  double to_mib(double bytes) const { return bytes / kMibToByte; }
  double to_bytes(double value, int from_unit) const;
};

// Функция для запуска задания 3
void run_task_3();

}
