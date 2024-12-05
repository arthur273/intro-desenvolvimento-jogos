#ifndef SPRITE_H
#define SPRITE_H


#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <string>
#include <Resources.h>

using namespace std;

class Sprite {
public:
    Sprite();  // Default constructor
    Sprite(const std::string& file, int frameCountW, int frameCountH);
    ~Sprite();  // Destructor

    void Open(const string& file); //, int frameCountW, int frameCountH);  // Load the texture from file
    void SetClip(int x, int y, int w, int h);  // Set the clipping rectangle
    void Render(int x, int y, int w, int h);
    void SetFrame(int frame);
    void SetFrameCount(int frameCountW, int frameCountH);
    int GetWidth() const;  // Get the width of the sprite
    int GetHeight() const;  // Get the height of the sprite
    int GetWidthFrame();
    int GetHeightFrame();
    bool IsOpen() const; // Check if the sprite is loaded]

private:
    SDL_Texture* texture;  // Pointer to the SDL texture
    int width;  // Width of the texture
    int height;  // Height of the texture
    SDL_Rect clipRect;  // Rectangle for clipping
    bool isOpen;  // Flag to indicate if the texture is loaded


    int frameCountW;
    int frameCountH;
    int currentFrame;
};

#endif // SPRITE_H
