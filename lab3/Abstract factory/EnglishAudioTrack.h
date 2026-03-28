#ifndef ENGLISHAUDIOTRACK_H
#define ENGLISHAUDIOTRACK_H

#include "AudioTrack.h"

class EnglishAudioTrack : public AudioTrack {
public:
    std::string getLanguage() const override {
        return "English";
    }
};

#endif // ENGLISHAUDIOTRACK_H