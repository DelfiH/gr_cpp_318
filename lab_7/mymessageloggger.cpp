#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <algorithm>
#include <iomanip>
#include <map>
#include <atomic>

namespace MyApplication {

//-----------------------------------------------------------------------------
// Класс для управления сообщениями различных типов
//-----------------------------------------------------------------------------
class MyMessage {
public:
    // Типы сообщений
    enum MessageType {
        EMERGENCY, // Аварийное сообщение
        ERROR,     // Ошибка
        WARNING,   // Предупреждение
        SYSTEM,    // Системное сообщение
        SERVICE,   // Сервисное сообщение
        DEBUG      // Отладочное сообщение
    };

    //-------------------------------------------------------------------------
    // Конструктор класса
    //-------------------------------------------------------------------------
    MyMessage() {
        enabledTypes["Emergency"] = true;
        enabledTypes["Error"] = true;
        enabledTypes["Warning"] = true;
        enabledTypes["System"] = true;
        enabledTypes["Service"] = true;
        enabledTypes["Debug"] = true;
        printType["Emergency"] = true;
        printType["Error"] = true;
        printType["Warning"] = true;
        printType["System"] = true;
        printType["Service"] = true;
        printType["Debug"] = true;
    }

    //-------------------------------------------------------------------------
    // Включить вывод сообщений определенного типа
    //-------------------------------------------------------------------------
    void enableMessageType(MessageType type);

    //-------------------------------------------------------------------------
    // Отключить вывод сообщений определенного типа
    //-------------------------------------------------------------------------
    void disableMessageType(MessageType type);

    //-------------------------------------------------------------------------
    // Включить вывод типа сообщения для определенного типа
    //-------------------------------------------------------------------------
    void enableMessageTypePrint(MessageType type);

    //-------------------------------------------------------------------------
    // Отключить вывод типа сообщения для определенного типа
    //-------------------------------------------------------------------------
    void disableMessageTypePrint(MessageType type);

    //-------------------------------------------------------------------------
    // Добавить сообщение
    //-------------------------------------------------------------------------
    void addMessage(MessageType type, const std::string& message, const std::string& functionName = "");

    //-------------------------------------------------------------------------
    // Получить все сообщения в виде строкового массива, исключая указанные типы
    //-------------------------------------------------------------------------
    std::vector<std::string> getMessages(const std::vector<MessageType>& typesToExclude = {}) const;

    //-------------------------------------------------------------------------
    // Очистить все сообщения
    //-------------------------------------------------------------------------
    void clearMessages(); // Добавляем метод для очистки сообщений

private:
    //-------------------------------------------------------------------------
    // Преобразовать тип сообщения в строку
    //-------------------------------------------------------------------------
    std::string messageTypeToString(MessageType type) const;

    std::vector<std::string> messages;
    std::map<std::string, bool> enabledTypes;
    std::map<std::string, bool> printType;
};

//-----------------------------------------------------------------------------
// Включить вывод сообщений определенного типа
//-----------------------------------------------------------------------------
void MyMessage::enableMessageType(MessageType type) {
    enabledTypes[messageTypeToString(type)] = true;
}

//-----------------------------------------------------------------------------
// Отключить вывод сообщений определенного типа
//-----------------------------------------------------------------------------
void MyMessage::disableMessageType(MessageType type) {
    enabledTypes[messageTypeToString(type)] = false;
}

//-----------------------------------------------------------------------------
// Включить вывод типа сообщения для определенного типа
//-----------------------------------------------------------------------------
void MyMessage::enableMessageTypePrint(MessageType type) {
    printType[messageTypeToString(type)] = true;
}

//-----------------------------------------------------------------------------
// Отключить вывод типа сообщения для определенного типа
//-----------------------------------------------------------------------------
void MyMessage::disableMessageTypePrint(MessageType type) {
    printType[messageTypeToString(type)] = false;
}

//-----------------------------------------------------------------------------
// Добавить сообщение
//-----------------------------------------------------------------------------
void MyMessage::addMessage(MessageType type, const std::string& message, const std::string& functionName) {
    std::string typeString = messageTypeToString(type);
    std::string formattedMessage = message;
    if (printType.count(typeString) && printType.at(typeString)) {
        formattedMessage = "<" + typeString + "> " + formattedMessage;
    }

    if (!functionName.empty()) {
        formattedMessage += " (Функция: " + functionName + ")";
    }
    messages.push_back(formattedMessage);
}

//-----------------------------------------------------------------------------
// Получить все сообщения в виде строкового массива, исключая указанные типы
//-----------------------------------------------------------------------------
std::vector<std::string> MyMessage::getMessages(const std::vector<MessageType>& typesToExclude) const {
    std::vector<std::string> filteredMessages;
    for (const auto& message : messages) {
        size_t start = message.find('<') + 1;
        size_t end = message.find('>');
        std::string type;
        if (start != std::string::npos && end != std::string::npos) {
             type = message.substr(start, end - start);
        } else {
            type = "Unknown";
        }

        MessageType messageType;
        if (type == "Emergency") messageType = EMERGENCY;
        else if (type == "Error") messageType = ERROR;
        else if (type == "Warning") messageType = WARNING;
        else if (type == "System") messageType = SYSTEM;
        else if (type == "Service") messageType = SERVICE;
        else if (type == "Debug") messageType = DEBUG;
        else continue;

        bool exclude = false;
        for (MessageType excludedType : typesToExclude) {
            if (excludedType == messageType) {
                exclude = true;
                break;
            }
        }

        if (!exclude) {
            filteredMessages.push_back(message);
        }
    }
    return filteredMessages;
}

//-----------------------------------------------------------------------------
// Очистить все сообщения
//-----------------------------------------------------------------------------
void MyMessage::clearMessages() {
    messages.clear();
}

//-----------------------------------------------------------------------------
// Преобразовать тип сообщения в строку
//-----------------------------------------------------------------------------
std::string MyMessage::messageTypeToString(MessageType type) const {
    switch (type) {
        case EMERGENCY: return "Emergency";
        case ERROR: return "Error";
        case WARNING: return "Warning";
        case SYSTEM: return "System";
        case SERVICE: return "Service";
        case DEBUG: return "Debug";
        default: return "Unknown";
    }
}

//-----------------------------------------------------------------------------
// Структура для хранения данных и синхронизации
//-----------------------------------------------------------------------------
struct AppData {
    static const int ARRAY_SIZE = 100; // Делаем ARRAY_SIZE статической константой
    int myArray[ARRAY_SIZE];
    std::queue<MyMessage> errorQueue;
    std::mutex queueMutex;
    std::condition_variable cv;
    std::atomic<bool> errorOccurred{false}; // Используем atomic для безопасной работы с флагом
    MyMessage logger;
};

//-----------------------------------------------------------------------------
// Функция для заполнения массива случайными числами
//-----------------------------------------------------------------------------
void fillArray(AppData& data) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1000);

    try {
        for (int i = 0; i < data.ARRAY_SIZE; ++i) {
            data.myArray[i] = distrib(gen);
        }
        std::cout << "Массив заполнен случайными числами." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Исключение в fillArray: " << e.what() << std::endl;
        std::lock_guard<std::mutex> lock(data.queueMutex);
        data.logger.addMessage(MyMessage::ERROR, "Ошибка при заполнении массива: " + std::string(e.what()), "fillArray()");
        data.errorQueue.push(data.logger);
        data.errorOccurred = true;
        data.cv.notify_one();
    } catch (...) {
        std::lock_guard<std::mutex> lock(data.queueMutex);
        data.logger.addMessage(MyMessage::ERROR, "Неизвестная ошибка при заполнении массива.", "fillArray()");
        data.errorQueue.push(data.logger);
        data.errorOccurred = true;
        data.cv.notify_one();
    }
}

//-----------------------------------------------------------------------------
// Функция для фильтрации значений массива
//-----------------------------------------------------------------------------
void filterArray(AppData& data, int minVal, int maxVal) {
    try {
        for (int i = 0; i < data.ARRAY_SIZE; ++i) {
            if (data.myArray[i] < minVal || data.myArray[i] > maxVal) {
                data.myArray[i] = 0;
            }
        }
        std::cout << "Массив отфильтрован. Значения вне диапазона [" << minVal << ", " << maxVal << "] установлены в 0." << std::endl;
    }  catch (const std::exception& e) {
        std::cerr << "Исключение в filterArray: " << e.what() << std::endl;
        std::lock_guard<std::mutex> lock(data.queueMutex);
        data.logger.addMessage(MyMessage::ERROR, "Ошибка при фильтрации массива: " + std::string(e.what()), "filterArray()");
        data.errorQueue.push(data.logger);
        data.errorOccurred = true;
        data.cv.notify_one();
    } catch (...) {
        std::lock_guard<std::mutex> lock(data.queueMutex);
        data.logger.addMessage(MyMessage::ERROR, "Неизвестная ошибка при фильтрации массива.", "filterArray()");
        data.errorQueue.push(data.logger);
        data.errorOccurred = true;
        data.cv.notify_one();
    }
}

//-----------------------------------------------------------------------------
// Функция для вывода значений массива
//-----------------------------------------------------------------------------
void printArray(AppData& data) {
    try {
        std::cout << "Значения массива: ";
        for (int i = 0; i < data.ARRAY_SIZE; ++i) {
            std::cout << data.myArray[i] << " ";
        }
        std::cout << std::endl;
    }  catch (const std::exception& e) {
        std::cerr << "Исключение в printArray: " << e.what() << std::endl;
        std::lock_guard<std::mutex> lock(data.queueMutex);
        data.logger.addMessage(MyMessage::ERROR, "Ошибка при выводе массива: " + std::string(e.what()), "printArray()");
        data.errorQueue.push(data.logger);
        data.errorOccurred = true;
        data.cv.notify_one();
    } catch (...) {
        std::lock_guard<std::mutex> lock(data.queueMutex);
        data.logger.addMessage(MyMessage::ERROR, "Неизвестная ошибка при выводе массива.", "printArray()");
        data.errorQueue.push(data.logger);
        data.errorOccurred = true;
        data.cv.notify_one();
    }
}

//-----------------------------------------------------------------------------
// Функция для потока логгера
//-----------------------------------------------------------------------------
void loggerThread(AppData& data) {
    while (true) {
        std::unique_lock<std::mutex> lock(data.queueMutex);
        data.cv.wait(lock, [&]{ return data.errorOccurred || !data.errorQueue.empty(); });

        if (!data.errorQueue.empty()) {
            MyMessage msg = data.errorQueue.front();
            data.errorQueue.pop();
            lock.unlock();
            std::vector<std::string> messages = msg.getMessages();
            for (const auto& message : messages) {
                std::cout << message << std::endl;
            }
            msg.clearMessages();
            lock.lock();
            data.errorOccurred = !data.errorQueue.empty();
        } else if (data.errorOccurred) {
            break;
        } else {
            break;
        }
    }
}

//-----------------------------------------------------------------------------
// Функция для запуска демонстрации работы логгера
//-----------------------------------------------------------------------------
void mymessagelogger() {
    AppData data;

    std::thread filler([&]{ fillArray(data); });
    std::thread filter([&]{ filterArray(data, 100, 500); });
    std::thread printer([&]{ printArray(data); });
    std::thread logger([&]{ loggerThread(data); });

    filler.join();
    filter.join();
    printer.join();

    data.errorOccurred = true;
    data.cv.notify_one();
    logger.join();
}
}
