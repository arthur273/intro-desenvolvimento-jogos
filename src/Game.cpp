// Game.cpp
#include "Game.h"

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

Game* Game::instance = nullptr;  // Define a instância única

Game& Game::GetInstance(const std::string& title, int width, int height) {
    if (instance == nullptr) {
        instance = new Game(title, width, height);
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
}

void Game::SHUTDOWN_SDL() {
    Mix_CloseAudio();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::Run() {
    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        SDL_RenderClear(renderer);
        // Aqui é onde a lógica de renderização será colocada no futuro

        SDL_RenderPresent(renderer);
    }
}

SDL_Renderer* Game::GetRenderer() {
    return renderer;
}

SDL_Window* Game::GetWindow() {
    return window;
}

