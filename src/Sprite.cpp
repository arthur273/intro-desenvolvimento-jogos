#include "Sprite.h"
#include "Game.h" // For getting the SDL_Renderer
#include <stdexcept> // For std::runtime_error
#include <iostream>

using namespace std;

Sprite::Sprite() : texture(nullptr), width(0), height(0), isOpen(false) {
    clipRect = {0, 0, 0, 0}; // Initialize the clipping rectangle
}

Sprite::Sprite(const std::string& file) : Sprite() { // Delegate to the default constructor
    Open(file);
}

Sprite::~Sprite() {
    if (texture) {
        SDL_DestroyTexture(texture); // Free the texture
    }
}


void Sprite::Open(const std::string& file) {
    SDL_Surface* surface = IMG_Load(file.c_str());
    if (!surface) {
        // Handle error
        cerr << "Failed to load image: " << IMG_GetError() << endl;
        return;
    }
    //texture = SDL_CreateTextureFromSurface(Game::GetInstance().GetRenderer(), surface);
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    if (!texture) {
        cerr << "Failed to create texture: " << SDL_GetError() << endl;
    } else {
        if (SDL_QueryTexture(texture, NULL, NULL, &width, &height) == 0) {
            //width e height agora tem os valores certos
        } else {
        printf("SDL_QueryTexture Error: %s\n", SDL_GetError());
       }
    }
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect = {x, y, w, h}; // Set the clipping rectangle
}

void Sprite::Render(int x, int y) {
    if (texture) {
        SDL_Rect destRect = {x, y, clipRect.w, clipRect.h}; // Create destination rectangle

        SDL_Log("clipRect - x: %d, y: %d, w: %d, h: %d", clipRect.x, clipRect.y, clipRect.w, clipRect.h);
        SDL_Log("destRect - x: %d, y: %d, w: %d, h: %d", destRect.x, destRect.y, destRect.w, destRect.h);
        SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &destRect); // Render the texture
    } else {
        SDL_Log("Texture is null.");
    }
}

int Sprite::GetWidth() const {
    return width; // Return the width of the sprite
}

int Sprite::GetHeight() const {
    return height; // Return the height of the sprite
}

bool Sprite::IsOpen() const {
    return isOpen; // Return whether the sprite is loaded
}
