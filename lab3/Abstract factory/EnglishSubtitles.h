#ifndef ENGLISHSUBTITLES_H
#define ENGLISHSUBTITLES_H

#include "Subtitles.h"

class EnglishSubtitles : public Subtitles {
public:
    std::string getLanguage() const override {
        return "English";
    }
};

#endif // ENGLISHSUBTITLES_H