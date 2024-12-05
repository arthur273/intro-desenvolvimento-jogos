#include "Zombie.h"
#include "Animator.h"
#include "GameObject.h"
#include "SpriteRenderer.h"


Zombie::Zombie(GameObject& associated) : Component(associated), 
    hitpoints(100), deathSound("recursos/Dead.wav") {
    // Create and setup the SpriteRenderer
   //auto spriteRenderer = new SpriteRenderer(associated);
    SDL_Log("Zombie Constructor Called");
    auto spriteRenderer = new SpriteRenderer(associated, "recursos/Enemy.png", 3, 2);
    associated.AddComponent(spriteRenderer);
    
    // Create and setup the Animator
    auto animator = new Animator(associated);
    animator->AddAnimation("walking", Animation(0, 3, 10));  // frames 0-3, 10 frames duration
    animator->AddAnimation("dead", Animation(5, 5, 0));      // frame 5, 0 duration (static)
    animator->SetAnimation("walking");  // Start with walking animation
    associated.AddComponent(animator);
}

void Zombie::Damage(int damage) {
    hitpoints -= damage;
    if (hitpoints == 0) {
        // Get the SpriteRenderer component and set death "animation"
        SpriteRenderer* renderer = (SpriteRenderer*)associated.GetComponent("SpriteRenderer");
        if (renderer != nullptr) {
            Animator* animator = (Animator*)associated.GetComponent("Animator");
            animator->SetAnimation("dead");
            deathSound.Play(1); 
        }
    }
}

void Zombie::Update(float dt) {
    // Temporary behavior: take 1 damage per frame
    Damage(1);
    Animator* animator = (Animator*)associated.GetComponent("Animator");
    if (animator != nullptr) {
        // Render the current animation frame
        SDL_Log("Zombie Update");
        animator->Update(0);
    }

}

void Zombie::Render() {
    // Get the Animator component
    Animator* animator = (Animator*)associated.GetComponent("Animator");
    if (animator != nullptr) {
        // Render the current animation frame
        SDL_Log("Zombie render");
        animator->Render();
    }
}

bool Zombie::Is(const std::string& type) const{
    return type == "Zombie";
}