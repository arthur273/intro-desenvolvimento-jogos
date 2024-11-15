#include "MenuState.h"
#include "Game.h"
#include <iostream>

MenuState::MenuState() : isMainMenu(true) {
    // Load menu-specific assets here
    LoadAssets();  
    // buttons = {
    //     Button("Play", {400, 300, 200, 50}),
    //     Button("Options", {400, 400, 200, 50}),
    //     Button("Quit", {400, 500, 200, 50})
    //};
}

MenuState::~MenuState() {
    // Clean up menu-specific resources
}

void MenuState::LoadAssets() {
    // Load the background sprite and music
    bg.Open("recursos/Background.png");
    bg.SetClip(0, 0, 1200, 900); 
    if (!bg.IsOpen()) {
        cerr << "Background sprite not loaded!" << endl;
    }
    music.Open("recursos/BGM.wav");
    if (music.IsOpen()) {
       SDL_Log("Musica carregada");
       music.Play(-1); // Play the music if it's loaded correctly
    } else {
       SDL_Log("Background music failed to load!");
   }  
}

void MenuState::HandleEvent(const SDL_Event& event) {
    State::HandleEvent(event);

    // Handle menu-specific events, such as button clicks
    // for (auto& button : buttons) {
    //     button.HandleEvent(event);
    // }
    if (event.type == SDL_QUIT) {
        quitRequested = true;  // Set quitRequested to true when a quit event is detected
    }
}

void MenuState::Update(float dt) {
    State::Update(dt);

    // Update menu-specific logic, such as button states
    // for (auto& button : buttons) {
    //     button.Update(dt);
    // }

    // Check for menu-specific conditions to set quitRequested
    // if (isMainMenu && buttons[2].IsClicked()) { // Quit button clicked
    //     quitRequested = true;
    // }
}

void MenuState::Render() {
    State::Render();
    bg.Render(0, 0, 0, 0); // Render the background at the top-left corner
    // Render menu-specific elements, such as buttons
    // for (const auto& button : buttons) {
    //     button.Render();
    // }
    SDL_RenderPresent(Game::GetInstance().GetRenderer()); // Present the frame
}