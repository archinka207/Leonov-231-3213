#ifndef TXT_READER_DIRECTOR_H
#define TXT_READER_DIRECTOR_H

#include "ArticleBuilder.h"
#include <string>

// Директор - управляет процессом конструирования
class TxtReaderDirector {
public:
    // Главный метод, который конструирует объект
    bool construct(const std::string& filename, ArticleBuilder& builder);

private:
    // Утилитарная функция для вычисления хеша
    std::string calculateHash(const std::string& text);
};


#endif //TXT_READER_DIRECTOR_H