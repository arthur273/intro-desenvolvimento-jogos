#include "State.h"
#include <iostream>
#include "Game.h"

// Constructor initializes the quitRequested flag to false
State::State() : quitRequested(false) {
    LoadAssets();  // Optionally load assets here or separately
}

// Loads the assets needed for this state
void State::LoadAssets() {
//     // Load the background sprite and music
//     bg.Open("recursos/Background.png", 0 , 0);
//     bg.SetClip(0, 0, 1200, 900); 
//     if (!bg.IsOpen()) {
//         cerr << "Background sprite not loaded!" << endl;
//     }
//     music.Open("recursos/BGM.wav");
//     if (music.IsOpen()) {
//        SDL_Log("Musica carregada");
//        music.Play(-1); // Play the music if it's loaded correctly
//     } else {
//        SDL_Log("Background music failed to load!");
//    }  
}
void State::HandleEvent(const SDL_Event& event) {
    if (event.type == SDL_QUIT) {
        quitRequested = true;  // Set quitRequested to true when a quit event is detected
    }
    // Handle other events as necessary
}

// Checks if a quit was requested by this state
bool State::QuitRequested() const {
    return quitRequested;
}

// Updates the state logic
void State::Update(float dt) {
    // Placeholder for actual update logic (e.g., handling object updates)

    // Example of setting quitRequested to true based on a condition
    // if (someCondition) {
    //     quitRequested = true;
    // }
    SDL_Log("Update in State called");
}

// Renders the state to the screen
void State::Render() {
    // SDL_RenderClear(Game::GetInstance().GetRenderer()); // Clear before rendering
    // cerr << "About to load image in State::Render!" << IMG_GetError() << endl;
    // bg.Render(0, 0, 0, 0); // Render the background at the top-left corner
    // SDL_RenderPresent(Game::GetInstance().GetRenderer()); // Present the frame
}


// // Destructor for cleanup, if needed
State::~State() {
    //Stop any music or release any resources if necessary
    music.Stop();
}
