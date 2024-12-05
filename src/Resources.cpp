#include "Resources.h"
#include "Game.h"  // Assuming you have a Game class with GetRenderer()

// Initialize static members
std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::GetImage(std::string file) {
    // Check if image already exists in the table
    auto it = imageTable.find(file);
    if (it != imageTable.end()) {
        return it->second;
    }

    // If not found, load the image
    SDL_Texture* texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    
    if (texture) {
        // Insert into the table if successfully loaded
        imageTable[file] = texture;
    }

    return texture;
}

void Resources::ClearImages() {
    for (auto& pair : imageTable) {
        SDL_DestroyTexture(pair.second);
    }
    imageTable.clear();
}

Mix_Music* Resources::GetMusic(std::string file) {
    // Check if music already exists in the table
    auto it = musicTable.find(file);
    if (it != musicTable.end()) {
        return it->second;
    }

    // If not found, load the music
    Mix_Music* music = Mix_LoadMUS(file.c_str());
    
    if (music) {
        // Insert into the table if successfully loaded
        musicTable[file] = music;
    }

    return music;
}

void Resources::ClearMusics() {
    for (auto& pair : musicTable) {
        Mix_FreeMusic(pair.second);
    }
    musicTable.clear();
}

Mix_Chunk* Resources::GetSound(std::string file) {
    // Check if sound already exists in the table
    auto it = soundTable.find(file);
    if (it != soundTable.end()) {
        return it->second;
    }

    // If not found, load the sound
    Mix_Chunk* sound = Mix_LoadWAV(file.c_str());
    
    if (sound) {
        // Insert into the table if successfully loaded
        soundTable[file] = sound;
    }

    return sound;
}

void Resources::ClearSounds() {
    for (auto& pair : soundTable) {
        Mix_FreeChunk(pair.second);
    }
    soundTable.clear();
}