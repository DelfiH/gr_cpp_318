#ifndef MYMESSAGE_H
#define MYMESSAGE_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

//-----------------------------------------------------------------------------
// Класс для управления сообщениями различных типов
//-----------------------------------------------------------------------------
class MyMessage {
private:
    std::vector<std::string> messages;
    std::unordered_map<std::string, bool> enabledTypes;
    std::unordered_map<std::string, bool> printType;

public:
    // Enum для типов сообщений
    enum MessageType {
        EMERGENCY, // Аварийное сообщение ??
        ERROR,     // Ошибка ?
        WARNING,   // Предупреждение ??
        SYSTEM,    // Системное сообщение ??
        SERVICE,   // Сервисное сообщение ??
        DEBUG      // Отладочное сообщение ??
    };

    // Конструктор
    MyMessage();

    // Включить вывод сообщений определенного типа
    void enableMessageType(MessageType type);

    // Отключить вывод сообщений определенного типа
    void disableMessageType(MessageType type);

    // Включить вывод типа сообщения для определенного типа
    void enableMessageTypePrint(MessageType type);

    // Отключить вывод типа сообщения для определенного типа
    void disableMessageTypePrint(MessageType type);

    // Добавить сообщение
    void addMessage(MessageType type, const std::string& message, const std::string& functionName = "");

    // Получить сообщения
    std::vector<std::string> getMessages(const std::vector<MessageType>& typesToExclude = {}) const;

private:
    // Преобразование типа сообщения в строку
    std::string messageTypeToString(MessageType type) const;
};

// Тестирующая функция
void testMyMessage();

#endif
