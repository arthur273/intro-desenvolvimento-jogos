#ifndef SPRITE_H
#define SPRITE_H


#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <string>

using namespace std;

class Sprite {
public:
    Sprite();  // Default constructor
    Sprite(const string& file);  // Constructor with file path
    ~Sprite();  // Destructor

    void Open(const string& file);  // Load the texture from file
    void SetClip(int x, int y, int w, int h);  // Set the clipping rectangle
    void Render(int x, int y);  // Render the sprite at (x, y)
    int GetWidth() const;  // Get the width of the sprite
    int GetHeight() const;  // Get the height of the sprite
    bool IsOpen() const;  // Check if the sprite is loaded

private:
    SDL_Texture* texture;  // Pointer to the SDL texture
    int width;  // Width of the texture
    int height;  // Height of the texture
    SDL_Rect clipRect;  // Rectangle for clipping
    bool isOpen;  // Flag to indicate if the texture is loaded
};

#endif // SPRITE_H
