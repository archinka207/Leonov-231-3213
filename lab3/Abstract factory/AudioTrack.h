#ifndef AUDIOTRACK_H
#define AUDIOTRACK_H

#include <string>

class AudioTrack {
public:
    virtual ~AudioTrack() {}
    virtual std::string getLanguage() const = 0;
};

#endif // AUDIOTRACK_H