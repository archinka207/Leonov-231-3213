#ifndef ARTICLE_BUILDER_H
#define ARTICLE_BUILDER_H

#include "Article.h"
#include <memory>

// Абстрактный Строитель
class ArticleBuilder {
public:
    virtual ~ArticleBuilder() = default;

    std::unique_ptr<Article> getArticle() {
        return std::move(article);
    }

    void createNewArticle() {
        article = std::make_unique<Article>();
    }

    virtual void buildTitle(const std::string& title) = 0;
    virtual void buildAuthors(const std::string& authors) = 0;
    virtual void buildBody(const std::string& body) = 0;
    virtual void buildHash(const std::string& hash) = 0;

protected:
    std::unique_ptr<Article> article;
};


// Конкретный строитель для XML
class XmlArticleBuilder : public ArticleBuilder {
public:
    XmlArticleBuilder() = default;
    
    void buildTitle(const std::string& title) override;
    void buildAuthors(const std::string& authors) override;
    void buildBody(const std::string& body) override;
    void buildHash(const std::string& hash) override;
};


#endif //ARTICLE_BUILDER_H