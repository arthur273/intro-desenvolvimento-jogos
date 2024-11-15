#include "SpriteRenderer.h"
#include "GameObject.h"

SpriteRenderer::SpriteRenderer(GameObject& associated) : Component(associated), sprite() {
   // Basic constructor initializing Component and empty sprite
}

SpriteRenderer::SpriteRenderer(GameObject& associated, std::string file, 
                            int frameCountW, int frameCountH) : Component(associated), sprite() {
   SDL_Log("Sprite Renderer Open called");
   Open(file);
   SetFrameCount(frameCountW, frameCountH);
   SetFrame(0); // Initialize first frame as 0
   
   // Set GameObject box dimensions based on sprite size
   associated.box.SetDimensions(sprite.GetWidth(), associated.box.GetHeight());

}


SpriteRenderer::~SpriteRenderer() {}

void SpriteRenderer::Open(std::string file) {
   sprite.Open(file); // Definir se frames deveriam ser 1, 1 
   // Update GameObject box dimensions when opening new sprite
   associated.box.SetDimensions(sprite.GetWidth(), associated.box.GetHeight());
}

void SpriteRenderer::SetFrameCount(int frameCountW, int frameCountH) {
   sprite.SetFrameCount(frameCountW, frameCountH);
}

void SpriteRenderer::Update(float dt) {
   // Empty as specified
}

void SpriteRenderer::Render() {
   SDL_Log("SpriteRenderer about to execute!");
   sprite.Render(associated.box.GetX(), associated.box.GetY(), 50 , 50 ); // Box diz a localização do sprite
}

bool SpriteRenderer::Is(const std::string& type) const{
    return type == "SpriteRenderer";
}


void SpriteRenderer::SetFrame(int frame) {
   sprite.SetFrame(frame);
}