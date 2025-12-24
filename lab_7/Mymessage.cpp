#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <mutex>

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

private:
    struct MessageData {
        MessageType type;
        std::string text;

        MessageData(MessageType t, const std::string& str) : type(t), text(str) {}
    };

public:
    //-------------------------------------------------------------------------
    // Конструктор класса
    //-------------------------------------------------------------------------
    MyMessage() {
        // Изначально включены все типы сообщений и вывод их типа
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
    void enableMessageType(MessageType type) {
        std::lock_guard<std::mutex> lock(mutex_);
        enabledTypes[messageTypeToString(type)] = true;
    }

    //-------------------------------------------------------------------------
    // Отключить вывод сообщений определенного типа
    //-------------------------------------------------------------------------
    void disableMessageType(MessageType type) {
        std::lock_guard<std::mutex> lock(mutex_);
        enabledTypes[messageTypeToString(type)] = false;
    }

    //-------------------------------------------------------------------------
    // Включить вывод типа сообщения для определенного типа
    //-------------------------------------------------------------------------
    void enableMessageTypePrint(MessageType type) {
        std::lock_guard<std::mutex> lock(mutex_);
        printType[messageTypeToString(type)] = true;
    }

    //-------------------------------------------------------------------------
    // Отключить вывод типа сообщения для определенного типа
    //-------------------------------------------------------------------------
    void disableMessageTypePrint(MessageType type) {
        std::lock_guard<std::mutex> lock(mutex_);
        printType[messageTypeToString(type)] = false;
    }

    //-------------------------------------------------------------------------
    // Добавить сообщение
    //-------------------------------------------------------------------------
    void addMessage(MessageType type, const std::string& message, const std::string& functionName = "") {
        std::lock_guard<std::mutex> lock(mutex_);
        std::string formattedMessage = message;
        if (printType.count(messageTypeToString(type)) && printType.at(messageTypeToString(type))) {
            formattedMessage = "<" + messageTypeToString(type) + "> " + formattedMessage;
        }

        if (!functionName.empty()) {
            formattedMessage += " (Функция генерирующая сообщение: " + functionName + ")";
        }
        messages.emplace_back(type, formattedMessage);
    }

    //-------------------------------------------------------------------------
    // Получить все сообщения в виде строкового массива, исключая указанные типы
    //-------------------------------------------------------------------------
    std::vector<std::string> getMessages(const std::vector<MessageType>& typesToExclude = {}) const {
        std::lock_guard<std::mutex> lock(mutex_);
        std::vector<std::string> filteredMessages;
        std::unordered_set<MessageType> excludeSet(typesToExclude.begin(), typesToExclude.end());

        for (const auto& messageData : messages) {
            if (excludeSet.find(messageData.type) == excludeSet.end()) {
                filteredMessages.push_back(messageData.text);
            }
        }
        return filteredMessages;
    }

private:
    //-------------------------------------------------------------------------
    // Преобразовать тип сообщения в строку
    //-------------------------------------------------------------------------
    std::string messageTypeToString(MessageType type) const {
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

    std::vector<MessageData> messages;
    std::unordered_map<std::string, bool> enabledTypes;
    std::unordered_map<std::string, bool> printType;
    mutable std::mutex mutex_;
};

//-----------------------------------------------------------------------------
// Тестирующая функция
//-----------------------------------------------------------------------------
void testMyMessage() {
    MyMessage myMessage;

    // Добавляем сообщения разных типов
    myMessage.addMessage(MyMessage::ERROR, "Не удалось открыть файл", "OpenFile()");
    myMessage.addMessage(MyMessage::WARNING, "Низкий уровень заряда батареи");
    myMessage.addMessage(MyMessage::DEBUG, "Значение переменной x: 10", "CalculateValue()");
    myMessage.addMessage(MyMessage::SYSTEM, "Программа запущена");
    myMessage.addMessage(MyMessage::SERVICE, "Сервис запущен", "StartService()");
    myMessage.enableMessageType(MyMessage::EMERGENCY);
    myMessage.addMessage(MyMessage::EMERGENCY, "Критическая ошибка! Программа будет закрыта.", "HandleCriticalError()");

    // Отключаем вывод типа сообщения для DEBUG
    myMessage.disableMessageTypePrint(MyMessage::DEBUG);

    // Настраиваем, какие типы сообщений исключить из вывода
    std::vector<MyMessage::MessageType> typesToExclude = {MyMessage::SYSTEM};

    // Получаем сообщения и выводим их
    std::vector<std::string> allMessages = myMessage.getMessages(typesToExclude);
    for (const auto& msg : allMessages) {
        std::cout << msg << std::endl;
    }
}
