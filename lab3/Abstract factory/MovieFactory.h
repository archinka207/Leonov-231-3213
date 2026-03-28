#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "AudioTrack.h"
#include "Subtitles.h"

class MovieFactory {
public:
    virtual ~MovieFactory() {}
    virtual AudioTrack* createAudioTrack() const = 0;
    virtual Subtitles* createSubtitles() const = 0;
};

#endif // MOVIEFACTORY_H