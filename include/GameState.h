#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
//#include "Button.h"

class GameState : public State {
public:
    GameState();
    ~GameState();

    virtual void LoadAssets();       // Loads assets for this state
    void HandleEvent(const SDL_Event& event) override;
    void Update(float dt) override;
    void Render() override;

    void AddGameObject(std::unique_ptr<GameObject> obj);
    void RemoveGameObject(const std::unique_ptr<GameObject>& obj);
};

#endif // MENUSTATE_H