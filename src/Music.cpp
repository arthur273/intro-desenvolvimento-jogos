#include "Music.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Resources.h"

Music::Music() : music(nullptr) {
    // Initialize SDL_mixer if needed
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        SDL_Log("SDL_mixer could not initialize! SDL_mixer Error: %s", Mix_GetError());
    }
}

Music::Music(const std::string& file) : music(nullptr) {
    Open(file);
}

Music::~Music() {
    Stop(); // Stop music if it's playing
    if (music != nullptr) {
        Mix_FreeMusic(music); // Free music memory
        music = nullptr;
    }
    Mix_CloseAudio();
} 

void Music::Play(int times) {
    SDL_Log("Music Play called!"); // Log error if music is not loaded
    if (music != nullptr) {
        Mix_VolumeMusic(MIX_MAX_VOLUME); // Set to maximum volume
        Mix_PlayMusic(music, times); // Play the music
        SDL_Log("Music Should be Playing"); // Log error if music is not loaded
    } else {
        SDL_Log("Music is not loaded!"); // Log error if music is not loaded
    }
}

void Music::Stop(int msToStop) {
    Mix_FadeOutMusic(msToStop); // Fade out music
}

void Music::Open(const std::string& file) {
    //SDL_Log("%s", file.c_str());
    Mix_FreeMusic(music);
    //music = nullptr; 
    //music = Mix_LoadMUS(file.c_str()); // Load music from file
    music = Resources::GetMusic(file);
    SDL_Log("Should have loaded music");
    if (music == nullptr) {
        SDL_Log("Failed to load music! SDL_mixer Error: %s", Mix_GetError());
    }
    SDL_Log("Not null ptr");
}
