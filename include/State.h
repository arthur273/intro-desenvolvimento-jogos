// State.h
#ifndef STATE_H
#define STATE_H

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include <string>
#include <vector>
#include <memory>

#include "Sprite.h"
#include "Music.h"
#include "GameObject.h"

using namespace std;

class State {
public:
    State();                 // Constructor to initialize the state
    ~State();           // Destructor (add this if missing)
    bool QuitRequested() const;  // Checks if a quit was requested // this should result in currentState.pop in StateStack
    virtual void HandleEvent(const SDL_Event& event); // Handles SDL events for this state
    virtual void LoadAssets();       // Loads assets for this state
    virtual void Update(float dt);   // Updates the state with a delta time
    virtual void Render();           // Renders the state to the screen

protected:
    Sprite bg;               // Background sprite
    Music music;             // Background music
    bool quitRequested;      // Flag to indicate if state wants to quit
    vector<unique_ptr<GameObject>> objectArray;
};

#endif // STATE_H
