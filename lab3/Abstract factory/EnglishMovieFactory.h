#ifndef ENGLISHMOVIEFACTORY_H
#define ENGLISHMOVIEFACTORY_H

#include "MovieFactory.h"
#include "EnglishAudioTrack.h"
#include "EnglishSubtitles.h"

class EnglishMovieFactory : public MovieFactory {
public:
    AudioTrack* createAudioTrack() const override {
        return new EnglishAudioTrack();
    }

    Subtitles* createSubtitles() const override {
        return new EnglishSubtitles();
    }
};

#endif // ENGLISHMOVIEFACTORY_H