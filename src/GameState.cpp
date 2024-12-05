#include "GameState.h"
#include "GameObject.h"
#include "Zombie.h"
#include "Game.h"
#include "TileMap.h"

GameState::GameState() : State() {
    SDL_Log("GameState Constructor Called");
    LoadAssets();
}

GameState::~GameState() {
    // Clean up any additional resources here
}

void GameState::HandleEvent(const SDL_Event& event) {
    State::HandleEvent(event);
    // Handle any additional events specific to the GameState here
}

void GameState::LoadAssets() {
    //Mapa
    auto mapObject = new GameObject();
    SDL_Log("Map emplaced in ObjectArray in LoadAssets 1 ");
    auto tileSet = new TileSet(64, 64, "recursos/Tileset.png");
    SDL_Log("Map emplaced in ObjectArray in LoadAssets 2");
    auto tileMap = new TileMap(*mapObject, "recursos/map.txt", tileSet);
    SDL_Log("Map emplaced in ObjectArray in LoadAssets 3");
    mapObject->AddComponent(tileMap);

    mapObject->box.SetPosition(0, 0);
    objectArray.emplace_back(std::move(mapObject));
    SDL_Log("Map emplaced in ObjectArray in LoadAssets");

    // Outros objetos
    // auto zombieObject = new GameObject();

    // // Step 2: Create the Zombie component and associate it with the GameObject
    // auto zombie = new Zombie(*zombieObject);

    // // Step 3: Add the Zombie component to the GameObject's component list
    // zombieObject->AddComponent(zombie);

    // // Step 4: Add the GameObject (with Zombie) to the state for rendering and updating
    // objectArray.emplace_back(std::move(zombieObject));
    // SDL_Log("GameState LoadAssets Called");
}

void GameState::Update(float dt) {
    //State::Update(dt);
    SDL_Log("Update in GameState called");
    // Update all game objects in the objectArray
    for (const auto& obj : objectArray) {
        obj->Update(dt);
    }
}

void GameState::Render() {
    //State::Render();
    
    // Render all game objects in the objectArray
    for (const auto& obj : objectArray) {
        obj->Render();
        SDL_Log("Render in GameState called");
    }
    SDL_RenderPresent(Game::GetInstance().GetRenderer()); // Present the frame
}