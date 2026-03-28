#ifndef SUBTITLES_H
#define SUBTITLES_H

#include <string>

class Subtitles {
public:
    virtual ~Subtitles() {}
    virtual std::string getLanguage() const = 0;
};

#endif // SUBTITLES_H