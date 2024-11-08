#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "State.h"
//#include "Button.h"

class MenuState : public State {
public:
    MenuState();
    ~MenuState();

    virtual void LoadAssets();       // Loads assets for this state
    void HandleEvent(const SDL_Event& event) override;
    void Update(float dt) override;
    void Render() override;

private:
    //std::vector<Button> buttons;
    bool isMainMenu;
};

#endif // MENUSTATE_H