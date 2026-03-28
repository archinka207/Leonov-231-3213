#ifndef RUSSIAAUDIOTRACK_H
#define RUSSIAAUDIOTRACK_H

#include "AudioTrack.h"

class RussianAudioTrack : public AudioTrack {
public:
    std::string getLanguage() const override {
        return "Russian";
    }
};

#endif // RUSSIAAUDIOTRACK_H