#include "ArticleBuilder.h"
#include <sstream>
#include <algorithm>

void XmlArticleBuilder::buildTitle(const std::string& title) {
    article->title = title;
}

void XmlArticleBuilder::buildAuthors(const std::string& authorsLine) {
    std::stringstream ss(authorsLine);
    std::string author;
    while (std::getline(ss, author, ',')) {
        // Удаляем лишние пробелы в начале и конце
        author.erase(0, author.find_first_not_of(" \t\n\r"));
        author.erase(author.find_last_not_of(" \t\n\r") + 1);
        article->authors.push_back(author);
    }
}

void XmlArticleBuilder::buildBody(const std::string& body) {
    article->body = body;
}

void XmlArticleBuilder::buildHash(const std::string& hash) {
    article->fileHash = hash;
}