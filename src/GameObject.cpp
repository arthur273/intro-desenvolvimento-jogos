#include "GameObject.h"
#include "Component.h"
#include "algorithm"

GameObject::GameObject() : isDead(false) {}

GameObject::~GameObject() {
    for (auto& component : components) {
        delete component;
    }
    components.clear();
}

void GameObject::Update(float dt) {
    for (auto& component : components) {
        component->Update(dt);
    }
}

void GameObject::Render() {
    SDL_Log("Render in GameObject called");
    for (auto& component : components) {
        if (component->Is("TileMap")) {
            SDL_Log("Rendering TileMap component");
        }
        component->Render();
        if (component->Is("Zombie")) {
            SDL_Log("Rendering Zombie component");
        }
    }
}

bool GameObject::IsDead() const {
    return isDead;
}

void GameObject::RequestDelete() {
    isDead = true;
}

void GameObject::AddComponent(Component* cpt) {
    // Adiciona um novo componente à lista de componentes
    components.push_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt) {
    // Remove um componente da lista de componentes
    auto it = std::find(components.begin(), components.end(), cpt);
    if (it != components.end()) {
        components.erase(it);
    }
}

Component* GameObject::GetComponent(const std::string& type) {
    // Retorna o primeiro componente do tipo especificado
    for (auto& component : components) {
        if (component->Is(type)) {
            return component;
        }
    }
    return nullptr;
}
