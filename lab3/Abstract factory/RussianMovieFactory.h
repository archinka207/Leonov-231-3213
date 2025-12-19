#ifndef RUSSIANMOVIEFACTORY_H
#define RUSSIANMOVIEFACTORY_H

#include "MovieFactory.h"
#include "RussianAudioTrack.h"
#include "RussianSubtitles.h"

class RussianMovieFactory : public MovieFactory {
public:
    AudioTrack* createAudioTrack() const override {
        return new RussianAudioTrack();
    }

    Subtitles* createSubtitles() const override {
        return new RussianSubtitles();
    }
};

#endif // RUSSIANMOVIEFACTORY_H