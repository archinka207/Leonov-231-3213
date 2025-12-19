#ifndef RUSSIANSUBTITLES_H
#define RUSSIANSUBTITLES_H

#include "Subtitles.h"

class RussianSubtitles : public Subtitles {
public:
    std::string getLanguage() const override {
        return "Russian";
    }
};

#endif // RUSSIANSUBTITLES_H