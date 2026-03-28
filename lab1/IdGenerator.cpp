#include "IdGenerator.h"
#include <chrono>
#include <random>
#include <string> // Добавлено, так как std::string используется в generateId
#include <atomic> // Добавлено, так как std::atomic<long long> nextId определяется здесь
// std::atomic<long long> nextId(0); // Определение инициализатора должно быть в .cpp
// Или можно инициализировать в .h если это inline/constexpr

// Инициализация статической переменной
std::atomic<long long> IdGenerator::nextId(0);

std::string IdGenerator::generateId() {
    long long timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count();
    
    long long counter = ++nextId;

    return std::to_string(timestamp) + "_" + std::to_string(counter);
}