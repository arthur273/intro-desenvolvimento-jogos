#ifndef COMPONENT_H
#define COMPONENT_H

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include <string>

using namespace std;

class GameObject;

class Component {
public:
    explicit Component(GameObject& associated);
    virtual ~Component();

    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual bool Is(const std::string& type) const = 0;

protected:
    GameObject& associated;
};

#endif // COMPONENT_H
