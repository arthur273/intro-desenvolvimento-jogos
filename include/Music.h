#ifndef MUSIC_H
#define MUSIC_H

#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <string>

using namespace std;


class Music {
public:
    Music(); // Default constructor
    Music(const string& file); // Constructor with file parameter
    ~Music(); // Destructor

    void Play(int times = -1); // Play music
    void Stop(int msToStop = 1500); // Stop music with fade out
    void Open(const string& file); // Load music from file
    bool IsOpen() const { return music != nullptr; } // Returns true if music is loaded


private:
    Mix_Music* music; // Pointer to the music
};

#endif // MUSIC_H
