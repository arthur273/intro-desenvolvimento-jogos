// State.h
#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "Component.h"
#include "Animation.h"
#include <string>
#include <unordered_map>


class Animator : public Component {
public:
    Animator(GameObject& associated);
    
    void Update(float dt) override;
    void Render() override;
    bool Is(const std::string& type) const override;
    
    void SetAnimation(const std::string& name);
    void AddAnimation(const std::string& name, Animation anim);
    //void AddAnimation(const std::string& name, int startFrame, int endFrame, float frameTime);

private:
    std::unordered_map<std::string, Animation> animations;
    int frameStart;
    int frameEnd;
    float frameTime;
    int currentFrame;
    float timeElapsed;
};
#endif