#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>
#include <fstream> // Для работы с файлами

// Enum для типов голов
enum class HeadType {
    ROUND,
    SQUARE,
    TRIANGULAR,
    OVAL,
    UNKNOWN
};

// Enum для типов хвостов
enum class TailType {
    LONG,
    SHORT,
    PLUMED,
    RINGED,
    NONE,
    UNKNOWN
};

// Enum для типов покровов тела
enum class BodyCoveringType {
    RED_FUR,
    BLACK_SCALES,
    BLUE_FEATHERS,
    GREEN_SKIN,
    PURPLE_SHELL,
    UNKNOWN
};

// Enum для цветов глаз
enum class EyeColor {
    BLUE,
    GREEN,
    BROWN,
    RED,
    YELLOW,
    UNKNOWN
};

// Структура для представления головы
struct Head {
    HeadType type;
};

// Структура для представления хвоста
struct Tail {
    TailType type;
};

// Структура для представления существа
struct Creature {
    std::vector<Head> heads;
    int numLegs;
    BodyCoveringType bodyCovering;
    std::vector<Tail> tails;
    int numEyes;
    EyeColor eyeColor;
    double height; // Рост
    double weight; // Вес
    std::string behavior; // Особенности поведения
};

// Функция для проверки корректности ввода целого числа
int getValidInt(const std::string& prompt) {
    int input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;

        if (std::cin.fail()) {
            std::cout << "Ошибка: Некорректный ввод. Пожалуйста, введите целое число.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (input < 0) {
            std::cout << "Ошибка: Пожалуйста, введите неотрицательное число.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return input;
}

// Функция для проверки корректности ввода числа с плавающей точкой
double getValidDouble(const std::string& prompt) {
    double input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;

        if (std::cin.fail()) {
            std::cout << "Ошибка: Некорректный ввод. Пожалуйста, введите число.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (input < 0) {
            std::cout << "Ошибка: Пожалуйста, введите неотрицательное число.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return input;
}

// Функция для проверки корректности ввода строки (не должна быть пустой и не должна содержать цифры)
std::string getValidString(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "Ошибка: Ввод не может быть пустым. Пожалуйста, попробуйте еще раз.\n";
        } else {
            // Проверяем, что строка не содержит цифры
            bool hasDigits = false;
            for (char c : input) {
                if (std::isdigit(c)) {
                    hasDigits = true;
                    break;
                }
            }
            if (hasDigits) {
                std::cout << "Ошибка: Ввод не должен содержать цифры. Пожалуйста, попробуйте еще раз.\n";
            } else {
                break;
            }
        }
    }
    return input;
}

// Функция для проверки корректности ввода имени файла (не должна быть пустой)
std::string getValidFilename(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (input.empty()) {
            std::cout << "Ошибка: Имя файла не может быть пустым. Пожалуйста, попробуйте еще раз.\n";
        } else {
            break;
        }
    }
    return input;
}

// Функция для преобразования строки в нижний регистр
std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Функция для выбора типа головы из enum
HeadType chooseHeadType() {
    std::cout << "\nВыберите тип головы:\n";
    std::cout << "1. Круглая\n";
    std::cout << "2. Квадратная\n";
    std::cout << "3. Треугольная\n";
    std::cout << "4. Овальная\n";

    int choice = getValidInt("Введите номер выбранного типа головы: ");

    switch (choice) {
        case 1: return HeadType::ROUND;
        case 2: return HeadType::SQUARE;
        case 3: return HeadType::TRIANGULAR;
        case 4: return HeadType::OVAL;
        default:
            std::cout << "Некорректный выбор. Установлен тип головы: Неизвестно.\n";
            return HeadType::UNKNOWN;
    }
}

// Функция для выбора типа хвоста из enum
TailType chooseTailType() {
    std::cout << "\nВыберите тип хвоста:\n";
    std::cout << "1. Длинный\n";
    std::cout << "2. Короткий\n";
    std::cout << "3. Перистый\n";
    std::cout << "4. Кольцевой\n";
    std::cout << "5. Отсутствует\n";

    int choice = getValidInt("Введите номер выбранного типа хвоста: ");

    switch (choice) {
        case 1: return TailType::LONG;
        case 2: return TailType::SHORT;
        case 3: return TailType::PLUMED;
        case 4: return TailType::RINGED;
        case 5: return TailType::NONE;
        default:
            std::cout << "Некорректный выбор. Установлен тип хвоста: Неизвестно.\n";
            return TailType::UNKNOWN;
    }
}

// Функция для выбора типа покрова тела из enum
BodyCoveringType chooseBodyCoveringType() {
    std::cout << "\nВыберите тип покрова тела:\n";
    std::cout << "1. Красная шерсть\n";
    std::cout << "2. Черная чешуя\n";
    std::cout << "3. Синие перья\n";
    std::cout << "4. Зеленая кожа\n";
    std::cout << "5. Фиолетовый панцирь\n";

    int choice = getValidInt("Введите номер выбранного типа покрова тела: ");

    switch (choice) {
        case 1: return BodyCoveringType::RED_FUR;
        case 2: return BodyCoveringType::BLACK_SCALES;
        case 3: return BodyCoveringType::BLUE_FEATHERS;
        case 4: return BodyCoveringType::GREEN_SKIN;
        case 5: return BodyCoveringType::PURPLE_SHELL;
        default:
            std::cout << "Некорректный выбор. Установлен тип покрова тела: Неизвестно.\n";
            return BodyCoveringType::UNKNOWN;
    }
}

// Функция для выбора цвета глаз из enum
EyeColor chooseEyeColor() {
    std::cout << "\nВыберите цвет глаз:\n";
    std::cout << "1. Синий\n";
    std::cout << "2. Зеленый\n";
    std::cout << "3. Коричневый\n";
    std::cout << "4. Красный\n";
    std::cout << "5. Желтый\n";

    int choice = getValidInt("Введите номер выбранного цвета глаз: ");

    switch (choice) {
        case 1: return EyeColor::BLUE;
        case 2: return EyeColor::GREEN;
        case 3: return EyeColor::BROWN;
        case 4: return EyeColor::RED;
        case 5: return EyeColor::YELLOW;
        default:
            std::cout << "Некорректный выбор. Установлен цвет глаз: Неизвестно.\n";
            return EyeColor::UNKNOWN;
    }
}

// Функция для создания существа
Creature createCreature() {
    Creature creature;

    // Запрашиваем параметры существа
    int numHeads = getValidInt("Введите количество голов существа: ");
    creature.heads.resize(numHeads);
    for (int i = 0; i < numHeads; ++i) {
        creature.heads[i].type = chooseHeadType();
    }

    creature.numLegs = getValidInt("Введите количество лап существа: ");
    creature.bodyCovering = chooseBodyCoveringType();

    int numTails = getValidInt("Введите количество хвостов у существа: ");
    creature.tails.resize(numTails);
    for (int i = 0; i < numTails; ++i) {
        creature.tails[i].type = chooseTailType();
    }

    creature.numEyes = getValidInt("Введите количество глаз у существа: ");
    creature.eyeColor = chooseEyeColor();

    creature.height = getValidDouble("Введите рост существа (в метрах): ");
    creature.weight = getValidDouble("Введите вес существа (в килограммах): ");
    creature.behavior = getValidString("Опишите особенности поведения существа: ");

    return creature;
}

// Функция для вывода информации о существе
void displayCreature(const Creature& creature) {
    std::cout << "\n=== Новый вид существа ===\n";
    std::cout << "Количество голов: " << creature.heads.size() << "\n";
    std::cout << "Типы голов: ";
    for (const auto& head : creature.heads) {
        switch (head.type) {
            case HeadType::ROUND: std::cout << "Круглая "; break;
            case HeadType::SQUARE: std::cout << "Квадратная "; break;
            case HeadType::TRIANGULAR: std::cout << "Треугольная "; break;
            case HeadType::OVAL: std::cout << "Овальная "; break;
            case HeadType::UNKNOWN: std::cout << "Неизвестно "; break;
        }
    }
    std::cout << "\n";

    std::cout << "Количество лап: " << creature.numLegs << "\n";

    std::cout << "Покров тела: ";
    switch (creature.bodyCovering) {
        case BodyCoveringType::RED_FUR: std::cout << "Красная шерсть\n"; break;
        case BodyCoveringType::BLACK_SCALES: std::cout << "Черная чешуя\n"; break;
        case BodyCoveringType::BLUE_FEATHERS: std::cout << "Синие перья\n"; break;
        case BodyCoveringType::GREEN_SKIN: std::cout << "Зеленая кожа\n"; break;
        case BodyCoveringType::PURPLE_SHELL: std::cout << "Фиолетовый панцирь\n"; break;
        case BodyCoveringType::UNKNOWN: std::cout << "Неизвестно\n"; break;
    }

    std::cout << "Количество хвостов: " << creature.tails.size() << "\n";
    std::cout << "Типы хвостов: ";
    for (const auto& tail : creature.tails) {
        switch (tail.type) {
            case TailType::LONG: std::cout << "Длинный "; break;
            case TailType::SHORT: std::cout << "Короткий "; break;
            case TailType::PLUMED: std::cout << "Перистый "; break;
            case TailType::RINGED: std::cout << "Кольцевой "; break;
            case TailType::NONE: std::cout << "Отсутствует "; break;
            case TailType::UNKNOWN: std::cout << "Неизвестно "; break;
        }
    }
    std::cout << "\n";

    std::cout << "Количество глаз: " << creature.numEyes << "\n";

    std::cout << "Цвет глаз: ";
    switch (creature.eyeColor) {
        case EyeColor::BLUE: std::cout << "Синий\n"; break;
        case EyeColor::GREEN: std::cout << "Зеленый\n"; break;
        case EyeColor::BROWN: std::cout << "Коричневый\n"; break;
        case EyeColor::RED: std::cout << "Красный\n"; break;
        case EyeColor::YELLOW: std::cout << "Желтый\n"; break;
        case EyeColor::UNKNOWN: std::cout << "Неизвестно\n"; break;
    }

    std::cout << "Рост: " << creature.height << " метров\n";
    std::cout << "Вес: " << creature.weight << " килограммов\n";
    std::cout << "Особенности поведения: " << creature.behavior << "\n";

    std::cout << "Вот такое удивительное существо у Вас получилось! ?\n";
}

// Функция для сохранения существа в файл
void saveCreatureToFile(const Creature& creature, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        // Сохраняем данные существа в файл
        file << static_cast<int>(creature.heads.size()) << "\n";
        for (const auto& head : creature.heads) {
            file << static_cast<int>(head.type) << "\n";
        }
        file << creature.numLegs << "\n";
        file << static_cast<int>(creature.bodyCovering) << "\n";
        file << static_cast<int>(creature.tails.size()) << "\n";
        for (const auto& tail : creature.tails) {
            file << static_cast<int>(tail.type) << "\n";
        }
        file << creature.numEyes << "\n";
        file << static_cast<int>(creature.eyeColor) << "\n";
        file << creature.height << "\n";
        file << creature.weight << "\n";
        file << creature.behavior << "\n";

        file.close();
        std::cout << "Существо сохранено в файл " << filename << "\n";
    } else {
        std::cout << "Не удалось открыть файл для сохранения.\n";
    }
}

// Функция для загрузки существа из файла
Creature loadCreatureFromFile(const std::string& filename) {
    Creature creature;
    std::ifstream file(filename);
    if (file.is_open()) {
        // Загружаем данные существа из файла
        int numHeads;
        file >> numHeads;
        creature.heads.resize(numHeads);
        for (int i = 0; i < numHeads; ++i) {
            int headType;
            file >> headType;
            creature.heads[i].type = static_cast<HeadType>(headType);
        }
        file >> creature.numLegs;
        int bodyCovering;
        file >> bodyCovering;
        creature.bodyCovering = static_cast<BodyCoveringType>(bodyCovering);
        int numTails;
        file >> numTails;
        creature.tails.resize(numTails);
        for (int i = 0; i < numTails; ++i) {
            int tailType;
            file >> tailType;
            creature.tails[i].type = static_cast<TailType>(tailType);
        }
        file >> creature.numEyes;
        int eyeColor;
        file >> eyeColor;
        creature.eyeColor = static_cast<EyeColor>(eyeColor);
        file >> creature.height;
        file >> creature.weight;
        std::getline(file >> std::ws, creature.behavior); // Читаем строку с пробелами

        file.close();
        std::cout << "Существо загружено из файла " << filename << "\n";
    } else {
        std::cout << "Не удалось открыть файл для загрузки. Создано стандартное существо.\n";
        // Возвращаем существо по умолчанию, если не удалось загрузить из файла
        creature.heads.clear();
        creature.numLegs = 4;
        creature.bodyCovering = BodyCoveringType::GREEN_SKIN; // Инициализируем тип покрова тела
        creature.tails.clear();
        creature.numEyes = 2;
        creature.eyeColor = EyeColor::BROWN; // Инициализируем цвет глаз
        creature.height = 1.0;
        creature.weight = 50.0;
        creature.behavior = "friendly";
    }
    return creature;
}

// Основная функция, выполняющая создание существа
void task2() {
    // Запрашиваем у пользователя, что он хочет сделать
    std::cout << "Выберите действие:\n";
    std::cout << "1. Создать новое существо\n";
    std::cout << "2. Загрузить существо из файла\n";
    int choice = getValidInt("Введите номер выбранного действия: ");

    Creature creature;
    if (choice == 1) {
        // Создаем новое существо
        creature = createCreature();
    } else if (choice == 2) {
        // Загружаем существо из файла
        std::string filename = getValidFilename("Введите имя файла для загрузки: ");
        creature = loadCreatureFromFile(filename);
    } else {
        std::cout << "Некорректный выбор. Создано стандартное существо.\n";
        creature.heads.clear();
        creature.numLegs = 4;
        creature.bodyCovering = BodyCoveringType::GREEN_SKIN; // Инициализируем тип покрова тела
        creature.tails.clear();
        creature.numEyes = 2;
        creature.eyeColor = EyeColor::BROWN; // Инициализируем цвет глаз
        creature.height = 1.0;
        creature.weight = 50.0;
        creature.behavior = "стандартное";
    }

    // Выводим информацию о созданном или загруженном существе
    displayCreature(creature);

    // Предлагаем сохранить существо в файл
    std::cout << "Сохранить существо в файл? (y/n): ";
    char saveChoice;
    std::cin >> saveChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume the newline character
    if (saveChoice == 'y') {
        std::string filename = getValidFilename("Введите имя файла для сохранения: ");
        saveCreatureToFile(creature, filename);
    }
}
