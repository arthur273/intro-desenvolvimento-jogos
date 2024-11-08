#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <string>
#include "Rect.h" // Assuming Rect is defined elsewhere
#include "Component.h" // Assuming Component is defined elsewhere

class GameObject {
public:
    GameObject();
    ~GameObject();

    void Update(float dt);
    void Render();
    bool IsDead() const;
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    Component* GetComponent(const std::string& type);

    Rect box;

private:
    std::vector<Component*> components;
    bool isDead;
};

#endif // GAMEOBJECT_H
