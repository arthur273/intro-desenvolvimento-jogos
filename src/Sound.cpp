#include "Sound.h"
#include <iostream>
#include <Resources.h>

Sound::Sound() : chunk(nullptr), channel(-1) {}

Sound::Sound(const std::string& file) : chunk(nullptr), channel(-1) {
    Open(file);

}

Sound::~Sound() {
    if (chunk != nullptr) {
        // Stop the channel if the sound is playing
        Stop();
        
        // Free the chunk
        Mix_FreeChunk(chunk);
        chunk = nullptr;
    }
}

void Sound::Play(int times) {
    if (chunk == nullptr) {
        std::cerr << "Error: No sound loaded to play" << std::endl;
        return;
    }

    // Play on the first available channel
    // times-1 because SDL_mixer's loops parameter works differently
    channel = Mix_PlayChannel(-1, chunk, times - 1);
    
    if (channel == -1) {
        std::cerr << "Error playing sound: " << Mix_GetError() << std::endl;
    }
}

void Sound::Stop() {
    if (chunk != nullptr) {
        // Stop the specific channel or all channels if not specified
        Mix_HaltChannel(channel);
    }
}

void Sound::Open(const std::string& file) {
    // Free existing chunk if it exists
    if (chunk != nullptr) {
        Mix_FreeChunk(chunk);
    }
    chunk = Resources::GetSound(file);
    if (chunk == nullptr) {
        std::cerr << "Failed to load sound file: " << file << std::endl;
        std::cerr << "SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
}

bool Sound::IsOpen() const {
    return chunk != nullptr;
}