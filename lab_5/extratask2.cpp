#include "extratask2.h"
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <random>
#include <queue>
#include <iomanip>
#include <atomic>
#include <condition_variable>

// Глобальные переменные для управления потоками и обмена данными
std::mutex mtx;
std::atomic<bool> running(true);
bool deviceEnabled = true;
bool dataAllowed = true;
std::queue<Packet> dataQueue;
std::vector<unsigned char> dataSequence = {0x55, 0xAA, 0x55, 0xAA, 0xFF, 0xFF, 0x00, 0x00, 0xAA, 0xAA};
std::condition_variable cv; // Добавляем condition variable

//-----------------------------------------------------------------------------
// Функция для расчета CRC32 (простой пример)
//-----------------------------------------------------------------------------
uint32_t calculateCRC32(const unsigned char* data, size_t length) {
    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < length; ++i) {
        crc ^= data[i];
        for (int j = 0; j < 8; ++j) {
            crc = (crc >> 1) ^ (0xEDB88320 & ((crc & 1) ? 0xFFFFFFFF : 0));
        }
    }
    return crc ^ 0xFFFFFFFF;
}

//-----------------------------------------------------------------------------
// Функция для вывода пакета данных в лог (для отладки)
//-----------------------------------------------------------------------------
void logPacket(const Packet& packet, const std::string& prefix) {
    std::cout << prefix << "Header: startByte=0x" << std::hex << (int)packet.header.startByte
              << ", clientAddress=" << packet.header.clientAddress
              << ", serverAddress=" << packet.header.serverAddress
              << ", flags=0x" << std::hex << (int)packet.header.flags << std::dec << std::endl;

    std::cout << prefix << "Command: status=0x" << std::hex << (int)packet.command.status
              << ", command=0x" << packet.command.command
              << ", confirmCommand=0x" << packet.command.confirmCommand << std::dec << std::endl;

    std::cout << prefix << "Data: status=0x" << std::hex << (int)packet.data.read.status << std::dec
              << ", first few bytes of data: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << "0x" << std::hex << (int)packet.data.read.data[i] << " ";
    }
    std::cout << std::dec << std::endl;

    std::cout << prefix << "Checksum: crc32=0x" << std::hex << packet.checksum.crc32 << std::dec
              << ", stopByte=0x" << std::hex << (int)packet.stopByte << std::dec << std::endl;
}

//-----------------------------------------------------------------------------
// Функция эмуляции устройства (Server)
//-----------------------------------------------------------------------------
void deviceThread() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 255);

    while (running) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait_for(lock, std::chrono::milliseconds(100), []{ return !running.load(); }); // Ждем уведомления или 100мс

        if (!running) break; // Проверяем флаг еще раз после ожидания

        if (!deviceEnabled) continue;

        if (dataAllowed) {
            // Генерируем случайные данные для примера
            Packet packet;
            packet.header.startByte = 0xAA;
            packet.header.clientAddress = 12345;
            packet.header.serverAddress = 67890;
            packet.header.flags = 0x01; // Пример флага

            packet.command.status = 0x02; // Пример статуса команды
            packet.command.command = 0x12345678;
            packet.command.confirmCommand = 0x87654321;
            memset(packet.command.reserve, 0, sizeof(packet.command.reserve));

            packet.data.read.status = 0x03; // Пример статуса данных
            for (int i = 0; i < DATA_SIZE; ++i) {
                packet.data.read.data[i] = distrib(gen);
            }
            memset(packet.data.read.reserve, 0, sizeof(packet.data.read.reserve));

            packet.stopByte = 0x55;

            // Рассчитываем CRC32 (исключаем поле checksum из расчета)
            unsigned char* packetData = reinterpret_cast<unsigned char*>(&packet);
            packet.checksum.crc32 = calculateCRC32(packetData, sizeof(Packet) - sizeof(packet.checksum));
            packet.checksum.reserve = 0;

            // Помещаем пакет в очередь
            dataQueue.push(packet);

            std::cout << "Устройство: Отправлен пакет данных" << std::endl;

            // Логируем отправленный пакет
            logPacket(packet, "Устройство: ");
        }
    }
}

//-----------------------------------------------------------------------------
// Функция эмуляции хоста (PC)
//-----------------------------------------------------------------------------
void hostThread() {
    while (running) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait_for(lock, std::chrono::seconds(1), []{ return !running.load(); }); // Ждем уведомления или 1 секунду

        if (!running) break; // Проверяем флаг еще раз после ожидания

        // Проверяем наличие данных в очереди
        if (!dataQueue.empty()) {
            Packet receivedPacket = dataQueue.front();
            dataQueue.pop();

            std::cout << "Хост: Получен пакет данных" << std::endl;

            // Логируем полученный пакет
            logPacket(receivedPacket, "Хост: ");

            // TODO: Проверка CRC32

            // TODO: Обработка данных (в зависимости от команды)
        }

        // Реализовать логику отправки запросов и приема ответов
        char command;
        std::cout << "Хост: Введите команду (e - вкл/выкл устройство, d - разрешить/запретить данные, q - выход): ";
        std::cin >> command;

        if (command == 'e') {
            deviceEnabled = !deviceEnabled;
            std::cout << "Устройство " << (deviceEnabled ? "включено" : "выключено") << std::endl;
        } else if (command == 'd') {
            dataAllowed = !dataAllowed;
            std::cout << "Передача данных " << (dataAllowed ? "разрешена" : "запрещена") << std::endl;
        } else if (command == 'q') {
            running = false;
            cv.notify_all(); // Уведомляем все потоки о завершении
            break;
        }
    }
}

//-----------------------------------------------------------------------------
// Функция логгера
//-----------------------------------------------------------------------------
void loggerThread() {
    while (running) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait_for(lock, std::chrono::seconds(5), []{ return !running.load(); }); // Ждем уведомления или 5 секунд

        if (!running) break; // Проверяем флаг еще раз после ожидания

        std::cout << "Логгер: Устройство " << (deviceEnabled ? "включено" : "выключено") << ", передача данных " << (dataAllowed ? "разрешена" : "запрещена") << std::endl;
    }
}

//-----------------------------------------------------------------------------
// Определяем функцию extraTask2
//-----------------------------------------------------------------------------
void extraTask2() {
    std::cout << "Выполнено дополнительное задание 2.\n";

    // Сбрасываем состояние для нового запуска
    running = true;
    deviceEnabled = true;
    dataAllowed = true;
    while (!dataQueue.empty()) dataQueue.pop(); // Очищаем очередь

    std::thread host(hostThread);
    std::thread device(deviceThread);
    std::thread logger(loggerThread);

    host.join();
    device.join();
    logger.join();

    std::cout << "Задание 2 завершено.\n";
}
