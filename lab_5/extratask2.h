#ifndef EXTRATASK2_H
#define EXTRATASK2_H

#include <cstdint> // Для определения типов данных uint8_t, uint32_t и т.д.
#include <cstring> // Для memset

void extraTask2();

// Константы
const int DATA_SIZE = 2048;

// Структура пакета данных
struct Packet {
    struct Header {
        uint8_t startByte;      // Всегда 0xAA
        uint32_t clientAddress; // Адрес устройства client
        uint32_t serverAddress; // Адрес устройства server
        uint8_t flags;          // Флаги статуса (4 бита)
    } header;

    struct Command {
        uint8_t status;       // Статус (3 бита)
        uint32_t command;      // Команда базис
        uint32_t confirmCommand; // Команда подтверждение
        uint8_t reserve[8];     // Резерв
    } command;

    union Data {
        struct Read {
            uint8_t status;    // Статус (2 бита)
            uint8_t data[DATA_SIZE]; // Данные
            uint8_t reserve[12];   // Резерв
        } read;

        struct Write {
            uint8_t status;    // Статус (2 бита)
            uint8_t state;     // Состояние
            uint8_t data[DATA_SIZE]; // Данные
            uint8_t reserve[32];   // Резерв
        } write;

        uint8_t reserve[24];   // Резерв
    } data;

    struct Checksum {
        uint32_t crc32; // CRC32
        uint8_t reserve;  // Резерв
    } checksum;

    uint8_t stopByte;       // Всегда 0x55
};

#endif // EXTRATASK2_H
