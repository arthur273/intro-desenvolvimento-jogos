// Game.cpp
#include "Game.h"

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

using namespace std;

Game* Game::instance = nullptr;  // Define a instância única


Game& Game::GetInstance(const std::string& title, int width, int height) {
    if (instance == nullptr) {
        instance = new Game(title, width, height);
        State* initialState = new State();
        instance->PushState(initialState);
        SDL_Log("Game Instance Created");
    }
    return *instance;
}

Game::Game(const std::string& title, int width, int height) {
    INIT_SDL();  // Inicializa SDL, SDL_image e SDL_mixer

    window = SDL_CreateWindow(
        title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        SDL_Log("Erro ao criar janela: %s", SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("Erro ao criar renderizador: %s", SDL_GetError());
        exit(1);
    }
}

void Game::PushState(State* state) {
    stateStack.push(state); // Store the raw pointer
}

void Game::PopState() {
    if (!stateStack.empty()) {
        stateStack.pop();
    }
}

State& Game::GetCurrentState() {
    if (stateStack.empty()) {
        SDL_Log("Error: State stack is empty.");
        exit(1);
    }
    return *stateStack.top();
}


Game::~Game() {
    SHUTDOWN_SDL();
    instance = nullptr;
}

void Game::INIT_SDL() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        SDL_Log("Erro ao inicializar SDL: %s", SDL_GetError());
        exit(1);
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        SDL_Log("Erro ao inicializar SDL_image: %s", IMG_GetError());
        exit(1);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        SDL_Log("Erro ao inicializar SDL_mixer: %s", Mix_GetError());
        exit(1);
    }


    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        SDL_Log("SDL_mixer could not initialize! SDL_mixer Error: %s", Mix_GetError());
    }
}

void Game::SHUTDOWN_SDL() {
    Mix_CloseAudio();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::Run() {
    SDL_Event event;

    while (!GetCurrentState().QuitRequested()) {
        while (SDL_PollEvent(&event)) {
            GetCurrentState().HandleEvent(event);  // Handle input events
        }

        //GetCurrentState().Update(0);  // Update game state
        GetCurrentState().Render();    // Render the current state
        //SDL_Delay(33); // Limit frame rate to approximately 30 FPS
    }
    SDL_Log("Jogo acabou");
}


SDL_Renderer* Game::GetRenderer() {
    return renderer;
}

SDL_Window* Game::GetWindow() {
    return window;
}

