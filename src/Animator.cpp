#include "Animator.h"
#include "GameObject.h"
#include "SpriteRenderer.h"

Animator::Animator(GameObject& associated) : 
    Component(associated),
    frameStart(0),
    frameEnd(0),
    frameTime(0),
    currentFrame(0),
    timeElapsed(0) {
}

void Animator::Update(float dt) {
    if (frameTime != 0) {
        timeElapsed += 1; // Will be modified to use dt in the future
        
        if (timeElapsed > frameTime) {
            currentFrame++;
            timeElapsed -= frameTime;
            
            if (currentFrame > frameEnd) {
                currentFrame = frameStart;
            }
            
            SpriteRenderer* renderer = (SpriteRenderer*)associated.GetComponent("SpriteRenderer");
            if (renderer != nullptr) {
                renderer->SetFrame(currentFrame);
            }
        }
    }
}

void Animator::Render() {
    SDL_Log("Animator render about to execute");
    SpriteRenderer* renderer = (SpriteRenderer*)associated.GetComponent("SpriteRenderer");
    if (renderer != nullptr) {
        renderer->SetFrame(currentFrame);
        renderer->Render();
    }
}

bool Animator::Is(const std::string& type) const{
    return type == "Animator";
}

void Animator::SetAnimation(const std::string& name) {
    auto it = animations.find(name);
    if (it != animations.end()) {
        frameStart = it->second.startFrame;
        frameEnd = it->second.endFrame;
        frameTime = it->second.frameTime;
        currentFrame = frameStart;
        timeElapsed = 0;
        
        SpriteRenderer* renderer = (SpriteRenderer*)associated.GetComponent("SpriteRenderer");
        if (renderer != nullptr) {
            renderer->SetFrame(currentFrame);
        }
    }
}

void Animator::AddAnimation(const std::string& name, Animation anim) {
    if (animations.find(name) == animations.end()) {
        animations[name] = anim;
    }
}