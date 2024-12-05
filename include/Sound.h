#ifndef SOUND_H
#define SOUND_H

#include <string>
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"


class Sound {
public:
    Sound();
    explicit Sound(const std::string& file);

    ~Sound();

    void Play(int times = 1);

    void Stop();

    void Open(const std::string& file);

    bool IsOpen() const;

private:

    Mix_Chunk* chunk;

    // Channel the sound is playing on
    int channel;
};

#endif // SOUND_H