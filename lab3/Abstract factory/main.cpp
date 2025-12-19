#include <iostream>
#include "MovieFactory.h"
#include "EnglishMovieFactory.h"
#include "RussianMovieFactory.h"
#include "AudioTrack.h"
#include "Subtitles.h"

void clientCode(const MovieFactory& factory, const std::string& movieName) {
    AudioTrack* audio = factory.createAudioTrack();
    Subtitles* subtitles = factory.createSubtitles();

    std::cout << "Renting movie: " << movieName << std::endl;
    std::cout << "Audio Language: " << audio->getLanguage() << std::endl;
    std::cout << "Subtitles Language: " << subtitles->getLanguage() << std::endl;

    delete audio;
    delete subtitles;
}

int main() {
    std::cout << "Client: I want to watch 'Inception' in English." << std::endl;
    EnglishMovieFactory englishFactory;
    clientCode(englishFactory, "Inception");

    std::cout << "\n----------------------------------------\n" << std::endl;

    std::cout << "Client: Now I want to watch 'The Matrix' in Russian." << std::endl;
    RussianMovieFactory russianFactory;
    clientCode(russianFactory, "The Matrix");

    return 0;
}