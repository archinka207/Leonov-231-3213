#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>
#include <vector>

// Продукт - Статья
class Article {
public:
    std::string title;
    std::vector<std::string> authors;
    std::string body;
    std::string fileHash;

    // Метод для представления статьи в формате XML
    std::string toXmlString() const;
};

#endif //ARTICLE_H