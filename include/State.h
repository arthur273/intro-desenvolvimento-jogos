// State.h
#ifndef STATE_H
#define STATE_H

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <string>
#include "State.h"
#include "Sprite.h"
#include "Music.h"

//#include "Sprite.h" // Assuming Sprite is a class that handles images
//#include "Music.h"  // Assuming Music is a class that handles audio

class State {
public:
    State();                 // Constructor to initialize the state
    ~State();           // Destructor (add this if missing)
    void HandleEvent(const SDL_Event& event); // Handles SDL events for this state
    bool QuitRequested() const;  // Checks if a quit was requested // this should result in currentState.pop in StateStack
    void LoadAssets();       // Loads assets for this state
    void Update(float dt);   // Updates the state with a delta time
    void Render();           // Renders the state to the screen

private:
    Sprite bg;               // Background sprite
    Music music;             // Background music
    bool quitRequested;      // Flag to indicate if state wants to quit
};

#endif // STATE_H
