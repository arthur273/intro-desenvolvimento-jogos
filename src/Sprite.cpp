#include "Sprite.h"
#include "Game.h" // For getting the SDL_Renderer
#include <stdexcept> // For std::runtime_error
#include <iostream>

using namespace std;

Sprite::Sprite() : texture(nullptr), width(0), height(0), isOpen(false) {
    clipRect = {0, 0, 0, 0}; // Initialize the clipping rectangle
}

Sprite::Sprite(const std::string& file, int frameCountW, int frameCountH) 
    : texture(nullptr), frameCountW(frameCountW), frameCountH(frameCountH), currentFrame(0) {
    Open(file);//, frameCountW, frameCountH);
}

Sprite::~Sprite() {
    // if (texture) {
    //     SDL_DestroyTexture(texture); // Free the texture
    // } // isso agora é lidado com a classe Resources
    //SDL_Log("Sprite about to be deleted!");
}


void Sprite::Open(const std::string& file) { //, int frameCountW, int frameCountH) {
    SDL_Surface* surface = IMG_Load(file.c_str());
    cerr << "About to load image in Sprite::Open!" << IMG_GetError() << endl;
    if (!surface) {
        // Handle error
        cerr << "Failed to load image: " << IMG_GetError() << endl;
        return;
    }


    // texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    // if (!texture) {
    //     cerr << "Failed to create texture: " << SDL_GetError() << endl;
    // } else {
    //     if (SDL_QueryTexture(texture, NULL, NULL, &width, &height) == 0) {
    //         //width e height agora tem os valores certos
    //         printf("Image is loaded \n!");
    //         isOpen = true;
    //     } else {
    //     printf("SDL_QueryTexture Error: %s\n", SDL_GetError());
    //    }
    // }
    SDL_Log("resources about to be called in Sprite Open");
    texture = Resources::GetImage(file);
    if (texture){
        if (SDL_QueryTexture(texture, NULL, NULL, &width, &height) == 0) {
            //width e height agora tem os valores certos
            printf("Image is loaded \n!");
            isOpen = true;
        }
    }
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect = {x, y, w, h}; // Set the clipping rectangle
}

void Sprite::Render(int x, int y, int w, int h) {
    //SDL_Log("Sprite about to render!");
    if (texture) {
        SDL_Rect destRect = {x, y, clipRect.w, clipRect.h}; // Create destination rectangle for bg
        SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &destRect); // Render the texture
    } else {
        SDL_Log("Texture is null.");
    }
};

void Sprite::SetFrame(int frame) {
    int frameWidth = GetWidth() / frameCountW;
    int frameHeight = GetHeight() / frameCountH;
    // Calculate the row and column of the frame in the sprite sheet
    int currentRow = (frame / frameCountW);    // Integer division to get row
    int currentCol = (frame % frameCountW);    // Modulo to get column
    
    // Set the clip rectangle to the correct portion of the sprite sheet
    SetClip(currentCol * frameWidth,      // x position
            currentRow * frameHeight,      // y position
            frameWidth,                    // width of single frame
            frameHeight);                  // height of single frame
}

void Sprite::SetFrameCount(int frameCountW, int frameCountH) {
    this->frameCountW = frameCountW;
    this->frameCountH = frameCountH;
}

int Sprite::GetWidth() const {
    return width; // Return the width of the sprite
}

int Sprite::GetHeight() const {
    return height; // Return the    int frameHeight = GetHeight() / frameCountH;
}


int Sprite::GetWidthFrame() {
    int frameWidth = GetWidth() / frameCountW;
    return frameWidth; // Return the width of the sprite
}

int Sprite::GetHeightFrame() {
    int frameHeight = GetHeight() / frameCountH;
    return frameHeight; // Return the height of the sprite
}



bool Sprite::IsOpen() const {
    return isOpen; // Return whether the sprite is loaded
}
