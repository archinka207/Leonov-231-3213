#ifndef ID_GENERATOR_H
#define ID_GENERATOR_H

#include <string>
#include <atomic>

class IdGenerator {
public:
    static std::string generateId();

private:
    static std::atomic<long long> nextId;
};

#endif // ID_GENERATOR_H