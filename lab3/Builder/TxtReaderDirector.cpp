#include "TxtReaderDirector.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <functional> // для std::hash
#include <iostream>

std::string TxtReaderDirector::calculateHash(const std::string& text) {
    std::hash<std::string> hasher;
    return std::to_string(hasher(text));
}

bool TxtReaderDirector::construct(const std::string& filename, ArticleBuilder& builder) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open input file " << filename << std::endl;
        return false;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    if (lines.size() < 4) {
        std::cerr << "Error: Invalid file format. Must contain at least 4 lines." << std::endl;
        return false;
    }

    builder.createNewArticle();

    // 1. Построить заголовок
    builder.buildTitle(lines[0]);

    // 2. Построить авторов
    builder.buildAuthors(lines[1]);

    // 3. Собрать тело статьи и построить его
    std::stringstream bodyStream;
    for (size_t i = 2; i < lines.size() - 1; ++i) {
        bodyStream << lines[i] << (i < lines.size() - 2 ? "\n" : "");
    }
    std::string body = bodyStream.str();
    builder.buildBody(body);

    // 4. Получить хеш из файла и построить его
    std::string fileHash = lines.back();
    builder.buildHash(fileHash);

    // 5. Проверить хеш
    std::string calculatedHash = calculateHash(body);
    if (calculatedHash != fileHash) {
        std::cerr << "Error: Hash mismatch!" << std::endl;
        std::cerr << "Expected: " << fileHash << std::endl;
        std::cerr << "Calculated: " << calculatedHash << std::endl;
        return false;
    }
    
    std::cout << "Hash verified successfully." << std::endl;
    return true;
}