// Game.h
#ifndef GAME_H
#define GAME_H

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <string>
#include "State.h"

class Game {
public:
    static Game& GetInstance(const std::string& title = "Jogo", int width = 800, int height = 600);
    void Run();
    State* GetState();
    SDL_Renderer* GetRenderer();
    SDL_Window* GetWindow();

    ~Game();

private:
    Game(const std::string& title, int width, int height);  // Construtor privado
    void INIT_SDL();
    void SHUTDOWN_SDL();  

    SDL_Window* window;         
    SDL_Renderer* renderer;
    State* state;    
    static Game* instance;      
};

#endif // GAME_H
